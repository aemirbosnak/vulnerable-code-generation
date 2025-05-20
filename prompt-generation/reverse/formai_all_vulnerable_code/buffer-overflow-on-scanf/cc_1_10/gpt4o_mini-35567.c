//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

void execute_query(sqlite3 *db, const char *query) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, query, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void add_employee(sqlite3 *db) {
    char name[100];
    int age;
    
    printf("Enter employee name: ");
    scanf("%s", name);
    printf("Enter employee age: ");
    scanf("%d", &age);
    
    char query[200];
    snprintf(query, sizeof(query), "INSERT INTO Employees(Name, Age) VALUES('%s', %d);", name, age);
    execute_query(db, query);
    printf("Employee added successfully.\n");
}

void delete_employee(sqlite3 *db) {
    int id;
    
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);
    
    char query[100];
    snprintf(query, sizeof(query), "DELETE FROM Employees WHERE ID=%d;", id);
    execute_query(db, query);
    printf("Employee deleted successfully.\n");
}

void list_employees(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM Employees;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return;
    }
    
    printf("Employees:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    }
    
    sqlite3_finalize(stmt);
}

void initialize_database(sqlite3 **db) {
    int rc = sqlite3_open("employees.db", db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*db));
        exit(0);
    }
    
    const char *sql = "CREATE TABLE IF NOT EXISTS Employees(ID INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Age INTEGER);";
    execute_query(*db, sql);
}

void show_menu() {
    printf("Choose an option:\n");
    printf("1. Add Employee\n");
    printf("2. Delete Employee\n");
    printf("3. List Employees\n");
    printf("4. Exit\n");
}

int main() {
    sqlite3 *db;

    initialize_database(&db);
    
    int option;
    do {
        show_menu();
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_employee(db);
                break;
            case 2:
                delete_employee(db);
                break;
            case 3:
                list_employees(db);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (option != 4);
    
    sqlite3_close(db);
    return 0;
}