//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of books in the library
#define MAX_BOOKS 100

// Define the book structure
struct book {
    char title[50];
    char author[50];
    int quantity;
    struct book* next;
};

// Function to insert a book into the library
void insertBook(struct book** head) {
    struct book* newBook = (struct book*)malloc(sizeof(struct book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);
    newBook->next = NULL;

    if (*head == NULL) {
        *head = newBook;
    } else {
        (*head)->next = newBook;
    }
}

// Function to search for a book in the library
struct book* searchBook(struct book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to update book quantity
void updateBookQuantity(struct book* head, char* title, int quantity) {
    struct book* book = searchBook(head, title);
    if (book) {
        book->quantity = quantity;
    }
}

// Function to delete a book from the library
void deleteBook(struct book* head, char* title) {
    struct book* book = searchBook(head, title);
    if (book) {
        struct book* prevBook = NULL;
        while (book->next) {
            prevBook = book;
            book = book->next;
        }
        if (prevBook) {
            prevBook->next = book->next;
        } else {
            head = book->next;
        }
        free(book);
    }
}

int main() {
    struct book* head = NULL;

    // Insert some books into the library
    insertBook(&head);
    insertBook(&head);
    insertBook(&head);

    // Search for a book in the library
    struct book* book = searchBook(head, "Book 2");
    if (book) {
        printf("Book title: %s\n", book->title);
        printf("Book author: %s\n", book->author);
        printf("Book quantity: %d\n", book->quantity);
    }

    // Update book quantity
    updateBookQuantity(head, "Book 2", 10);

    // Search for the updated book quantity
    book = searchBook(head, "Book 2");
    if (book) {
        printf("Book quantity: %d\n", book->quantity);
    }

    // Delete a book from the library
    deleteBook(head, "Book 2");

    // Search for the book after deletion
    book = searchBook(head, "Book 2");
    if (book) {
        printf("Error: Book not found.\n");
    } else {
        printf("Book successfully deleted.\n");
    }

    return 0;
}