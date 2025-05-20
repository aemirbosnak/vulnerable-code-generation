//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void displayBooks(sqlite3 *db, const char *query) {
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("\nBooks satisfying the criteria:\n");
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const unsigned char *title = sqlite3_column_text(stmt, 0);
        const unsigned char *author = sqlite3_column_text(stmt, 1);
        const unsigned char *genre = sqlite3_column_text(stmt, 2);
        printf("Title: %s, Author: %s, Genre: %s\n", title, author, genre);
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void createTable(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS books("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "title TEXT NOT NULL, "
                      "author TEXT NOT NULL, "
                      "genre TEXT NOT NULL);";

    char *errMsg;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void insertBook(sqlite3 *db, const char *title, const char *author, const char *genre) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO books (title, author, genre) VALUES (?, ?, ?);";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare insert statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, title, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, author, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, genre, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Insert failed: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("books.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    createTable(db);

    insertBook(db, "The Alchemist", "Paulo Coelho", "Fiction");
    insertBook(db, "1984", "George Orwell", "Dystopian");
    insertBook(db, "To Kill a Mockingbird", "Harper Lee", "Fiction");
    insertBook(db, "The Great Gatsby", "F. Scott Fitzgerald", "Classic");

    char choice;
    do {
        printf("\nWelcome to the Peaceful Book Database!\n");
        printf("Choose a query method:\n");
        printf("1. View all books\n");
        printf("2. Search by author\n");
        printf("3. Search by genre\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                displayBooks(db, "SELECT title, author, genre FROM books;");
                break;
            case '2': {
                char author[100];
                printf("Enter author's name: ");
                scanf(" %[^\n]", author);
                char query[150];
                snprintf(query, sizeof(query), "SELECT title, author, genre FROM books WHERE author LIKE '%%%s%%';", author);
                displayBooks(db, query);
                break;
            }
            case '3': {
                char genre[100];
                printf("Enter genre: ");
                scanf(" %[^\n]", genre);
                char query[150];
                snprintf(query, sizeof(query), "SELECT title, author, genre FROM books WHERE genre LIKE '%%%s%%';", genre);
                displayBooks(db, query);
                break;
            }
            case '4':
                printf("Thank you for visiting the Peaceful Book Database.\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != '4');

    sqlite3_close(db);
    return 0;
}