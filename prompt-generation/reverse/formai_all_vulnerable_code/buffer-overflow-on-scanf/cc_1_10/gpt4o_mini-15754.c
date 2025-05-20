//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Function prototypes
void create_table(sqlite3 *db);
void insert_book(sqlite3 *db);
void display_books(sqlite3 *db);
void execute_sql(char *sql, sqlite3 *db);
void log_error(char *message, int res);
void close_database(sqlite3 *db);

int main() {
    sqlite3 *db;
    int res;

    // Open database
    res = sqlite3_open("cheerful_books.db", &db);
    if (res) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        printf("Hooray! Database opened successfully!\n");
    }

    // Create the books table
    create_table(db);

    // Main menu loop
    int choice;
    while (1) {
        printf("\n😊 Welcome to the Cheerful Book Database! 😊\n");
        printf("1. Insert a new book\n");
        printf("2. Display all books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_book(db);
                break;
            case 2:
                display_books(db);
                break;
            case 3:
                printf("Goodbye! Have a wonderful day! 🌼\n");
                close_database(db);
                return 0;
            default:
                printf("Oops! Please select a valid option!\n");
                break;
        }
    }

    closesqlite3(db);
    return 0;
}

void create_table(sqlite3 *db) {
    char *sql = "CREATE TABLE IF NOT EXISTS books (" \
                "id INTEGER PRIMARY KEY AUTOINCREMENT," \
                "title TEXT NOT NULL," \
                "author TEXT NOT NULL," \
                "year INTEGER NOT NULL);";
    
    execute_sql(sql, db);
    printf("🎉 Table created successfully! 🎉\n");
}

void insert_book(sqlite3 *db) {
    char title[100], author[100];
    int year;

    printf("Enter book title: ");
    getchar(); // Clear newline character
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character

    printf("Enter author's name: ");
    fgets(author, 100, stdin);
    author[strcspn(author, "\n")] = 0; // Remove newline character

    printf("Enter year of publication: ");
    scanf("%d", &year);

    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO books (title, author, year) VALUES ('%s', '%s', %d);", title, author, year);
    
    execute_sql(sql, db);
    printf("📚 Book \"%s\" by %s added successfully! 🎆\n", title, author);
}

void display_books(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *tail;
    
    char *sql = "SELECT * FROM books;";
    int res = sqlite3_prepare_v2(db, sql, -1, &stmt, &tail);
    
    if (res != SQLITE_OK) {
        log_error("Failed to prepare select statement", res);
        return;
    }

    printf("📖 Here are all the cheerful books in the database:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("ID: %d, Title: %s, Author: %s, Year: %d\n",
               sqlite3_column_int(stmt, 0),
               sqlite3_column_text(stmt, 1),
               sqlite3_column_text(stmt, 2),
               sqlite3_column_int(stmt, 3));
    }
    
    sqlite3_finalize(stmt);
}

void execute_sql(char *sql, sqlite3 *db) {
    char *err_msg = NULL;
    int res = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (res != SQLITE_OK) {
        log_error(err_msg, res);
        sqlite3_free(err_msg);
    }
}

void log_error(char *message, int res) {
    printf("❌ Error: %s (Error code: %d)\n", message, res);
}

void close_database(sqlite3 *db) {
    sqlite3_close(db);
    printf("Database closed. Until next time! 🥳\n");
}