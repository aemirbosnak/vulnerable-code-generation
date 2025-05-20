//FormAI DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a book
struct Book {
    char title[100];
    char author[100];
    int year;
    float price;
};

// Array to hold all books in the library
struct Book library[100];
int numBooks = 0;

// Function to add a book to the library
void addBook() {
    struct Book newBook;

    // Get book details from user input
    printf("Enter book title: ");
    scanf("%s", newBook.title);

    printf("Enter book author: ");
    scanf("%s", newBook.author);

    printf("Enter book year: ");
    scanf("%d", &newBook.year);

    printf("Enter book price: ");
    scanf("%f", &newBook.price);

    // Add the book to the library
    library[numBooks] = newBook;
    numBooks++;

    printf("Book added to library.\n");
}

// Function to display all books in the library
void displayAllBooks() {
    if(numBooks == 0) {
        printf("No books in library.\n");
        return;
    }

    printf("All books in library:\n\n");
    for(int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n", library[i].year);
        printf("Price: %.2f\n\n", library[i].price);
    }
}

// Function to display books by a specific author
void displayBooksByAuthor() {
    char author[100];

    printf("Enter author name: ");
    scanf("%s", author);

    printf("Books by author %s:\n\n", author);
    int found = 0;
    for(int i = 0; i < numBooks; i++) {
        if(strcmp(library[i].author, author) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Year: %d\n", library[i].year);
            printf("Price: %.2f\n\n", library[i].price);
            found = 1;
        }
    }
    if(!found) {
        printf("No books found for author %s.\n", author);
    }
}

// Main function to handle user input and menu options
int main() {
    char choice = ' ';

    printf("Welcome to the Medieval Library!\n");

    while(choice != 'q') {
        printf("\nPlease choose an option:\n");
        printf("a) Add a book\n");
        printf("b) Display all books\n");
        printf("c) Display books by author\n");
        printf("q) Quit\n");

        scanf(" %c", &choice);

        switch(choice) {
            case 'a':
                addBook();
                break;
            case 'b':
                displayAllBooks();
                break;
            case 'c':
                displayBooksByAuthor();
                break;
            case 'q':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}