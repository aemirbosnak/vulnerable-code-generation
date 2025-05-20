//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100

// Structure to hold book information
typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
} Book;

// Simple database to hold books and their count
typedef struct {
    Book books[MAX_BOOKS];
    int count;
} BookDatabase;

// Function prototypes
void initializeDatabase(BookDatabase *db);
void addBook(BookDatabase *db);
void searchByTitle(BookDatabase *db);
void searchByAuthor(BookDatabase *db);
void searchByYear(BookDatabase *db);
void displayBooks(BookDatabase *db);

int main() {
    BookDatabase db;
    initializeDatabase(&db);

    int choice;
    do {
        printf("\n--- Book Database Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Search by Title\n");
        printf("3. Search by Author\n");
        printf("4. Search by Year\n");
        printf("5. Display All Books\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addBook(&db);
                break;
            case 2:
                searchByTitle(&db);
                break;
            case 3:
                searchByAuthor(&db);
                break;
            case 4:
                searchByYear(&db);
                break;
            case 5:
                displayBooks(&db);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Initialize the database
void initializeDatabase(BookDatabase *db) {
    db->count = 0;
}

// Add a new book to the database
void addBook(BookDatabase *db) {
    if (db->count >= MAX_BOOKS) {
        printf("Database is full. Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    printf("Enter year of publication: ");
    scanf("%d", &newBook.year);
    getchar(); // Consume newline character

    db->books[db->count] = newBook;
    db->count++;
    printf("Book added successfully!\n");
}

// Search books by title
void searchByTitle(BookDatabase *db) {
    char title[TITLE_LEN];
    printf("Enter title to search for: ");
    fgets(title, TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    printf("\n--- Search Results for Title: %s ---\n", title);
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strstr(db->books[i].title, title)) {
            printf("Title: %s, Author: %s, Year: %d\n", 
                   db->books[i].title, db->books[i].author, db->books[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found with the title '%s'.\n", title);
    }
}

// Search books by author
void searchByAuthor(BookDatabase *db) {
    char author[AUTHOR_LEN];
    printf("Enter author name to search for: ");
    fgets(author, AUTHOR_LEN, stdin);
    author[strcspn(author, "\n")] = 0; // Remove newline

    printf("\n--- Search Results for Author: %s ---\n", author);
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strstr(db->books[i].author, author)) {
            printf("Title: %s, Author: %s, Year: %d\n", 
                   db->books[i].title, db->books[i].author, db->books[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by the author '%s'.\n", author);
    }
}

// Search books by year
void searchByYear(BookDatabase *db) {
    int year;
    printf("Enter year of publication to search for: ");
    scanf("%d", &year);
    getchar(); // Consume newline character

    printf("\n--- Search Results for Year: %d ---\n", year);
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (db->books[i].year == year) {
            printf("Title: %s, Author: %s, Year: %d\n", 
                   db->books[i].title, db->books[i].author, db->books[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found for the year %d.\n", year);
    }
}

// Display all books in the database
void displayBooks(BookDatabase *db) {
    printf("\n--- List of All Books ---\n");
    if (db->count == 0) {
        printf("No books in the database.\n");
        return;
    }
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n", 
               db->books[i].title, db->books[i].author, db->books[i].year);
    }
}