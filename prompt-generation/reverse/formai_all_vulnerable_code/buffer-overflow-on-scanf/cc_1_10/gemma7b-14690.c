//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 50

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

typedef struct Member {
    char name[50];
    char email[50];
    struct Member* next;
} Member;

Book* insertBook(Book* head);
Member* insertMember(Member* head);

int main() {
    Book* bookHead = NULL;
    Member* memberHead = NULL;

    // Multiplayer functionality
    printf("Welcome to the Music Library Management System!\n");
    printf("Please select an option:\n");
    printf("1. Register a new book\n");
    printf("2. Register a new member\n");
    printf("3. Search for a book\n");
    printf("4. Search for a member\n");
    printf("5. Exit\n");

    int choice = 0;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertBook(bookHead);
            break;
        case 2:
            insertMember(memberHead);
            break;
        case 3:
            // Search for book
            break;
        case 4:
            // Search for member
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

Book* insertBook(Book* head) {
    Book* newNode = (Book*)malloc(sizeof(Book));

    printf("Enter the book title: ");
    scanf("%s", newNode->title);

    printf("Enter the book author: ");
    scanf("%s", newNode->author);

    printf("Enter the book quantity: ");
    scanf("%d", &newNode->quantity);

    newNode->next = head;
    head = newNode;

    return head;
}

Member* insertMember(Member* head) {
    Member* newNode = (Member*)malloc(sizeof(Member));

    printf("Enter the member name: ");
    scanf("%s", newNode->name);

    printf("Enter the member email: ");
    scanf("%s", newNode->email);

    newNode->next = head;
    head = newNode;

    return head;
}