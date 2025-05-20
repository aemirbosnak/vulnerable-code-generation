//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_QUERY_LENGTH 256
#define DB_NAME "cryptic_db.sqlite"

void execute_query(sqlite3 *db, const char *query) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, query, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Operation executed successfully\n");
    }
}

void display_callback(void *data, int argc, char **argv, char **azColName) {
    for(int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
}

void fetch_rows(sqlite3 *db, const char *query) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, query, display_callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS Crypto("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "NAME TEXT NOT NULL,"
                      "VALUE REAL NOT NULL);";
    execute_query(db, sql);
}

void insert_data(sqlite3 *db, const char *name, double value) {
    char query[MAX_QUERY_LENGTH];
    snprintf(query, sizeof(query), "INSERT INTO Crypto (NAME, VALUE) VALUES ('%s', %f);", name, value);
    execute_query(db, query);
}

void delete_data(sqlite3 *db, const char *name) {
    char query[MAX_QUERY_LENGTH];
    snprintf(query, sizeof(query), "DELETE FROM Crypto WHERE NAME='%s';", name);
    execute_query(db, query);
}

void update_data(sqlite3 *db, const char *name, double value) {
    char query[MAX_QUERY_LENGTH];
    snprintf(query, sizeof(query), "UPDATE Crypto SET VALUE=%f WHERE NAME='%s';", value, name);
    execute_query(db, query);
}

void select_all(sqlite3 *db) {
    const char *sql = "SELECT * FROM Crypto;";
    fetch_rows(db, sql);
}

void cryptic_interaction(sqlite3 *db) {
    char operation[10], name[50];
    double value;

    while(1) {
        printf("Enter operation (insert, update, delete, select or exit): ");
        scanf("%s", operation);

        if (strcmp(operation, "exit") == 0) {
            break;
        }

        if (strcmp(operation, "insert") == 0) {
            printf("Enter name and value: ");
            scanf("%s %lf", name, &value);
            insert_data(db, name, value);
        } else if (strcmp(operation, "update") == 0) {
            printf("Enter name and new value: ");
            scanf("%s %lf", name, &value);
            update_data(db, name, value);
        } else if (strcmp(operation, "delete") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            delete_data(db, name);
        } else if (strcmp(operation, "select") == 0) {
            select_all(db);
        } else {
            printf("Invalid operation. Try again.\n");
        }
    }
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open(DB_NAME, &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    create_table(db);
    cryptic_interaction(db);

    sqlite3_close(db);
    return 0;
}