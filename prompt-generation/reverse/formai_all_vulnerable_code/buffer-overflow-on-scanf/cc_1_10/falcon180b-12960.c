//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

int main() {
    int numBooks, i;
    Book library[MAX_BOOKS];

    printf("Welcome to the Ebook Reader!\n");
    printf("How many books do you have in your library? ");
    scanf("%d", &numBooks);

    if (numBooks > MAX_BOOKS) {
        printf("Sorry, the library can only hold up to %d books.\n", MAX_BOOKS);
        return 1;
    }

    printf("Enter the details for each book:\n");

    for (i = 0; i < numBooks; i++) {
        printf("Book %d:\n", i+1);
        printf("Title: ");
        scanf("%s", library[i].title);

        printf("Author: ");
        scanf("%s", library[i].author);

        printf("Number of pages: ");
        scanf("%d", &library[i].pages);
    }

    printf("\nYour library:\n");
    for (i = 0; i < numBooks; i++) {
        printf("Book %d:\n", i+1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Pages: %d\n\n", library[i].pages);
    }

    return 0;
}