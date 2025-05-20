//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addBook(Database *db) {
    if (db->count >= MAX_BOOKS) {
        printf("Database is full. Cannot add more books.\n");
        return;
    }
    Book newBook;
    printf("Enter book title: ");
    getchar(); // To clear the newline character from input buffer
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);

    db->books[db->count++] = newBook;
    printf("Book added successfully!\n");
}

void deleteBook(Database *db) {
    if (db->count == 0) {
        printf("No books to delete.\n");
        return;
    }
    char title[TITLE_LENGTH];
    printf("Enter title of the book to delete: ");
    getchar(); // To clear the newline character from input buffer
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->books[i].title, title) == 0) {
            for (int j = i; j < db->count - 1; j++) {
                db->books[j] = db->books[j + 1];
            }
            db->count--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void searchBook(const Database *db) {
    char title[TITLE_LENGTH];
    printf("Enter title of the book to search: ");
    getchar(); // To clear the newline character from input buffer
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->books[i].title, title) == 0) {
            printf("Book found: %s by %s (%d)\n", db->books[i].title, db->books[i].author, db->books[i].year);
            return;
        }
    }
    printf("Book not found.\n");
}

void listBooks(const Database *db) {
    if (db->count == 0) {
        printf("No books in the database.\n");
        return;
    }
    printf("Listing all books:\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, db->books[i].title, db->books[i].author, db->books[i].year);
    }
}

void displayMenu() {
    printf("\nDatabase Menu:\n");
    printf("1. Add Book\n");
    printf("2. Delete Book\n");
    printf("3. Search Book\n");
    printf("4. List Books\n");
    printf("5. Exit\n");
}

int main() {
    Database db;
    initializeDatabase(&db);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook(&db);
                break;
            case 2:
                deleteBook(&db);
                break;
            case 3:
                searchBook(&db);
                break;
            case 4:
                listBooks(&db);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}