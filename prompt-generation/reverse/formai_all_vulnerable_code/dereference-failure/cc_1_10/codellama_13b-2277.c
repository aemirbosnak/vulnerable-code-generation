//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: modular
/*
 * Modular C Program to Query a Database
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Structure to hold database query results
typedef struct {
    int id;
    char name[50];
    char email[50];
} Result;

// Function to execute a database query and store results in a Result structure
int executeQuery(sqlite3 *db, const char *query, Result *result) {
    // Initialize statement and result set
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    // Execute query and retrieve results
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        // Save results in Result structure
        result->id = sqlite3_column_int(stmt, 0);
        strcpy(result->name, (char *)sqlite3_column_text(stmt, 1));
        strcpy(result->email, (char *)sqlite3_column_text(stmt, 2));
    } else {
        fprintf(stderr, "Failed to execute query: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    // Clean up
    sqlite3_finalize(stmt);
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Initialize database
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }

    // Execute query and store results in Result structure
    Result result;
    rc = executeQuery(db, "SELECT id, name, email FROM users WHERE id = 1", &result);
    if (rc != 0) {
        fprintf(stderr, "Failed to execute query\n");
        sqlite3_close(db);
        return -1;
    }

    // Print results
    printf("ID: %d\nName: %s\nEmail: %s\n", result.id, result.name, result.email);

    // Clean up
    sqlite3_close(db);
    return 0;
}