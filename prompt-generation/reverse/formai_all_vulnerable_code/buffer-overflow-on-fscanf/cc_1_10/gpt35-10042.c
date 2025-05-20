//FormAI DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define book data structure
typedef struct {
    char title[50];
    char author[50];
    char publisher[50];
    int num_pages;
    float price;
} Book;

// Define function to read book data from file
Book* read_books(char* filename, int* num_books) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read number of books from first line of file
    fscanf(fp, "%d\n", num_books);

    // Allocate memory for Book array
    Book* books = (Book*)malloc(sizeof(Book) * (*num_books));
    if (books == NULL) {
        printf("Error allocating memory for books\n");
        fclose(fp);
        return NULL;
    }

    // Read book data from file
    for (int i = 0; i < *num_books; i++) {
        fscanf(fp, "%[^,],%[^,],%[^,],%d,%f\n",
               books[i].title, books[i].author, books[i].publisher,
               &(books[i].num_pages), &(books[i].price));
    }

    fclose(fp);
    return books;
}

// Define function to print book data
void print_book(Book book) {
    printf("%s by %s, published by %s, %d pages, $%0.2f\n",
           book.title, book.author, book.publisher, book.num_pages, book.price);
}

// Define function to print all books in array
void print_books(Book* books, int num_books) {
    for (int i = 0; i < num_books; i++) {
        print_book(books[i]);
    }
}

// Define function to search for books by author
void search_books_by_author(Book* books, int num_books, char* author) {
    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].author, author) == 0) {
            print_book(books[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by %s\n", author);
    }
}

int main() {
    int num_books;
    Book* books = read_books("books.txt", &num_books);
    if (books == NULL) {
        return 1;
    }

    printf("All books:\n");
    print_books(books, num_books);

    printf("\nBooks by J.K. Rowling:\n");
    search_books_by_author(books, num_books, "J.K. Rowling");

    free(books);
    return 0;
}