//FormAI DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the maximum number of books the program can handle
#define MAX_BOOKS 100

//Define a struct to hold information about each book
typedef struct {
    char title[50];
    char author[30];
    char genre[20];
    float price;
    int pages;
} Book;

//Function to read a book from a file and return it as a Book struct
Book read_book(FILE *file) {
    Book book;
    fscanf(file, "%s %s %s %f %d", book.title, book.author, book.genre, &book.price, &book.pages);
    return book;
}

//Function to print out a book's details
void print_book(Book book) {
    printf("Title: %s\nAuthor: %s\nGenre: %s\nPrice: %.2f\nPages: %d\n", book.title, book.author, book.genre, book.price, book.pages);
}

int main() {
    //Open the file and check for errors
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    //Read the books from the file and store them in an array of Book structs
    Book books[MAX_BOOKS];
    int num_books = 0;
    while (!feof(file) && num_books < MAX_BOOKS) {
        books[num_books] = read_book(file);
        num_books++;
    }

    //Close the file
    fclose(file);

    //Print out the details of each book in the array
    for (int i = 0; i < num_books; i++) {
        printf("Book %d:\n", i+1);
        print_book(books[i]);
        printf("\n");
    }

    return 0;
}