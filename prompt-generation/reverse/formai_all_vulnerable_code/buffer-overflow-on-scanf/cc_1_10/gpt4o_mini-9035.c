//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int id;
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
        printf("Database is full! Cannot add more books.\n");
        return;
    }
    
    Book newBook;
    printf("Enter book ID: ");
    scanf("%d", &newBook.id);
    getchar(); // consume newline
    
    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // remove newline

    printf("Enter book author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // remove newline

    db->books[db->count++] = newBook;
    printf("Book added successfully!\n");
}

void removeBook(Database *db) {
    int id;
    printf("Enter book ID to remove: ");
    scanf("%d", &id);
    
    for (int i = 0; i < db->count; i++) {
        if (db->books[i].id == id) {
            db->books[i] = db->books[db->count - 1]; // replace with last book
            db->count--;
            printf("Book removed successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

void displayBooks(Database *db) {
    if (db->count == 0) {
        printf("No books in the database.\n");
        return;
    }

    printf("\nCurrent Books in Database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", db->books[i].id, db->books[i].title, db->books[i].author);
    }
}

void searchBook(Database *db) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // consume newline
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // remove newline
    
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->books[i].title, title) == 0) {
            printf("Found Book -> ID: %d, Title: %s, Author: %s\n", db->books[i].id, db->books[i].title, db->books[i].author);
            return;
        }
    }
    printf("Book not found!\n");
}

void clearDatabase(Database *db) {
    db->count = 0;
    printf("Database cleared!\n");
}

int main() {
    Database db;
    initializeDatabase(&db);
    int choice;

    do {
        printf("\nLibrary Database Menu:\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Display Books\n");
        printf("4. Search Book\n");
        printf("5. Clear Database\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(&db); break;
            case 2: removeBook(&db); break;
            case 3: displayBooks(&db); break;
            case 4: searchBook(&db); break;
            case 5: clearDatabase(&db); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid option, please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}