//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char *argv[])
{
    // Check if the user has provided the database file name
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <database file>\n", argv[0]);
        return 1;
    }

    // Open the database file
    sqlite3 *db;
    if (sqlite3_open(argv[1], &db) != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Prepare the SQL statement
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM students WHERE name LIKE ? ORDER BY name";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Bind the user-provided search term to the SQL statement
    char search_term[256];
    printf("Enter a search term: ");
    scanf("%s", search_term);
    sqlite3_bind_text(stmt, 1, search_term, -1, SQLITE_TRANSIENT);

    // Execute the SQL statement
    int rc;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Retrieve the values from the current row
        int id = sqlite3_column_int(stmt, 0);
        const char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);

        // Print the values to the console
        printf("%d | %s | %d\n", id, name, age);
    }

    // Check for any errors during execution
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error executing statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Finalize the SQL statement
    sqlite3_finalize(stmt);

    // Close the database connection
    sqlite3_close(db);

    return 0;
}