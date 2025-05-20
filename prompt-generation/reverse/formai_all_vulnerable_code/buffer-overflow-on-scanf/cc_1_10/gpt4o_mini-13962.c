//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DB_NAME "books.db"

// Function to create the database and table
void create_database(sqlite3 *db) {
    const char *sql_create_table = "CREATE TABLE IF NOT EXISTS Books("
                                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                    "title TEXT NOT NULL,"
                                    "author TEXT NOT NULL,"
                                    "year INTEGER NOT NULL);";

    char *err_msg = 0;
    if (sqlite3_exec(db, sql_create_table, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

// Function to add a new book
void add_book(sqlite3 *db, const char *title, const char *author, int year) {
    const char *sql_insert = "INSERT INTO Books (title, author, year) VALUES (?, ?, ?);";
    sqlite3_stmt *stmt;
    
    if (sqlite3_prepare_v2(db, sql_insert, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }
    
    sqlite3_bind_text(stmt, 1, title, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, author, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, year);
    
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(db));
    }
    
    sqlite3_finalize(stmt);
}

// Function to query books
void query_books(sqlite3 *db) {
    const char *sql_select = "SELECT id, title, author, year FROM Books;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql_select, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("Books in the database:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *title = (const char *)sqlite3_column_text(stmt, 1);
        const char *author = (const char *)sqlite3_column_text(stmt, 2);
        int year = sqlite3_column_int(stmt, 3);
        
        printf("ID: %d, Title: %s, Author: %s, Year: %d\n", id, title, author, year);
    }

    sqlite3_finalize(stmt);
}

// Main function to run the program
int main() {
    sqlite3 *db;
    int exit = sqlite3_open(DB_NAME, &db);

    if (exit != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    create_database(db);
    
    int choice;
    do {
        printf("\nBook Manager Menu:\n");
        printf("1. Add Book\n");
        printf("2. Query Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1: {
                char title[100], author[100];
                int year;
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline
                printf("Enter year of publication: ");
                scanf("%d", &year);
                
                add_book(db, title, author, year);
                break;
            }
            case 2:
                query_books(db);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    sqlite3_close(db);
    return 0;
}