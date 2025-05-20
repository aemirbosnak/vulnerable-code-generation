//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "your_username"
#define PASSWORD "your_password"
#define DATABASE "your_database"

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void display_menu() {
    printf("1. Add Employee\n");
    printf("2. View Employees\n");
    printf("3. Update Employee\n");
    printf("4. Delete Employee\n");
    printf("5. Exit\n");
}

void add_employee(MYSQL *con) {
    char name[100];
    int age;
    char department[50];
    
    printf("Enter employee name: ");
    scanf("%s", name);
    printf("Enter employee age: ");
    scanf("%d", &age);
    printf("Enter employee department: ");
    scanf("%s", department);

    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO employees(name, age, department) VALUES('%s', %d, '%s')", name, age, department);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
    printf("Employee added successfully.\n");
}

void view_employees(MYSQL *con) {
    if (mysql_query(con, "SELECT * FROM employees")) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("ID\tName\t\tAge\tDepartment\n");
    printf("---------------------------------------------\n");
    
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

void update_employee(MYSQL *con) {
    int id;
    char name[100];
    int age;
    char department[50];
    
    printf("Enter employee ID to update: ");
    scanf("%d", &id);
    
    printf("Enter new employee name: ");
    scanf("%s", name);
    printf("Enter new employee age: ");
    scanf("%d", &age);
    printf("Enter new employee department: ");
    scanf("%s", department);

    char query[256];
    snprintf(query, sizeof(query), "UPDATE employees SET name='%s', age=%d, department='%s' WHERE id=%d", name, age, department, id);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
    printf("Employee updated successfully.\n");
}

void delete_employee(MYSQL *con) {
    int id;
    
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);

    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM employees WHERE id=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
    printf("Employee deleted successfully.\n");
}

int main() {
    MYSQL *con = mysql_init(NULL);
    
    if (con == NULL) {
        finish_with_error(con);
    }

    if (mysql_real_connect(con, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    while (1) {
        display_menu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee(con);
                break;
            case 2:
                view_employees(con);
                break;
            case 3:
                update_employee(con);
                break;
            case 4:
                delete_employee(con);
                break;
            case 5:
                mysql_close(con);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    mysql_close(con);
    return 0;
}