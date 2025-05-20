//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
} Book;

void addBook(Book *library, int *count);
void displayBooks(const Book *library, int count);
void sortBooksByTitle(Book *library, int count);
void sortBooksByAuthor(Book *library, int count);
void menu();

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to remove the newline after the number input

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                printf("\nBooks in the library:\n");
                displayBooks(library, count);
                break;
            case 3:
                sortBooksByTitle(library, count);
                printf("Books sorted by title.\n");
                break;
            case 4:
                sortBooksByAuthor(library, count);
                printf("Books sorted by author.\n");
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void menu() {
    printf("\n--- Library Management System ---\n");
    printf("1. Add a Book\n");
    printf("2. Display All Books\n");
    printf("3. Sort Books by Title\n");
    printf("4. Sort Books by Author\n");
    printf("5. Exit\n");
}

void addBook(Book *library, int *count) {
    if (*count < MAX_BOOKS) {
        printf("Enter book title: ");
        fgets(library[*count].title, TITLE_LENGTH, stdin);
        library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline
        printf("Enter author name: ");
        fgets(library[*count].author, AUTHOR_LENGTH, stdin);
        library[*count].author[strcspn(library[*count].author, "\n")] = 0; // Remove newline
        (*count)++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full! Can't add more books.\n");
    }
}

void displayBooks(const Book *library, int count) {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Book %d: %s by %s\n", i + 1, library[i].title, library[i].author);
    }
}

void sortBooksByTitle(Book *library, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(library[j].title, library[j + 1].title) > 0) {
                Book temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
        }
    }
}

void sortBooksByAuthor(Book *library, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(library[j].author, library[j + 1].author) > 0) {
                Book temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
        }
    }
}