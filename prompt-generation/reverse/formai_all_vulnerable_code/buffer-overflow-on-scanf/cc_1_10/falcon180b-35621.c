//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LEN 50
#define MAX_BOOK_AUTHOR_LEN 50
#define MAX_BOOK_GENRE_LEN 50
#define MAX_BOOK_DESCRIPTION_LEN 200

typedef struct {
    char name[MAX_BOOK_NAME_LEN];
    char author[MAX_BOOK_AUTHOR_LEN];
    char genre[MAX_BOOK_GENRE_LEN];
    char description[MAX_BOOK_DESCRIPTION_LEN];
} Book;

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    printf("Welcome to the Cyberpunk Ebook Reader!\n\n");

    while(numBooks < MAX_BOOKS) {
        printf("Enter book name: ");
        scanf("%s", books[numBooks].name);

        printf("Enter book author: ");
        scanf("%s", books[numBooks].author);

        printf("Enter book genre: ");
        scanf("%s", books[numBooks].genre);

        printf("Enter book description: ");
        scanf("%s", books[numBooks].description);

        numBooks++;
    }

    printf("\nYour library contains the following books:\n");

    for(int i=0; i<numBooks; i++) {
        printf("Book #%d:\n", i+1);
        printf("Name: %s\n", books[i].name);
        printf("Author: %s\n", books[i].author);
        printf("Genre: %s\n", books[i].genre);
        printf("Description: %s\n\n", books[i].description);
    }

    return 0;
}