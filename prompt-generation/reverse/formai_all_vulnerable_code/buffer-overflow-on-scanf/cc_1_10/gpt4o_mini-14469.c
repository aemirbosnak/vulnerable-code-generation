//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_ISBN 20

// Structure to represent a book
typedef struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char isbn[MAX_ISBN];
    struct Book* next;
} Book;

// Function prototypes
Book* createBook(const char* title, const char* author, const char* isbn);
void addBook(Book** head, const char* title, const char* author, const char* isbn);
void removeBook(Book** head, const char* isbn);
void displayBooks(Book* head);
Book* searchBook(Book* head, const char* isbn);
void freeMemory(Book* head);

int main() {
    Book* bookList = NULL;
    int choice;
    char title[MAX_TITLE], author[MAX_AUTHOR], isbn[MAX_ISBN];

    while (1) {
        printf("\n===== Simple Book Database =====\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Display Books\n");
        printf("4. Search Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume newline character

        switch (choice) {
            case 1: // Add Book
                printf("Enter title: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0; // remove trailing newline

                printf("Enter author: ");
                fgets(author, MAX_AUTHOR, stdin);
                author[strcspn(author, "\n")] = 0; // remove trailing newline

                printf("Enter ISBN: ");
                fgets(isbn, MAX_ISBN, stdin);
                isbn[strcspn(isbn, "\n")] = 0; // remove trailing newline

                addBook(&bookList, title, author, isbn);
                printf("Book added successfully!\n");
                break;

            case 2: // Remove Book
                printf("Enter ISBN of the book to remove: ");
                fgets(isbn, MAX_ISBN, stdin);
                isbn[strcspn(isbn, "\n")] = 0; // remove trailing newline

                removeBook(&bookList, isbn);
                break;

            case 3: // Display Books
                displayBooks(bookList);
                break;

            case 4: // Search Book
                printf("Enter ISBN to search: ");
                fgets(isbn, MAX_ISBN, stdin);
                isbn[strcspn(isbn, "\n")] = 0; // remove trailing newline

                Book* foundBook = searchBook(bookList, isbn);
                if (foundBook) {
                    printf("Book found:\nTitle: %s\nAuthor: %s\nISBN: %s\n", foundBook->title, foundBook->author, foundBook->isbn);
                } else {
                    printf("No book found with ISBN: %s\n", isbn);
                }
                break;

            case 5: // Exit
                freeMemory(bookList);
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

Book* createBook(const char* title, const char* author, const char* isbn) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (!newBook) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newBook->title, title, MAX_TITLE);
    strncpy(newBook->author, author, MAX_AUTHOR);
    strncpy(newBook->isbn, isbn, MAX_ISBN);
    newBook->next = NULL;
    return newBook;
}

void addBook(Book** head, const char* title, const char* author, const char* isbn) {
    Book* newBook = createBook(title, author, isbn);
    newBook->next = *head;
    *head = newBook;
}

void removeBook(Book** head, const char* isbn) {
    Book* current = *head;
    Book* previous = NULL;

    while (current != NULL && strcmp(current->isbn, isbn) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Book with ISBN %s not found.\n", isbn);
        return; // Book not found
    }

    if (previous == NULL) {
        // Book is at the head
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    
    free(current);
    printf("Book with ISBN %s removed successfully!\n", isbn);
}

void displayBooks(Book* head) {
    if (head == NULL) {
        printf("No books in the database.\n");
        return;
    }

    printf("\nBooks in Database:\n");
    while (head != NULL) {
        printf("Title: %s, Author: %s, ISBN: %s\n", head->title, head->author, head->isbn);
        head = head->next;
    }
}

Book* searchBook(Book* head, const char* isbn) {
    while (head != NULL) {
        if (strcmp(head->isbn, isbn) == 0) {
            return head; // Found
        }
        head = head->next;
    }
    return NULL; // Not found
}

void freeMemory(Book* head) {
    while (head != NULL) {
        Book* temp = head;
        head = head->next;
        free(temp);
    }
}