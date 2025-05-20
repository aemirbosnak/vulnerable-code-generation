//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
/*
 * ebook_reader.c
 *
 * A simple ebook reader program in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK_NAME 100
#define MAX_PAGES 1000

struct book {
    char name[MAX_BOOK_NAME];
    int pages;
    char* content[MAX_PAGES];
};

void open_book(struct book* b) {
    printf("Enter the name of the book: ");
    scanf("%s", b->name);
    printf("Enter the number of pages in the book: ");
    scanf("%d", &b->pages);
    for (int i = 0; i < b->pages; i++) {
        b->content[i] = (char*)malloc(MAX_PAGES);
        printf("Enter the content of page %d: ", i + 1);
        scanf("%s", b->content[i]);
    }
}

void print_book(struct book* b) {
    printf("Name: %s\n", b->name);
    printf("Pages: %d\n", b->pages);
    for (int i = 0; i < b->pages; i++) {
        printf("Page %d: %s\n", i + 1, b->content[i]);
    }
}

void close_book(struct book* b) {
    for (int i = 0; i < b->pages; i++) {
        free(b->content[i]);
    }
}

int main() {
    struct book book;
    open_book(&book);
    print_book(&book);
    close_book(&book);
    return 0;
}