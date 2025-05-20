//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 100

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    int pages;
    int year;
} Book;

int main() {
    int numBooks;
    Book books[MAX_BOOKS];

    // Read in number of books
    printf("Enter number of books: ");
    scanf("%d", &numBooks);

    // Read in book information
    for (int i = 0; i < numBooks; i++) {
        printf("Enter book %d information:\n", i + 1);
        printf("Name: ");
        scanf("%s", books[i].name);
        printf("Author: ");
        scanf("%s", books[i].author);
        printf("Pages: ");
        scanf("%d", &books[i].pages);
        printf("Year: ");
        scanf("%d", &books[i].year);
    }

    // Sort books by year
    for (int i = 0; i < numBooks - 1; i++) {
        for (int j = i + 1; j < numBooks; j++) {
            if (books[i].year > books[j].year) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

    // Print book information
    printf("Book information:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s (%d pages, %d)\n", i + 1, books[i].name, books[i].author, books[i].pages, books[i].year);
    }

    return 0;
}