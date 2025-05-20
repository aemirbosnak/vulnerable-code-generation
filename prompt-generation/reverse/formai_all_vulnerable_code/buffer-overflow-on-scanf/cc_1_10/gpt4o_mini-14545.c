//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100

// Struct to represent a Book
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

// Array to store books
Book *library = NULL;
int totalBooks = 0;

// Function prototypes
void addBook(const char *title, const char *author);
void listBooks(int index);
int searchBook(const char *title, int index);

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];

    library = (Book *)malloc(MAX_BOOKS * sizeof(Book));
    if (library == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    do {
        printf("\nLibrary System Menu:\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // To consume newline character left by scanf

        switch (choice) {
            case 1:
                if (totalBooks >= MAX_BOOKS) {
                    printf("Library is full. Cannot add more books.\n");
                } else {
                    printf("Enter book title: ");
                    fgets(title, MAX_TITLE_LENGTH, stdin);
                    title[strcspn(title, "\n")] = 0; // Remove newline character

                    printf("Enter author name: ");
                    fgets(author, MAX_AUTHOR_LENGTH, stdin);
                    author[strcspn(author, "\n")] = 0; // Remove newline character

                    addBook(title, author);
                    printf("Book added successfully.\n");
                }
                break;
            case 2:
                if (totalBooks == 0) {
                    printf("No books in the library.\n");
                } else {
                    printf("Listing all books:\n");
                    listBooks(0);
                }
                break;
            case 3:
                printf("Enter book title to search: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character

                if (searchBook(title, 0)) {
                    printf("Book found: %s\n", title);
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 4:
                printf("Exiting the library system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(library);
    return 0;
}

// Function to add a book to the library
void addBook(const char *title, const char *author) {
    strcpy(library[totalBooks].title, title);
    strcpy(library[totalBooks].author, author);
    totalBooks++;
}

// Function to list all books recursively
void listBooks(int index) {
    if (index < totalBooks) {
        printf("Title: %s, Author: %s\n", library[index].title, library[index].author);
        listBooks(index + 1);
    }
}

// Function to search for a book recursively
int searchBook(const char *title, int index) {
    if (index >= totalBooks) {
        return 0; // Book not found
    }
    if (strcmp(library[index].title, title) == 0) {
        return 1; // Book found
    }
    return searchBook(title, index + 1);
}