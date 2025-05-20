//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

int main() {
    char input[100];
    int choice, book_index;
    Book books[MAX_BOOKS];
    int num_books = 0;

    printf("Welcome to the Ebook Reader!\n");

    while (1) {
        printf("\nPlease enter your choice:\n");
        printf("1. Add a book\n2. Display all books\n3. Search for a book\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_books >= MAX_BOOKS) {
                printf("You have reached the maximum number of books.\n");
            } else {
                printf("Enter the title of the book:\n");
                scanf("%s", books[num_books].title);

                printf("Enter the author of the book:\n");
                scanf("%s", books[num_books].author);

                printf("Enter the number of pages:\n");
                scanf("%d", &books[num_books].pages);

                num_books++;
            }
            break;

        case 2:
            printf("\nList of all books:\n");
            for (book_index = 0; book_index < num_books; book_index++) {
                printf("%d. Title: %s\nAuthor: %s\nPages: %d\n", book_index + 1, books[book_index].title, books[book_index].author, books[book_index].pages);
            }
            break;

        case 3:
            printf("\nEnter the title of the book to search for:\n");
            scanf("%s", input);

            for (book_index = 0; book_index < num_books; book_index++) {
                if (strcmp(input, books[book_index].title) == 0) {
                    printf("\nBook found:\n");
                    printf("Title: %s\nAuthor: %s\nPages: %d\n", books[book_index].title, books[book_index].author, books[book_index].pages);
                }
            }
            break;

        case 4:
            printf("\nExiting Ebook Reader...\n");
            exit(0);

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}