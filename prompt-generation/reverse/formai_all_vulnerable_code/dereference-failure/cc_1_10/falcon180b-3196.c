//Falcon-180B DATASET v1.0 Category: Database querying ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to connect to the MySQL database
MYSQL *connect_db(char *host, char *user, char *pass, char *db) {
    MYSQL *conn = NULL;
    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Error initializing MySQL connection\n");
        return NULL;
    }
    if (!mysql_real_connect(conn, host, user, pass, db, 0, NULL, 0)) {
        printf("Error connecting to MySQL database: %s\n", mysql_error(conn));
        return NULL;
    }
    return conn;
}

// Function to execute a query and return the result set
MYSQL_RES *query_db(MYSQL *conn, char *query) {
    MYSQL_RES *result = NULL;
    if (mysql_query(conn, query)) {
        printf("Error executing MySQL query: %s\n", mysql_error(conn));
        return NULL;
    }
    result = mysql_store_result(conn);
    return result;
}

// Function to print the result set
void print_result(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    while ((row = mysql_fetch_row(result))!= NULL) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }
}

// Function to close the MySQL connection
void close_db(MYSQL *conn) {
    if (conn!= NULL) {
        mysql_close(conn);
    }
}

int main() {
    char host[] = "localhost";
    char user[] = "root";
    char pass[] = "";
    char db[] = "test_db";

    MYSQL *conn = connect_db(host, user, pass, db);
    if (conn == NULL) {
        return 1;
    }

    char query[] = "SELECT * FROM users";
    MYSQL_RES *result = query_db(conn, query);
    if (result == NULL) {
        close_db(conn);
        return 1;
    }

    print_result(result);
    mysql_free_result(result);

    close_db(conn);

    return 0;
}