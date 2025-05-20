//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* title;
    char* author;
    int num_pages;
} Book;

char* read_line(FILE* fp) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    getline(&line, &len, fp);

    if (line == NULL) {
        fprintf(stderr, "Error: failed to read line.\n");
        exit(EXIT_FAILURE);
    }

    return line;
}

Book* create_book(char* title, char* author, int num_pages) {
    Book* book = malloc(sizeof(Book));

    if (book == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for book.\n");
        exit(EXIT_FAILURE);
    }

    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;

    return book;
}

void print_book(Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of Pages: %d\n", book->num_pages);
}

int main() {
    FILE* fp = fopen("books.txt", "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: failed to open books.txt.\n");
        exit(EXIT_FAILURE);
    }

    char* line = read_line(fp);

    while (line!= NULL) {
        char* title = strtok(line, ",");
        char* author = strtok(NULL, ",");
        int num_pages = atoi(strtok(NULL, ","));

        Book* book = create_book(title, author, num_pages);
        print_book(book);

        free(book->title);
        free(book->author);
        free(book);

        line = read_line(fp);
    }

    fclose(fp);

    return 0;
}