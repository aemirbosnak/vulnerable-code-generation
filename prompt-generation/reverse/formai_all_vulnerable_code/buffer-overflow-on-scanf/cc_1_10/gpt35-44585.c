//FormAI DATASET v1.0 Category: Database querying ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "testdb"

int main() {

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    char query[50];
    printf("Enter name to search in the database: ");
    scanf("%s", query);

    char sql_query[100] = "SELECT id, name, age, address FROM People WHERE name LIKE '%";
    strcat(sql_query, query);
    strcat(sql_query, "%'");

    if (mysql_query(conn, sql_query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    
    res = mysql_store_result(conn);

    if (res == NULL) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    printf("Search results:\n");
    printf("+----+-----------+-----+---------------+\n");
    printf("| ID |   Name    | Age |    Address    |\n");
    printf("+----+-----------+-----+---------------+\n");

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("| %2d | %-9s | %2d  | %-13s |\n",
                atoi(row[0]), row[1], atoi(row[2]), row[3]);
    }

    printf("+----+-----------+-----+---------------+\n");

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}