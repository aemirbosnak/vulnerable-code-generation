//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
} Book;

void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter the title of the book: ");
    // Read the book title
    scanf(" %[^\n]", books[*count].title);
    (*count)++;
    printf("Book added successfully!\n");
}

void searchBook(Book books[], int count) {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    scanf(" %[^\n]", searchTitle);

    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, searchTitle) != NULL) {
            printf("Found: %s\n", books[i].title);
        }
    }
}

void displayBooks(Book books[], int count) {
    if (count == 0) {
        printf("No books in the library!\n");
        return;
    }

    printf("\nList of Books in the Library:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, books[i].title);
    }
}

void deleteBook(Book books[], int *count) {
    if (*count == 0) {
        printf("No books to delete!\n");
        return;
    }

    displayBooks(books, *count);
    int index;
    printf("Enter the book number to delete: ");
    scanf("%d", &index);
    index--; // To convert to 0-based index

    if (index < 0 || index >= *count) {
        printf("Invalid book number!\n");
    } else {
        printf("Deleting: %s\n", books[index].title);
        for (int i = index; i < (*count) - 1; i++) {
            strcpy(books[i].title, books[i + 1].title);
        }
        (*count)--;
        printf("Book deleted successfully!\n");
    }
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("\n*** Library Management System ***\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Display Books\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                searchBook(books, count);
                break;
            case 3:
                displayBooks(books, count);
                break;
            case 4:
                deleteBook(books, &count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}