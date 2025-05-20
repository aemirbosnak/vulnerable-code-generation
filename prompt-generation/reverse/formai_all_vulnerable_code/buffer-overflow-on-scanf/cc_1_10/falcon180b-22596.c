//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 50

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    int pages;
} book;

book books[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Sorry, the library is full! ");
        return;
    }
    printf("Enter the name of the book: ");
    scanf("%s", books[num_books].name);
    printf("Enter the author of the book: ");
    scanf("%s", books[num_books].author);
    printf("Enter the number of pages: ");
    scanf("%d", &books[num_books].pages);
    num_books++;
    printf("Book added successfully! ");
}

void display_books() {
    if (num_books == 0) {
        printf("The library is empty! ");
        return;
    }
    printf("List of books in the library:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s (%d pages)\n", i+1, books[i].name, books[i].author, books[i].pages);
    }
}

int main() {
    printf("Welcome to the Happy Library! ");
    int choice;
    do {
        printf("\nWhat would you like to do? \n1. Add a book\n2. Display books\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                printf("Thank you for visiting the Happy Library! ");
                break;
            default:
                printf("Invalid choice! ");
        }
    } while (choice!= 3);
    return 0;
}