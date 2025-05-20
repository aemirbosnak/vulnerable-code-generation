//FormAI DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 50
#define MAX_FILENAME 50

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
    char filename[MAX_FILENAME];
} Book;

void print_book(Book b) {
    printf("%s, written by %s in %d\n", b.title, b.author, b.year);
}

int main() {
    Book collection[MAX_BOOKS];
    int num_books = 0;
    char filename[MAX_FILENAME];

    printf("Welcome to Ebook Reader\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Load a book\n");
        printf("2. List all books\n");
        printf("3. Search for a book\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_books == MAX_BOOKS) {
                    printf("Cannot load more books. Collection is full.\n");
                    break;
                }

                printf("Enter the book title: ");
                scanf("%s", collection[num_books].title);

                printf("Enter the author: ");
                scanf("%s", collection[num_books].author);

                printf("Enter the year published: ");
                scanf("%d", &collection[num_books].year);

                printf("Enter the filename: ");
                scanf("%s", collection[num_books].filename);

                num_books++;
                break;

            case 2:
                printf("\nListing all books:\n");

                for (int i=0; i<num_books; i++) {
                    printf("%d. ", i+1);
                    print_book(collection[i]);
                }

                break;

            case 3:
                printf("Enter the book title to search: ");
                scanf("%s", filename);

                for (int i=0; i<num_books; i++) {
                    if (strcmp(collection[i].filename, filename) == 0) {
                        printf("\nThe book is found:");
                        print_book(collection[i]);
                        break;
                    } else {
                        printf("\nBook not found.");
                        break;
                    }
                }

                break;

            case 4:
                printf("Thank you for using Ebook Reader!\n");
                return 0;

            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}