//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct book {
    char title[20];
    char author[20];
    int quantity;
    struct book* next;
};

void insertBook(struct book** head) {
    struct book* newBook = malloc(sizeof(struct book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter author's name: ");
    scanf("%s", newBook->author);
    printf("Enter quantity: ");
    scanf("%d", &newBook->quantity);
    newBook->next = NULL;

    if (*head == NULL) {
        *head = newBook;
    } else {
        (*head)->next = newBook;
    }
}

void searchBook(struct book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            printf("Book found: \n");
            printf("Title: %s\n", head->title);
            printf("Author: %s\n", head->author);
            printf("Quantity: %d\n", head->quantity);
            return;
        }
        head = head->next;
    }

    printf("Book not found.\n");
}

int main() {
    struct book* head = NULL;

    insertBook(&head);
    insertBook(&head);
    insertBook(&head);

    searchBook(head, "Book 2");

    return 0;
}