//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char* content;
} Book;

void load_book(FILE* fp, Book* book) {
    fscanf(fp, "%s %s %d\n", book->title, book->author, &book->pages);
    book->content = (char*)malloc(book->pages * sizeof(char));
    fread(book->content, sizeof(char), book->pages, fp);
}

void save_book(FILE* fp, Book* book) {
    fprintf(fp, "%s %s %d\n", book->title, book->author, book->pages);
    fwrite(book->content, sizeof(char), book->pages, fp);
}

int main() {
    FILE* fp = fopen("books.dat", "rb");
    if (fp == NULL) {
        printf("Error: books.dat not found.\n");
        return 1;
    }

    Book books[MAX_BOOKS];
    int num_books = 0;

    while (num_books < MAX_BOOKS && fgetc(fp)!= EOF) {
        if (num_books >= MAX_BOOKS) {
            printf("Error: too many books.\n");
            return 2;
        }

        Book* book = &books[num_books];
        load_book(fp, book);
        num_books++;
    }

    fclose(fp);

    char input[MAX_TITLE_LENGTH];
    while (1) {
        printf("Enter book title to search: ");
        fgets(input, MAX_TITLE_LENGTH, stdin);

        int i;
        for (i = 0; i < num_books; i++) {
            if (strcmp(books[i].title, input) == 0) {
                printf("Book found:\n");
                printf("Title: %s\n", books[i].title);
                printf("Author: %s\n", books[i].author);
                printf("Pages: %d\n", books[i].pages);

                char ch;
                while ((ch = getc(stdin))!= '\n') {
                    if (ch == 'q') {
                        return 0;
                    }
                }

                break;
            }
        }

        if (i == num_books) {
            printf("Book not found.\n");
        }
    }

    return 0;
}