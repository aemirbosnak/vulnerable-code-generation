//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>

// define the structure of a book
typedef struct {
    char title[100];
    char author[100];
    int num_pages;
    char genre[50];
} Book;

// function to display the details of a book
void display_book(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Number of Pages: %d\n", book.num_pages);
    printf("Genre: %s\n", book.genre);
}

// function to read a book
void read_book(Book book) {
    printf("You are about to read %s by %s.\n", book.title, book.author);
    printf("This book is %d pages long and is in the %s genre.\n", book.num_pages, book.genre);
    printf("Enjoy your reading!\n");
}

int main() {
    // create an array of books
    Book books[] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", 180, "Fiction"},
        {"To Kill a Mockingbird", "Harper Lee", 281, "Fiction"},
        {"1984", "George Orwell", 328, "Dystopian"},
        {"Pride and Prejudice", "Jane Austen", 279, "Romance"}
    };

    // number of books in the array
    int num_books = sizeof(books)/sizeof(books[0]);

    // loop through all the books and display their details
    for(int i=0; i<num_books; i++) {
        display_book(books[i]);
    }

    // ask the user which book they want to read
    int choice;
    printf("Which book would you like to read?\n");
    for(int i=0; i<num_books; i++) {
        printf("%d. %s by %s\n", i+1, books[i].title, books[i].author);
    }
    scanf("%d", &choice);

    // read the chosen book
    read_book(books[choice-1]);

    return 0;
}