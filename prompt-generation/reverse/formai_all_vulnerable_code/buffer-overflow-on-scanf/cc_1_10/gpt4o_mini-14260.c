//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: inquisitive
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

void addBook(Database *db) {
    if (db->count >= MAX_BOOKS) {
        printf("Database is full, cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter book title: ");
    getchar(); // to consume the newline
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // remove newline

    printf("Enter book author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // remove newline
    
    printf("Enter publication year: ");
    scanf("%d", &newBook.year);
    
    db->books[db->count++] = newBook;
    printf("Book added successfully.\n");
}

void viewBooks(Database *db) {
    if (db->count == 0) {
        printf("No books in the database.\n");
        return;
    }

    printf("Books in the database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n", 
                db->books[i].title, db->books[i].author, db->books[i].year);
    }
}

void searchBook(Database *db) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // to consume the newline
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->books[i].title, title) == 0) {
            printf("Book found! Title: %s, Author: %s, Year: %d\n", 
                    db->books[i].title, db->books[i].author, db->books[i].year);
            return;
        }
    }
    printf("Book not found.\n");
}

void deleteBook(Database *db) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the book to delete: ");
    getchar(); // to consume the newline
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline

    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->books[i].title, title) == 0) {
            for (int j = i; j < db->count - 1; j++) {
                db->books[j] = db->books[j + 1]; // shift books left
            }
            db->count--;
            printf("Book deleted successfully.\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void displayMenu() {
    printf("\nChoose an action:\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
}

int main() {
    Database db;
    db.count = 0;

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&db);
                break;
            case 2:
                viewBooks(&db);
                break;
            case 3:
                searchBook(&db);
                break;
            case 4:
                deleteBook(&db);
                break;
            case 5:
                printf("Exiting the database program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}