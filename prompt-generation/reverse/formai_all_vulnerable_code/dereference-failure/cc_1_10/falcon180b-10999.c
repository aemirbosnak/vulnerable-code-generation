//Falcon-180B DATASET v1.0 Category: Database querying ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024

MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;

int main() {
    char query[MAX_QUERY_LENGTH];
    char *server = "localhost";
    char *user = "username";
    char *password = "password";
    char *dbname = "database_name";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, dbname, 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        return 1;
    }

    printf("Connected to database successfully.\n");

    while (1) {
        printf("Enter SQL query: ");
        fgets(query, MAX_QUERY_LENGTH, stdin);

        if (strcasecmp(query, "exit") == 0) {
            break;
        }

        if (mysql_query(conn, query)) {
            printf("Error executing query: %s\n", mysql_error(conn));
        } else {
            res = mysql_store_result(conn);

            if (res == NULL) {
                printf("No results found.\n");
            } else {
                printf("Results:\n");

                while ((row = mysql_fetch_row(res))!= NULL) {
                    for (int i = 0; i < mysql_num_fields(res); i++) {
                        printf("%s ", row[i]? row[i] : "NULL");
                    }

                    printf("\n");
                }

                mysql_free_result(res);
            }
        }
    }

    mysql_close(conn);

    return 0;
}