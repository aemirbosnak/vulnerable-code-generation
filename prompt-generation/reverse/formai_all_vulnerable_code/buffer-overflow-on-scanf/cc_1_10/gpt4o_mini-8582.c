//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void executeQuery(sqlite3 *db, const char *sql);
void fetchEmployeesByDepartment(sqlite3 *db, const char *department);
void displayMenu();
void closeDatabase(sqlite3 *db);

int main() {
    sqlite3 *db;
    int rc;
    char *errMsg = 0;

    // Open the database
    rc = sqlite3_open("company.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    // Initialize the database with employees table if it doesn't exist
    const char *initSQL = 
        "CREATE TABLE IF NOT EXISTS Employees ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "Name TEXT NOT NULL,"
        "Department TEXT NOT NULL,"
        "Salary REAL NOT NULL);";

    executeQuery(db, initSQL);

    // Insert sample data
    const char *insertSQL = 
        "INSERT INTO Employees (Name, Department, Salary) VALUES "
        "('Alice', 'HR', 60000),"
        "('Bob', 'Engineering', 75000),"
        "('Charlie', 'Engineering', 80000),"
        "('Diana', 'Marketing', 50000);";

    executeQuery(db, insertSQL);

    int choice;
    char department[50];

    // Menu loop
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Department Name: ");
                scanf("%s", department);
                fetchEmployeesByDepartment(db, department);
                break;

            case 2:
                printf("Exiting program...\n");
                closeDatabase(db);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    sqlite3_close(db);
    return 0;
}

void displayMenu() {
    printf("\n--- Employee Database Menu ---\n");
    printf("1. Fetch Employees by Department\n");
    printf("2. Exit\n");
}

void executeQuery(sqlite3 *db, const char *sql) {
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Query executed successfully\n");
    }
}

void fetchEmployeesByDepartment(sqlite3 *db, const char *department) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM Employees WHERE Department = ?";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, department, -1, SQLITE_STATIC);

    printf("\nEmployees in %s Department:\n", department);
    printf("ID\tName\tSalary\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        double salary = sqlite3_column_double(stmt, 3);

        printf("%d\t%s\t%.2f\n", id, name, salary);
    }

    sqlite3_finalize(stmt);
}

void closeDatabase(sqlite3 *db) {
    sqlite3_close(db);
    printf("Database closed successfully.\n");
}