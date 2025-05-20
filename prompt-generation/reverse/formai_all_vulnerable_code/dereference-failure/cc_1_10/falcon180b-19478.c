//Falcon-180B DATASET v1.0 Category: Database querying ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} record_t;

static int callback(void *data, int argc, char **argv, char **azColName) {
    record_t *record = (record_t *) data;
    int i;

    for (i = 0; i < argc; i++) {
        if (strcmp(azColName[i], "name") == 0) {
            strcpy(record->name, argv[i]? argv[i] : "");
        } else if (strcmp(azColName[i], "value") == 0) {
            strcpy(record->value, argv[i]? argv[i] : "");
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    sqlite3 *db;
    char *sql;
    char *errMsg = NULL;
    int rc;
    record_t record;

    if (argc!= 3) {
        printf("Usage: %s <database> <table>\n", argv[0]);
        return 1;
    }

    rc = sqlite3_open(argv[1], &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sql = malloc(strlen("SELECT * FROM ") + strlen(argv[2]) + 2);
    sprintf(sql, "SELECT * FROM %s", argv[2]);

    rc = sqlite3_exec(db, sql, callback, &record, &errMsg);
    if (rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Name: %s\nValue: %s\n", record.name, record.value);
    }

    sqlite3_close(db);
    free(sql);

    return 0;
}