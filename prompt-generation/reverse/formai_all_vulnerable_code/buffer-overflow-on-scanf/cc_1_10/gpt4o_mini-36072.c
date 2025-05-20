//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 50
#define TITLE_LENGTH 50
#define NAME_LENGTH 30

typedef struct {
    char title[TITLE_LENGTH];
    char author[TITLE_LENGTH];
    int id;
    int is_checked_out;
} Book;

typedef struct {
    char name[NAME_LENGTH];
    int id;
} Member;

Book* books[MAX_BOOKS];
Member* members[MAX_MEMBERS];
int book_count = 0;
int member_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Can't add more books.\n");
        return;
    }
    
    Book* new_book = (Book*)malloc(sizeof(Book));
    printf("Enter Book Title: ");
    scanf(" %[^\n]s", new_book->title);
    printf("Enter Book Author: ");
    scanf(" %[^\n]s", new_book->author);
    new_book->id = book_count + 1;
    new_book->is_checked_out = 0;

    books[book_count++] = new_book;
    printf("Book added successfully! ID: %d\n", new_book->id);
}

void add_member() {
    if (member_count >= MAX_MEMBERS) {
        printf("Too many members! Can't add more.\n");
        return;
    }

    Member* new_member = (Member*)malloc(sizeof(Member));
    printf("Enter Member Name: ");
    scanf(" %[^\n]s", new_member->name);
    new_member->id = member_count + 1;

    members[member_count++] = new_member;
    printf("Member added successfully! ID: %d\n", new_member->id);
}

void list_books() {
    printf("=== Available Books ===\n");
    for (int i = 0; i < book_count; i++) {
        if (!books[i]->is_checked_out) {
            printf("ID: %d | Title: %s | Author: %s\n", books[i]->id, books[i]->title, books[i]->author);
        }
    }
}

void checkout_book() {
    int book_id;
    printf("Enter Book ID to checkout: ");
    scanf("%d", &book_id);
    
    if(book_id <= 0 || book_id > book_count || books[book_id - 1]->is_checked_out) {
        printf("Invalid Book ID or Book already checked out!\n");
        return;
    }

    books[book_id - 1]->is_checked_out = 1;
    printf("You have checked out: %s\n", books[book_id - 1]->title);
}

void return_book() {
    int book_id;
    printf("Enter Book ID to return: ");
    scanf("%d", &book_id);
    
    if(book_id <= 0 || book_id > book_count || !books[book_id - 1]->is_checked_out) {
        printf("Invalid Book ID or Book wasn't checked out!\n");
        return;
    }

    books[book_id - 1]->is_checked_out = 0;
    printf("You have returned: %s\n", books[book_id - 1]->title);
}

void list_members() {
    printf("=== Registered Members ===\n");
    for (int i = 0; i < member_count; i++) {
        printf("ID: %d | Name: %s\n", members[i]->id, members[i]->name);
    }
}

void menu() {
    int choice;

    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Add Member\n");
        printf("3. List Books\n");
        printf("4. List Members\n");
        printf("5. Checkout Book\n");
        printf("6. Return Book\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_book(); break;
            case 2: add_member(); break;
            case 3: list_books(); break;
            case 4: list_members(); break;
            case 5: checkout_book(); break;
            case 6: return_book(); break;
            case 0: exit(0);
            default: printf("Invalid option! Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Library Management System!\n");
    menu();
    
    // Free allocated memory
    for (int i = 0; i < book_count; i++) {
       free(books[i]);
    }
    for (int i = 0; i < member_count; i++) {
       free(members[i]);
    }

    return 0;
}