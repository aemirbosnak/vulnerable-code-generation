//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK_SIZE 1000000
#define MAX_LINE_SIZE 1000

typedef struct {
    char *title;
    char *author;
    char *content;
    int content_size;
} Book;

Book *read_book_from_file(FILE *fp) {
    Book *book = malloc(sizeof(Book));
    char line[MAX_LINE_SIZE];
    char *token;
    int content_size = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (line[0] == '#') {
            token = strtok(line, ":");
            if (token!= NULL) {
                if (strcmp(token, "title") == 0) {
                    book->title = strdup(strtok(NULL, ":"));
                } else if (strcmp(token, "author") == 0) {
                    book->author = strdup(strtok(NULL, ":"));
                }
            }
        } else {
            content_size += strlen(line);
            book->content = realloc(book->content, content_size + 1);
            strcat(book->content, line);
        }
    }

    book->content_size = content_size;
    return book;
}

void print_book(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Content Size: %d\n", book->content_size);
    printf("Content:\n%s", book->content);
}

void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

int main() {
    FILE *fp;
    char filename[MAX_LINE_SIZE];
    Book *book;

    printf("Enter the name of the book file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    book = read_book_from_file(fp);
    if (book == NULL) {
        printf("Error: Invalid book format.\n");
        return 2;
    }

    print_book(book);
    free_book(book);

    fclose(fp);
    return 0;
}