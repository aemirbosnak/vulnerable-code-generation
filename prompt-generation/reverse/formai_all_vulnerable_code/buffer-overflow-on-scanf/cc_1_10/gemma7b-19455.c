//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 10

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

typedef struct Member {
    char name[50];
    char email[50];
    int membership_id;
    struct Member* next;
} Member;

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

Member* insertMember(Member* head) {
    Member* newMember = (Member*)malloc(sizeof(Member));
    printf("Enter member name: ");
    scanf("%s", newMember->name);
    printf("Enter member email: ");
    scanf("%s", newMember->email);
    printf("Enter membership id: ");
    scanf("%d", &newMember->membership_id);
    newMember->next = head;
    head = newMember;
    return head;
}

void searchBook(Book* head) {
    char title[50];
    printf("Enter book title: ");
    scanf("%s", title);
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

void searchMember(Member* head) {
    char name[50];
    printf("Enter member name: ");
    scanf("%s", name);
    Member* currentMember = head;
    while (currentMember) {
        if (strcmp(currentMember->name, name) == 0) {
            printf("Member name: %s\n", currentMember->name);
            printf("Member email: %s\n", currentMember->email);
            printf("Membership id: %d\n", currentMember->membership_id);
            break;
        }
        currentMember = currentMember->next;
    }
    if (currentMember == NULL) {
        printf("Member not found.\n");
    }
}

int main() {
    Book* bookHead = NULL;
    Member* memberHead = NULL;

    // Insert some books and members
    insertBook(bookHead);
    insertBook(bookHead);
    insertMember(memberHead);
    insertMember(memberHead);

    // Search for a book
    searchBook(bookHead);

    // Search for a member
    searchMember(memberHead);

    return 0;
}