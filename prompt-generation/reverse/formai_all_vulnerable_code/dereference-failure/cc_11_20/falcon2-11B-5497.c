//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_RESULTS 1024

void print_results(char **results, int num_results, int num_fields, sqlite3_stmt *stmt);

int main(int argc, char *argv[]) {
    char *database_file = "example.db";
    char query[MAX_QUERY_LENGTH];
    char **results;
    int num_results;
    int num_fields;
    sqlite3 *db;
    sqlite3_stmt *stmt;

    if (argc!= 2) {
        printf("Usage: %s <sqlite3 database file>\n", argv[0]);
        return 1;
    }

    if (sqlite3_open(argv[1], &db) == SQLITE_ERROR) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    if (sqlite3_prepare(db, "SELECT * FROM users", MAX_QUERY_LENGTH, &stmt, NULL) == SQLITE_ERROR) {
        fprintf(stderr, "Can't prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    while (1) {
        if (sqlite3_step(stmt) == SQLITE_DONE) {
            break;
        }

        if (sqlite3_column_type(stmt, 0)!= SQLITE_TEXT) {
            fprintf(stderr, "Invalid column type\n");
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
        }

        if (sqlite3_column_bytes(stmt, 0) > MAX_QUERY_LENGTH) {
            fprintf(stderr, "Query too long\n");
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
        }

        if (sqlite3_column_type(stmt, 1)!= SQLITE_TEXT) {
            fprintf(stderr, "Invalid column type\n");
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
        }

        if (sqlite3_column_bytes(stmt, 1) > MAX_QUERY_LENGTH) {
            fprintf(stderr, "Query too long\n");
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
        }

        if (sqlite3_column_type(stmt, 2)!= SQLITE_TEXT) {
            fprintf(stderr, "Invalid column type\n");
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
        }

        if (sqlite3_column_bytes(stmt, 2) > MAX_QUERY_LENGTH) {
            fprintf(stderr, "Query too long\n");
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
        }

        if (sqlite3_column_type(stmt, 3)!= SQLITE_TEXT) {
            fprintf(stderr, "Invalid column type\n");
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
        }

        if (sqlite3_column_bytes(stmt, 3) > MAX_QUERY_LENGTH) {
            fprintf(stderr, "Query too long\n");
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
        }

        char *user = sqlite3_column_text(stmt, 0);
        char *email = sqlite3_column_text(stmt, 1);
        char *password = sqlite3_column_text(stmt, 2);
        char *name = sqlite3_column_text(stmt, 3);

        printf("%s,%s,%s,%s\n", user, email, password, name);

        results = (char **)malloc(sizeof(char *) * num_fields);
        for (int i = 0; i < num_fields; i++) {
            results[i] = (char *)malloc(MAX_QUERY_LENGTH * sizeof(char));
            strcpy(results[i], sqlite3_column_text(stmt, i));
        }

        num_results = sqlite3_column_count(stmt);
        num_fields = sqlite3_column_count(stmt);

        print_results(results, num_results, num_fields, stmt);

        sqlite3_clear_bindings(stmt);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}

void print_results(char **results, int num_results, int num_fields, sqlite3_stmt *stmt) {
    for (int i = 0; i < num_results; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < num_fields; j++) {
            if (i == 0 && j == 0) {
                printf("%s", results[j]);
            } else if (i == 0 && j!= 0) {
                printf(", %s", results[j]);
            } else if (i!= 0 && j == 0) {
                printf(", %s", results[j]);
            } else if (i!= 0 && j!= 0) {
                printf(", %s, ", results[j]);
            }
        }
        printf("\n");
    }
}