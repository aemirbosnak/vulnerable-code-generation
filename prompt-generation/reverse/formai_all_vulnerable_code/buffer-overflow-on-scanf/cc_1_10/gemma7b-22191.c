//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct book {
    char title[50];
    char author[50];
    int quantity;
    struct book* next;
};

struct book* insertBook(struct book* head) {
    struct book* newBook = (struct book*)malloc(sizeof(struct book));
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
        head->next = newBook;
    }

    return head;
}

struct book* searchBook(struct book* head, char* title) {
    struct book* currentBook = head;

    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            return currentBook;
        }
        currentBook = currentBook->next;
    }

    return NULL;
}

void updateBookQuantity(struct book* book, int quantity) {
    book->quantity = quantity;
}

void deleteBook(struct book* head, struct book* bookToDelete) {
    struct book* currentBook = head;
    struct book* previousBook = NULL;

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
    struct book* head = NULL;

    while (1) {
        printf("Enter command (add, search, update, delete): ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            head = insertBook(head);
        } else if (strcmp(command, "search") == 0) {
            char title[50];
            printf("Enter book title: ");
            scanf("%s", title);
            struct book* book = searchBook(head, title);
            if (book) {
                printf("Book found: \n");
                printf("Title: %s\n", book->title);
                printf("Author: %s\n", book->author);
                printf("Quantity: %d\n", book->quantity);
            } else {
                printf("Book not found.\n");
            }
        } else if (strcmp(command, "update") == 0) {
            char title[50];
            printf("Enter book title: ");
            scanf("%s", title);
            struct book* book = searchBook(head, title);
            if (book) {
                printf("Enter new book quantity: ");
                int quantity;
                scanf("%d", &quantity);
                updateBookQuantity(book, quantity);
                printf("Book quantity updated.\n");
            } else {
                printf("Book not found.\n");
            }
        } else if (strcmp(command, "delete") == 0) {
            char title[50];
            printf("Enter book title: ");
            scanf("%s", title);
            struct book* bookToDelete = searchBook(head, title);
            if (bookToDelete) {
                deleteBook(head, bookToDelete);
                printf("Book deleted.\n");
            } else {
                printf("Book not found.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}