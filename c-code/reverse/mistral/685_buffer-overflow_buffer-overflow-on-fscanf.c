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
} Book;

int read_book(FILE *file, Book *books, int *num_books) {
    char line[200];
    if (fgets(line, sizeof(line), file) == NULL) return -1;
    sscanf(line, "%s %s %d", books[*num_books].title, books[*num_books].author, &books[*num_books].pages);
    (*num_books)++;
    return 0;
}

int search_book_by_title(Book books[], int num_books, char title[]) {
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) return i;
    }
    return -1;
}

int main() {
    FILE *file;
    char filename[100];
    int num_books = 0;
    Book books[100];

    printf("Enter the file name: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (read_book(file, books, &num_books) == 0) {}
    fclose(file);

    char title[100];
    printf("Enter the title to search for: ");
    scanf("%s", title);

    int index = search_book_by_title(books, num_books, title);
    if (index == -1) printf("Book not found.\n");
    else printf("Book found at index %d.\n", index);

    return 0;
}
