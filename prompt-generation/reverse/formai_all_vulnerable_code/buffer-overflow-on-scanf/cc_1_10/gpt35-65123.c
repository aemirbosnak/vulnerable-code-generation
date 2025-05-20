//FormAI DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
    char author[50];
    int year;
    char contents[1000];
} Book;

void print_book(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
}

void print_menu() {
    printf("\n1) List all books\n");
    printf("2) Add a book\n");
    printf("3) Read a book\n");
    printf("4) Exit\n\n");
}

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("List of all books:\n");
                for (int i = 0; i < num_books; i++) {
                    print_book(books[i]);
                }
                break;
            case 2:
                printf("Enter the title: ");
                scanf("%s", books[num_books].title);
                printf("Enter the author: ");
                scanf("%s", books[num_books].author);
                printf("Enter the year: ");
                scanf("%d", &books[num_books].year);
                printf("Enter the contents (max 1000 characters): ");
                scanf("%s", books[num_books].contents);
                num_books++;
                break;
            case 3:
                if (num_books == 0) {
                    printf("There are no books to read.\n");
                    break;
                }

                printf("Enter the title of the book you want to read: ");
                char title[50];
                scanf("%s", title);

                for (int i = 0; i < num_books; i++) {
                    if (strcmp(title, books[i].title) == 0) {
                        printf("The contents of %s:\n", title);
                        printf("%s\n", books[i].contents);
                        break;
                    } else if (i == num_books - 1) {
                        printf("Book not found.\n");
                    }
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}