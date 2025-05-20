//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_GENRE_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int pages;
} Book;

int main() {
    Book library[MAX_BOOKS];
    int numBooks = 0;

    FILE *fp = fopen("library.txt", "r");
    if (fp == NULL) {
        printf("Error opening library file.\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char title[MAX_TITLE_LENGTH];
        char author[MAX_AUTHOR_LENGTH];
        char genre[MAX_GENRE_LENGTH];
        int pages;

        sscanf(line, "%s %s %s %d", title, author, genre, &pages);

        strcpy(library[numBooks].title, title);
        strcpy(library[numBooks].author, author);
        strcpy(library[numBooks].genre, genre);
        library[numBooks].pages = pages;

        numBooks++;
    }

    fclose(fp);

    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter a book title to search for: ");
    scanf("%s", searchTitle);

    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Genre: %s\n", library[i].genre);
            printf("Pages: %d\n", library[i].pages);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    return 0;
}