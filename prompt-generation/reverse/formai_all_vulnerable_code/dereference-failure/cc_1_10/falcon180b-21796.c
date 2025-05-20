//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_BOOK_PAGES 100

typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    int num_pages;
    char *text;
} Ebook;

int main() {
    Ebook book;

    printf("Enter the title of the ebook: ");
    scanf("%s", book.title);

    printf("Enter the author of the ebook: ");
    scanf("%s", book.author);

    printf("Enter the number of pages: ");
    scanf("%d", &book.num_pages);

    book.text = (char *) malloc(book.num_pages * MAX_LINE_LENGTH);

    if (book.text == NULL) {
        printf("Error: could not allocate memory for ebook text.\n");
        exit(1);
    }

    printf("Enter the ebook text:\n");

    for (int i = 0; i < book.num_pages; i++) {
        fgets(book.text + i * MAX_LINE_LENGTH, MAX_LINE_LENGTH, stdin);
    }

    printf("Reading ebook...\n");

    for (int page = 0; page < book.num_pages; page++) {
        printf("Page %d:\n", page + 1);
        printf("%s\n", book.text + page * MAX_LINE_LENGTH);
    }

    free(book.text);

    return 0;
}