//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BOOKS 10
#define MAX_BOOK_NAME_LENGTH 50
#define MAX_BOOK_AUTHOR_LENGTH 50
#define MAX_BOOK_GENRE_LENGTH 50

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    char genre[MAX_BOOK_GENRE_LENGTH];
    bool is_read;
} Book;

void add_book(Book* books, int index) {
    printf("Enter book name: ");
    scanf("%s", books[index].name);

    printf("Enter book author: ");
    scanf("%s", books[index].author);

    printf("Enter book genre: ");
    scanf("%s", books[index].genre);

    books[index].is_read = false;
}

void display_books(Book* books) {
    printf("Book Name\tAuthor\tGenre\tRead\n");
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (books[i].is_read) {
            printf("%s\t%s\t%s\tYes\n", books[i].name, books[i].author, books[i].genre);
        } else {
            printf("%s\t%s\t%s\tNo\n", books[i].name, books[i].author, books[i].genre);
        }
    }
}

int main() {
    Book books[MAX_BOOKS];

    for (int i = 0; i < MAX_BOOKS; i++) {
        add_book(books, i);
    }

    int choice;
    do {
        printf("\n1. Display books\n2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_books(books);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 2);

    return 0;
}