//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_SIZE 1000000
#define MAX_BOOK_TITLE 100

typedef struct {
    char title[MAX_BOOK_TITLE];
    char content[MAX_BOOK_SIZE];
} Book;

void read_book(Book *book) {
    printf("Reading book: %s\n", book->title);
    printf("Content:\n%s\n", book->content);
}

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;

    while (num_books < MAX_BOOKS) {
        printf("Enter title of book (leave blank to stop): ");
        char title[MAX_BOOK_TITLE];
        scanf("%s", title);

        if (strlen(title) == 0) {
            break;
        }

        printf("Enter content of book:\n");
        char content[MAX_BOOK_SIZE];
        fgets(content, MAX_BOOK_SIZE, stdin);
        content[strcspn(content, "\n")] = '\0';

        books[num_books] = (Book) {
           .title = strdup(title),
           .content = strdup(content)
        };
        num_books++;
    }

    printf("Number of books: %d\n", num_books);

    for (int i = 0; i < num_books; i++) {
        read_book(&books[i]);
    }

    for (int i = 0; i < num_books; i++) {
        free(books[i].title);
        free(books[i].content);
    }

    return 0;
}