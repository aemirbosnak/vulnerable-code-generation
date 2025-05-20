//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
} Book;

int main() {
    int numBooks = 0;
    Book library[MAX_BOOKS];

    // Initialize the library with some books
    library[numBooks++] = (Book) {.title = "Harry Potter and the Philosopher's Stone",
                                 .author = "J.K. Rowling",
                                 .pages = 223 };
    library[numBooks++] = (Book) {.title = "The Hobbit",
                                  .author = "J.R.R. Tolkien",
                                  .pages = 366 };

    // Print the library
    printf("Library:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s (%d pages)\n", i+1, library[i].title, library[i].author, library[i].pages);
    }

    // Search for a book
    char searchTitle[MAX_TITLE_LEN];
    printf("\nEnter the title of the book you want to search: ");
    scanf("%s", searchTitle);

    int foundBook = -1;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            foundBook = i;
            break;
        }
    }

    if (foundBook!= -1) {
        printf("\n%s was found in the library.\n", searchTitle);
    } else {
        printf("\n%s was not found in the library.\n", searchTitle);
    }

    return 0;
}