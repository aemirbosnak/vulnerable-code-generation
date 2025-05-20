//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> // Using SQLite for the database
#include <string.h>

#define MAX_QUERY_LENGTH 256
#define MAX_DB_NAME_LENGTH 100

// Error handling function
void handle_error(int rc, sqlite3 *db) {
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }
}

// Function to create a table if it does not exist
void create_table(sqlite3 *db) {
    const char *create_table_sql = 
        "CREATE TABLE IF NOT EXISTS Employees ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "Name TEXT NOT NULL,"
        "Position TEXT NOT NULL,"
        "Salary REAL NOT NULL);";
    
    char *error_message = NULL;
    int rc = sqlite3_exec(db, create_table_sql, 0, 0, &error_message);
    
    if (error_message) {
        fprintf(stderr, "SQLite Error: %s\n", error_message);
        sqlite3_free(error_message);
    }
}

// Function to insert an employee into the database
void insert_employee(sqlite3 *db, const char *name, const char *position, double salary) {
    const char *insert_sql = "INSERT INTO Employees (Name, Position, Salary) VALUES (?, ?, ?);";
    sqlite3_stmt *stmt;
    
    int rc = sqlite3_prepare_v2(db, insert_sql, -1, &stmt, NULL);
    handle_error(rc, db);
    
    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, position, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 3, salary);
    
    rc = sqlite3_step(stmt);
    handle_error(rc, db);
    
    sqlite3_finalize(stmt);
    printf("Inserted employee: %s, %s, %.2f\n", name, position, salary);
}

// Function to display all employees
void display_employees(sqlite3 *db) {
    const char *select_sql = "SELECT * FROM Employees;";
    sqlite3_stmt *stmt;
    
    int rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, NULL);
    handle_error(rc, db);
    
    printf("\nEmployee List:\n");
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        const char *position = (const char *)sqlite3_column_text(stmt, 2);
        double salary = sqlite3_column_double(stmt, 3);
        
        printf("ID: %d, Name: %s, Position: %s, Salary: %.2f\n", id, name, position, salary);
    }
    
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error fetching data: %s\n", sqlite3_errmsg(db));
    }
    
    sqlite3_finalize(stmt);
}

// Function to delete an employee by ID
void delete_employee(sqlite3 *db, int id) {
    const char *delete_sql = "DELETE FROM Employees WHERE ID = ?;";
    sqlite3_stmt *stmt;
    
    int rc = sqlite3_prepare_v2(db, delete_sql, -1, &stmt, NULL);
    handle_error(rc, db);
    
    sqlite3_bind_int(stmt, 1, id);
    rc = sqlite3_step(stmt);
    handle_error(rc, db);
    
    sqlite3_finalize(stmt);
    printf("Deleted employee with ID: %d\n", id);
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("employees.db", &db);
    handle_error(rc, db);
    
    create_table(db);
    
    char name[MAX_DB_NAME_LENGTH];
    char position[MAX_DB_NAME_LENGTH];
    double salary;
    int choice, id;

    // Menu for user interaction
    do {
        printf("\n=== Employee Database Menu ===\n");
        printf("1. Insert Employee\n");
        printf("2. Display Employees\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Position: ");
                scanf("%s", position);
                printf("Enter Salary: ");
                scanf("%lf", &salary);
                insert_employee(db, name, position, salary);
                break;
            case 2:
                display_employees(db);
                break;
            case 3:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id);
                delete_employee(db, id);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    sqlite3_close(db);
    return 0;
}