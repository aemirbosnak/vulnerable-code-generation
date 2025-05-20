//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define DATABASE "romeo_juliet_db"
#define USER "romeo"
#define PASS "juliet"

// Function to connect to the database
MYSQL *connect_to_db() {
    MYSQL *conn = NULL;
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, DATABASE, USER, PASS, NULL, 0, NULL, 0)) {
        printf("Error connecting to the database: %s\n", mysql_error(conn));
        exit(1);
    }

    return conn;
}

// Function to execute a query and print the result
void execute_query(MYSQL *conn, char *query) {
    if (mysql_query(conn, query)) {
        printf("Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))!= NULL) {
        printf("%s\n", row[0]);
    }

    mysql_free_result(result);
}

// Function to close the database connection
void close_connection(MYSQL *conn) {
    mysql_close(conn);
}

int main() {
    MYSQL *conn = connect_to_db();

    // Insert data into the database
    char insert_query1[] = "INSERT INTO characters (name, role) VALUES ('Romeo', 'Lead Male')";
    char insert_query2[] = "INSERT INTO characters (name, role) VALUES ('Juliet', 'Lead Female')";
    char insert_query3[] = "INSERT INTO characters (name, role) VALUES ('Tybalt', 'Supporting Male')";

    execute_query(conn, insert_query1);
    execute_query(conn, insert_query2);
    execute_query(conn, insert_query3);

    // Retrieve data from the database
    char select_query1[] = "SELECT name FROM characters WHERE role = 'Lead Male'";
    char select_query2[] = "SELECT name FROM characters WHERE role = 'Lead Female'";
    char select_query3[] = "SELECT name FROM characters WHERE role = 'Supporting Male'";

    execute_query(conn, select_query1);
    execute_query(conn, select_query2);
    execute_query(conn, select_query3);

    close_connection(conn);

    return 0;
}