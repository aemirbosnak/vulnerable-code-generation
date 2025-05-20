//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100  // Configurable limit for maximum number of books

// Structure to represent a book
typedef struct {
    int id;
    char title[100];
    char author[100];
} Book;

// Function to add a book to the library
void addBook(Book *library, int *currentCount) {
    if (*currentCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    printf("Enter book ID: ");
    scanf("%d", &library[*currentCount].id);
    printf("Enter book title: ");
    getchar();  // Consume newline character left by scanf
    fgets(library[*currentCount].title, sizeof(library[*currentCount].title), stdin);
    library[*currentCount].title[strcspn(library[*currentCount].title, "\n")] = 0;  // Remove newline
    printf("Enter book author: ");
    fgets(library[*currentCount].author, sizeof(library[*currentCount].author), stdin);
    library[*currentCount].author[strcspn(library[*currentCount].author, "\n")] = 0;  // Remove newline
    (*currentCount)++;
    printf("Book added successfully!\n");
}

// Function to display all books in the library
void displayBooks(Book *library, int currentCount) {
    printf("\nLibrary Books:\n");
    if (currentCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    for (int i = 0; i < currentCount; i++) {
        printf("ID: %d | Title: %s | Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

// Function to search for a book by title
void searchBook(Book *library, int currentCount) {
    char searchTitle[100];
    printf("Enter the title of the book to search: ");
    getchar();  // Consume newline character
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;  // Remove newline

    int found = 0;
    for (int i = 0; i < currentCount; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {  // Case insensitive comparison
            printf("Book found: ID: %d | Title: %s | Author: %s\n", library[i].id, library[i].title, library[i].author);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found in the library.\n");
    }
}

// Function to show the main menu
void showMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
}

int main() {
    Book library[MAX_BOOKS];  // Array to hold the books
    int currentCount = 0;  // Current count of books in the library
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &currentCount);
                break;
            case 2:
                displayBooks(library, currentCount);
                break;
            case 3:
                searchBook(library, currentCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}