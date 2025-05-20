//Falcon-180B DATASET v1.0 Category: Database querying ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024

// Function to connect to the MySQL database
MYSQL *connect_to_database(char *host, char *user, char *password, char *database) {
    MYSQL *conn = NULL;
    if ((conn = mysql_init(NULL))) {
        if (!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)) {
            fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
            mysql_close(conn);
            conn = NULL;
        }
    }
    return conn;
}

// Function to execute a query and return the result set
MYSQL_RES *execute_query(MYSQL *conn, char *query) {
    MYSQL_RES *result = NULL;
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
    } else {
        result = mysql_store_result(conn);
    }
    return result;
}

// Function to fetch a row from the result set
MYSQL_ROW fetch_row(MYSQL_RES *result) {
    return mysql_fetch_row(result);
}

// Function to close the database connection and result set
void close_connection(MYSQL *conn, MYSQL_RES *result) {
    if (result) {
        mysql_free_result(result);
    }
    if (conn) {
        mysql_close(conn);
    }
}

// Function to print the contents of a row
void print_row(MYSQL_ROW row) {
    int i = 0;
    while (row[i]!= NULL) {
        printf("%s ", row[i]);
        i++;
    }
    printf("\n");
}

// Example usage of the above functions
int main() {
    char query[MAX_QUERY_LENGTH];
    char host[] = "localhost";
    char user[] = "username";
    char password[] = "password";
    char database[] = "database_name";

    MYSQL *conn = connect_to_database(host, user, password, database);
    if (conn) {
        // Example SELECT query
        sprintf(query, "SELECT * FROM my_table");
        MYSQL_RES *result = execute_query(conn, query);
        if (result) {
            MYSQL_ROW row = fetch_row(result);
            while (row!= NULL) {
                print_row(row);
                row = fetch_row(result);
            }
        }
        close_connection(conn, result);
    }
    return 0;
}