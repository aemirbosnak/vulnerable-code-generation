//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: dynamic
// Dynamic Database Querying Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main() {
    // Initialize MySQL connection
    MYSQL* conn;
    conn = mysql_init(NULL);
    if (!conn) {
        fprintf(stderr, "Error: mysql_init failed\n");
        exit(1);
    }

    if (mysql_real_connect(conn, "localhost", "root", "password", "database", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Error: mysql_real_connect failed\n");
        mysql_close(conn);
        exit(1);
    }

    // Set up database query
    char* query = "SELECT * FROM users WHERE name = 'John' AND age > 25";
    MYSQL_RES* res;
    MYSQL_ROW row;

    // Execute query
    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "Error: mysql_query failed\n");
        mysql_close(conn);
        exit(1);
    }

    // Fetch results
    res = mysql_store_result(conn);
    if (!res) {
        fprintf(stderr, "Error: mysql_store_result failed\n");
        mysql_close(conn);
        exit(1);
    }

    // Print results
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%s %s\n", row[0], row[1]);
    }

    // Clean up
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}