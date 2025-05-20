//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: genius
/*
 * Ebook reader example program in a genius style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[50];
    char author[50];
    char genre[50];
    int pages;
    char *content;
};

struct book *create_book(char *title, char *author, char *genre, int pages, char *content) {
    struct book *new_book = malloc(sizeof(struct book));
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    strcpy(new_book->genre, genre);
    new_book->pages = pages;
    new_book->content = malloc(strlen(content) + 1);
    strcpy(new_book->content, content);
    return new_book;
}

void display_book(struct book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Genre: %s\n", book->genre);
    printf("Pages: %d\n", book->pages);
    printf("Content: %s\n", book->content);
}

void edit_book(struct book *book, char *new_content) {
    strcpy(book->content, new_content);
}

void delete_book(struct book *book) {
    free(book->content);
    free(book);
}

int main() {
    struct book *book = create_book("The Alchemist", "Paulo Coelho", "Fantasy", 300, "The story of a shepherd boy who follows his dreams.");
    display_book(book);
    edit_book(book, "The story of a shepherd boy who follows his dreams and becomes a famous writer.");
    display_book(book);
    delete_book(book);
    return 0;
}