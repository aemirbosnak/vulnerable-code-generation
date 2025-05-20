//FormAI DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char* author;
    int num_pages;
    float price;
} Book;

void print_book(Book* book) {
    printf("\nTitle: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of Pages: %d\n", book->num_pages);
    printf("Price: $%.2f\n", book->price);
}

void print_all_books(Book** books, int num_books) {
    printf("\nAll books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n", i+1, books[i]->title, books[i]->author);
    }
    printf("\n");
}

void read_book_info(Book* book) {
    printf("Enter book title: ");
    gets(book->title);
    printf("Enter book author: ");
    char author_buffer[100];
    gets(author_buffer);
    book->author = malloc(strlen(author_buffer)+1);
    strcpy(book->author, author_buffer);
    printf("Enter number of pages: ");
    scanf("%d", &book->num_pages);
    printf("Enter book price: ");
    scanf("%f", &book->price);
}

int main() {
    Book* books[MAX_BOOKS];
    int num_books = 0;

    int choice = 1;
    while (choice != 0) {
        printf("\nWelcome to the Ebook reader program!\n");
        printf("1. Add a book\n");
        printf("2. View all books\n");
        printf("0. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (num_books >= MAX_BOOKS) {
                printf("Error: Maximum number of books reached!\n");
            } else {
                Book* new_book = malloc(sizeof(Book));
                read_book_info(new_book);
                books[num_books] = new_book;
                num_books++;
            }
        } else if (choice == 2) {
            if (num_books == 0) {
                printf("No books added yet!\n");
            } else {
                print_all_books(books, num_books);
                printf("Enter the number of the book you want to read: ");
                int selection;
                scanf("%d", &selection);
                getchar();
                if (selection < 1 || selection > num_books) {
                    printf("Error: Invalid selection!\n");
                } else {
                    print_book(books[selection-1]);
                }
            }
        } else if (choice == 0) {
            printf("Thank you for using the Ebook reader program!\n");
        } else {
            printf("Error: Invalid choice!\n");
        }
    }

    for (int i = 0; i < num_books; i++) {
        free(books[i]->author);
        free(books[i]);
    }

    return 0;
}