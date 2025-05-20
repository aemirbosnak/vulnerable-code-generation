//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_BUFFER 1024

// Struct to hold book information
typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char content[MAX_BUFFER];
} Book;

// Function to read the book content from a file
int readBookContent(const char *filePath, Book *book) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        printf("Error opening file: %s\n", filePath);
        return -1;
    }

    // Read the book's content into the struct
    fgets(book->content, MAX_BUFFER, file);
    
    fclose(file);
    return 0;
}

// Function to initialize a book with title and author
void initializeBook(Book *book, const char *title, const char *author) {
    strncpy(book->title, title, MAX_TITLE);
    strncpy(book->author, author, MAX_AUTHOR);
}

// Function to display a book
void displayBook(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Content: %s\n", book->content);
}

// Function to display the menu options
void displayMenu() {
    printf("\n--- Ebook Reader Menu ---\n");
    printf("1. Load Book\n");
    printf("2. Display Book\n");
    printf("3. Exit\n");
    printf("-------------------------\n");
}

// Driver function to run the Ebook reader
int main() {
    Book books[MAX_BOOKS];
    int choice;
    int currentBookIndex = -1;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer

        switch (choice) {
            case 1: {
                if (currentBookIndex >= MAX_BOOKS - 1) {
                    printf("Maximum number of books loaded.\n");
                    break;
                }

                char title[MAX_TITLE];
                char author[MAX_AUTHOR];
                char filePath[256];

                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character

                printf("Enter book author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline character

                printf("Enter file path for the book content: ");
                fgets(filePath, sizeof(filePath), stdin);
                filePath[strcspn(filePath, "\n")] = 0; // Remove newline character

                currentBookIndex++;
                initializeBook(&books[currentBookIndex], title, author);
                if (readBookContent(filePath, &books[currentBookIndex]) == 0) {
                    printf("Book '%s' by '%s' loaded successfully!\n", title, author);
                } else {
                    printf("Failed to load the book content.\n");
                    currentBookIndex--; // Decrement index if loading fails
                }
                break;
            }
            case 2: {
                if (currentBookIndex == -1) {
                    printf("No books loaded yet!\n");
                } else {
                    for (int i = 0; i <= currentBookIndex; i++) {
                        displayBook(&books[i]);
                    }
                }
                break;
            }
            case 3:
                printf("Exiting Ebook Reader...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}