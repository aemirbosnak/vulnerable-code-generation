//FormAI DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOKS 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float price;
} Book;

int book_count = 0;
Book books[MAX_BOOKS];

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Error: Maximum number of books reached.\n");
        return;
    }

    Book new_book;

    printf("Enter the book's title: ");
    fgets(new_book.title, MAX_TITLE_LENGTH, stdin);

    printf("Enter the author's name: ");
    fgets(new_book.author, MAX_AUTHOR_LENGTH, stdin);

    printf("Enter the price: ");
    scanf("%f", &new_book.price);

    books[book_count] = new_book;
    book_count++;

    printf("Book added successfully!\n");
}

void display_books() {
    if (book_count == 0) {
        printf("No books to display.\n");
        return;
    }

    printf("Title\t\tAuthor\t\tPrice\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < book_count; i++) {
        printf("%s\t\t%s\t\t%.2f\n", books[i].title, books[i].author, books[i].price);
    }
}

int main() {
    int option;

    do {
        printf("\n\n*** Ebook Reader App ***\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &option);
        getchar();  // Consume the newline character left by scanf

        switch (option) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 3);

    return 0;
}