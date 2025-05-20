//Falcon-180B DATASET v1.0 Category: Database querying ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_QUERY_LENGTH 1024

static char *query = NULL;
static int query_length = 0;

static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i]? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void execute_query(sqlite3 *db) {
    char *errMsg = NULL;
    int rc = sqlite3_exec(db, query, callback, NULL, &errMsg);

    if (rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Query executed successfully\n");
    }
}

void execute_update(sqlite3 *db) {
    char *errMsg = NULL;
    int rc = sqlite3_exec(db, query, NULL, NULL, &errMsg);

    if (rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Update executed successfully\n");
    }
}

int main(int argc, char **argv) {
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    query = malloc(MAX_QUERY_LENGTH);
    if (query == NULL) {
        fprintf(stderr, "Out of memory\n");
        sqlite3_close(db);
        return 1;
    }

    query_length = 0;

    printf("Enter SQL query: ");
    fgets(query, MAX_QUERY_LENGTH, stdin);

    execute_query(db);

    sqlite3_close(db);

    return 0;
}