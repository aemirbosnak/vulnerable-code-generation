//Falcon-180B DATASET v1.0 Category: Database querying ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to connect to the database
MYSQL *connect_to_database() {
    MYSQL *conn = NULL;
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    return conn;
}

// Function to execute a query and print the results
void execute_query(MYSQL *conn, char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < mysql_num_fields(result); i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

// Main function
int main() {
    MYSQL *conn = connect_to_database();

    // Example queries
    char *query1 = "SELECT * FROM users";
    char *query2 = "INSERT INTO users (name, email) VALUES ('John Doe', 'johndoe@example.com')";
    char *query3 = "UPDATE users SET email = 'newemail@example.com' WHERE id = 1";
    char *query4 = "DELETE FROM users WHERE id = 1";

    execute_query(conn, query1);
    execute_query(conn, query2);
    execute_query(conn, query3);
    execute_query(conn, query4);

    mysql_close(conn);

    return 0;
}