#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int year;
} Book;

int main() {
    FILE *file = fopen("books.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    Book books[MAX_BOOKS];
    int count = 0;

    while (count < MAX_BOOKS && fscanf(file, "%s %d", books[count].title, &books[count].year) == 2) {
        count++;
    }

    fclose(file);

    char search_title[MAX_TITLE_LENGTH];
    printf("Enter title to search: ");
    scanf("%s", search_title);

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, search_title) == 0) {
            printf("Found: %s, Year: %d\n", books[i].title, books[i].year);
            break;
        }
    }

    return EXIT_SUCCESS;
}
