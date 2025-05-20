//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DB_FILE "example.db"

int main() {
    // Open the database file.
    sqlite3 *db;
    int rc = sqlite3_open(DB_FILE, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Prepare the SQL statement.
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM people WHERE name LIKE ?;";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Bind the wildcard parameter to the user's input.
    char input[256];
    printf("Enter a name to search for: ");
    scanf("%s", input);
    rc = sqlite3_bind_text(stmt, 1, input, -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error binding parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Execute the query.
    int first = 1;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (first) {
            printf("Found the following people:\n");
            first = 0;
        }
        printf(" - %s\n", sqlite3_column_text(stmt, 1));
    }
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error executing query: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Finalize the statement and close the database.
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}