//Falcon-180B DATASET v1.0 Category: Database querying ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

int main() {
    MYSQL *conn = NULL;
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    char query[256];
    Employee emp;

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        printf("Error: Unable to connect to MySQL: %s\n", mysql_error(conn));
        exit(1);
    }

    // Select all employees
    sprintf(query, "SELECT name, age, salary FROM employees");
    if (mysql_query(conn, query)) {
        printf("Error: Query failed: %s\n", mysql_error(conn));
        exit(1);
    }
    result = mysql_store_result(conn);

    // Print header
    printf("Name\tAge\tSalary\n");

    // Iterate through result set and print employee details
    while ((row = mysql_fetch_row(result))!= NULL) {
        emp.name = strdup(row[0]);
        emp.age = atoi(row[1]);
        emp.salary = atof(row[2]);
        printf("%s\t%d\t%.2f\n", emp.name, emp.age, emp.salary);
        free(emp.name);
    }
    mysql_free_result(result);

    // Close connection
    mysql_close(conn);

    return 0;
}