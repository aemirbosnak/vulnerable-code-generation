//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_STR_LEN 100

static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s : %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void execute_sql(sqlite3 *db, const char *sql) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Operation executed successfully\n");
    }
}

void create_tables(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS authors (id INTEGER PRIMARY KEY, name TEXT);"
                      "CREATE TABLE IF NOT EXISTS books (id INTEGER PRIMARY KEY, title TEXT, author_id INTEGER, "
                      "FOREIGN KEY(author_id) REFERENCES authors(id));";
    execute_sql(db, sql);
}

void add_author(sqlite3 *db, const char *name) {
    char sql[MAX_STR_LEN];
    snprintf(sql, sizeof(sql), "INSERT INTO authors (name) VALUES ('%s');", name);
    execute_sql(db, sql);
}

void add_book(sqlite3 *db, const char *title, int author_id) {
    char sql[MAX_STR_LEN];
    snprintf(sql, sizeof(sql), "INSERT INTO books (title, author_id) VALUES ('%s', %d);", title, author_id);
    execute_sql(db, sql);
}

void fetch_books(sqlite3 *db) {
    const char *sql = "SELECT books.id, books.title, authors.name FROM books "
                      "JOIN authors ON books.author_id = authors.id;";
    execute_sql(db, sql);
}

void display_menu() {
    printf("Library Database Menu:\n");
    printf("1. Add Author\n");
    printf("2. Add Book\n");
    printf("3. View Books\n");
    printf("4. Exit\n");
}

int main(int argc, char **argv) {
    sqlite3 *db;
    int rc = sqlite3_open("library.db", &db);
    
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    
    create_tables(db);

    int choice;
    char name[MAX_STR_LEN];
    char title[MAX_STR_LEN];
    int author_id;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter author name: ");
                scanf("%s", name);
                add_author(db, name);
                break;
            case 2:
                printf("Enter book title: ");
                scanf("%s", title);
                printf("Enter author ID: ");
                scanf("%d", &author_id);
                add_book(db, title, author_id);
                break;
            case 3:
                fetch_books(db);
                break;
            case 4:
                sqlite3_close(db);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    sqlite3_close(db);
    return 0;
}