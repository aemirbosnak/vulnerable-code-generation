//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

void displayMenu() {
    printf("Library Management System\n");
    printf("1. Add a Book\n");
    printf("2. View All Books\n");
    printf("3. Search for a Book\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void addBook(Book *books, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Cannot add more books. Library is full.\n");
        return;
    }
    printf("Enter title: ");
    getchar(); // Clear the newline character from the input buffer
    fgets(books[*count].title, MAX_TITLE_LENGTH, stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = 0; // Remove newline

    printf("Enter author: ");
    fgets(books[*count].author, MAX_AUTHOR_LENGTH, stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = 0; // Remove newline

    printf("Enter year of publication: ");
    scanf("%d", &books[*count].year);

    (*count)++;
    printf("Book added successfully!\n");
}

void viewBooks(Book *books, int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }
    printf("\nList of Books:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n", books[i].title, books[i].author, books[i].year);
    }
}

void searchBook(Book *books, int count) {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // Clear the newline character from the input buffer
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\nSearch Results:\n");
    for (int i = 0; i < count; i++) {
        if (strcasecmp(books[i].title, searchTitle) == 0) {
            printf("Title: %s, Author: %s, Year: %d\n", books[i].title, books[i].author, books[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found with the title '%s'.\n", searchTitle);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                viewBooks(books, count);
                break;
            case 3:
                searchBook(books, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
        printf("\n");
    }
    return 0;
}