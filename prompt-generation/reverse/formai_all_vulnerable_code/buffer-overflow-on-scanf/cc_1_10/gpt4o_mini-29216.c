//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
} Book;

void inputBooks(Book books[], int *count) {
    for (*count = 0; *count < MAX_BOOKS; (*count)++) {
        printf("Enter book ID (negative to stop): ");
        scanf("%d", &books[*count].id);
        if (books[*count].id < 0) {
            break; // Stop input if id is negative
        }
        printf("Enter book title: ");
        getchar(); // Clear the newline character from buffer
        fgets(books[*count].title, MAX_TITLE_LENGTH, stdin);
        books[*count].title[strcspn(books[*count].title, "\n")] = 0; // Remove newline
    }
}

void printBooks(const Book books[], int count) {
    printf("\nList of Books:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: %s\n", books[i].id, books[i].title);
    }
}

void sortBooksAlphabetically(Book books[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (strcmp(books[j].title, books[j + 1].title) > 0) {
                // Swap books if they are in the wrong order
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0;

    printf("Welcome to the Library Book Management System\n");
    inputBooks(books, &count);

    printf("\nBefore Sorting:\n");
    printBooks(books, count);

    sortBooksAlphabetically(books, count);

    printf("\nAfter Sorting:\n");
    printBooks(books, count);

    return 0;
}