//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define MAX_BOOK_LEN 1000

typedef struct {
    char title[MAX_LINE_LEN];
    char author[MAX_LINE_LEN];
    char content[MAX_BOOK_LEN];
} Book;

Book* createBook(char* title, char* author, char* content) {
    Book* book = (Book*)malloc(sizeof(Book));

    strncpy(book->title, title, MAX_LINE_LEN);
    strncpy(book->author, author, MAX_LINE_LEN);

    int contentLen = strlen(content);
    if (contentLen > MAX_BOOK_LEN) {
        printf("Error: Content is too long.\n");
        exit(1);
    }

    strncpy(book->content, content, MAX_BOOK_LEN);

    return book;
}

void readBook(Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("\n");
    printf("%s", book->content);
}

int main() {
    char title[MAX_LINE_LEN];
    char author[MAX_LINE_LEN];
    char content[MAX_BOOK_LEN];

    printf("Enter book title: ");
    scanf("%s", title);

    printf("Enter book author: ");
    scanf("%s", author);

    printf("Enter book content:\n");
    fgets(content, MAX_BOOK_LEN, stdin);
    content[strcspn(content, "\n")] = '\0';

    Book* book = createBook(title, author, content);
    readBook(book);

    free(book);

    return 0;
}