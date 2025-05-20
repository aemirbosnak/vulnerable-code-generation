//Falcon-180B DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1000
#define MAX_ROW_LENGTH 1000

MYSQL *conn = NULL;
MYSQL_RES *result = NULL;
MYSQL_ROW row;
char query[MAX_QUERY_LENGTH];
char row_data[MAX_ROW_LENGTH];

int main() {
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    printf("Connected to database successfully!\n");
    printf("Enter a SQL query to execute: ");
    fgets(query, MAX_QUERY_LENGTH, stdin);

    // Trim the newline character from the end of the query
    query[strcspn(query, "\n")] = '\0';

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);
    printf("Query executed successfully!\n");

    int num_rows = mysql_num_rows(result);
    printf("Number of rows: %d\n", num_rows);
    printf("Results:\n");

    while ((row = mysql_fetch_row(result))) {
        memset(row_data, 0, MAX_ROW_LENGTH);
        int i = 0;
        while (row[i]) {
            strncat(row_data, row[i], MAX_ROW_LENGTH - strlen(row_data));
            i++;
        }
        printf("%s\n", row_data);
    }

    mysql_free_result(result);
    mysql_close(conn);
    return 0;
}