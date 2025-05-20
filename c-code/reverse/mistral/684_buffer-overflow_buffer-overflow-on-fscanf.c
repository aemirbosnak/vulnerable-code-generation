#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[50];
    int pages;
} Book;

void read_book(FILE *file, Book books[], int size) {
    for (int i = 0; i < size; ++i) {
        fscanf(file, "%s %s %d", books[i].title, books[i].author, &books[i].pages);
    }
}

int main() {
    FILE *file;
    char filename[100];
    int num_books;

    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    printf("Enter the number of books: ");
    scanf("%d", &num_books);

    Book books[num_books];
    read_book(file, books, num_books);

    fclose(file);

    return 0;
}
