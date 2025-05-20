//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    struct Book* next;
} Book;

Book* head = NULL;
int book_count = 0;

// Function prototypes
void addBook();
void viewBooks();
void deleteBook();
void freeMemory();

int main() {
    int choice;

    while (1) {
        printf("\n---- Simple Book Database ----\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
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
                freeMemory();
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void addBook() {
    Book* new_book = (Book*)malloc(sizeof(Book));
    if (new_book == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    new_book->id = ++book_count;
    printf("Enter the title of the book: ");
    getchar(); // Clear the newline character from buffer
    fgets(new_book->title, MAX_TITLE_LENGTH, stdin);
    new_book->title[strcspn(new_book->title, "\n")] = 0; // Remove newline character

    printf("Enter the author of the book: ");
    fgets(new_book->author, MAX_AUTHOR_LENGTH, stdin);
    new_book->author[strcspn(new_book->author, "\n")] = 0; // Remove newline character

    new_book->next = head;  // Insert new book at the beginning
    head = new_book;

    printf("Book added successfully!\n");
}

void viewBooks() {
    if (head == NULL) {
        printf("No books in the database.\n");
        return;
    }

    printf("\n---- List of Books ----\n");
    Book* current = head;
    while (current != NULL) {
        printf("ID: %d, Title: %s, Author: %s\n", current->id, current->title, current->author);
        current = current->next;
    }
}

void deleteBook() {
    if (head == NULL) {
        printf("No books to delete.\n");
        return;
    }

    int id;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);

    Book* current = head;
    Book* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Deleting the head
    } else {
        previous->next = current->next; // Bypass the deleted book
    }
    
    free(current);
    printf("Book with ID %d deleted successfully!\n", id);
}

void freeMemory() {
    Book* current = head;
    while (current != NULL) {
        Book* next = current->next;
        free(current);
        current = next;
    }
}