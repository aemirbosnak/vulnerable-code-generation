//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100

void check_sqlite_error(int rc, sqlite3* db) {
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }
}

void create_table(sqlite3* db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS books ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "title TEXT NOT NULL, "
                      "author TEXT NOT NULL);";
    char *error_message = 0;

    int rc = sqlite3_exec(db, sql, 0, 0, &error_message);
    check_sqlite_error(rc, db);
}

void add_book(sqlite3* db, const char* title, const char* author) {
    char sql[256];
    sprintf(sql, "INSERT INTO books (title, author) VALUES ('%s', '%s');", title, author);
    
    char *error_message = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &error_message);
    
    check_sqlite_error(rc, db);
    printf("Book added: %s by %s\n", title, author);
}

void search_book(sqlite3* db, const char* title) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT title, author FROM books WHERE title = ?;";
    
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    check_sqlite_error(rc, db);
    
    sqlite3_bind_text(stmt, 1, title, -1, SQLITE_STATIC);
    
    if ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const char *book_title = (const char *)sqlite3_column_text(stmt, 0);
        const char *book_author = (const char *)sqlite3_column_text(stmt, 1);
        printf("Found: %s by %s\n", book_title, book_author);
    } else {
        printf("No book found with title: %s\n", title);
    }
    
    sqlite3_finalize(stmt);
}

void display_books(sqlite3* db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT title, author FROM books;";
    
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    check_sqlite_error(rc, db);
    
    printf("Books in the database:\n");
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const char *title = (const char *)sqlite3_column_text(stmt, 0);
        const char *author = (const char *)sqlite3_column_text(stmt, 1);
        printf(" - %s by %s\n", title, author);
    }
    
    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("books.db", &db);
    check_sqlite_error(rc, db);
    
    create_table(db);
    
    int choice;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];

    do {
        printf("\nMenu:\n");
        printf("1. Add a Book\n");
        printf("2. Search a Book\n");
        printf("3. Display All Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        getchar(); // consume newline
        
        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                strtok(title, "\n"); // Remove newline
                
                printf("Enter author name: ");
                fgets(author, MAX_AUTHOR_LENGTH, stdin);
                strtok(author, "\n"); // Remove newline
                
                add_book(db, title, author);
                break;
            case 2:
                printf("Enter book title to search: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                strtok(title, "\n"); // Remove newline
                
                search_book(db, title);
                break;
            case 3:
                display_books(db);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 4);
    
    sqlite3_close(db);
    return 0;
}