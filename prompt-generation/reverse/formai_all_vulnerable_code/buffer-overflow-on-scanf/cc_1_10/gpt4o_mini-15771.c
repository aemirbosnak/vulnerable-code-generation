//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100

typedef struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    struct Book *next;
} Book;

Book *head = NULL;  // Head of the linked list for books

// Function to create a new book
Book* create_book(const char *title, const char *author) {
    Book *new_book = (Book*)malloc(sizeof(Book));
    if (!new_book) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(new_book->title, title, MAX_TITLE);
    strncpy(new_book->author, author, MAX_AUTHOR);
    new_book->next = NULL;
    return new_book;
}

// Function to add a book to the collection
void add_book(const char *title, const char *author) {
    Book *new_book = create_book(title, author);
    new_book->next = head; // Insert at the head
    head = new_book;
}

// Function to remove a book by title
void remove_book(const char *title) {
    Book *current = head;
    Book *previous = NULL;

    while (current != NULL) {
        if (strncmp(current->title, title, MAX_TITLE) == 0) {
            if (previous == NULL) {
                head = current->next; // Book was found at head
            } else {
                previous->next = current->next; // Bypass the current book
            }
            free(current); // Free the allocated memory
            printf("Book '%s' removed from the collection.\n", title);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Book '%s' not found in the collection.\n", title);
}

// Function to display all books in the collection
void display_books() {
    Book *current = head;
    if (current == NULL) {
        printf("No books in the collection.\n");
        return;
    }
    printf("Books in the collection:\n");
    while (current != NULL) {
        printf("Title: %s, Author: %s\n", current->title, current->author);
        current = current->next;
    }
}

// Function to free all allocated memory
void free_books() {
    Book *current = head;
    while (current != NULL) {
        Book *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    int choice;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];

    while (1) {
        printf("\n1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Display Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0; // Remove trailing newline
                printf("Enter book author: ");
                fgets(author, MAX_AUTHOR, stdin);
                author[strcspn(author, "\n")] = 0; // Remove trailing newline
                add_book(title, author);
                break;

            case 2:
                printf("Enter book title to remove: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0; // Remove trailing newline
                remove_book(title);
                break;

            case 3:
                display_books();
                break;

            case 4:
                free_books(); // Free all allocated memory
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}