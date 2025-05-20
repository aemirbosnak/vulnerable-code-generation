//FormAI DATASET v1.0 Category: Database querying ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Callback function to print records
static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *errMsg = NULL;

    // Open the database connection
    int rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create a table
    char *sql = "CREATE TABLE IF NOT EXISTS users ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name TEXT NOT NULL,"
                "email TEXT NOT NULL UNIQUE,"
                "password TEXT NOT NULL);";
    rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully\n");
    }

    // Insert some records
    sql = "INSERT INTO users (name, email, password) "
          "VALUES ('Alice', 'alice@example.com', 'password1'),"
          "('Bob', 'bob@example.com', 'password2'),"
          "('Charlie', 'charlie@example.com', 'password3');";
    rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Records inserted successfully\n");
    }

    // Query the database using user input
    char name[20];
    printf("Enter a name to search for: ");
    scanf("%s", name);
    char query[50];
    sprintf(query, "SELECT * FROM users WHERE name='%s';", name);
    rc = sqlite3_exec(db, query, callback, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    // Close the database connection
    sqlite3_close(db);
    return 0;
}