//FormAI DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_BUFFER_SIZE 1000

// database configuration
const char *db_server = "localhost";
const char *username = "root";
const char *password = "password";
const char *database = "mydb";

MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;

// function to query the database
int query_database(char *query) {
    // establish connection
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, db_server, username, password, database, 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        return 1;
    }

    // execute query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error querying database: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // get result set
    res = mysql_store_result(conn);

    // print results
    int num_fields = mysql_num_fields(res);
    while ((row = mysql_fetch_row(res))) {
        for(int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    // close connection
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    int player_count;

    // get player count from user
    printf("How many players would you like to search for? ");
    scanf("%d", &player_count);

    // query database for each player
    for (int i = 0; i < player_count; i++) {
        char player_name[50];
        printf("Enter player %d name: ", i+1);
        scanf("%s", player_name);
        sprintf(buffer, "SELECT * FROM players WHERE name='%s'", player_name);
        printf("\nResults for %s:\n", player_name);
        query_database(buffer);
        printf("\n");
    }

    return 0;
}