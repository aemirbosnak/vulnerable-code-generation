//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: intelligent
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

void displayBooks(Book* head) {
    Book* currentBook = head;
    while (currentBook) {
        printf("Title: %s\n", currentBook->title);
        printf("Author: %s\n", currentBook->author);
        printf("Quantity: %d\n", currentBook->quantity);
        printf("\n");
        currentBook = currentBook->next;
    }
}

void updateBookQuantity(Book* head, char* title, int newQuantity) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            currentBook->quantity = newQuantity;
            break;
        }
        currentBook = currentBook->next;
    }
}

int main() {
    Book* head = NULL;
    head = insertBook(head);
    insertBook(head);
    insertBook(head);
    displayBooks(head);
    updateBookQuantity(head, "Book 2", 10);
    displayBooks(head);

    return 0;
}