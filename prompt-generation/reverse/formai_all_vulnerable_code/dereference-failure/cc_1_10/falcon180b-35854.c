//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define the structure of a book */
typedef struct {
    char title[100];
    char author[100];
    int pages;
} Book;

/* Function prototypes */
void printBook(Book book);
Book* readBook(FILE* file);
int main() {
    FILE* file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    Book* book = readBook(file);
    fclose(file);
    printBook(*book);
    return 0;
}

/* Read a book from a file */
Book* readBook(FILE* file) {
    Book* book = malloc(sizeof(Book));
    book->title[0] = '\0';
    book->author[0] = '\0';
    book->pages = 0;
    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (line[0] == '\0') {
            continue;
        }
        if (strncmp(line, "Title:", 6) == 0) {
            strcpy(book->title, line + 7);
        } else if (strncmp(line, "Author:", 7) == 0) {
            strcpy(book->author, line + 8);
        } else if (strncmp(line, "Pages:", 7) == 0) {
            book->pages = atoi(line + 8);
        }
    }
    return book;
}

/* Print a book */
void printBook(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
}