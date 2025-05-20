//Falcon-180B DATASET v1.0 Category: Database querying ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName) {
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

    char *sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
    char *errMsg = 0;

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    sqlite3_stmt *stmt;
    sql = "INSERT INTO users (name, age) VALUES ('John', 30);";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    rc = sqlite3_step(stmt);

    if (rc!= SQLITE_DONE) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    sqlite3_finalize(stmt);

    sql = "SELECT * FROM users;";
    stmt = NULL;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc!= SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    rc = sqlite3_step(stmt);

    while (rc == SQLITE_ROW) {
        callback(NULL, sqlite3_column_count(stmt), sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1));
        rc = sqlite3_step(stmt);
    }

    if (rc!= SQLITE_DONE) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}