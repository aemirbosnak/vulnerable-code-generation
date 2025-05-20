//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_CHAPTER_LENGTH 10000

typedef struct {
    char title[MAX_WORD_LENGTH];
    char author[MAX_WORD_LENGTH];
    char genre[MAX_WORD_LENGTH];
    char summary[MAX_LINE_LENGTH];
    char content[MAX_CHAPTER_LENGTH];
} Book;

void loadBook(Book* book, FILE* file) {
    fscanf(file, "Title: %s\n", book->title);
    fscanf(file, "Author: %s\n", book->author);
    fscanf(file, "Genre: %s\n", book->genre);
    fscanf(file, "Summary: %s\n", book->summary);

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        strcat(book->content, buffer);
        strcat(book->content, "\n");
    }
}

void displayBook(Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Genre: %s\n", book->genre);
    printf("Summary: %s\n", book->summary);

    printf("\nContent:\n");
    printf("%s", book->content);
}

int main() {
    FILE* file = fopen("example.book", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Book book;
    loadBook(&book, file);
    fclose(file);

    displayBook(&book);

    return 0;
}