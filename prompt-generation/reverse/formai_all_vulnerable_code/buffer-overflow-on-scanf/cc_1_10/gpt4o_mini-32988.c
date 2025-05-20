//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

// Function declarations
int create_table(sqlite3 *db);
int add_book(sqlite3 *db, const char *title, const char *author);
int view_books(sqlite3 *db);
int delete_book(sqlite3 *db, int id);
void execute_choice(int choice, sqlite3 *db);

// Main function
int main() {
    sqlite3 *db;

    // Open the database
    if (sqlite3_open("books.db", &db) != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Create the table
    create_table(db);

    // User interface loop
    int choice;
    do {
        printf("\n*** Book Database Management ***\n");
        printf("1. Add a book\n");
        printf("2. View all books\n");
        printf("3. Delete a book\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        execute_choice(choice, db);
    } while (choice != 4);
    
    // Close the database
    sqlite3_close(db);
    return 0;
}

// Function to create the table
int create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS Books (ID INTEGER PRIMARY KEY AUTOINCREMENT, Title TEXT NOT NULL, Author TEXT NOT NULL);";
    char *err_msg = 0;
    
    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to create table: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 0;
    }
    printf("Table created successfully!\n");
    return 1;
}

// Function to add a book
int add_book(sqlite3 *db, const char *title, const char *author) {
    char *err_msg = 0;
    char sql[256];

    snprintf(sql, sizeof(sql), "INSERT INTO Books (Title, Author) VALUES ('%s', '%s');", title, author);

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to add book: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 0;
    }
    printf("Book added successfully!\n");
    return 1;
}

// Function to view all books
int view_books(sqlite3 *db) {
    const char *sql = "SELECT * FROM Books;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch books: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    printf("\n*** List of Books ***\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("ID: %d | Title: %s | Author: %s\n", 
               sqlite3_column_int(stmt, 0), 
               sqlite3_column_text(stmt, 1), 
               sqlite3_column_text(stmt, 2));
    }

    sqlite3_finalize(stmt);
    return 1;
}

// Function to delete a book
int delete_book(sqlite3 *db, int id) {
    char *err_msg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "DELETE FROM Books WHERE ID = %d;", id);

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to delete book: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 0;
    }
    printf("Book with ID %d deleted successfully!\n", id);
    return 1;
}

// Function to execute user choice
void execute_choice(int choice, sqlite3 *db) {
    char title[100], author[100];
    int id;

    switch (choice) {
        case 1:
            printf("Enter book title: ");
            scanf(" %[^\n]s", title);
            printf("Enter book author: ");
            scanf(" %[^\n]s", author);
            add_book(db, title, author);
            break;
        case 2:
            view_books(db);
            break;
        case 3:
            printf("Enter the ID of the book to delete: ");
            scanf("%d", &id);
            delete_book(db, id);
            break;
        case 4:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}