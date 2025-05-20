//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LEN 1024
#define MAX_RESULT_LEN 1024

// Struct to hold query results
typedef struct {
    char *query;
    MYSQL_RES *result;
    MYSQL_ROW row;
} QueryResult;

// Function to execute a query and store the result
QueryResult execute_query(MYSQL *conn, const char *query) {
    QueryResult result = {0};
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }
    result.result = mysql_store_result(conn);
    result.row = mysql_fetch_row(result.result);
    return result;
}

// Function to print query results in a formatted manner
void print_results(QueryResult result) {
    int num_fields = mysql_num_fields(result.result);
    while (result.row!= NULL) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", result.row[i]? result.row[i] : "NULL");
        }
        printf("\n");
        result.row = mysql_fetch_row(result.result);
    }
}

int main() {
    // Connect to database
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    // Example queries
    QueryResult select_result = execute_query(conn, "SELECT * FROM users");
    print_results(select_result);

    QueryResult insert_result = execute_query(conn, "INSERT INTO users (name, email) VALUES ('John Doe', 'john@example.com')");
    printf("Inserted %d rows\n", mysql_affected_rows(conn));

    QueryResult update_result = execute_query(conn, "UPDATE users SET email = 'johndoe@example.com' WHERE id = 1");
    printf("Updated %d rows\n", mysql_affected_rows(conn));

    QueryResult delete_result = execute_query(conn, "DELETE FROM users WHERE id = 1");
    printf("Deleted %d rows\n", mysql_affected_rows(conn));

    // Close connection
    mysql_close(conn);

    return 0;
}