//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

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
    head = newBook;
    return head;
}

void searchBook(Book* head, char* title) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            printf("Book title: %s\n", currentBook->title);
            printf("Book author: %s\n", currentBook->author);
            printf("Book quantity: %d\n", currentBook->quantity);
            break;
        }
        currentBook = currentBook->next;
    }
    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

void updateBookQuantity(Book* head, char* title, int quantity) {
    Book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            currentBook->quantity = quantity;
            break;
        }
        currentBook = currentBook->next;
    }
    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

void deleteBook(Book* head, char* title) {
    Book* currentBook = head;
    Book* previousBook = NULL;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            if (previousBook) {
                previousBook->next = currentBook->next;
            } else {
                head = currentBook->next;
            }
            free(currentBook);
            break;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }
    if (currentBook == NULL) {
        printf("Book not found.\n");
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
            int quantity;
            printf("Enter book title: ");
            scanf("%s", title);
            printf("Enter new book quantity: ");
            scanf("%d", &quantity);
            updateBookQuantity(head, title, quantity);
        } else if (strcmp(command, "delete") == 0) {
            char title[50];
            printf("Enter book title: ");
            scanf("%s", title);
            deleteBook(head, title);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}