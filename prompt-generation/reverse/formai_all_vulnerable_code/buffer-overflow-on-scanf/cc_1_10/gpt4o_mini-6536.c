//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASSWORD "your_password"
#define DATABASE "test_db"

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "MySQL error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
}

void print_results(MYSQL *conn) {
    MYSQL_RES *res = mysql_store_result(conn);
    if (res == NULL) {
        finish_with_error(conn);
    }

    int num_fields = mysql_num_fields(res);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(res);
}

void create_table(MYSQL *conn) {
    const char *create_table_query = 
        "CREATE TABLE IF NOT EXISTS Employee ("
        "ID INT AUTO_INCREMENT PRIMARY KEY, "
        "Name VARCHAR(100), "
        "Position VARCHAR(100), "
        "Salary FLOAT)";
    execute_query(conn, create_table_query);
    printf("Employee table created or already exists.\n");
}

void insert_employee(MYSQL *conn, const char *name, const char *position, float salary) {
    char query[256];
    snprintf(query, sizeof(query), 
        "INSERT INTO Employee (Name, Position, Salary) VALUES ('%s', '%s', %.2f)", 
        name, position, salary);
    execute_query(conn, query);
    printf("Inserted: %s, %s, %.2f\n", name, position, salary);
}

void retrieve_employees(MYSQL *conn) {
    const char *select_query = "SELECT * FROM Employee";
    execute_query(conn, select_query);
    print_results(conn);
}

void update_employee(MYSQL *conn, int id, const char *name, const char *position, float salary) {
    char query[256];
    snprintf(query, sizeof(query), 
        "UPDATE Employee SET Name='%s', Position='%s', Salary=%.2f WHERE ID=%d", 
        name, position, salary, id);
    execute_query(conn, query);
    printf("Updated Employee ID %d: %s, %s, %.2f\n", id, name, position, salary);
}

void delete_employee(MYSQL *conn, int id) {
    char query[128];
    snprintf(query, sizeof(query), "DELETE FROM Employee WHERE ID=%d", id);
    execute_query(conn, query);
    printf("Deleted Employee ID %d\n", id);
}

void menu() {
    printf("Database Operations Menu:\n");
    printf("1. Insert Employee\n");
    printf("2. Update Employee\n");
    printf("3. Delete Employee\n");
    printf("4. Retrieve Employees\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    create_table(conn);
    
    int choice, id;
    char name[100], position[100];
    float salary;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Position: ");
                scanf("%s", position);
                printf("Enter Salary: ");
                scanf("%f", &salary);
                insert_employee(conn, name, position, salary);
                break;

            case 2:
                printf("Enter Employee ID to update: ");
                scanf("%d", &id);
                printf("Enter new Name: ");
                scanf("%s", name);
                printf("Enter new Position: ");
                scanf("%s", position);
                printf("Enter new Salary: ");
                scanf("%f", &salary);
                update_employee(conn, id, name, position, salary);
                break;

            case 3:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id);
                delete_employee(conn, id);
                break;

            case 4:
                retrieve_employees(conn);
                break;

            case 5:
                mysql_close(conn);
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    mysql_close(conn);
    return EXIT_SUCCESS;
}