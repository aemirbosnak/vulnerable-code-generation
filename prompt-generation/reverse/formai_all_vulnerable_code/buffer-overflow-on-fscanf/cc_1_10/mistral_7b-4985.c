//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
    int publication_year;
} Book;

void print_book(const Book* book) {
    printf("%s (%d)\n", book->title, book->publication_year);
}

void bubble_sort(Book books[], int n) {
    int i, j, temp_publication_year;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (books[j].publication_year > books[j + 1].publication_year) {
                temp_publication_year = books[j].publication_year;
                books[j].publication_year = books[j + 1].publication_year;
                books[j + 1].publication_year = temp_publication_year;

                char temp_title[50];
                strcpy(temp_title, books[j].title);
                strcpy(books[j].title, books[j + 1].title);
                strcpy(books[j + 1].title, temp_title);
            }
        }
    }
}

int main() {
    Book library[MAX_BOOKS];
    int num_books = 0;

    while (num_books < MAX_BOOKS && fscanf(stdin, "%s %d", library[num_books].title, &library[num_books].publication_year) != EOF) {
        num_books++;
    }

    if (num_books == 0) {
        printf("No books to sort.\n");
        return 0;
    }

    bubble_sort(library, num_books);

    printf("\nSorted library:\n");
    for (int i = 0; i < num_books; i++) {
        print_book(&library[i]);
    }

    return 0;
}