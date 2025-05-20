//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    struct Book* next;
} Book;

Book* head = NULL;
int book_count = 0;

void addBook() {
    Book* new_book = (Book*)malloc(sizeof(Book));
    if (!new_book) {
        printf("Memory allocation failed!\n");
        return;
    }

    new_book->id = ++book_count;
    printf("Enter Book Title: ");
    getchar(); // To consume the newline character from previous input
    fgets(new_book->title, MAX_TITLE_LENGTH, stdin);
    new_book->title[strcspn(new_book->title, "\n")] = '\0'; // Remove newline character
    printf("Enter Author Name: ");
    fgets(new_book->author, MAX_AUTHOR_LENGTH, stdin);
    new_book->author[strcspn(new_book->author, "\n")] = '\0'; // Remove newline character
    new_book->next = head;
    head = new_book;

    printf("Book \"%s\" by %s added successfully with ID %d.\n\n", new_book->title, new_book->author, new_book->id);
}

void viewBooks() {
    if (head == NULL) {
        printf("No books available to view.\n\n");
        return;
    }
    
    printf("Books List:\n");
    Book* current = head;
    while (current != NULL) {
        printf("ID: %d, Title: \"%s\", Author: \"%s\"\n", current->id, current->title, current->author);
        current = current->next;
    }
    printf("\n");
}

void deleteBook() {
    if (head == NULL) {
        printf("No books available to delete.\n\n");
        return;
    }
    
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    Book* current = head;
    Book* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("No book found with ID %d.\n\n", id);
        return;
    }

    if (previous == NULL) { // Deleting head
        head = current->next;
    } else {
        previous->next = current->next;
    }
    
    free(current);
    printf("Book with ID %d deleted successfully.\n\n", id);
}

void freeMemory() {
    Book* current = head;
    while (current != NULL) {
        Book* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    int choice;
    
    do {
        printf("Simple Book Database\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 4);

    return 0;
}