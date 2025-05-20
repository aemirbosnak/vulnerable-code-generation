//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);
    newBook->next = head;
    return newBook;
}

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

void updateBookQuantity(Book* book, int quantity) {
    book->quantity = quantity;
}

void deleteBook(Book* head, Book* bookToDelete) {
    Book* currentBook = head;
    Book* previousBook = NULL;
    while (currentBook) {
        if (currentBook == bookToDelete) {
            if (previousBook) {
                previousBook->next = currentBook->next;
            } else {
                head = currentBook->next;
            }
            free(bookToDelete);
            return;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }
    return;
}

int main() {
    Book* head = NULL;
    head = insertBook(head);
    insertBook(head);
    insertBook(head);

    Book* book = searchBook(head, "Book 2");
    if (book) {
        updateBookQuantity(book, 10);
    }

    deleteBook(head, book);

    return 0;
}