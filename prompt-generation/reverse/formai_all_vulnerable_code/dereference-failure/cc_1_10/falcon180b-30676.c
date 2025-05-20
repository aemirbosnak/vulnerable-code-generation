//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_RESULTS 1000

typedef struct {
    char *name;
    int age;
} Person;

void print_results(MYSQL_RES *result, MYSQL_ROW row, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        printf("%s = %s\n", mysql_fetch_field(result)->name, row[i]? row[i] : "NULL");
    }
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    char query[MAX_QUERY_LENGTH];
    printf("Enter SQL query: ");
    fgets(query, MAX_QUERY_LENGTH, stdin);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);

    if (mysql_field_count(conn) > 0) {
        printf("Results:\n");
        while ((row = mysql_fetch_row(result))) {
            print_results(result, row, num_fields);
        }
    } else {
        printf("Query executed successfully, but no results found.\n");
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}