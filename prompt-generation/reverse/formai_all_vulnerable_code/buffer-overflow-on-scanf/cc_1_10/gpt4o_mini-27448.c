//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define DB_NAME "library.db"

// Function prototypes
int create_table();
int add_book(const char *title, const char *author);
int display_books();
int search_book(const char *title);
void execute_query(const char *sql, sqlite3 *db);

// Structure to hold book details
typedef struct {
    char title[100];
    char author[100];
} Book;

// Callback function to display query results
int display_callback(void *data, int argc, char **argv, char **azColName){
    for(int i = 0; i < argc; i++){
        printf("%s: %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// Main function
int main() {
    int option;
    char title[100];
    char author[100];

    // Create a new database table for books
    create_table();
    
    do {
        printf("Library Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar(); // Clear newline character from buffer

        switch (option) {
            case 1:
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline
                add_book(title, author);
                break;
            case 2:
                display_books();
                break;
            case 3:
                printf("Enter book title to search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                search_book(title);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 4);

    return 0;
}

// Function to create the books table
int create_table() {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open(DB_NAME, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS Books("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Title TEXT NOT NULL,"
                      "Author TEXT NOT NULL);";

    execute_query(sql, db);

    sqlite3_close(db);
    return 0;
}

// Function to add a book to the database
int add_book(const char *title, const char *author) {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open(DB_NAME, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Books (Title, Author) VALUES ('%s', '%s');", title, author);

    execute_query(sql, db);
    sqlite3_close(db);
    return 0;
}

// Function to display all books in the database
int display_books() {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open(DB_NAME, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    const char *sql = "SELECT * FROM Books;";
    printf("Listing all books:\n");
    execute_query(sql, db);

    sqlite3_close(db);
    return 0;
}

// Function to search for a book by title
int search_book(const char *title) {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open(DB_NAME, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT * FROM Books WHERE Title LIKE '%%s%';", title);

    printf("Searching for book titled: %s\n", title);
    execute_query(sql, db);

    sqlite3_close(db);
    return 0;
}

// Helper function to execute and handle query results
void execute_query(const char *sql, sqlite3 *db) {
    char *err_msg = 0;

    int rc = sqlite3_exec(db, sql, display_callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}