//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK_SIZE 1000000
#define MAX_LINE_SIZE 500

typedef struct {
    char *title;
    char *author;
    char *content;
    int content_size;
} Book;

int read_book_from_file(FILE *fp, Book *book) {
    char line[MAX_LINE_SIZE];
    char *content = NULL;
    int content_size = 0;

    if (fgets(line, MAX_LINE_SIZE, fp) == NULL) {
        return -1;
    }

    book->title = strdup(line);

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        content_size += strlen(line);
        content = realloc(content, content_size + 1);
        strcat(content, line);
    }

    book->author = strdup(content);
    free(content);
    book->content_size = content_size;

    return 0;
}

void print_book_info(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Content size: %d bytes\n", book->content_size);
}

void print_book_content(Book *book) {
    printf("Content:\n%s\n", book->content);
}

int main() {
    FILE *fp;
    Book book;

    fp = fopen("example.book", "r");
    if (fp == NULL) {
        printf("Error: Failed to open book file.\n");
        return -1;
    }

    if (read_book_from_file(fp, &book)!= 0) {
        printf("Error: Failed to read book from file.\n");
        return -1;
    }

    print_book_info(&book);

    if (book.content_size > 0) {
        print_book_content(&book);
    }

    free(book.title);
    free(book.author);
    free(book.content);

    fclose(fp);

    return 0;
}