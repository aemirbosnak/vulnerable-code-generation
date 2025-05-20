//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_PAGES_PER_BOOK 1000
#define MAX_WORDS_PER_PAGE 1000
#define MAX_CHARACTERS_PER_WORD 50

typedef struct {
    char title[MAX_CHARACTERS_PER_WORD];
    int pages[MAX_PAGES_PER_BOOK];
    char words[MAX_WORDS_PER_PAGE][MAX_CHARACTERS_PER_WORD];
} book_t;

void read_book(book_t* book, FILE* file) {
    fscanf(file, "Book Title: %s\n", book->title);
    fscanf(file, "Number of pages: %d\n", &book->pages[0]);
    for (int i = 1; i < MAX_PAGES_PER_BOOK; i++) {
        fscanf(file, "Page %d: ", &book->pages[i]);
    }
    for (int i = 0; i < MAX_PAGES_PER_BOOK; i++) {
        for (int j = 0; j < MAX_WORDS_PER_PAGE; j++) {
            fscanf(file, "Word %d: %s\n", &j, book->words[i][j]);
        }
    }
}

void print_book(book_t* book) {
    printf("Book Title: %s\n", book->title);
    printf("Number of pages: %d\n", book->pages[0]);
    for (int i = 1; i < MAX_PAGES_PER_BOOK; i++) {
        printf("Page %d: ", book->pages[i]);
        for (int j = 0; j < MAX_WORDS_PER_PAGE; j++) {
            printf("%s ", book->words[i][j]);
        }
        printf("\n");
    }
}

int main() {
    book_t books[MAX_BOOKS];
    FILE* file = fopen("books.txt", "r");
    int num_books = 0;

    while (fscanf(file, "Book %d:\n", &num_books)!= EOF) {
        if (num_books >= MAX_BOOKS) {
            printf("Error: Too many books!\n");
            exit(1);
        }
        read_book(&books[num_books], file);
    }

    fclose(file);

    printf("Books:\n");
    for (int i = 0; i < num_books; i++) {
        print_book(&books[i]);
    }

    return 0;
}