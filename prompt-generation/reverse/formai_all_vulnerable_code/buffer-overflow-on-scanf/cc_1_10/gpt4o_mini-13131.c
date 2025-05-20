//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the Book node
typedef struct Book {
    char title[100];
    char author[100];
    int year;
    struct Book* next;
} Book;

// Function prototype declarations
Book* createBook(char* title, char* author, int year);
void addBook(Book** head, char* title, char* author, int year);
void removeBook(Book** head, char* title);
void displayBooks(Book* head);
void freeList(Book* head);

// Function to create a new book
Book* createBook(char* title, char* author, int year) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (!newBook) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    newBook->next = NULL;
    return newBook;
}

// Function to add a book to the linked list
void addBook(Book** head, char* title, char* author, int year) {
    Book* newBook = createBook(title, author, year);
    newBook->next = *head;
    *head = newBook;
    printf("Book '%s' added to the library!\n", title);
}

// Function to remove a book from the linked list
void removeBook(Book** head, char* title) {
    Book* current = *head;
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
        *head = current->next; // Removing the first book
    } else {
        previous->next = current->next; // Removing a book not at the start
    }
    
    free(current);
    printf("Book '%s' removed from the library!\n", title);
}

// Function to display all books in the linked list
void displayBooks(Book* head) {
    if (head == NULL) {
        printf("No books in the library.\n");
        return;
    }
    
    printf("Books in the library:\n");
    Book* current = head;
    while (current != NULL) {
        printf("Title: '%s', Author: '%s', Year: %d\n", current->title, current->author, current->year);
        current = current->next;
    }
}

// Function to free the allocated memory
void freeList(Book* head) {
    Book* current = head;
    while (current != NULL) {
        Book* next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    Book* library = NULL;
    int choice;
    char title[100], author[100];
    int year;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Display Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline
                printf("Enter publication year: ");
                scanf("%d", &year);
                addBook(&library, title, author, year);
                break;

            case 2:
                printf("Enter book title to remove: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                removeBook(&library, title);
                break;

            case 3:
                displayBooks(library);
                break;

            case 4:
                freeList(library);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}