//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DB_NAME "library.db"

void create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS books ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "title TEXT NOT NULL,"
                      "author TEXT NOT NULL,"
                      "year INTEGER NOT NULL);";

    char *err_msg = 0;
    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Table 'books' created successfully.\n");
    }
}

void insert_book(sqlite3 *db, const char *title, const char *author, int year) {
    char sql[256];

    snprintf(sql, sizeof(sql), "INSERT INTO books (title, author, year) VALUES ('%s', '%s', %d);", title, author, year);

    char *err_msg = 0;
    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Book '%s' by '%s' added successfully.\n", title, author);
    }
}

void display_books(sqlite3 *db) {
    const char *sql = "SELECT * FROM books;";
    
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute query: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("\nList of Books:\n");
    printf("ID\tTitle\t\tAuthor\tYear\n");
    printf("--------------------------------------------\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *title = (const char *)sqlite3_column_text(stmt, 1);
        const char *author = (const char *)sqlite3_column_text(stmt, 2);
        int year = sqlite3_column_int(stmt, 3);
        printf("%d\t%s\t%s\t%d\n", id, title, author, year);
    }

    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;

    // Open the database
    if (sqlite3_open(DB_NAME, &db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    
    create_table(db);

    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Insert Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char title[100], author[100];
                int year;
                printf("Enter book title: ");
                getchar(); // Clears the newline character from input buffer
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove trailing newline

                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // Remove trailing newline

                printf("Enter publication year: ");
                scanf("%d", &year);

                insert_book(db, title, author, year);
                break;
            }
            case 2:
                display_books(db);
                break;
            case 3:
                printf("Exiting the program...\n");
                sqlite3_close(db);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    sqlite3_close(db);
    return 0;
}