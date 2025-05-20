//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int publicationYear;
} Book;

void addBook(Book *books, int *count);
void listBooks(Book *books, int count);
void searchBook(Book *books, int count);
void removeBook(Book *books, int *count);
void displayMenu();

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after choice input

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                listBooks(books, count);
                break;
            case 3:
                searchBook(books, count);
                break;
            case 4:
                removeBook(books, &count);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n--- Bookstore Inventory Management ---\n");
    printf("1. Add a book\n");
    printf("2. List all books\n");
    printf("3. Search for a book\n");
    printf("4. Remove a book\n");
    printf("5. Exit\n");
}

void addBook(Book *books, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Inventory full, cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    fgets(books[*count].title, TITLE_LENGTH, stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(books[*count].author, AUTHOR_LENGTH, stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = 0; // Remove newline

    printf("Enter publication year: ");
    scanf("%d", &books[*count].publicationYear);
    getchar(); // Consume newline character

    (*count)++;
    printf("Book added successfully!\n");
}

void listBooks(Book *books, int count) {
    if (count == 0) {
        printf("No books in inventory.\n");
        return;
    }

    printf("\n--- List of Books ---\n");
    for (int i = 0; i < count; i++) {
        printf("Book %d:\n", i + 1);
        printf("  Title: %s\n", books[i].title);
        printf("  Author: %s\n", books[i].author);
        printf("  Publication Year: %d\n", books[i].publicationYear);
        printf("-------------------------\n");
    }
}

void searchBook(Book *books, int count) {
    if (count == 0) {
        printf("No books in inventory.\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter the book title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Found Book:\n");
            printf("  Title: %s\n", books[i].title);
            printf("  Author: %s\n", books[i].author);
            printf("  Publication Year: %d\n", books[i].publicationYear);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found in inventory.\n");
    }
}

void removeBook(Book *books, int *count) {
    if (*count == 0) {
        printf("No books in inventory to remove.\n");
        return;
    }

    char removeTitle[TITLE_LENGTH];
    printf("Enter the book title to remove: ");
    fgets(removeTitle, TITLE_LENGTH, stdin);
    removeTitle[strcspn(removeTitle, "\n")] = 0; // Remove newline

    int i, found = 0;
    for (i = 0; i < *count; i++) {
        if (strcmp(books[i].title, removeTitle) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < *count - 1; j++) {
            books[j] = books[j + 1]; // Shift books left
        }
        (*count)--;
        printf("Book removed successfully!\n");
    } else {
        printf("Book not found in inventory.\n");
    }
}