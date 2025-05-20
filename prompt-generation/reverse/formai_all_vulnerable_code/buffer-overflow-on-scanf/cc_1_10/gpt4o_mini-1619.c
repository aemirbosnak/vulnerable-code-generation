//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_INPUT 100

// Function to execute a SQL query and print the results
int execute_query(sqlite3 *db, const char *query) {
    char *errMsg = 0;
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to execute query: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    // Loop through the rows in the result set
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Printing column data
        for (int i = 0; i < sqlite3_column_count(stmt); i++) {
            const char *colText = (const char *)sqlite3_column_text(stmt, i);
            printf("%s | ", colText ? colText : "NULL");
        }
        printf("\n");
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Execution finished with error: %s\n", sqlite3_errmsg(db));
    }
    
    sqlite3_finalize(stmt);
    return 0;
}

void create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS Employees"
                      "(ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Name TEXT NOT NULL,"
                      "Position TEXT NOT NULL,"
                      "Salary REAL NOT NULL);";
    
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created or already exists.\n");
    }
}

void insert_employee(sqlite3 *db) {
    char name[MAX_INPUT], position[MAX_INPUT];
    double salary;

    printf("Enter Employee Name: ");
    fgets(name, MAX_INPUT, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline

    printf("Enter Position: ");
    fgets(position, MAX_INPUT, stdin);
    position[strcspn(position, "\n")] = 0; // remove newline

    printf("Enter Salary: ");
    scanf("%lf", &salary);
    getchar(); // Consume newline character

    char sql[MAX_INPUT * 3];
    snprintf(sql, sizeof(sql), "INSERT INTO Employees (Name, Position, Salary) VALUES ('%s', '%s', %f);", name, position, salary);
    
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Insert error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Employee added successfully.\n");
    }
}

void display_employees(sqlite3 *db) {
    const char *sql = "SELECT * FROM Employees;";
    printf("Displaying Employees:\n");
    execute_query(db, sql);
}

void delete_employee(sqlite3 *db) {
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);
    getchar(); // Consume newline character
    
    char sql[MAX_INPUT];
    snprintf(sql, sizeof(sql), "DELETE FROM Employees WHERE ID = %d;", id);
    
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Delete error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Employee deleted successfully.\n");
    }
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("employee.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        printf("Opened database successfully.\n");
    }

    create_table(db);

    int option;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        getchar(); // Consume newline character

        switch (option) {
            case 1:
                insert_employee(db);
                break;
            case 2:
                display_employees(db);
                break;
            case 3:
                delete_employee(db);
                break;
            case 4:
                sqlite3_close(db);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    sqlite3_close(db);
    return 0;
}