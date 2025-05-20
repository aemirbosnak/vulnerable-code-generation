//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head, Book* newBook);
Book* searchBook(Book* head, char* title);
Book* deleteBook(Book* head, char* title);

int main() {
    Book* head = NULL;
    Book* newBook = NULL;
    char title[50];
    char author[50];
    int quantity;

    while (1) {
        printf("Enter command (add, search, delete, exit): ");
        scanf("%s", title);

        if (strcmp(title, "exit") == 0) {
            break;
        }

        switch (title[0]) {
            case 'a':
                printf("Enter book title: ");
                scanf("%s", author);
                printf("Enter book quantity: ");
                scanf("%d", &quantity);

                newBook = malloc(sizeof(Book));
                strcpy(newBook->title, author);
                newBook->quantity = quantity;
                newBook->next = NULL;

                insertBook(head, newBook);
                break;
            case 's':
                printf("Enter book title: ");
                scanf("%s", title);

                newBook = searchBook(head, title);

                if (newBook) {
                    printf("Book title: %s\n", newBook->title);
                    printf("Book author: %s\n", newBook->author);
                    printf("Book quantity: %d\n", newBook->quantity);
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 'd':
                printf("Enter book title: ");
                scanf("%s", title);

                newBook = deleteBook(head, title);

                if (newBook) {
                    printf("Book title: %s\n", newBook->title);
                    printf("Book author: %s\n", newBook->author);
                    printf("Book quantity: %d\n", newBook->quantity);
                } else {
                    printf("Book not found.\n");
                }
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}

Book* insertBook(Book* head, Book* newBook) {
    if (head == NULL) {
        head = newBook;
    } else {
        newBook->next = head;
        head = newBook;
    }

    return head;
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

Book* deleteBook(Book* head, char* title) {
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
            return currentBook;
        }

        previousBook = currentBook;
        currentBook = currentBook->next;
    }

    return NULL;
}