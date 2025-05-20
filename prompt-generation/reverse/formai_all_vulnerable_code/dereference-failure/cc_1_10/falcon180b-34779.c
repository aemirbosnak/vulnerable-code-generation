//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOK_LENGTH 1000000

typedef struct {
    char *title;
    char *author;
    char *text;
    int length;
} EBook;

int read_book(FILE *file, EBook *book) {
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    book->title = NULL;
    book->author = NULL;
    book->text = NULL;
    book->length = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        line_number++;

        if (line_number == 1) {
            char *title_start = strstr(line, "title:");
            if (title_start!= NULL) {
                title_start += strlen("title:");
                book->title = malloc(strlen(title_start) + 1);
                strcpy(book->title, title_start);
            }
        } else if (line_number == 2) {
            char *author_start = strstr(line, "author:");
            if (author_start!= NULL) {
                author_start += strlen("author:");
                book->author = malloc(strlen(author_start) + 1);
                strcpy(book->author, author_start);
            }
        } else {
            book->text = realloc(book->text, book->length + strlen(line) + 1);
            strcat(book->text, line);
            book->length += strlen(line);
        }
    }

    return 0;
}

int main() {
    EBook book;
    FILE *file = fopen("example.ebook", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_book(file, &book);

    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Text:\n%s", book.text);

    fclose(file);
    free(book.title);
    free(book.author);
    free(book.text);

    return 0;
}