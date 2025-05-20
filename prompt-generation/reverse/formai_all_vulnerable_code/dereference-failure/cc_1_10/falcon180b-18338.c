//Falcon-180B DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_ROWS 100

typedef struct {
    char *query;
    int query_length;
    char *database;
    char *username;
    char *password;
    char *hostname;
    int port;
    MYSQL *connection;
    MYSQL_RES *result;
    MYSQL_ROW row;
} Database;

int main() {
    Database db;
    db.query = (char *)malloc(MAX_QUERY_LENGTH);
    db.query_length = 0;
    db.database = (char *)malloc(MAX_QUERY_LENGTH);
    db.username = (char *)malloc(MAX_QUERY_LENGTH);
    db.password = (char *)malloc(MAX_QUERY_LENGTH);
    db.hostname = (char *)malloc(MAX_QUERY_LENGTH);
    db.port = 0;
    db.connection = NULL;
    db.result = NULL;
    db.row = NULL;

    // Set default database connection values
    strcpy(db.database, "localhost");
    strcpy(db.username, "root");
    strcpy(db.password, "");

    // Connect to the database
    if (!mysql_init(&db.connection)) {
        printf("Error initializing MySQL connection\n");
        exit(1);
    }
    if (!mysql_real_connect(db.connection, db.hostname, db.username, db.password, db.database, db.port, NULL, 0)) {
        printf("Error connecting to MySQL database: %s\n", mysql_error(db.connection));
        exit(1);
    }

    // Execute a query and display the results
    sprintf(db.query, "SELECT * FROM customers LIMIT %d", MAX_ROWS);
    if (mysql_query(db.connection, db.query)) {
        printf("Error executing query: %s\n", mysql_error(db.connection));
        exit(1);
    }
    db.result = mysql_store_result(db.connection);
    printf("Customer ID\tCustomer Name\tCustomer Email\n");
    while ((db.row = mysql_fetch_row(db.result))!= NULL) {
        printf("%s\t%s\t%s\n", db.row[0], db.row[1], db.row[2]);
    }
    mysql_free_result(db.result);
    mysql_close(db.connection);

    free(db.query);
    free(db.database);
    free(db.username);
    free(db.password);
    free(db.hostname);

    return 0;
}