//Falcon-180B DATASET v1.0 Category: Database querying ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function prototypes
int connect_to_database(MYSQL **conn);
int create_table(MYSQL *conn);
int insert_data(MYSQL *conn);
int query_data(MYSQL *conn);

int main() {
    MYSQL *conn = NULL;

    if (connect_to_database(&conn)) {
        printf("Error connecting to database.\n");
        return 1;
    }

    if (create_table(conn)) {
        printf("Error creating table.\n");
        return 1;
    }

    if (insert_data(conn)) {
        printf("Error inserting data.\n");
        return 1;
    }

    if (query_data(conn)) {
        printf("Error querying data.\n");
        return 1;
    }

    mysql_close(conn);
    return 0;
}

int connect_to_database(MYSQL **conn) {
    MYSQL *mysql = mysql_init(NULL);

    if (mysql == NULL) {
        printf("Error initializing MySQL.\n");
        return 1;
    }

    *conn = mysql;

    if (!mysql_real_connect(mysql, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(mysql));
        return 1;
    }

    return 0;
}

int create_table(MYSQL *conn) {
    char query[100];
    sprintf(query, "CREATE TABLE IF NOT EXISTS users (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(50), age INT)");

    if (mysql_query(conn, query)) {
        printf("Error creating table: %s\n", mysql_error(conn));
        return 1;
    }

    return 0;
}

int insert_data(MYSQL *conn) {
    char query[100];
    sprintf(query, "INSERT INTO users (name, age) VALUES ('John Doe', 30)");

    if (mysql_query(conn, query)) {
        printf("Error inserting data: %s\n", mysql_error(conn));
        return 1;
    }

    return 0;
}

int query_data(MYSQL *conn) {
    char query[100];
    sprintf(query, "SELECT * FROM users");

    if (mysql_query(conn, query)) {
        printf("Error querying data: %s\n", mysql_error(conn));
        return 1;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        printf("ID: %s, Name: %s, Age: %s\n", row[0], row[1], row[2]);
    }

    mysql_free_result(result);

    return 0;
}