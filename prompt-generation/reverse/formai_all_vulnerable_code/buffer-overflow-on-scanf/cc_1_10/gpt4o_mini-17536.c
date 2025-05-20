//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define DB_NAME "example.db"

void execute_sql(const char *sql);
void create_table();
void insert_data(int id, const char *name);
void query_data();
void delete_data(int id);
void display_menu();
void handle_menu_option(int option);

int main() {
    int option;

    // Create or open a database
    execute_sql("PRAGMA foreign_keys = ON;");
    create_table();

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        handle_menu_option(option);
    } while (option != 5);

    return 0;
}

void execute_sql(const char *sql) {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open(DB_NAME, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
}

void create_table() {
    const char *sql = "CREATE TABLE IF NOT EXISTS Person("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Name TEXT NOT NULL);";
    execute_sql(sql);
}

void insert_data(int id, const char *name) {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open(DB_NAME, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Person (ID, Name) VALUES (%d, '%s');", id, name);

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQLite Error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Record added successfully!\n");
    }

    sqlite3_close(db);
}

void query_data() {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM Person;";
    
    int rc = sqlite3_open(DB_NAME, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("ID\tName\n");
    printf("------------------\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        printf("%d\t%s\n", id, name);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void delete_data(int id) {
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open(DB_NAME, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char sql[256];
    snprintf(sql, sizeof(sql), "DELETE FROM Person WHERE ID = %d;", id);

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQLite Error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Record deleted successfully!\n");
    }

    sqlite3_close(db);
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Insert Data\n");
    printf("2. Query Data\n");
    printf("3. Delete Data\n");
    printf("4. Exit\n");
}

void handle_menu_option(int option) {
    switch(option) {
        case 1: {
            int id;
            char name[100];
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter Name: ");
            scanf("%s", name);
            insert_data(id, name);
            break;
        }
        case 2:
            query_data();
            break;
        case 3: {
            int id;
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            delete_data(id);
            break;
        }
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option, please try again!\n");
            break;
    }
}