//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_BOOK_LENGTH 1000

typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    char text[MAX_BOOK_LENGTH];
} Book;

void read_book_file(const char* filename, Book* book) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (line_number == 0) {
            strcpy(book->title, line);
        } else if (line_number == 1) {
            strcpy(book->author, line);
        } else {
            strcat(book->text, line);
            strcat(book->text, "\n");
        }
        line_number++;
    }

    fclose(file);
}

void display_book_info(const Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
}

void display_book_text(const Book* book) {
    printf("Book text:\n%s", book->text);
}

int main() {
    Book book;
    char filename[MAX_LINE_LENGTH];

    printf("Enter the filename of the book: ");
    scanf("%s", filename);

    read_book_file(filename, &book);

    display_book_info(&book);
    display_book_text(&book);

    return 0;
}