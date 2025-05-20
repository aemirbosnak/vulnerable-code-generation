//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DB_NAME "example.db"

void handle_error(int rc, sqlite3 *db) {
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
}

void create_table(sqlite3 *db) {
    const char *sql_create = "CREATE TABLE IF NOT EXISTS Students ("
                             "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                             "Name TEXT NOT NULL, "
                             "Age INTEGER NOT NULL, "
                             "Grade TEXT NOT NULL);";
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql_create, 0, 0, &err_msg);
    handle_error(rc, db);
}

void insert_student(sqlite3 *db, const char *name, int age, const char *grade) {
    char sql_insert[256];
    snprintf(sql_insert, sizeof(sql_insert), "INSERT INTO Students (Name, Age, Grade) VALUES ('%s', %d, '%s');", name, age, grade);
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql_insert, 0, 0, &err_msg);
    handle_error(rc, db);
}

void query_students(sqlite3 *db) {
    const char *sql_query = "SELECT ID, Name, Age, Grade FROM Students;";
    sqlite3_stmt *stmt;
    
    int rc = sqlite3_prepare_v2(db, sql_query, -1, &stmt, 0);
    handle_error(rc, db);
    
    printf("Querying students...\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        const unsigned char *grade = sqlite3_column_text(stmt, 3);
        
        printf("ID: %d, Name: %s, Age: %d, Grade: %s\n", id, name, age, grade);
    }
    
    sqlite3_finalize(stmt);
}

void cleanup(sqlite3 *db) {
    sqlite3_close(db);
}

void prompt_user_for_student_data(sqlite3 *db) {
    char name[50];
    int age;
    char grade[3];

    printf("Enter student's name: ");
    scanf("%49s", name);
    printf("Enter student's age: ");
    scanf("%d", &age);
    printf("Enter student's grade (e.g., A, B, C): ");
    scanf("%2s", grade);

    insert_student(db, name, age, grade);
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open(DB_NAME, &db);
    handle_error(rc, db);
    
    create_table(db);
    
    char option;
    do {
        printf("Choose an option:\n");
        printf("1. Add a Student\n");
        printf("2. View Students\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf(" %c", &option);
        
        switch (option) {
            case '1':
                prompt_user_for_student_data(db);
                break;
            case '2':
                query_students(db);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != '3');

    cleanup(db);
    return 0;
}