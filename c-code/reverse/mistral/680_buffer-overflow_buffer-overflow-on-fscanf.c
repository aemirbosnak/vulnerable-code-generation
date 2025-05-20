#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int pages;
    char genre[50];
} Book;

int read_book(FILE *file, Book *books, int *num_books) {
    char title[100];
    char author[100];
    char genre[50];
    int pages;

    if (fscanf(file, "%s%s%d%s", title, author, &pages, genre) != 4)
        return 0;

    books[(*num_books)++] = (Book){ .title = title, .author = author, .pages = pages, .genre = genre };
    return 1;
}

int search_book(Book books[], int num_books, char *title) {
    for (int i = 0; i < num_books; ++i)
        if (strcmp(books[i].title, title) == 0)
            return i;

    return -1;
}

int main() {
    FILE *file = fopen("books.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    Book books[100];
    int num_books = 0;

    while (read_book(file, books, &num_books))
        ;

    fclose(file);

    char title[100];
    printf("Enter book title to search: ");
    scanf("%s", title);

    int index = search_book(books, num_books, title);
    if (index != -1)
        printf("Found: %s by %s\n", books[index].title, books[index].author);
    else
        printf("Not found\n");

    return 0;
}
