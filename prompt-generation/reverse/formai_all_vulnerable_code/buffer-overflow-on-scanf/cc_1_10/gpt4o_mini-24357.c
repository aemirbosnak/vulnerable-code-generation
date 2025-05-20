//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void displayMenu() {
    printf("=========================================\n");
    printf("           DATABASE MENU                \n");
    printf("=========================================\n");
    printf("1. Add a new employee\n");
    printf("2. Query all employees\n");
    printf("3. Search employee by ID\n");
    printf("4. Update employee salary\n");
    printf("5. Delete an employee\n");
    printf("6. Exit\n");
    printf("=========================================\n");
    printf("Select an option: ");
}

int addEmployee(sqlite3* db) {
    char sql[256];
    sqlite3_stmt* stmt;

    char name[50];
    int age;
    float salary;

    printf("Enter employee name: ");
    scanf("%s", name);
    printf("Enter employee age: ");
    scanf("%d", &age);
    printf("Enter employee salary: ");
    scanf("%f", &salary);

    snprintf(sql, sizeof(sql), "INSERT INTO Employees (Name, Age, Salary) VALUES ('%s', %d, %f);", name, age, salary);

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return -1;
    }

    sqlite3_finalize(stmt);
    printf("Employee added successfully!\n");
    return 0;
}

void queryAllEmployees(sqlite3* db) {
    const char* sql = "SELECT * FROM Employees;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("ID\tName\t\tAge\tSalary\n");
    printf("------------------------------------------\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*)sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        float salary = (float)sqlite3_column_double(stmt, 3);
        printf("%d\t%s\t\t%d\t%.2f\n", id, name, age, salary);
    }

    sqlite3_finalize(stmt);
}

void searchEmployeeByID(sqlite3* db) {
    sqlite3_stmt* stmt;
    int id;

    printf("Enter employee ID to search: ");
    scanf("%d", &id);

    char sql[100];
    snprintf(sql, sizeof(sql), "SELECT * FROM Employees WHERE ID=%d;", id);

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int empID = sqlite3_column_int(stmt, 0);
        const char* name = (const char*)sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        float salary = (float)sqlite3_column_double(stmt, 3);
        printf("Employee found: ID=%d, Name=%s, Age=%d, Salary=%.2f\n", empID, name, age, salary);
    } else {
        printf("No employee found with ID %d.\n", id);
    }

    sqlite3_finalize(stmt);
}

void updateEmployeeSalary(sqlite3* db) {
    sqlite3_stmt* stmt;
    int id;
    float newSalary;

    printf("Enter employee ID to update salary: ");
    scanf("%d", &id);
    printf("Enter new salary: ");
    scanf("%f", &newSalary);

    char sql[100];
    snprintf(sql, sizeof(sql), "UPDATE Employees SET Salary=%.2f WHERE ID=%d;", newSalary, id);

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Salary updated successfully!\n");
    }

    sqlite3_finalize(stmt);
}

void deleteEmployee(sqlite3* db) {
    sqlite3_stmt* stmt;
    int id;

    printf("Enter employee ID to delete: ");
    scanf("%d", &id);

    char sql[100];
    snprintf(sql, sizeof(sql), "DELETE FROM Employees WHERE ID=%d;", id);

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Employee deleted successfully!\n");
    }

    sqlite3_finalize(stmt);
}

int main() {
    sqlite3* db;
    if (sqlite3_open("company.db", &db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Create Employees table if it doesn't exist
    char* sql = "CREATE TABLE IF NOT EXISTS Employees (ID INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Age INTEGER, Salary REAL);";
    char* errMsg;
    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return 1;
    }

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee(db);
                break;
            case 2:
                queryAllEmployees(db);
                break;
            case 3:
                searchEmployeeByID(db);
                break;
            case 4:
                updateEmployeeSalary(db);
                break;
            case 5:
                deleteEmployee(db);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    sqlite3_close(db);
    return 0;
}