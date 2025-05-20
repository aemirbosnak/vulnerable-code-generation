//Falcon-180B DATASET v1.0 Category: Database querying ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_ROW_LENGTH 4096

int main(int argc, char *argv[]) {
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    char query[MAX_QUERY_LENGTH];
    char host[64];
    char user[64];
    char password[64];
    char database[64];
    int port = 3306;
    int num_fields;
    int i;

    printf("Enter MySQL server hostname: ");
    scanf("%s", host);

    printf("Enter MySQL server port (default is 3306): ");
    scanf("%d", &port);

    printf("Enter MySQL username: ");
    scanf("%s", user);

    printf("Enter MySQL password: ");
    scanf("%s", password);

    printf("Enter MySQL database name: ");
    scanf("%s", database);

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, host, user, password, database, port, NULL, 0)) {
        printf("Error connecting to MySQL server: %s\n", mysql_error(conn));
        return 1;
    }

    printf("Connected to MySQL server.\n");

    printf("Enter SQL query: ");
    fgets(query, MAX_QUERY_LENGTH, stdin);

    if (mysql_query(conn, query)) {
        printf("Error executing SQL query: %s\n", mysql_error(conn));
        return 1;
    }

    result = mysql_store_result(conn);

    num_fields = mysql_num_fields(result);

    printf("Query results:\n");

    while ((row = mysql_fetch_row(result))!= NULL) {
        for (i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}