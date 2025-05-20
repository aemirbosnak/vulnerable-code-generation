//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME 100
#define MAX_BOOK_AUTHOR 100
#define MAX_BOOK_GENRE 100
#define MAX_BOOK_SUMMARY 1000

typedef struct {
    char name[MAX_BOOK_NAME];
    char author[MAX_BOOK_AUTHOR];
    char genre[MAX_BOOK_GENRE];
    char summary[MAX_BOOK_SUMMARY];
} book;

int main() {
    int num_books = 0;
    book books[MAX_BOOKS];

    while (num_books < MAX_BOOKS) {
        printf("Enter book name: ");
        scanf("%s", books[num_books].name);

        printf("Enter author name: ");
        scanf("%s", books[num_books].author);

        printf("Enter book genre: ");
        scanf("%s", books[num_books].genre);

        printf("Enter book summary: ");
        scanf("%s", books[num_books].summary);

        num_books++;
    }

    printf("Enter the name of the book you want to read: ");
    char book_name[MAX_BOOK_NAME];
    scanf("%s", book_name);

    int book_index = -1;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].name, book_name) == 0) {
            book_index = i;
            break;
        }
    }

    if (book_index == -1) {
        printf("Book not found.\n");
    } else {
        printf("Book found.\n");
        printf("Book name: %s\n", books[book_index].name);
        printf("Author name: %s\n", books[book_index].author);
        printf("Genre: %s\n", books[book_index].genre);
        printf("Summary: %s\n", books[book_index].summary);
    }

    return 0;
}