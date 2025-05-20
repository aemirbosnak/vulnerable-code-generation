//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define DB_NAME "example.db"
#define BUFFER_SIZE 256

void handle_error(const char *msg, int rc) {
    fprintf(stderr, "%s: %s\n", msg, sqlite3_errstr(rc));
    exit(EXIT_FAILURE);
}

sqlite3* connect_database(const char *db_name) {
    sqlite3 *db;
    int rc = sqlite3_open(db_name, &db);
    if (rc) {
        handle_error("Can't open database", rc);
    }
    return db;
}

void create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS Users ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Name TEXT NOT NULL,"
                      "Age INTEGER NOT NULL);";
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        handle_error("Failed to create table", rc);
    }
}

void insert_user(sqlite3 *db, const char *name, int age) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO Users (Name, Age) VALUES (?, ?);";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        handle_error("Failed to prepare statement", rc);
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, age);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        handle_error("Execution failed", rc);
    }

    sqlite3_finalize(stmt);
}

void display_users(sqlite3 *db) {
    const char *sql = "SELECT * FROM Users;";
    sqlite3_stmt *stmt;
    
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        handle_error("Failed to prepare select statement", rc);
    }

    printf("ID\tName\tAge\n");
    printf("------------------------\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        printf("%d\t%s\t%d\n", id, name, age);
    }

    sqlite3_finalize(stmt);
}

void cleanup(sqlite3 *db) {
    sqlite3_close(db);
}

int main() {
    sqlite3 *db = connect_database(DB_NAME);
    create_table(db);

    int choice;
    char name[BUFFER_SIZE];
    int age;

    while (1) {
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                insert_user(db, name, age);
                break;
            case 2:
                display_users(db);
                break;
            case 3:
                cleanup(db);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    cleanup(db);
    return 0;
}