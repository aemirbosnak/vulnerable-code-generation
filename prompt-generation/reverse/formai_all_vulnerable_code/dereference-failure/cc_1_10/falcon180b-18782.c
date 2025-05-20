//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_NUM_ROWS 100

// Function prototypes
void execute_query(MYSQL *conn, char *query);
void print_results(MYSQL_RES *result, int num_fields);

int main() {
    MYSQL *conn;
    char query[MAX_QUERY_LENGTH];
    char *server = "localhost";
    char *user = "root";
    char *password = "";
    char *database = "test";

    conn = mysql_init(NULL);
    
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        printf("Error: Unable to connect to MySQL: %s\n", mysql_error(conn));
        return 1;
    }

    printf("Connected to MySQL server.\n");

    while (1) {
        printf("Enter a query or type 'exit' to quit: ");
        fgets(query, MAX_QUERY_LENGTH, stdin);

        if (strncmp(query, "exit", 4) == 0) {
            break;
        }

        execute_query(conn, query);
    }

    mysql_close(conn);
    return 0;
}

void execute_query(MYSQL *conn, char *query) {
    if (mysql_query(conn, query)) {
        printf("Error: %s\n", mysql_error(conn));
        return;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (!result) {
        printf("No results found.\n");
        return;
    }

    int num_rows = mysql_num_rows(result);
    int num_fields = mysql_num_fields(result);

    printf("Query executed successfully. Number of rows affected: %d\n", num_rows);
    printf("Number of fields: %d\n", num_fields);

    print_results(result, num_fields);

    mysql_free_result(result);
}

void print_results(MYSQL_RES *result, int num_fields) {
    MYSQL_ROW row;
    int i;

    printf("Results:\n");
    while ((row = mysql_fetch_row(result))) {
        for (i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
}