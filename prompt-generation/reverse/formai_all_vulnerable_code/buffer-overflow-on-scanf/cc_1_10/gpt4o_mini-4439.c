//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define DATABASE_NAME "library.db"

void create_table(sqlite3 *db) {
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS Books("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Title TEXT NOT NULL,"
                      "Author TEXT NOT NULL);";

    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully!\n");
    }
}

void add_book(sqlite3 *db) {
    char title[100], author[100];
    char *errMsg = 0;
    char sql[256];

    printf("Enter book title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character

    printf("Enter book author: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = 0; // Remove newline character

    snprintf(sql, sizeof(sql), "INSERT INTO Books (Title, Author) VALUES ('%s', '%s');", title, author);
    
    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Book added successfully! 🎉\n");
    }
}

void view_books(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM Books;";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch books: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("\nBooks in the library:\n");
    printf("--------------------\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *title = sqlite3_column_text(stmt, 1);
        const unsigned char *author = sqlite3_column_text(stmt, 2);
        printf("ID: %d, Title: %s, Author: %s\n", id, title, author);
    }
    sqlite3_finalize(stmt);
}

void delete_book(sqlite3 *db) {
    int id;
    char *errMsg = 0;
    char sql[128];

    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);
    getchar(); // Clear newline character from input buffer

    snprintf(sql, sizeof(sql), "DELETE FROM Books WHERE ID = %d;", id);
    
    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Book deleted successfully! 🥳\n");
    }
}

int main() {
    sqlite3 *db;
    int exitCode = sqlite3_open(DATABASE_NAME, &db);

    if (exitCode) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    } else {
        printf("Database opened successfully! 🎊\n");
    }

    create_table(db);

    int choice;
    while (1) {
        printf("\nLibrary Menu:\n");
        printf("1. Add a Book\n");
        printf("2. View Books\n");
        printf("3. Delete a Book\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                add_book(db);
                break;
            case 2:
                view_books(db);
                break;
            case 3:
                delete_book(db);
                break;
            case 4:
                sqlite3_close(db);
                printf("Goodbye! 🌈\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice, please try again! 😊\n");
        }
    }

    sqlite3_close(db);
    return 0;
}