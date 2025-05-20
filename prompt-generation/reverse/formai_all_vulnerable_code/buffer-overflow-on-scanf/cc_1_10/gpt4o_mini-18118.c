//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// A heartfelt greeting to our beloved user
void greet_user() {
    printf("Welcome, cherished user! Thank you for choosing this program to interact with your book database.\n");
    printf("Here, you can add new books, view your collection, and appreciate the gift of literature!\n");
}

// Function to open the SQLite database
int open_database(sqlite3 **db) {
    int rc = sqlite3_open("books.db", db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*db));
        return rc;
    } else {
        printf("Opened database successfully. We appreciate your trust!\n");
    }
    return 0;
}

// Function to create a table for books
void create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS BOOKS("  \
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
                      "TITLE TEXT NOT NULL," \
                      "AUTHOR TEXT NOT NULL," \
                      "YEAR INT NOT NULL);";
    
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Table created successfully. Your collection is evolving!\n");
    }
}

// Function to insert a book record into the database
void insert_book(sqlite3 *db) {
    char title[100], author[100];
    int year;
    
    printf("Please enter the book title: ");
    fgets(title, sizeof(title), stdin);
    
    printf("Please enter the author's name: ");
    fgets(author, sizeof(author), stdin);
    
    printf("Please enter the year of publication: ");
    scanf("%d", &year);
    getchar(); // clear the newline from buffer

    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO BOOKS (TITLE, AUTHOR, YEAR) VALUES ('%s', '%s', %d);", 
             title, author, year);
             
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Book added successfully! Thank you for adding to your collection!\n");
    }
}

// Callback function to display query results
int display_books(void *notused, int argc, char **argv, char **azColName) {
    printf("\nBooks in your collection:\n");
    for (int i = 0; i < argc; i++) {
        printf("%s: %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

// Function to query and display all books from the database
void query_books(sqlite3 *db) {
    const char *sql = "SELECT * FROM BOOKS;";
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, display_books, 0, &errMsg);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Query executed successfully! Your literary journey awaits.\n");
    }
}

int main() {
    sqlite3 *db;
    greet_user();

    if (open_database(&db) != 0) {
        return 1; // Exit if database can't be opened
    }

    create_table(db);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert a new book\n");
        printf("2. View all books\n");
        printf("3. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear the newline from buffer

        switch (choice) {
            case 1:
                insert_book(db);
                break;
            case 2:
                query_books(db);
                break;
            case 3:
                printf("Thank you for using the book database! May your reading journeys be fulfilling!\n");
                break;
            default:
                printf("Invalid choice! We appreciate your enthusiasm!\n");
        }
    } while (choice != 3);

    sqlite3_close(db);
    return 0;
}