//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_ROWS 100
#define MAX_COLUMNS 10
#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 64
#define MAX_DATABASE_LENGTH 64
#define MAX_TABLE_LENGTH 64
#define MAX_COLUMN_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char database[MAX_DATABASE_LENGTH];
} User;

typedef struct {
    char table[MAX_TABLE_LENGTH];
    char column[MAX_COLUMN_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Query;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s host port username\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, host, username, NULL, NULL, port, NULL, 0)) {
        printf("Error: Unable to connect to database: %s\n", mysql_error(conn));
        return 1;
    }

    printf("Connected to database successfully\n");

    User user;
    strcpy(user.username, username);
    strcpy(user.database, "test");

    if (mysql_select_db(conn, user.database)) {
        printf("Error: Unable to select database: %s\n", mysql_error(conn));
        return 1;
    }

    printf("Selected database successfully\n");

    Query query;
    strcpy(query.table, "users");
    strcpy(query.column, "name");
    strcpy(query.value, "John Doe");

    char query_string[MAX_QUERY_LENGTH];
    snprintf(query_string, MAX_QUERY_LENGTH, "INSERT INTO %s (%s) VALUES ('%s')", query.table, query.column, query.value);

    if (mysql_query(conn, query_string)) {
        printf("Error: Unable to execute query: %s\n", mysql_error(conn));
        return 1;
    }

    printf("Executed query successfully\n");

    mysql_close(conn);
    return 0;
}