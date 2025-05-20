//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_NAME_LENGTH 50
#define DB_NAME "students.db"

void create_table(sqlite3 *db);
void add_student(sqlite3 *db, const char *name);
void view_students(sqlite3 *db);
void search_student(sqlite3 *db, const char *name);
int callback(void *NotUsed, int argc, char **argv, char **azColName);


int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    int choice;
    char name[MAX_NAME_LENGTH];

    rc = sqlite3_open(DB_NAME, &db);
    
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    create_table(db);

    do {
        printf("\n--- Student Database ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter student name: ");
                scanf("%s", name);
                add_student(db, name);
                break;
            case 2:
                view_students(db);
                break;
            case 3:
                printf("Enter student name to search: ");
                scanf("%s", name);
                search_student(db, name);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    sqlite3_close(db);
    return 0;
}

void create_table(sqlite3 *db) {
    char *sql = "CREATE TABLE IF NOT EXISTS STUDENTS (" \
                "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
                "NAME TEXT NOT NULL);";
    char *zErrMsg = 0;
    
    int rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Table created successfully\n");
    }
}

void add_student(sqlite3 *db, const char *name) {
    char sql[100];
    char *zErrMsg = 0;
    snprintf(sql, sizeof(sql), "INSERT INTO STUDENTS (NAME) VALUES ('%s');", name);
    
    int rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Student added successfully: %s\n", name);
    }
}

void view_students(sqlite3 *db) {
    const char *sql = "SELECT * FROM STUDENTS;";
    char *zErrMsg = 0;
    
    int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

void search_student(sqlite3 *db, const char *name) {
    char sql[100];
    char *zErrMsg = 0;
    snprintf(sql, sizeof(sql), "SELECT * FROM STUDENTS WHERE NAME = '%s';", name);
    
    int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}