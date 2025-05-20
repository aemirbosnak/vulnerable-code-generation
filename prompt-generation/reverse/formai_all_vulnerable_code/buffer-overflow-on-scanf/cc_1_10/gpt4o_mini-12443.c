//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define DB_NAME "library.db"

void create_table(sqlite3 *db) {
    char *err_msg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS Books(Id INTEGER PRIMARY KEY, Title TEXT, Author TEXT);";

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Cannot create table: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Table created successfully.\n");
    }
}

void add_book(sqlite3 *db, const char *title, const char *author) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO Books(Title, Author) VALUES(?, ?);";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, title, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, author, -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            fprintf(stderr, "Error inserting book: %s\n", sqlite3_errmsg(db));
        } else {
            printf("Book added successfully: %s by %s\n", title, author);
        }
    }
    sqlite3_finalize(stmt);
}

void list_books(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM Books;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK) {
        printf("List of Books:\n");
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const char *title = (const char *)sqlite3_column_text(stmt, 1);
            const char *author = (const char *)sqlite3_column_text(stmt, 2);
            printf("ID: %d | Title: %s | Author: %s\n", id, title, author);
        }
    }
    sqlite3_finalize(stmt);
}

void query_books(sqlite3 *db, const char *searchTerm) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM Books WHERE Title LIKE ? OR Author LIKE ?;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK) {
        char searchQuery[100];
        snprintf(searchQuery, sizeof(searchQuery), "%%%s%%", searchTerm);
        sqlite3_bind_text(stmt, 1, searchQuery, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, searchQuery, -1, SQLITE_STATIC);

        printf("Search results for '%s':\n", searchTerm);
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const char *title = (const char *)sqlite3_column_text(stmt, 1);
            const char *author = (const char *)sqlite3_column_text(stmt, 2);
            printf("ID: %d | Title: %s | Author: %s\n", id, title, author);
        }
    }
    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    int exit = sqlite3_open(DB_NAME, &db);

    if (exit) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    }

    create_table(db);

    int choice;
    char title[100], author[100], searchTerm[100];

    do {
        printf("\n--- Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Query Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline
                add_book(db, title, author);
                break;
            case 2:
                list_books(db);
                break;
            case 3:
                printf("Enter search term (title or author): ");
                fgets(searchTerm, sizeof(searchTerm), stdin);
                searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline
                query_books(db, searchTerm);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    sqlite3_close(db);
    return EXIT_SUCCESS;
}