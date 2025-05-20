#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int pages;
} Book;

int read_book(FILE *file, Book *book) {
    if (fscanf(file, "%s %s %d", book->title, book->author, &book->pages) != 3)
        return 0;
    return 1;
}

int main(int argc, char *argv[]) {
    FILE *file;
    Book book;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while (read_book(file, &book)) {
        printf("Title: %s\nAuthor: %s\nPages: %d\n", book.title, book.author, book.pages);
    }

    fclose(file);
    return 0;
}
