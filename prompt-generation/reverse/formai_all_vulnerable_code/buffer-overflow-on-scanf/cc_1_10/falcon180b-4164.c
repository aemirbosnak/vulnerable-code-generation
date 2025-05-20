//Falcon-180B DATASET v1.0 Category: Database querying ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_QUERY_LENGTH 1000
#define MAX_COLUMN_NAME_LENGTH 100
#define MAX_COLUMN_VALUE_LENGTH 1000
#define MAX_ROWS 100
#define MAX_TABLE_NAME_LENGTH 100

typedef struct {
    char *name;
    int length;
} Column;

typedef struct {
    char *name;
    int length;
} Table;

int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i]? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char sql[MAX_QUERY_LENGTH];
    sprintf(sql, "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);");
    rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);

    if (rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Table created successfully\n");
    }

    sprintf(sql, "INSERT INTO users (name, age) VALUES ('John', 30);");
    rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);

    if (rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Data inserted successfully\n");
    }

    char *query;
    printf("Enter SQL query: ");
    scanf("%s", query);

    rc = sqlite3_exec(db, query, callback, NULL, &zErrMsg);

    if (rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        printf("Query executed successfully\n");
    }

    sqlite3_close(db);

    return 0;
}