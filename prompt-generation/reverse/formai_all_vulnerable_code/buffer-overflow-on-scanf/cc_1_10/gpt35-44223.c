//FormAI DATASET v1.0 Category: Ebook reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50

typedef struct {
    char title[100];
    char author[50];
    int pages;
    double price;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int num_books;
} Library;

void read_book(Book *book);
void display_book(Book book);
void add_book(Library *lib, Book book);
void browse_books(Library lib);
void load_library(Library *lib, char *filename);
void save_library(Library lib, char *filename);

int main() {
    Library lib;
    lib.num_books = 0;
    char filename[50];

    // Load existing library from file
    printf("Enter filename to load from: ");
    scanf("%s", filename);
    load_library(&lib, filename);

    // Show library
    browse_books(lib);

    // Add a book
    printf("\nAdding a book...\n");
    Book new_book;
    read_book(&new_book);
    add_book(&lib, new_book);
    printf("\nNew book added to library.\n");

    // Show updated library
    browse_books(lib);

    // Save library to file
    printf("\nSaving library to file...\n");
    printf("Enter filename to save to: ");
    scanf("%s", filename);
    save_library(lib, filename);
    printf("Library saved to file.\n");

    return 0;
}

void read_book(Book *book) {
    printf("Enter book title: ");
    scanf(" %[^\n]s", book->title);  // Notice the space before %[^\n]s
    printf("Enter book author: ");
    scanf(" %[^\n]s", book->author);
    printf("Enter number of pages: ");
    scanf("%d", &book->pages);
    printf("Enter book price: ");
    scanf("%lf", &book->price);
}

void display_book(Book book) {
    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
    printf("Price: $%.2lf\n", book.price);
}

void add_book(Library *lib, Book book) {
    if (lib->num_books == MAX_BOOKS) {
        printf("Cannot add book. Library is full.\n");
        return;
    }
    lib->books[lib->num_books++] = book;
}

void browse_books(Library lib) {
    printf("\nBooks in library:\n");
    if (lib.num_books == 0) {
        printf("None.\n");
        return;
    }
    for (int i = 0; i < lib.num_books; i++) {
        printf("%d. ", i+1);
        display_book(lib.books[i]);
    }
}

void load_library(Library *lib, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }
    fread(&lib->num_books, sizeof(int), 1, fp);
    fread(&lib->books, sizeof(Book), lib->num_books, fp);
    fclose(fp);
    printf("Library loaded successfully from file.\n");
}

void save_library(Library lib, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }
    fwrite(&lib.num_books, sizeof(int), 1, fp);
    fwrite(&lib.books, sizeof(Book), lib.num_books, fp);
    fclose(fp);
}