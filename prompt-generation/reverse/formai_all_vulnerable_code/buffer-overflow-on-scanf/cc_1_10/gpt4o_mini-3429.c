//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define MAX_QUERY_LENGTH 256

void print_error(const char *msg, sqlite3 *db) {
    fprintf(stderr, "%s: %s\n", msg, sqlite3_errmsg(db));
}

void query_database(sqlite3 *db, const char *sql) {
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        print_error("Failed to prepare statement", db);
        return;
    }

    printf("Query results:\n");
    
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Assuming we are selecting two columns: id and name
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        printf("ID: %d, Name: %s\n", id, name);
    }

    if (rc != SQLITE_DONE) {
        print_error("Failed to execute statement", db);
    }

    sqlite3_finalize(stmt);
}

void insert_sample_data(sqlite3 *db) {
    const char *insert_sql = "INSERT INTO users (name) VALUES (?);";
    sqlite3_stmt *stmt;

    for (int i = 1; i <= 5; i++) {
        char name[20];
        sprintf(name, "User%d", i);

        if (sqlite3_prepare_v2(db, insert_sql, -1, &stmt, NULL) != SQLITE_OK) {
            print_error("Could not prepare insert statement", db);
            return;
        }

        sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
        
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            print_error("Failed to insert data", db);
        }

        sqlite3_finalize(stmt);
    }
}

void create_table(sqlite3 *db) {
    const char *create_table_sql = 
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT NOT NULL);";
    
    char *err_msg;
    int rc = sqlite3_exec(db, create_table_sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Table created successfully.\n");
    }
}

void user_menu(sqlite3 *db) {
    char query[MAX_QUERY_LENGTH];
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Query all users\n");
        printf("2. Quit\n");
        printf("Select an option (1-2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sprintf(query, "SELECT * FROM users;");
                query_database(db, query);
                break;
            case 2:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 2);
}

int main() {
    sqlite3 *db;

    int rc = sqlite3_open("example.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    }

    create_table(db);
    insert_sample_data(db);
    user_menu(db);

    sqlite3_close(db);
    return EXIT_SUCCESS;
}