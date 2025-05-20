//FormAI DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("data.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char *sql = "CREATE TABLE Scientists(Name TEXT, Age INT, Field TEXT);"
                "INSERT INTO Scientists VALUES('Marie Curie', 66, 'Physics');"
                "INSERT INTO Scientists VALUES('Albert Einstein', 76, 'Physics');"
                "INSERT INTO Scientists VALUES('Isaac Newton', 84, 'Mathematics');"
                "INSERT INTO Scientists VALUES('Stephen Hawking', 76, 'Physics');";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    sqlite3_stmt *stmt;
    char q[100];
    printf("Enter the name of the Scientist to Search." );
    scanf("%s", q);
    char *query = "SELECT * FROM Scientists WHERE Name = ?";

    if (sqlite3_prepare_v2(db, query, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, q, -1, SQLITE_STATIC);
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    int step = sqlite3_step(stmt);

    if (step == SQLITE_ROW) {
        printf("%s is a %d year old scientist who worked in the field of %s.\n",
                sqlite3_column_text(stmt, 0), sqlite3_column_int(stmt, 1), sqlite3_column_text(stmt, 2));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}