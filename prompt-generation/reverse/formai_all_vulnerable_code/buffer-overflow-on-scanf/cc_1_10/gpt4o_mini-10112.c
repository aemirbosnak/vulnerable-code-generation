//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DB_NAME "books.db"

void create_table(sqlite3 *db);
void insert_book(sqlite3 *db, const char *title, const char *author, int year);
void query_books(sqlite3 *db);
void execute_sql(sqlite3 *db, const char *sql);
int callback(void *data, int argc, char **argv, char **azColName);

int main() {
    sqlite3 *db;
    char *err_msg = 0;

    if (sqlite3_open(DB_NAME, &db) != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    create_table(db);

    int choice;
    while (1) {
        printf("\nBook Database Menu:\n");
        printf("1. Add a book\n");
        printf("2. List all books\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clearing input buffer

        if (choice == 1) {
            char title[100];
            char author[100];
            int year;

            printf("Enter book title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // Remove newline

            printf("Enter author name: ");
            fgets(author, sizeof(author), stdin);
            author[strcspn(author, "\n")] = 0; // Remove newline

            printf("Enter publication year: ");
            scanf("%d", &year);
            getchar(); // Clearing input buffer

            insert_book(db, title, author, year);
        } else if (choice == 2) {
            query_books(db);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    sqlite3_close(db);
    return 0;
}

void create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS Books("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Title TEXT NOT NULL,"
                      "Author TEXT NOT NULL,"
                      "Year INTEGER NOT NULL);";
    execute_sql(db, sql);
}

void insert_book(sqlite3 *db, const char *title, const char *author, int year) {
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Books (Title, Author, Year) VALUES ('%s', '%s', %d);", title, author, year);
    execute_sql(db, sql);
}

void query_books(sqlite3 *db) {
    const char *sql = "SELECT * FROM Books;";
    char *err_msg = 0;

    printf("\nList of Books:\n");

    if (sqlite3_exec(db, sql, callback, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void execute_sql(sqlite3 *db, const char *sql) {
    char *err_msg = 0;

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Operation done successfully.\n");
    }
}