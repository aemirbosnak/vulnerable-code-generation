//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DB_NAME "students.db"

int create_table(sqlite3 *db) {
    const char *create_table_sql = 
        "CREATE TABLE IF NOT EXISTS Students (" \
        "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
        "Name TEXT NOT NULL," \
        "Age INTEGER NOT NULL);";

    char *err_msg;
    int rc = sqlite3_exec(db, create_table_sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to create table: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}

int add_student(sqlite3 *db, const char *name, int age) {
    sqlite3_stmt *stmt;
    const char *insert_sql = "INSERT INTO Students (Name, Age) VALUES (?, ?);";
    
    int rc = sqlite3_prepare_v2(db, insert_sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, age);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to insert data: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    sqlite3_finalize(stmt);
    return 0;
}

int display_students(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *select_sql = "SELECT * FROM Students;";
    
    int rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    printf("Students List:\n");
    printf("ID\tName\t\tAge\n");
    printf("-------------------------\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        printf("%d\t%s\t\t%d\n", id, name, age);
    }

    sqlite3_finalize(stmt);
    return 0;
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open(DB_NAME, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    if (create_table(db) != 0) {
        sqlite3_close(db);
        return 1;
    }

    int choice;
    char name[100];
    int age;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                if (add_student(db, name, age) == 0) {
                    printf("Student added successfully!\n");
                }
                break;
            case 2:
                display_students(db);
                break;
            case 3:
                sqlite3_close(db);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    sqlite3_close(db);
    return 0;
}