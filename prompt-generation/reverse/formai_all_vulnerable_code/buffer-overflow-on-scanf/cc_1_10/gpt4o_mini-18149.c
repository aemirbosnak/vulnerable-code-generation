//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 30

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

void addBook(Book *library, int *count);
void searchBook(Book *library, int count);
void viewBooks(Book *library, int count);
void clearBuffer();

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("=== Library Management System ===\n");
        printf("1. Add a new book\n");
        printf("2. Search for a book\n");
        printf("3. View all books\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();  // Clear input buffer

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                searchBook(library, count);
                break;
            case 3:
                viewBooks(library, count);
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    fgets(library[*count].title, TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline

    printf("Enter book author: ");
    fgets(library[*count].author, AUTHOR_LENGTH, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = 0; // Remove newline

    printf("Enter year of publication: ");
    scanf("%d", &library[*count].year);
    clearBuffer();  // Clear input buffer

    (*count)++;
    printf("Book added successfully: \"%s\" by %s (%d)\n", library[*count - 1].title, library[*count - 1].author, library[*count - 1].year);
}

void searchBook(Book *library, int count) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter book title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, searchTitle) != NULL) {
            printf("Found Book: \"%s\" by %s (%d)\n", library[i].title, library[i].author, library[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No book found with title containing \"%s\".\n", searchTitle);
    }
}

void viewBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("=== List of Books ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. \"%s\" by %s (%d)\n", i + 1, library[i].title, library[i].author, library[i].year);
    }
}

void clearBuffer() {
    while (getchar() != '\n');
}