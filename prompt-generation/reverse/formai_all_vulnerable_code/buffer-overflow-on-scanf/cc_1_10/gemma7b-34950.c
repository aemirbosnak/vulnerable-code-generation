//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: recursive
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

    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        head = insertBook(head);
    }

    return head;
}

void searchBook(Book* head, char* title) {
    if (head == NULL) {
        printf("Book not found.\n");
        return;
    }

    if (strcmp(head->title, title) == 0) {
        printf("Book found: \n");
        printf("Title: %s\n", head->title);
        printf("Author: %s\n", head->author);
        printf("Quantity: %d\n", head->quantity);
    } else {
        searchBook(head->next, title);
    }
}

void updateBookQuantity(Book* head, char* title, int newQuantity) {
    if (head == NULL) {
        printf("Book not found.\n");
        return;
    }

    if (strcmp(head->title, title) == 0) {
        head->quantity = newQuantity;
        printf("Book quantity updated.\n");
    } else {
        updateBookQuantity(head->next, title, newQuantity);
    }
}

void deleteBook(Book* head, char* title) {
    if (head == NULL) {
        printf("Book not found.\n");
        return;
    }

    if (strcmp(head->title, title) == 0) {
        Book* temp = head;
        head = head->next;
        free(temp);
        printf("Book deleted.\n");
    } else {
        deleteBook(head->next, title);
    }
}

int main() {
    Book* head = NULL;

    while (1) {
        printf("Enter command (add, search, update, delete, exit): ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            head = insertBook(head);
        } else if (strcmp(command, "search") == 0) {
            char title[50];
            printf("Enter book title: ");
            scanf("%s", title);
            searchBook(head, title);
        } else if (strcmp(command, "update") == 0) {
            char title[50];
            int newQuantity;
            printf("Enter book title: ");
            scanf("%s", title);
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            updateBookQuantity(head, title, newQuantity);
        } else if (strcmp(command, "delete") == 0) {
            char title[50];
            printf("Enter book title: ");
            scanf("%s", title);
            deleteBook(head, title);
        } else if (strcmp(command, "exit") == 0) {
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}