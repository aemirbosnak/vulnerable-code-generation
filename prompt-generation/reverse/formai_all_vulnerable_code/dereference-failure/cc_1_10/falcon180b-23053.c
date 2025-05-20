//Falcon-180B DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

MYSQL *conn = NULL;

void connect_to_db() {
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "database", 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }
    printf("Connected to database\n");
}

void execute_query(char *query) {
    if (mysql_query(conn, query)) {
        printf("Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }
}

void print_result(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
}

void free_result(MYSQL_RES *result) {
    mysql_free_result(result);
}

int main() {
    connect_to_db();

    char query[1000];
    sprintf(query, "SELECT * FROM employees WHERE salary > %d", 50000);
    execute_query(query);

    MYSQL_RES *result = mysql_store_result(conn);
    print_result(result);
    free_result(result);

    mysql_close(conn);
    return 0;
}