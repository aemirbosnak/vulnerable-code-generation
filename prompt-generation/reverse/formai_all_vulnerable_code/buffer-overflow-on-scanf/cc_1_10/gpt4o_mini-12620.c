//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 30
#define ISBN_LENGTH 20

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    char isbn[ISBN_LENGTH];
    int year;
    int available; // 1 for available, 0 for borrowed
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    Book newBook;
    printf("Enter title: ");
    getchar(); // Consume newline
    fgets(newBook.title, TITLE_LENGTH, stdin);
    strtok(newBook.title, "\n"); // Remove newline

    printf("Enter author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    strtok(newBook.author, "\n"); // Remove newline

    printf("Enter ISBN: ");
    fgets(newBook.isbn, ISBN_LENGTH, stdin);
    strtok(newBook.isbn, "\n"); // Remove newline

    printf("Enter year of publication: ");
    scanf("%d", &newBook.year);
    
    newBook.available = 1; // Available to borrow
    library[bookCount++] = newBook;

    printf("Book added successfully!\n");
}

void viewBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    
    printf("\n--- Library Books ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("ISBN: %s\n", library[i].isbn);
        printf("Year: %d\n", library[i].year);
        printf("Status: %s\n\n", library[i].available ? "Available" : "Borrowed");
    }
}

void borrowBook() {
    char isbn[ISBN_LENGTH];
    printf("Enter ISBN of the book to borrow: ");
    getchar(); // Consume newline
    fgets(isbn, ISBN_LENGTH, stdin);
    strtok(isbn, "\n"); // Remove newline

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            if (library[i].available) {
                library[i].available = 0; // Borrow the book
                printf("You have borrowed: %s\n", library[i].title);
                return;
            } else {
                printf("This book is currently borrowed.\n");
                return;
            }
        }
    }
    printf("Book not found.\n");
}

void returnBook() {
    char isbn[ISBN_LENGTH];
    printf("Enter ISBN of the book to return: ");
    getchar(); // Consume newline
    fgets(isbn, ISBN_LENGTH, stdin);
    strtok(isbn, "\n"); // Remove newline

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            if (!library[i].available) {
                library[i].available = 1; // Return the book
                printf("You have returned: %s\n", library[i].title);
                return;
            } else {
                printf("This book is not borrowed.\n");
                return;
            }
        }
    }
    printf("Book not found.\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}