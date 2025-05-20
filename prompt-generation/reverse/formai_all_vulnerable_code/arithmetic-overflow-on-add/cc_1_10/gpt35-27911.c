//FormAI DATASET v1.0 Category: Ebook reader ; Style: complex
// include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 50

// define structs
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_TITLE_LENGTH];
    int pages;
    float price;
} Book;

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int num_books;
    Book books[MAX_BOOKS];
} Ebook;

// function declarations
void display_menu();
void add_book(Ebook *ebook);
void view_library(Ebook *ebook);
void read_book(Ebook *ebook);

// main function
int main() {

    // initialize empty ebook library
    Ebook ebook = {"My Ebook Library", 0, {}};

    // display menu and handle user input until they quit
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book(&ebook);
                break;
            case 2:
                view_library(&ebook);
                break;
            case 3:
                read_book(&ebook);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// function definitions
void display_menu() {
    printf("\nMenu:\n");
    printf("1. Add book to library\n");
    printf("2. View library\n");
    printf("3. Read book\n");
    printf("4. Quit\n");
    printf("Enter choice: ");
}

void add_book(Ebook *ebook) {
    // prompt user for book information
    printf("\nEnter book title: ");
    fgets(ebook->books[ebook->num_books].title, MAX_TITLE_LENGTH, stdin);
    printf("Enter book author: ");
    fgets(ebook->books[ebook->num_books].author, MAX_TITLE_LENGTH, stdin);
    printf("Enter number of pages: ");
    scanf("%d", &ebook->books[ebook->num_books].pages);
    printf("Enter book price: ");
    scanf("%f", &ebook->books[ebook->num_books].price);
    getchar(); // consume newline left in stdin

    // increment number of books in ebook
    ebook->num_books++;

    // give confirmation to user
    printf("\nBook added to library!\n");
}

void view_library(Ebook *ebook) {
    // print header
    printf("\nBook library:\n");

    if (ebook->num_books == 0) {
        printf("No books in library.\n");
    } else {
        // loop through each book and print its information
        for (int i = 0; i < ebook->num_books; i++) {
            printf("\nTitle: %s", ebook->books[i].title);
            printf("Author: %s", ebook->books[i].author);
            printf("Pages: %d\n", ebook->books[i].pages);
            printf("Price: $%.2f\n", ebook->books[i].price);
        }
    }
}

void read_book(Ebook *ebook) {
    // print header
    printf("\nRead book:\n");

    if (ebook->num_books == 0) {
        printf("No books in library.\n");
    } else {
        // loop through each book and print its title
        for (int i = 0; i < ebook->num_books; i++) {
            printf("%d. %s", i+1, ebook->books[i].title);
        }

        // prompt user for book number and print its information
        int book_num;
        printf("\nEnter book number: ");
        scanf("%d", &book_num);
        getchar(); // consume newline left in stdin

        if (book_num > 0 && book_num <= ebook->num_books) {
            printf("Title: %s", ebook->books[book_num-1].title);
            printf("Author: %s", ebook->books[book_num-1].author);
            printf("Pages: %d\n", ebook->books[book_num-1].pages);
            printf("Price: $%.2f\n", ebook->books[book_num-1].price);
        } else {
            printf("Invalid book number.\n");
        }
    }
}