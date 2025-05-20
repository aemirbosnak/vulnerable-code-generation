//Falcon-180B DATASET v1.0 Category: Database querying ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024

struct record {
    int id;
    char name[64];
    char address[256];
};

MYSQL *conn;
MYSQL_RES *result;
MYSQL_ROW row;

void connect_to_database() {
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }
}

void disconnect_from_database() {
    mysql_close(conn);
}

int execute_query(const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
        return 1;
    }
    return 0;
}

int fetch_records(struct record *records, int max_records) {
    int count = 0;
    while ((row = mysql_fetch_row(result))!= NULL && count < max_records) {
        memset(records[count].name, 0, sizeof(records[count].name));
        memset(records[count].address, 0, sizeof(records[count].address));
        records[count].id = atoi(row[0]);
        strncpy(records[count].name, row[1], sizeof(records[count].name) - 1);
        strncpy(records[count].address, row[2], sizeof(records[count].address) - 1);
        count++;
    }
    return count;
}

int main() {
    connect_to_database();

    char query[MAX_QUERY_LENGTH];
    snprintf(query, MAX_QUERY_LENGTH, "SELECT * FROM customers WHERE city='%s'", "New York");
    if (execute_query(query)) {
        fprintf(stderr, "Error fetching records\n");
        disconnect_from_database();
        return 1;
    }

    struct record records[100];
    int num_records = fetch_records(records, sizeof(records) / sizeof(records[0]));

    for (int i = 0; i < num_records; i++) {
        printf("ID: %d\nName: %s\nAddress: %s\n\n", records[i].id, records[i].name, records[i].address);
    }

    disconnect_from_database();
    return 0;
}