//Falcon-180B DATASET v1.0 Category: Database querying ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Struct to hold user data
typedef struct User {
    int id;
    char name[50];
    int age;
} User;

// Function to print user data
void printUser(User user) {
    printf("ID: %d Name: %s Age: %d\n", user.id, user.name, user.age);
}

// Function to execute SQL query and print results
void executeQuery(sqlite3 *db, char *query) {
    char *sql = (char *) malloc(strlen(query) + 1);
    strcpy(sql, query);

    sqlite3_stmt *stmt = NULL;
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        User user;
        user.id = sqlite3_column_int(stmt, 0);
        user.age = sqlite3_column_int(stmt, 1);
        strncpy(user.name, (char *) sqlite3_column_text(stmt, 2), sizeof(user.name));
        printUser(user);
    }

    sqlite3_finalize(stmt);
    free(sql);
}

// Function to create a new user
void createUser(sqlite3 *db, User user) {
    char sql[100];
    sprintf(sql, "INSERT INTO users (name, age) VALUES ('%s', %d)", user.name, user.age);
    sqlite3_exec(db, sql, NULL, NULL, NULL);
}

int main() {
    sqlite3 *db;
    int rc;

    // Open database
    rc = sqlite3_open("user_database.db", &db);

    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    // Create table
    char sql[100];
    sprintf(sql, "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER)");
    sqlite3_exec(db, sql, NULL, NULL, NULL);

    // Insert sample data
    User user1 = { 0, "John Doe", 25 };
    createUser(db, user1);

    User user2 = { 0, "Jane Doe", 30 };
    createUser(db, user2);

    // Execute queries
    executeQuery(db, "SELECT * FROM users");
    executeQuery(db, "SELECT * FROM users WHERE age > 25");

    // Close database
    sqlite3_close(db);

    return 0;
}