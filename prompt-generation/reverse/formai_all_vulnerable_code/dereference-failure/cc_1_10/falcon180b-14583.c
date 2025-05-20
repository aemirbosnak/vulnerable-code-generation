//Falcon-180B DATASET v1.0 Category: Database querying ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

typedef struct {
    char *name;
    int age;
    float salary;
} employee;

int main() {
    MYSQL *conn = NULL;
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    char query[200];
    char *server = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "company";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        printf("Error: Unable to connect to MySQL: %s\n", mysql_error(conn));
        exit(1);
    }

    printf("Connected to MySQL database\n");

    sprintf(query, "SELECT * FROM employees");

    if (mysql_query(conn, query)) {
        printf("Error: Query failed: %s\n", mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);

    printf("Employee data:\n");

    while ((row = mysql_fetch_row(result))!= NULL) {
        employee emp;
        emp.name = strdup(row[0]);
        emp.age = atoi(row[1]);
        emp.salary = atof(row[2]);

        printf("Name: %s\nAge: %d\nSalary: %.2f\n\n", emp.name, emp.age, emp.salary);
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}