//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Database;

void initializeDatabase(Database* db) {
    db->count = 0;
}

int addBook(Database* db, int id, const char* title, const char* author) {
    if (db->count >= MAX_BOOKS) {
        return -1; // Database full
    }
    db->books[db->count].id = id;
    strncpy(db->books[db->count].title, title, TITLE_LENGTH);
    strncpy(db->books[db->count].author, author, AUTHOR_LENGTH);
    db->count++;
    return 0; // Success
}

int searchBookById(Database* db, int id, Book* result) {
    for (int i = 0; i < db->count; i++) {
        if (db->books[i].id == id) {
            *result = db->books[i];
            return 0; // Book found
        }
    }
    return -1; // Book not found
}

void displayBooks(Database* db) {
    if (db->count == 0) {
        printf("No books in the database.\n");
        return;
    }
    printf("ID\tTitle\t\t\tAuthor\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%-20s\t%-20s\n", db->books[i].id, db->books[i].title, db->books[i].author);
    }
}

void showMenu() {
    printf("\n=== Book Database ===\n");
    printf("1. Add a book\n");
    printf("2. Search for a book by ID\n");
    printf("3. Display all books\n");
    printf("4. Exit\n");
    printf("=====================\n");
}

int main() {
    Database db;
    initializeDatabase(&db);
    int choice;
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    Book foundBook;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book title: ");
                getchar(); // To consume the newline character
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                printf("Enter author name: ");
                fgets(author, AUTHOR_LENGTH, stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline

                if (addBook(&db, id, title, author) == 0) {
                    printf("Book added successfully!\n");
                } else {
                    printf("Database is full, cannot add more books.\n");
                }
                break;
            case 2:
                printf("Enter book ID to search: ");
                scanf("%d", &id);
                if (searchBookById(&db, id, &foundBook) == 0) {
                    printf("Book found: ID:%d, Title:%s, Author:%s\n", foundBook.id, foundBook.title, foundBook.author);
                } else {
                    printf("No book found with ID: %d\n", id);
                }
                break;
            case 3:
                displayBooks(&db);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}