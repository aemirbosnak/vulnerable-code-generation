//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char title[100];
    char author[100];
    char *pages;
    int num_pages;
} Book;

void read_file(FILE *fp, Book *book) {
    fseek(fp, 0, SEEK_SET); // Reset file pointer to the beginning
    fscanf(fp, "%s %s", book->title, book->author);
    book->num_pages = (int) ceil(ftell(fp) / 100.0); // Calculate number of pages based on file size
    rewind(fp); // Reset file pointer to the beginning
    book->pages = malloc(book->num_pages * 100);
    int i;
    for (i = 0; i < book->num_pages; i++) {
        fgets(book->pages + i * 100, 100, fp);
    }
}

void display_book(Book book) {
    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);
    int i;
    for (i = 0; i < book.num_pages; i++) {
        printf("\nPage %d:\n", i + 1);
        int j;
        for (j = 0; j < strlen(book.pages + i * 100); j++) {
            if (book.pages[i * 100 + j] == '\n') {
                printf("\n");
                j++;
                break;
            }
            printf("%c", book.pages[i * 100 + j]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ebook_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    Book book;
    read_file(fp, &book);
    display_book(book);

    free(book.pages);
    fclose(fp);
    return 0;
}