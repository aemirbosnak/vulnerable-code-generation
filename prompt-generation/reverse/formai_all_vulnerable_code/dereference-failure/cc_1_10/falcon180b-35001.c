//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to connect to the MySQL database
MYSQL *connect_to_database(const char *host, const char *user, const char *password, const char *database) {
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }
    return conn;
}

// Function to execute a query and return the result
MYSQL_RES *execute_query(MYSQL *conn, const char *query) {
    MYSQL_RES *result;
    if (mysql_query(conn, query)) {
        printf("Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }
    result = mysql_store_result(conn);
    return result;
}

// Function to print the results of a query
void print_results(MYSQL_RES *result) {
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

// Function to close the database connection
void close_database(MYSQL *conn) {
    mysql_close(conn);
}

int main() {
    // Connect to the database
    MYSQL *conn = connect_to_database("localhost", "username", "password", "database_name");

    // Execute a query and print the results
    MYSQL_RES *result = execute_query(conn, "SELECT * FROM players");
    print_results(result);

    // Close the database connection
    close_database(conn);
    return 0;
}