//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    struct Book* next;
} Book;

Book* head = NULL;

// Function to create a new book node
Book* createBook(const char* title) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    newBook->next = NULL;
    return newBook;
}

// Function to display all books in the library
void displayBooks() {
    Book* current = head;
    if (current == NULL) {
        printf("The library is empty! No books to display.\n");
        return;
    }
    printf("Books in the library:\n");
    while (current != NULL) {
        printf("- %s\n", current->title);
        current = current->next;
    }
}

// Function to add a book to the end of the list
void addBook(const char* title) {
    Book* newBook = createBook(title);
    if (head == NULL) {
        head = newBook;
    } else {
        Book* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
    }
    printf("Added: %s\n", title);
}

// Function to delete a book by title
void deleteBook(const char* title) {
    Book* current = head;
    Book* previous = NULL;

    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Book '%s' not found in the library.\n", title);
        return;
    }
    
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Deleted: %s\n", title);
}

// Function to free all books in the library
void freeLibrary() {
    Book* current = head;
    Book* nextBook;

    while (current != NULL) {
        nextBook = current->next;
        free(current);
        current = nextBook;
    }
    head = NULL;
    printf("The library is now empty!\n");
}

// Main function to interact with the library
int main() {
    int choice;
    char title[100];

    while (1) {
        printf("\nWelcome to the Magical Library!\n");
        printf("1. Add a Book\n");
        printf("2. Delete a Book\n");
        printf("3. Display Books\n");
        printf("4. Exit\n");
        printf("Choose your action (1-4): ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter the book title to add: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                addBook(title);
                break;
            case 2:
                printf("Enter the book title to delete: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                deleteBook(title);
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                freeLibrary();
                printf("Thank you for visiting the Magical Library! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}