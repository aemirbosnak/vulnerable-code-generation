//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DB_NAME "students.db"

// Function to execute an SQL statement
int execute_sql(sqlite3 *db, const char *sql) {
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return rc;
    }
    return SQLITE_OK;
}

// Callback function to display retrieved student data
int display_students(void *not_used, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s: %s ", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// Function to connect to the database and initialize it
sqlite3 *initialize_db() {
    sqlite3 *db;
    int rc = sqlite3_open(DB_NAME, &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return NULL;
    }
    
    const char *sql = "CREATE TABLE IF NOT EXISTS Students("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "Name TEXT NOT NULL, "
                      "Age INT NOT NULL, "
                      "Grade TEXT NOT NULL );";
    
    if (execute_sql(db, sql) != SQLITE_OK) {
        sqlite3_close(db);
        return NULL;
    }
    
    return db;
}

// Function to add a student to the database
void add_student(sqlite3 *db, const char *name, int age, const char *grade) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO Students (Name, Age, Grade) VALUES (?, ?, ?)";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, age);
    sqlite3_bind_text(stmt, 3, grade, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(db));
    }
    sqlite3_finalize(stmt);
}

// Function to query and display all students
void query_students(sqlite3 *db) {
    const char *sql = "SELECT * FROM Students";
    char *errMsg = 0;

    if (sqlite3_exec(db, sql, display_students, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute query: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

int main() {
    sqlite3 *db = initialize_db();
    if (!db) {
        return EXIT_FAILURE;
    }

    while (1) {
        printf("\nStudent Database Menu:\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            char name[100];
            int age;
            char grade[10];

            printf("Enter Student Name: ");
            scanf("%s", name);

            printf("Enter Student Age: ");
            scanf("%d", &age);

            printf("Enter Student Grade: ");
            scanf("%s", grade);

            add_student(db, name, age, grade);
            printf("Student added successfully.\n");
        } else if (choice == 2) {
            printf("List of Students:\n");
            query_students(db);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    sqlite3_close(db);
    return EXIT_SUCCESS;
}