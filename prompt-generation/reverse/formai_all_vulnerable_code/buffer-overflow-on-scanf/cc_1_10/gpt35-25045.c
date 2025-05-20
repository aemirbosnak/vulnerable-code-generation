//FormAI DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_PUBLISHER_LENGTH 30

typedef struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char publisher[MAX_PUBLISHER_LENGTH];
    int yearPublished;
    float price;
} Book;

// function for printing book details
void print_book(Book b) {
    printf("\nTitle: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Publisher: %s\n", b.publisher);
    printf("Year Published: %d\n", b.yearPublished);
    printf("Price: $%.2f\n", b.price);
}

int main() {
    // array of books
    Book library[5] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", 1925, 10.99},
        {"To Kill a Mockingbird", "Harper Lee", "J. B. Lippincott & Co.", 1960, 12.99},
        {"1984", "George Orwell", "Secker & Warburg", 1949, 8.99},
        {"The Catcher in the Rye", "J. D. Salinger", "Little, Brown and Company", 1951, 6.99},
        {"Pride and Prejudice", "Jane Austen", "T. Egerton, Whitehall", 1813, 9.99}
    };

    char user_input[MAX_TITLE_LENGTH];
    int book_found = 0;

    while (1) {
        printf("Enter the title of the book you would like to read: ");
        scanf("%s", user_input);

        // iterate through library to find user-input book
        for (int i = 0; i < 5; i++) {
            if (strcmp(user_input, library[i].title) == 0) {
                print_book(library[i]);
                book_found = 1;
                break;
            }
        }

        if (!book_found) {
            printf("Sorry, we do not have that book in our library.\n");
        }

        // ask user if they want to continue reading
        char yn_input;
        printf("\nWould you like to continue reading? (y/n): ");
        scanf("%s", &yn_input);

        if (yn_input == 'n') {
            break;
        }

        // reset book_found flag
        book_found = 0;
    }

    printf("Thank you for using our Ebook reader!\n");

    return 0;
}