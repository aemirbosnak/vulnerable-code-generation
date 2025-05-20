//FormAI DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define SQL statement for querying database
#define SQL_QUERY "SELECT * FROM customers WHERE age > ? AND state = ?;"

int main() {
    int age;
    char state[3];
    sqlite3 *db;
    sqlite3_stmt *stmt;
    
    // Execute security measures to prevent SQL injection attacks
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter state code: ");
    scanf("%2s", state);
    
    // Open database connection
    int rc = sqlite3_open("customers.db", &db);
    if (rc) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    
    // Prepare SQL statement
    rc = sqlite3_prepare_v2(db, SQL_QUERY, strlen(SQL_QUERY), &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing SQL statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    
    // Bind parameters to SQL statement
    rc = sqlite3_bind_int(stmt, 1, age);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error binding age parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        exit(1);
    }
    rc = sqlite3_bind_text(stmt, 2, state, strlen(state), SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error binding state parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        exit(1);
    }
    
    // Execute SQL statement and print results
    printf("Results:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        char *name = (char *) sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        char *state = (char *) sqlite3_column_text(stmt, 3);
        printf("ID:%d, Name:%s, Age:%d, State:%s\n", id, name, age, state);
    }
    
    // Finalize statement and close database connection
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return 0;
}