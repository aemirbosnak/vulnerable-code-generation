//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define DB_NAME "test.db"

void exitWithError(char *message, sqlite3 *db) {
    fprintf(stderr, "%s: %s\n", message, sqlite3_errmsg(db));
    sqlite3_close(db);
    exit(EXIT_FAILURE);
}

void createTable(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS Users("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Name TEXT NOT NULL,"
                      "Age INTEGER NOT NULL);";
    
    char *errMsg = NULL;
    if (sqlite3_exec(db, sql, NULL, 0, &errMsg) != SQLITE_OK) {
        exitWithError("Failed to create table", db);
    }
}

void insertUser(sqlite3 *db, const char *name, int age) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO Users (Name, Age) VALUES (?, ?);";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        exitWithError("Failed to prepare insert statement", db);
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, age);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        exitWithError("Failed to execute insert statement", db);
    }

    sqlite3_finalize(stmt);
    printf("User \"%s\" added to the database.\n", name);
}

void queryUsers(sqlite3 *db) {
    const char *sql = "SELECT * FROM Users;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        exitWithError("Failed to prepare query statement", db);
    }

    printf("Users in Database:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    }

    sqlite3_finalize(stmt);
}

void deleteUser(sqlite3 *db, int id) {
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM Users WHERE ID = ?;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        exitWithError("Failed to prepare delete statement", db);
    }

    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        exitWithError("Failed to execute delete statement", db);
    }

    sqlite3_finalize(stmt);
    printf("User with ID %d deleted from the database.\n", id);
}

int main() {
    sqlite3 *db;
    char *errMsg = NULL;

    if (sqlite3_open(DB_NAME, &db) != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    }

    createTable(db);

    int choice;
    char name[100];
    int age, id;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add User\n");
        printf("2. View Users\n");
        printf("3. Delete User\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                insertUser(db, name, age);
                break;
            case 2:
                queryUsers(db);
                break;
            case 3:
                printf("Enter User ID to Delete: ");
                scanf("%d", &id);
                deleteUser(db, id);
                break;
            case 4:
                sqlite3_close(db);
                printf("Goodbye!\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    sqlite3_close(db);
    return EXIT_SUCCESS;
}