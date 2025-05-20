//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 100

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    int pages;
} book;

book books[MAX_BOOKS];
int num_books;

void add_book() {
    printf("Enter book name: ");
    scanf("%s", books[num_books].name);
    printf("Enter book author: ");
    scanf("%s", books[num_books].author);
    printf("Enter number of pages: ");
    scanf("%d", &books[num_books].pages);
    num_books++;
}

void display_books() {
    printf("Book Name\tAuthor\tPages\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s\t%s\t%d\n", books[i].name, books[i].author, books[i].pages);
    }
}

int main() {
    printf("Welcome to the Ebook Reader!\n");
    printf("Please choose an option:\n");
    printf("1. Add a book\n");
    printf("2. Display books\n");
    printf("3. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add_book();
            break;
        case 2:
            display_books();
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}