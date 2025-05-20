//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void execute_query(sqlite3 *db, const char *sql);
void insert_user(sqlite3 *db);
void display_users(sqlite3 *db);
void run_user_queries(sqlite3 *db);

int main() {
    sqlite3 *db;
    char *err_msg = 0;

    int exit = sqlite3_open("users.db", &db);

    if (exit != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return exit;
    }

    // Create a table for users
    const char *create_table_sql = "CREATE TABLE IF NOT EXISTS Users("
                                    "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                    "Name TEXT NOT NULL, "
                                    "Age INTEGER NOT NULL);";

    execute_query(db, create_table_sql);

    run_user_queries(db);

    sqlite3_close(db);
    return 0;
}

void execute_query(sqlite3 *db, const char *sql) {
    char *err_msg = 0;
    int exit = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (exit != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Operation done successfully\n");
    }
}

void insert_user(sqlite3 *db) {
    char name[50];
    int age;

    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Age: ");
    scanf("%d", &age);

    char sql[100];
    snprintf(sql, sizeof(sql), "INSERT INTO Users (Name, Age) VALUES ('%s', %d);", name, age);

    execute_query(db, sql);
}

void display_users(sqlite3 *db) {
    const char *select_users_sql = "SELECT * FROM Users;";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, select_users_sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    printf("\nList of Users:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        printf("ID: %d | Name: %s | Age: %d\n", id, name, age);
    }

    sqlite3_finalize(stmt);
}

void run_user_queries(sqlite3 *db) {
    int choice;
    do {
        printf("\nUser Menu:\n");
        printf("1. Insert User\n");
        printf("2. Display All Users\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_user(db);
                break;
            case 2:
                display_users(db);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);
}