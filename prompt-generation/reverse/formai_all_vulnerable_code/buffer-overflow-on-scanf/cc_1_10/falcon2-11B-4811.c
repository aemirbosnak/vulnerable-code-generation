//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct e_book {
    char title[100];
    char author[100];
    char language[100];
    char genre[100];
    int pages;
    int price;
    char publisher[100];
    char isbn[20];
};

struct e_book* create_book() {
    struct e_book* new_book = (struct e_book*)malloc(sizeof(struct e_book));
    if (new_book == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for new book.\n");
        return NULL;
    }
    new_book->title[0] = '\0';
    new_book->author[0] = '\0';
    new_book->language[0] = '\0';
    new_book->genre[0] = '\0';
    new_book->pages = 0;
    new_book->price = 0;
    new_book->publisher[0] = '\0';
    new_book->isbn[0] = '\0';
    return new_book;
}

void read_book(struct e_book* book) {
    printf("Enter the book's title: ");
    scanf("%s", book->title);
    printf("Enter the book's author: ");
    scanf("%s", book->author);
    printf("Enter the book's language: ");
    scanf("%s", book->language);
    printf("Enter the book's genre: ");
    scanf("%s", book->genre);
    printf("Enter the book's pages: ");
    scanf("%d", &book->pages);
    printf("Enter the book's price: ");
    scanf("%d", &book->price);
    printf("Enter the book's publisher: ");
    scanf("%s", book->publisher);
    printf("Enter the book's ISBN: ");
    scanf("%s", book->isbn);
}

void print_book(struct e_book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Language: %s\n", book->language);
    printf("Genre: %s\n", book->genre);
    printf("Pages: %d\n", book->pages);
    printf("Price: $%.2f\n", (double)book->price / 100.0);
    printf("Publisher: %s\n", book->publisher);
    printf("ISBN: %s\n", book->isbn);
}

int main() {
    struct e_book* book = create_book();
    read_book(book);
    print_book(book);
    free(book);
    return 0;
}