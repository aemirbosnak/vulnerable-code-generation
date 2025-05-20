#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int pages;
} Book;

int main() {
    FILE *file;
    Book books[100];
    int num_books = 0;

    file = fopen("books.txt", "r");

    while (fscanf(file, "%s %s %d", books[num_books].title, books[num_books].author, &books[num_books].pages) != EOF) {
        num_books++;
    }

    char search_title[100];
    printf("Enter title to search: ");
    scanf("%s", search_title);

    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, search_title) == 0) {
            printf("Title: %s\nAuthor: %s\nPages: %d\n", books[i].title, books[i].author, books[i].pages);
            return 0;
        }
    }

    printf("Book not found.\n");
    return 0;
}
