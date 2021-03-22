/*
 * This file is part of the ZoneMinder Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "catch2/catch.hpp"

#include "zm_utils.h"

TEST_CASE("trimSet") {
  REQUIRE(trimSet("", "") == "");
  REQUIRE(trimSet("test", "") == "test");
  REQUIRE(trimSet(" ", "") == " ");

  REQUIRE(trimSet("\"test", "\"") == "test");
  REQUIRE(trimSet("test\"", "\"") == "test");
  REQUIRE(trimSet("\"test\"", "\"") == "test");

  REQUIRE(trimSet("te\"st", "\"") == "te\"st");
  REQUIRE(trimSet("\"te\"st\"", "\"") == "te\"st");
}

TEST_CASE("trimSpaces") {
  REQUIRE(trimSpaces(" ") == "");

  REQUIRE(trimSpaces("test") == "test");
  REQUIRE(trimSpaces(" test ") == "test");
  REQUIRE(trimSpaces("  test ") == "test");
  REQUIRE(trimSpaces("  test  ") == "test");
  REQUIRE(trimSpaces(" test") == "test");
  REQUIRE(trimSpaces("\ttest") == "test");
  REQUIRE(trimSpaces("test\t") == "test");
  REQUIRE(trimSpaces("\ttest\t") == "test");
  REQUIRE(trimSpaces(" test\t") == "test");
  REQUIRE(trimSpaces("\ttest ") == "test");
  REQUIRE(trimSpaces("\t test \t") == "test");

  REQUIRE(trimSpaces("\t te st \t") == "te st");
}
