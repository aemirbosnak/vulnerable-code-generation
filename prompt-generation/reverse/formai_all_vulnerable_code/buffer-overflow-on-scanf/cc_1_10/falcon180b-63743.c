//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *author;
    int pages;
} book_t;

void add_book(book_t *books, int *count, char *name, char *author, int pages) {
    books = realloc(books, sizeof(book_t) * (*count + 1));
    if (books == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    books[*count].name = strdup(name);
    books[*count].author = strdup(author);
    books[*count].pages = pages;
    (*count)++;
}

void print_books(book_t *books, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s by %s (%d pages)\n", books[i].name, books[i].author, books[i].pages);
    }
}

int main() {
    book_t *books = NULL;
    int count = 0;
    char input[100];

    printf("Enter 'a' to add a book, 'p' to print the list, or 'q' to quit:\n");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "a") == 0) {
            char name[100], author[100];
            int pages;
            printf("Enter book name:\n");
            scanf("%s", name);
            printf("Enter author name:\n");
            scanf("%s", author);
            printf("Enter number of pages:\n");
            scanf("%d", &pages);
            add_book(books, &count, name, author, pages);
        } else if (strcmp(input, "p") == 0) {
            print_books(books, count);
        } else if (strcmp(input, "q") == 0) {
            exit(0);
        }
    }

    return 0;
}