//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int id;
    char title[50];
    struct Book* next;
} Book;

Book* head = NULL;

void addBook(int id, const char* title) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (!newBook) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newBook->id = id;
    strncpy(newBook->title, title, sizeof(newBook->title) - 1);
    newBook->title[sizeof(newBook->title) - 1] = '\0';
    newBook->next = head;
    head = newBook;
    printf("Book added: ID=%d, Title=%s\n", id, title);
}

void deleteBook(int id) {
    Book* current = head;
    Book* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Book with ID=%d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Book with ID=%d deleted.\n", id);
}

Book* searchBook(int id) {
    Book* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void displayBooks() {
    Book* current = head;
    if (current == NULL) {
        printf("No books available.\n");
        return;
    }
    
    printf("Books in the library:\n");
    while (current != NULL) {
        printf("ID: %d, Title: %s\n", current->id, current->title);
        current = current->next;
    }
}

void freeMemory() {
    Book* current = head;
    Book* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    int choice, id;
    char title[50];

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book title: ");
                getchar(); // To consume newline character left by previous input
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline character
                addBook(id, title);
                break;
            case 2:
                printf("Enter book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            case 3:
                printf("Enter book ID to search: ");
                scanf("%d", &id);
                Book* foundBook = searchBook(id);
                if (foundBook) {
                    printf("Book found: ID=%d, Title=%s\n", foundBook->id, foundBook->title);
                } else {
                    printf("Book with ID=%d not found.\n", id);
                }
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                freeMemory();
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}