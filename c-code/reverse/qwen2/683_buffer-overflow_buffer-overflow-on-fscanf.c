#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_GENRE_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char genre[MAX_GENRE_LENGTH];
} Book;

void readCatalog(Book *catalog, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%s %s %d %s", catalog[*count].title, catalog[*count].author, &catalog[*count].pages, catalog[*count].genre) != EOF) {
        (*count)++;
    }
    fclose(file);
}

void displayCatalog(const Book *catalog, int count) {
    printf("Library Catalog:\n");
    for (int i = 0; i < count; i++) {
        printf("%s by %s, Pages: %d, Genre: %s\n", catalog[i].title, catalog[i].author, catalog[i].pages, catalog[i].genre);
    }
}

void searchByTitle(const Book *catalog, int count, const char *searchTitle) {
    printf("Search Results for '%s':\n", searchTitle);
    for (int i = 0; i < count; i++) {
        if (strcmp(catalog[i].title, searchTitle) == 0) {
            printf("%s by %s, Pages: %d, Genre: %s\n", catalog[i].title, catalog[i].author, catalog[i].pages, catalog[i].genre);
        }
    }
}

int main() {
    Book catalog[100];
    int count = 0;
    const char *filename = "books.txt";

    readCatalog(catalog, &count, filename);
    displayCatalog(catalog, count);

    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter title to search: ");
    scanf("%s", searchTitle);
    searchByTitle(catalog, count, searchTitle);

    return 0;
}
