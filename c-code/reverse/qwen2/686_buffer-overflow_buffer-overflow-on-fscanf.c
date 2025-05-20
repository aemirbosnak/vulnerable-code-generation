#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int year;
} Book;

void readBooks(Book books[], int *count) {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    while (fscanf(file, "%s %d", books[*count].title, &books[*count].year) != EOF && *count < MAX_BOOKS) {
        (*count)++;
    }
    fclose(file);
}

int searchBook(const Book books[], int count, const char *searchTitle) {
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
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
    printf("Enter book title to search: ");
    scanf("%s", searchTitle);

    int index = searchBook(books, count, searchTitle);
    if (index != -1) {
        printf("Book found: %s, Year: %d\n", books[index].title, books[index].year);
    } else {
        printf("Book not found\n");
    }

    return 0;
}
