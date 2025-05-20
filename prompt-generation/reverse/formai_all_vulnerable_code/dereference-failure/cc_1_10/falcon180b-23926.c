//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1000

struct query_result {
    char *query;
    MYSQL_RES *result;
    MYSQL_ROW row;
    int num_fields;
    char **field_names;
};

void die(MYSQL *mysql) {
    fprintf(stderr, "Error: %s\n", mysql_error(mysql));
    exit(1);
}

void print_result(struct query_result *result) {
    int i;

    printf("Query: %s\n", result->query);
    printf("---------------------------------------------------\n");

    while ((result->row = mysql_fetch_row(result->result))) {
        for (i = 0; i < result->num_fields; i++) {
            printf("%s = %s\n", result->field_names[i], result->row[i]? result->row[i] : "NULL");
        }
        printf("---------------------------------------------------\n");
    }
}

int main(int argc, char **argv) {
    MYSQL *mysql;
    struct query_result result;
    char query[MAX_QUERY_LENGTH];
    char *database, *table, *where_clause = NULL;
    int i, num_fields, num_rows;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s database table [WHERE clause]\n", argv[0]);
        return 1;
    }

    database = argv[1];
    table = argv[2];

    if (argc > 3) {
        where_clause = argv[3];
    }

    mysql = mysql_init(NULL);

    if (!mysql_real_connect(mysql, "localhost", "username", "password", database, 0, NULL, 0)) {
        die(mysql);
    }

    sprintf(query, "SELECT * FROM %s WHERE %s;", table, where_clause? where_clause : "1");

    if (mysql_query(mysql, query)) {
        die(mysql);
    }

    if ((result.result = mysql_store_result(mysql)) == NULL) {
        die(mysql);
    }

    result.num_fields = mysql_num_fields(result.result);
    result.field_names = mysql_fetch_fields(result.result);

    num_rows = mysql_num_rows(result.result);
    result.row = mysql_fetch_row(result.result);

    printf("Database: %s\n", database);
    printf("Table: %s\n", table);
    printf("Number of rows: %d\n", num_rows);

    print_result(&result);

    mysql_free_result(result.result);
    mysql_close(mysql);

    return 0;
}