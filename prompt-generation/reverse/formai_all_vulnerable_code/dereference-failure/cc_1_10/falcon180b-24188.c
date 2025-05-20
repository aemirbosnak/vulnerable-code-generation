//Falcon-180B DATASET v1.0 Category: Database querying ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to connect to the database
MYSQL *connect_to_database(const char *host, const char *user, const char *password, const char *database) {
    MYSQL *conn = NULL;
    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Error: Could not initialize MySQL\n");
        exit(1);
    }
    if (!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)) {
        printf("Error: Could not connect to the database: %s\n", mysql_error(conn));
        exit(1);
    }
    return conn;
}

// Function to execute a query and return the result set
MYSQL_RES *execute_query(MYSQL *conn, const char *query) {
    MYSQL_RES *result = NULL;
    if (mysql_query(conn, query)) {
        printf("Error: Could not execute query: %s\n", mysql_error(conn));
        exit(1);
    }
    result = mysql_store_result(conn);
    if (result == NULL) {
        printf("Error: No result set returned\n");
        exit(1);
    }
    return result;
}

// Function to print the result set
void print_result_set(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    while ((row = mysql_fetch_row(result))!= NULL) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
}

// Function to close the database connection and free the resources
void close_database(MYSQL *conn) {
    mysql_close(conn);
    mysql_library_end();
}

int main() {
    MYSQL *conn = connect_to_database("localhost", "username", "password", "database");
    MYSQL_RES *result = execute_query(conn, "SELECT * FROM table");
    print_result_set(result);
    close_database(conn);
    return 0;
}