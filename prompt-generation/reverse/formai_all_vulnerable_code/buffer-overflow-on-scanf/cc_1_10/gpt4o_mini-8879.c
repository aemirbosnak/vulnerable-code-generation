//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

void execute_sql(sqlite3 *db, const char *sql) {
    char *errorMessage = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errorMessage);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errorMessage);
        sqlite3_free(errorMessage);
    } else {
        printf("Executed: %s\n", sql);
    }
}

void add_book(sqlite3 *db, const char *title, const char *author, int year) {
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Books (Title, Author, Year) VALUES ('%s', '%s', %d);",
             title, author, year);
    execute_sql(db, sql);
}

void fetch_books(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM Books;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch books: %s\n", sqlite3_errmsg(db));
        return;
    }
    
    printf("\nBooks in the database:\n");
    printf("-------------------------------------------------\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char *title = (const char *)sqlite3_column_text(stmt, 1);
        const char *author = (const char *)sqlite3_column_text(stmt, 2);
        int year = sqlite3_column_int(stmt, 3);
        printf("Title: %s, Author: %s, Year: %d\n", title, author, year);
    }
    printf("-------------------------------------------------\n");
    
    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("books.db", &db);
    
    if (rc) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return rc;
    } else {
        fprintf(stdout, "Opened database successfully.\n");
    }

    const char *createTableSQL = "CREATE TABLE IF NOT EXISTS Books ("
                                  "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                                  "Title TEXT NOT NULL,"
                                  "Author TEXT NOT NULL,"
                                  "Year INTEGER NOT NULL);";
    execute_sql(db, createTableSQL);
    
    char title[100];
    char author[100];
    int year;
    
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a new book\n");
        printf("2. View all books\n");
        printf("3. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter book title: ");
                scanf(" %[^\n]%*c", title);  // Read string with spaces
                printf("Enter author name: ");
                scanf(" %[^\n]%*c", author);  // Read string with spaces
                printf("Enter publication year: ");
                scanf("%d", &year);
                add_book(db, title, author, year);
                break;
            case 2:
                fetch_books(db);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                sqlite3_close(db);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    sqlite3_close(db);
    return 0;
}