//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Book* insertBook(Book* head, char* title, char* author, int quantity) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->next = head;
    head = newBook;
    return head;
}

Member* insertMember(Member* head, char* name, char* email) {
    Member* newMember = (Member*)malloc(sizeof(Member));
    strcpy(newMember->name, name);
    strcpy(newMember->email, email);
    newMember->next = head;
    head = newMember;
    return head;
}

int main() {
    Book* books = NULL;
    Member* members = NULL;

    // Multiplayer functionality
    // Here, you can add code to handle multiple clients connecting and interacting with the system

    // Example commands
    printf("Enter command: ");
    char command[50];
    scanf("%s", command);

    // Check if command is to add a book
    if (strcmp(command, "add book") == 0) {
        char title[50];
        char author[50];
        int quantity;
        printf("Enter book title: ");
        scanf("%s", title);
        printf("Enter book author: ");
        scanf("%s", author);
        printf("Enter book quantity: ");
        scanf("%d", &quantity);
        insertBook(books, title, author, quantity);
    }

    // Check if command is to add a member
    else if (strcmp(command, "add member") == 0) {
        char name[50];
        char email[50];
        printf("Enter member name: ");
        scanf("%s", name);
        printf("Enter member email: ");
        scanf("%s", email);
        insertMember(members, name, email);
    }

    return 0;
}