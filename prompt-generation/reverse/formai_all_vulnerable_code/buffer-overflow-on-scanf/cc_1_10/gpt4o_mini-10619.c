//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: peaceful
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

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }

    Book newBook;
    newBook.id = bookCount + 1;

    printf("Enter book title: ");
    getchar(); // To consume newline
    fgets(newBook.title, TITLE_LENGTH, stdin);
    strtok(newBook.title, "\n"); // Remove newline character

    printf("Enter book author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    strtok(newBook.author, "\n"); // Remove newline character

    library[bookCount] = newBook;
    bookCount++;
    printf("Book added successfully: [%d] %s by %s\n", newBook.id, newBook.title, newBook.author);
}

void viewBooks() {
    if (bookCount == 0) {
        printf("The library is currently empty.\n");
        return;
    }

    printf("\nBooks in the library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("[%d] %s by %s\n", library[i].id, library[i].title, library[i].author);
    }
}

void deleteBook() {
    if (bookCount == 0) {
        printf("The library is currently empty, nothing to delete.\n");
        return;
    }

    int idToDelete;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &idToDelete);

    if (idToDelete < 1 || idToDelete > bookCount) {
        printf("Invalid book ID.\n");
        return;
    }

    for (int i = idToDelete - 1; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
    }
    
    bookCount--;
    printf("Book with ID %d deleted successfully.\n", idToDelete);
}

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Delete Book\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                printf("Exiting the program. Thank you for using the Library Management System!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}