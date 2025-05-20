//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_PAGES 1000
#define MAX_WORDS 10000

typedef struct {
    char title[100];
    char author[100];
    int pages;
    char words[MAX_WORDS];
} Book;

int main() {
    int numBooks, i;
    char filename[100];
    Book books[MAX_BOOKS];

    printf("Enter the number of books: ");
    scanf("%d", &numBooks);

    for(i=0; i<numBooks; i++) {
        printf("Enter book %d title: ", i+1);
        scanf("%s", books[i].title);
        printf("Enter book %d author: ", i+1);
        scanf("%s", books[i].author);
        printf("Enter book %d pages: ", i+1);
        scanf("%d", &books[i].pages);

        printf("Enter words for book %d:\n", i+1);
        scanf("%[^\n]", books[i].words);
        books[i].words[strcspn(books[i].words, "\n")] = '\0';
    }

    printf("Enter the filename to save the books: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "wb");
    if(fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    for(i=0; i<numBooks; i++) {
        fwrite(&books[i], sizeof(Book), 1, fp);
    }

    fclose(fp);

    printf("Books saved to file %s\n", filename);

    return 0;
}