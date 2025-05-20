//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: complex
/*
 * A complex C ebook reader example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures

typedef struct {
    char title[50];
    char author[50];
    char genre[50];
    int page_count;
    int year;
    float price;
} Book;

typedef struct {
    Book book;
    char filename[50];
    char filepath[50];
    char password[50];
} Ebook;

// Function prototypes

void read_book(Book *book);
void read_ebook(Ebook *ebook);
void write_book(Book *book);
void write_ebook(Ebook *ebook);

// Function definitions

void read_book(Book *book) {
    printf("Enter book title: ");
    scanf("%s", book->title);
    printf("Enter book author: ");
    scanf("%s", book->author);
    printf("Enter book genre: ");
    scanf("%s", book->genre);
    printf("Enter book page count: ");
    scanf("%d", &book->page_count);
    printf("Enter book year: ");
    scanf("%d", &book->year);
    printf("Enter book price: ");
    scanf("%f", &book->price);
}

void read_ebook(Ebook *ebook) {
    read_book(&ebook->book);
    printf("Enter ebook filename: ");
    scanf("%s", ebook->filename);
    printf("Enter ebook filepath: ");
    scanf("%s", ebook->filepath);
    printf("Enter ebook password: ");
    scanf("%s", ebook->password);
}

void write_book(Book *book) {
    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
    printf("Book genre: %s\n", book->genre);
    printf("Book page count: %d\n", book->page_count);
    printf("Book year: %d\n", book->year);
    printf("Book price: %.2f\n", book->price);
}

void write_ebook(Ebook *ebook) {
    write_book(&ebook->book);
    printf("Ebook filename: %s\n", ebook->filename);
    printf("Ebook filepath: %s\n", ebook->filepath);
    printf("Ebook password: %s\n", ebook->password);
}

int main() {
    Book book;
    Ebook ebook;

    read_book(&book);
    read_ebook(&ebook);

    write_book(&book);
    write_ebook(&ebook);

    return 0;
}