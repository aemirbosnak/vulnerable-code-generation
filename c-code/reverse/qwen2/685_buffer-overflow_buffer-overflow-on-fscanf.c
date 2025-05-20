#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int year;
} Book;

void readBooks(Book books[], int *count) {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    while (fgets(books[*count].title, MAX_TITLE_LENGTH, file) != NULL && *count < MAX_BOOKS) {
        fscanf(file, "%d\n", &books[*count].year);
        (*count)++;
    }
    fclose(file);
}

int searchBookByTitle(const Book books[], int count, const char *title) {
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    readBooks(books, &count);

    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title to search: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';

    int index = searchBookByTitle(books, count, searchTitle);
    if (index != -1) {
        printf("Found book: %s, Year: %d\n", books[index].title, books[index].year);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}
