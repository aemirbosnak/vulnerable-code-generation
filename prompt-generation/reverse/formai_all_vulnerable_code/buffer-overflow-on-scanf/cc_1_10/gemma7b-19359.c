//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of books in the library
#define NUM_BOOKS 100

// Define the book structure
typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

// Function to insert a book into the library
void insertBook(Book* head) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);

    newBook->next = head;
    head = newBook;
}

// Function to search for a book in the library
Book* searchBook(Book* head, char* title) {
    Book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }

    return NULL;
}

// Function to update the quantity of a book
void updateQuantity(Book* book, int newQuantity) {
    book->quantity = newQuantity;
}

// Function to delete a book from the library
void deleteBook(Book* head, char* title) {
    Book* previousBook = NULL;
    Book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            if (previousBook) {
                previousBook->next = currentBook->next;
            } else {
                head = currentBook->next;
            }
            free(currentBook);
            return;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }

    return;
}

// Main function
int main() {
    Book* head = NULL;

    // Insert some books into the library
    insertBook(head);
    insertBook(head);
    insertBook(head);

    // Search for a book in the library
    Book* book = searchBook(head, "The Lord of the Flies");
    if (book) {
        printf("Book title: %s\n", book->title);
        printf("Book author: %s\n", book->author);
        printf("Book quantity: %d\n", book->quantity);
    } else {
        printf("Book not found.\n");
    }

    // Update the quantity of a book
    updateQuantity(book, 10);

    // Delete a book from the library
    deleteBook(head, "The Lord of the Flies");

    return 0;
}