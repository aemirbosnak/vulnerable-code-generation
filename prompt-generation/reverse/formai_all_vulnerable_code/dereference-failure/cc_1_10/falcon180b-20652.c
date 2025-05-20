//Falcon-180B DATASET v1.0 Category: Database querying ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_FIELD_LENGTH 1024

MYSQL *conn;
MYSQL_RES *result;
MYSQL_ROW row;
char query[MAX_QUERY_LENGTH];
char field[MAX_FIELD_LENGTH];

void connect_to_database() {
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }
}

void execute_query(char *sql_query) {
    if (mysql_query(conn, sql_query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }
    result = mysql_store_result(conn);
}

void print_result() {
    int num_fields = mysql_num_fields(result);
    int i;

    printf("+----+-------------------------------+\n");
    for (i = 0; i < num_fields; i++) {
        row = mysql_fetch_row(result);
        strncpy(field, row[i], MAX_FIELD_LENGTH - 1);
        field[MAX_FIELD_LENGTH - 1] = '\0';
        printf("| %s |", field);
    }
    printf("+----+-------------------------------+\n");
}

int main() {
    connect_to_database();
    sprintf(query, "SELECT * FROM table_name");
    execute_query(query);
    print_result();
    mysql_close(conn);
    return 0;
}