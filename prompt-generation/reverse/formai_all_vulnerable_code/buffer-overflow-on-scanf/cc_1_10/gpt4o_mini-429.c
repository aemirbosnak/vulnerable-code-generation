//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_ISBN_LENGTH 20

typedef struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char isbn[MAX_ISBN_LENGTH];
    struct Book* next;
} Book;

Book* head = NULL;

void addBook() {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (!newBook) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the book title: ");
    getchar(); // To consume leftover newline character
    fgets(newBook->title, MAX_TITLE_LENGTH, stdin);
    newBook->title[strcspn(newBook->title, "\n")] = '\0'; // Remove newline character

    printf("Enter the author's name: ");
    fgets(newBook->author, MAX_AUTHOR_LENGTH, stdin);
    newBook->author[strcspn(newBook->author, "\n")] = '\0'; // Remove newline character

    printf("Enter the ISBN number: ");
    fgets(newBook->isbn, MAX_ISBN_LENGTH, stdin);
    newBook->isbn[strcspn(newBook->isbn, "\n")] = '\0'; // Remove newline character

    newBook->next = head;
    head = newBook;

    printf("Book added successfully!\n");
}

void viewBooks() {
    if (head == NULL) {
        printf("No books in the database.\n");
        return;
    }

    Book* current = head;
    printf("\nBooks in Database:\n");
    while (current != NULL) {
        printf("Title: %s, Author: %s, ISBN: %s\n", current->title, current->author, current->isbn);
        current = current->next;
    }
}

void deleteBook() {
    if (head == NULL) {
        printf("No books to delete.\n");
        return;
    }

    char isbnToDelete[MAX_ISBN_LENGTH];
    printf("Enter the ISBN number of the book to delete: ");
    getchar();
    fgets(isbnToDelete, MAX_ISBN_LENGTH, stdin);
    isbnToDelete[strcspn(isbnToDelete, "\n")] = '\0';

    Book* current = head;
    Book* previous = NULL;

    while (current != NULL && strcmp(current->isbn, isbnToDelete) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Book with ISBN %s not found.\n", isbnToDelete);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Deleting the head
    } else {
        previous->next = current->next; // Bypass the current
    }

    free(current);
    printf("Book deleted successfully!\n");
}

void menu() {
    printf("\nLibrary Database System\n");
    printf("1. Add a Book\n");
    printf("2. View All Books\n");
    printf("3. Delete a Book\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}