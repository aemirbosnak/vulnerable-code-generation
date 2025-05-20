#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int year;
} Book;

void readBooks(Book books[], int *count) {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    while (*count < MAX_BOOKS && fscanf(file, "%s %d", books[*count].title, &books[*count].year) != EOF) {
        (*count)++;
    }

    fclose(file);
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0;

    readBooks(books, &count);

    for (int i = 0; i < count; i++) {
        printf("Title: %s, Year: %d\n", books[i].title, books[i].year);
    }

    return 0;
}
