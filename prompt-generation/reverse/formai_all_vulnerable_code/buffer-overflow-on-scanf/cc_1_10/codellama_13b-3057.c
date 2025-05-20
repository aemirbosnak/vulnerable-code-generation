//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: peaceful
// Ebook reader program in a peaceful style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 256
#define MAX_BOOK_COUNT 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_TITLE_LEN];
    char genre[MAX_TITLE_LEN];
    int year;
    float price;
} Book;

void print_book(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Genre: %s\n", book.genre);
    printf("Year: %d\n", book.year);
    printf("Price: %.2f\n\n", book.price);
}

int main() {
    int book_count = 0;
    Book books[MAX_BOOK_COUNT];

    // Input books
    while (book_count < MAX_BOOK_COUNT) {
        Book book;
        printf("Enter book %d:\n", book_count + 1);
        printf("Title: ");
        scanf("%s", book.title);
        printf("Author: ");
        scanf("%s", book.author);
        printf("Genre: ");
        scanf("%s", book.genre);
        printf("Year: ");
        scanf("%d", &book.year);
        printf("Price: ");
        scanf("%f", &book.price);
        books[book_count] = book;
        book_count++;
    }

    // Print books
    printf("\nHere is the list of books:\n");
    for (int i = 0; i < book_count; i++) {
        print_book(books[i]);
    }

    return 0;
}