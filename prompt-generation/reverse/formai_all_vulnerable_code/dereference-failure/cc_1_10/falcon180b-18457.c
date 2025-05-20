//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to connect to the database
MYSQL *connect_to_database(char *host, char *user, char *password, char *database) {
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }
    return conn;
}

// Function to execute a query and return the result
MYSQL_RES *execute_query(MYSQL *conn, char *query) {
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        printf("Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }
    return result;
}

// Function to print the result set
void print_result_set(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);
    int num_fields = mysql_num_fields(result);

    printf("+----+------------------+------------------+\n");
    printf("| %4s | %20s | %20s |\n", "ID", "First Name", "Last Name");
    printf("+----+------------------+------------------+\n");

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("| %4d | %20s | %20s |\n", atoi(row[0]), row[1], row[2]);
        }
    }
    printf("+----+------------------+------------------+\n");
}

int main() {
    // Connect to the database
    MYSQL *conn = connect_to_database("localhost", "username", "password", "database_name");

    // Execute a query and print the result set
    char query[100] = "SELECT * FROM customers";
    MYSQL_RES *result = execute_query(conn, query);
    print_result_set(result);

    // Execute another query and print the result set
    strcpy(query, "SELECT * FROM orders");
    result = execute_query(conn, query);
    print_result_set(result);

    // Close the database connection
    mysql_close(conn);
    return 0;
}