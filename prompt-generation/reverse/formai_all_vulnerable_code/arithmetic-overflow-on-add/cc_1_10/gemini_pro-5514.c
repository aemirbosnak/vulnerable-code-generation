//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// A magical function that retrieves a spell from the database
char* cast_spell(sqlite3 *db, char *spell_name) {
  char *query = "SELECT incantation FROM Spells WHERE name = ?";
  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
    return NULL;
  }

  // Bind the spell name to the query parameter
  rc = sqlite3_bind_text(stmt, 1, spell_name, -1, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error binding parameter: %s\n", sqlite3_errmsg(db));
    return NULL;
  }

  // Execute the query and retrieve the spell incantation
  rc = sqlite3_step(stmt);
  if (rc != SQLITE_ROW) {
    fprintf(stderr, "No such spell found: %s\n", spell_name);
    return NULL;
  }

  const unsigned char *incantation = sqlite3_column_text(stmt, 0);
  int incantation_length = sqlite3_column_bytes(stmt, 0);

  // Copy the incantation into a new string and return it
  char *spell_incantation = malloc(incantation_length + 1);
  memcpy(spell_incantation, incantation, incantation_length);
  spell_incantation[incantation_length] = '\0';

  sqlite3_finalize(stmt);
  return spell_incantation;
}

// A brave adventurer who uses the magic database to cast spells
int main() {
  // Connect to the database of magical incantations
  sqlite3 *db;
  int rc = sqlite3_open("spells.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
    return EXIT_FAILURE;
  }

  // Define the spells to be cast
  char *spells[] = {"Fireball", "Lightning Bolt", "Heal"};

  // Cast and print the incantations of the spells
  for (int i = 0; i < 3; i++) {
    char *incantation = cast_spell(db, spells[i]);
    if (incantation != NULL) {
      printf("%s: %s\n", spells[i], incantation);
      free(incantation);
    }
  }

  // Close the database
  sqlite3_close(db);
  return EXIT_SUCCESS;
}