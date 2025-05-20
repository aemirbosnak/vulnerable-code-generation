//FormAI DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 1000

struct Book {
    char title[MAX_TITLE_SIZE];
    int pages;
    char author[MAX_TITLE_SIZE];
    char publisher[MAX_TITLE_SIZE];
};

void print_book(struct Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Publisher: %s\n", book.publisher);
    printf("Pages: %d\n", book.pages);
}

int main() {
    int num_books = 0;
    struct Book library[MAX_BOOKS];

    printf("Welcome to My C Ebook Reader!\n");

    char choice;
    do {
        printf("\nWould you like to:\n");
        printf("(a) Add a book\n");
        printf("(b) Print library\n");
        printf("(q) Quit\n");

        scanf(" %c", &choice);

        if (choice == 'a') {
            if (num_books < MAX_BOOKS) {
                printf("\nEnter book title: ");
                scanf(" %[^\n]s", library[num_books].title);

                printf("Enter book author: ");
                scanf(" %[^\n]s", library[num_books].author);

                printf("Enter book publisher: ");
                scanf(" %[^\n]s", library[num_books].publisher);

                printf("Enter number of pages: ");
                scanf("%d", &library[num_books].pages);

                num_books++;
                printf("Book added successfully!\n");
            }
            else {
                printf("\nLibrary is full, cannot add more books.\n");
            }
        }
        else if (choice == 'b') {
            if (num_books == 0) {
                printf("\nNo books in library.\n");
            }
            else {
                printf("\nLibrary contents: \n");
                for (int i = 0; i < num_books; i++) {
                    printf("%d. ", i+1);
                    print_book(library[i]);
                }
            }
        }
        else if (choice != 'q') {
            printf("\nInvalid choice, please try again.\n");
        }
    } while (choice != 'q');

    printf("\nThank you for using My C Ebook Reader! Goodbye.\n");
    return 0;
}