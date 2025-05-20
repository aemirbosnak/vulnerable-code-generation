//FormAI DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a structure to represent a book
typedef struct {
    char title[50];
    char author[50];
    char publisher[50];
    int year;
    double price;
    char isbn[20];
    char format[10];
    int pages;
    char language[20];
} Book;

// function to display the details of a book
void display_book(Book b) {
    printf("\nTitle: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Publisher: %s\n", b.publisher);
    printf("Year: %d\n", b.year);
    printf("Price: $%.2f\n", b.price);
    printf("ISBN: %s\n", b.isbn);
    printf("Format: %s\n", b.format);
    printf("Pages: %d\n", b.pages);
    printf("Language: %s\n", b.language);
}

// function to read the details of a book from file
Book read_book_from_file(FILE* fp) {
    Book b;
    fscanf(fp, "%s %s %s %d %lf %s %s %d %s", b.title, b.author, b.publisher, &b.year, &b.price, b.isbn, b.format, &b.pages, b.language);
    return b;
}

int main() {
    char filename[50];
    printf("Enter the name of the E-book file: ");
    scanf("%s", filename);

    // open the file for reading
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // read the number of books in the file
    int num_books;
    fscanf(fp, "%d", &num_books);

    // allocate memory for the array of books
    Book* books = (Book*) malloc(num_books * sizeof(Book));

    // read each book from the file
    for(int i = 0; i < num_books; i++) {
        books[i] = read_book_from_file(fp);
    }

    // close the file
    fclose(fp);

    // display the details of each book
    for(int i = 0; i < num_books; i++) {
        display_book(books[i]);
    }

    // free the memory allocated for the array of books
    free(books);

    return 0;
}