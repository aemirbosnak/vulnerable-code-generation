//Falcon-180B DATASET v1.0 Category: Database querying ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} employee;

void display_result(MYSQL_RES *result) {
    MYSQL_ROW row = mysql_fetch_row(result);
    while (row!= NULL) {
        printf("%s %d %.2f\n", row[0], atoi(row[1]), atof(row[2]));
        row = mysql_fetch_row(result);
    }
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    employee emp;
    char query[100];

    printf("Enter employee name: ");
    scanf("%s", emp.name);

    strcpy(query, "SELECT * FROM employees WHERE name='");
    strcat(query, emp.name);
    strcat(query, "'");

    if (mysql_query(conn, query)) {
        printf("Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (mysql_num_rows(result) == 0) {
        printf("No record found\n");
    } else {
        display_result(result);
    }

    mysql_close(conn);
    return 0;
}