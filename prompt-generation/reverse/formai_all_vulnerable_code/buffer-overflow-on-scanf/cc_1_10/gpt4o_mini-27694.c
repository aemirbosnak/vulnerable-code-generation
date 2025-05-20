//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

void displayMenu();
void addBook(Book *library, int *count);
void viewBooks(Book *library, int count);
void searchBook(Book *library, int count);
void sortBooks(Book *library, int count);
void freeMemory();

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline from buffer

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                viewBooks(library, count);
                break;
            case 3:
                searchBook(library, count);
                break;
            case 4:
                sortBooks(library, count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n=== Book Management System ===\n");
    printf("1. Add a new book\n");
    printf("2. View all books\n");
    printf("3. Search for a book\n");
    printf("4. Sort books by title\n");
    printf("5. Exit\n");
}

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';  // Remove newline

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';  // Remove newline

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);
    getchar();  // clear newline from buffer

    library[*count] = newBook;
    (*count)++;
    printf("Book added successfully!\n");
}

void viewBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nList of books:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n", library[i].year);
        printf("-------------------\n");
    }
}

void searchBook(Book *library, int count) {
    if (count == 0) {
        printf("No books available for search.\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';  // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Year: %d\n", library[i].year);
            return;
        }
    }

    printf("No book found with the title: %s\n", searchTitle);
}

void sortBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books to sort.\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(library[i].title, library[j].title) > 0) {
                Book temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }

    printf("Books sorted by title.\n");
}