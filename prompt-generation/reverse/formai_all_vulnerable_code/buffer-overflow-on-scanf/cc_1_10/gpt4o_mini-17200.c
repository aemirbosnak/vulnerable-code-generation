//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

void execute_query(sqlite3 *db, const char *sql);
void display_results(sqlite3_stmt *stmt);

int main() {
    sqlite3 *db;
    char *err_msg = 0;

    // Open a connection to the SQLite database
    int rc = sqlite3_open("company.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Create a sample table
    const char *create_table_sql = 
        "CREATE TABLE IF NOT EXISTS Employees ("
        "Id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "Name TEXT NOT NULL,"
        "Department TEXT NOT NULL,"
        "Salary REAL NOT NULL);";
    execute_query(db, create_table_sql);

    // Insert sample data into the Employees table
    const char *insert_sql = 
        "INSERT INTO Employees (Name, Department, Salary) VALUES "
        "('Alice', 'Engineering', 70000),"
        "('Bob', 'Marketing', 50000),"
        "('Charlie', 'Engineering', 75000),"
        "('David', 'HR', 55000);";
    execute_query(db, insert_sql);

    // Prompt for parameters to filter Employee records
    char department[30];
    double min_salary;

    printf("Enter department to filter (Engineering, Marketing, HR): ");
    scanf("%s", department);
    printf("Enter minimum salary to filter: ");
    scanf("%lf", &min_salary);

    // Construct the query with multiple variables
    char query[256];
    snprintf(query, sizeof(query),
            "SELECT Id, Name, Department, Salary FROM Employees "
            "WHERE Department = '%s' AND Salary >= %.2f;", department, min_salary);

    // Execute the query and display results
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
    } else {
        display_results(stmt);
        sqlite3_finalize(stmt);
    }

    // Close the database connection
    sqlite3_close(db);
    return 0;
}

void execute_query(sqlite3 *db, const char *sql) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void display_results(sqlite3_stmt *stmt) {
    printf("Filtered Employees:\n");
    printf("Id\tName\t\tDepartment\tSalary\n");
    printf("---------------------------------------------\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        const char *department = (const char *)sqlite3_column_text(stmt, 2);
        double salary = sqlite3_column_double(stmt, 3);

        printf("%d\t%s\t%s\t%.2f\n", id, name, department, salary);
    }
}