//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: lively
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
} BookDatabase;

void addBook(BookDatabase *db) {
    if (db->count >= MAX_BOOKS) {
        printf("Database is full! Can't add more books.\n");
        return;
    }
    
    Book newBook;
    printf("Enter the book title: ");
    getchar();  // Consume the newline character left by previous input
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter the author's name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    printf("Enter the publication year: ");
    scanf("%d", &newBook.year);
    
    db->books[db->count++] = newBook;
    printf("Book added successfully!\n\n");
}

void displayBooks(const BookDatabase *db) {
    if (db->count == 0) {
        printf("No books in the database.\n\n");
        return;
    }
    
    printf("Books in the database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n", 
                db->books[i].title, 
                db->books[i].author, 
                db->books[i].year);
    }
    printf("\n");
}

void searchBook(const BookDatabase *db) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // Consume newline character
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character

    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->books[i].title, title) == 0) {
            printf("Book found!\nTitle: %s, Author: %s, Year: %d\n\n", 
                    db->books[i].title, 
                    db->books[i].author, 
                    db->books[i].year);
            return;
        }
    }

    printf("Book not found in the database.\n\n");
}

void printMenu() {
    printf("******** Book Database Menu ********\n");
    printf("1. Add a Book\n");
    printf("2. Display All Books\n");
    printf("3. Search for a Book\n");
    printf("4. Exit\n");
    printf("************************************\n");
    printf("Choose an option: ");
}

int main() {
    BookDatabase db;
    db.count = 0;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&db);
                break;
            case 2:
                displayBooks(&db);
                break;
            case 3:
                searchBook(&db);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    } while (choice != 4);
    
    return 0;
}