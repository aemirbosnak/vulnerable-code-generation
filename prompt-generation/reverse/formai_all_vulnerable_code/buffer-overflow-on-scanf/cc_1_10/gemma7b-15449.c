//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
    struct Book* next;
} Book;

Book* insertBook(Book* head) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book genre: ");
    scanf("%s", newBook->genre);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    return head;
}

void searchBook(Book* head) {
    char searchTitle[50];
    printf("Enter book title: ");
    scanf("%s", searchTitle);

    Book* temp = head;
    while (temp) {
        if (strcmp(searchTitle, temp->title) == 0) {
            printf("Book title: %s\n", temp->title);
            printf("Book author: %s\n", temp->author);
            printf("Book genre: %s\n", temp->genre);
            printf("Book quantity: %d\n", temp->quantity);
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    Book* head = NULL;

    while (1) {
        printf("1. Insert Book\n");
        printf("2. Search Book\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertBook(head);
                break;
            case 2:
                searchBook(head);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}