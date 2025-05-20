//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_TITLE_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 50
#define MAX_BOOK_GENRE_LENGTH 20
#define MAX_BOOK_DESCRIPTION_LENGTH 200

typedef struct {
    char title[MAX_BOOK_TITLE_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    char genre[MAX_BOOK_GENRE_LENGTH];
    char description[MAX_BOOK_DESCRIPTION_LENGTH];
} book;

int main() {
    int numBooks = 0;
    book books[MAX_BOOKS];

    while(numBooks < MAX_BOOKS) {
        printf("Enter book title (or 'q' to quit): ");
        scanf("%s", books[numBooks].title);

        if(strcmp(books[numBooks].title, "q") == 0) {
            break;
        }

        printf("Enter book author: ");
        scanf("%s", books[numBooks].author);

        printf("Enter book genre: ");
        scanf("%s", books[numBooks].genre);

        printf("Enter book description: ");
        scanf("%s", books[numBooks].description);

        numBooks++;
    }

    printf("Number of books: %d\n", numBooks);

    for(int i = 0; i < numBooks; i++) {
        printf("Book %d:\n");
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Genre: %s\n", books[i].genre);
        printf("Description: %s\n\n", books[i].description);
    }

    return 0;
}