//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <mysql/mysql.h>

#define MAX_THREADS 10
#define MAX_QUERY_LENGTH 1000
#define DATABASE "test"
#define USER "root"
#define PASSWORD "password"
#define HOST "localhost"

typedef struct {
    char query[MAX_QUERY_LENGTH];
    int result;
} QueryData;

void *execute_query(void *param) {
    QueryData *query_data = (QueryData *) param;
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        return NULL;
    }
    if (mysql_query(conn, query_data->query)) {
        printf("Error executing query: %s\n", mysql_error(conn));
        return NULL;
    }
    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        printf("%s\n", row[0]);
    }
    mysql_free_result(result);
    mysql_close(conn);
    query_data->result = 1;
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    QueryData query_data[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        sprintf(query_data[i].query, "SELECT * FROM test_table WHERE id=%d", i);
        pthread_create(&threads[i], NULL, execute_query, &query_data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}