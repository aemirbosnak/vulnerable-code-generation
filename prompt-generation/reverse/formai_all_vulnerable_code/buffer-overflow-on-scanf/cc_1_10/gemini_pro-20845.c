//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define the database file name
#define DB_FILE "mydb.db"

// Define the SQL query to execute
#define SQL_QUERY "SELECT * FROM users WHERE username LIKE ?"

// Define the maximum number of rows to return
#define MAX_ROWS 100

// Define the maximum length of a username
#define MAX_USERNAME_LENGTH 255

// Main function
int main() {
    // Initialize the SQLite database connection
    sqlite3 *db;
    int rc = sqlite3_open(DB_FILE, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Prepare the SQL statement
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, SQL_QUERY, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Bind the username parameter to the SQL statement
    char username[MAX_USERNAME_LENGTH];
    printf("Enter a username to search for: ");
    scanf("%s", username);
    rc = sqlite3_bind_text(stmt, 1, username, -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error binding parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Execute the SQL statement
    int row_count = 0;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Get the column values
        int id = sqlite3_column_int(stmt, 0);
        char *username = sqlite3_column_text(stmt, 1);
        char *email = sqlite3_column_text(stmt, 2);

        // Print the row data
        printf("ID: %d, Username: %s, Email: %s\n", id, username, email);

        // Increment the row count
        row_count++;

        // Check if the maximum number of rows has been reached
        if (row_count >= MAX_ROWS) {
            printf("Maximum number of rows reached (%d).\n", MAX_ROWS);
            break;
        }
    }

    // Check for errors
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error executing statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Finalize the SQL statement
    sqlite3_finalize(stmt);

    // Close the SQLite database connection
    sqlite3_close(db);

    return 0;
}