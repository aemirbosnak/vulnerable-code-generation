//Falcon-180B DATASET v1.0 Category: Database querying ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to connect to MySQL server
MYSQL *connect_to_server(char *server, char *user, char *password, char *database) {
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }
    return conn;
}

// Function to execute SQL query and return result set
MYSQL_RES *execute_query(MYSQL *conn, char *query) {
    MYSQL_RES *result;
    if (mysql_query(conn, query)) {
        printf("Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }
    result = mysql_store_result(conn);
    return result;
}

// Function to display result set
void display_result(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields;
    num_fields = mysql_num_fields(result);
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
}

// Example usage
int main() {
    MYSQL *conn;
    MYSQL_RES *result;
    char server[] = "localhost";
    char user[] = "username";
    char password[] = "password";
    char database[] = "database_name";

    conn = connect_to_server(server, user, password, database);

    // Example query to retrieve all records from a table
    char query[] = "SELECT * FROM employees";
    result = execute_query(conn, query);
    display_result(result);

    mysql_close(conn);
    return 0;
}