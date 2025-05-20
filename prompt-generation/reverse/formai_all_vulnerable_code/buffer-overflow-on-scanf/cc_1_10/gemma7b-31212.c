//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR 50

typedef struct Book
{
    char title[50];
    char author[50];
    int quantity;
} Book;

Book books[MAX_BOOKS];

void scan_book_info(Book *book)
{
    printf("Enter book title: ");
    scanf("%s", book->title);

    printf("Enter book author: ");
    scanf("%s", book->author);

    printf("Enter book quantity: ");
    scanf("%d", &book->quantity);
}

void update_book_quantity(Book *book, int quantity)
{
    book->quantity = quantity;
}

void print_book_list()
{
    int i = 0;
    for (i = 0; i < MAX_BOOKS && books[i].title[0] != '\0'; i++)
    {
        printf("%s by %s (Quantity: %d)\n", books[i].title, books[i].author, books[i].quantity);
    }
}

int main()
{
    Book book;
    scan_book_info(&book);
    update_book_quantity(&book, book.quantity + 1);
    print_book_list();

    return 0;
}