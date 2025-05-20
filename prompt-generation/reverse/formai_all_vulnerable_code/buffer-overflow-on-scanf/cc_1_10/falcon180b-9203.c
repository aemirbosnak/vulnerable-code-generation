//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_PUBLISHER_LEN 50
#define MAX_YEAR_LEN 10

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char publisher[MAX_PUBLISHER_LEN];
    char year[MAX_YEAR_LEN];
    int pages;
} Book;

int main() {
    FILE *file;
    char filename[100];
    int numBooks = 0;
    Book books[MAX_BOOKS];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    while (fscanf(file, "%s %s %s %s %d", books[numBooks].title, books[numBooks].author, books[numBooks].publisher, books[numBooks].year, &books[numBooks].pages)!= EOF) {
        numBooks++;
        if (numBooks >= MAX_BOOKS) {
            printf("Error: too many books in file\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    printf("Enter a search query:\n");
    scanf("%s", filename);

    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strstr(books[i].title, filename)!= NULL || strstr(books[i].author, filename)!= NULL || strstr(books[i].publisher, filename)!= NULL || strstr(books[i].year, filename)!= NULL) {
            printf("%s\n", books[i].title);
            found = 1;
        }
    }

    if (!found) {
        printf("No results found\n");
    }

    return 0;
}