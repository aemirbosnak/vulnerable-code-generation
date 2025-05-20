//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Function to create a new SQLite database and a students table
void create_database(sqlite3 *db) {
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS students "
                      "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "name TEXT NOT NULL, "
                      "age INTEGER NOT NULL);";

    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully.\n");
    }
}

// Function to insert a new student into the database
void insert_student(sqlite3 *db, const char *name, int age) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO students (name, age) VALUES (?, ?);";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, age);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Inserted student: %s, Age: %d\n", name, age);
    }
    sqlite3_finalize(stmt);
}

// Function to list all students in the database
void list_students(sqlite3 *db) {
    const char *sql = "SELECT * FROM students;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("Students List:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    }
    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    int exit;

    exit = sqlite3_open("school.db", &db);
    if (exit) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        printf("Opened database successfully.\n");
    }

    create_database(db);

    char name[100];
    int age;
    int option;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert Student\n");
        printf("2. List Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                insert_student(db, name, age);
                break;
            case 2:
                list_students(db);
                break;
            case 3:
                sqlite3_close(db);
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}