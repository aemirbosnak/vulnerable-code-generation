//FormAI DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>

// Define a struct for the book
struct Book {
    char title[50];
    char author[50];
    int pages;
    float rating;
    char format[50];
};

int main() {
    // Create an array of books
    struct Book library[3];

    // Add book 1 to the array
    strcpy(library[0].title, "The Alchemist");
    strcpy(library[0].author, "Paulo Coelho");
    library[0].pages = 208;
    library[0].rating = 4.3;
    strcpy(library[0].format, "PDF");

    // Add book 2 to the array
    strcpy(library[1].title, "The Hunger Games");
    strcpy(library[1].author, "Suzanne Collins");
    library[1].pages = 374;
    library[1].rating = 4.2;
    strcpy(library[1].format, "EPUB");

    // Add book 3 to the array
    strcpy(library[2].title, "The Lord of the Rings");
    strcpy(library[2].author, "J.R.R. Tolkien");
    library[2].pages = 1178;
    library[2].rating = 4.6;
    strcpy(library[2].format, "MOBI");

    // Display the library
    printf("Welcome to the Ebook Library!\n\n");
    for(int i = 0; i < 3; i++) {
        printf("Book %d\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Pages: %d\n", library[i].pages);
        printf("Rating: %.1f\n", library[i].rating);
        printf("Format: %s\n\n", library[i].format);
    }

    // Prompt user to select a book to read
    printf("Please enter the number of the book you wish to read: ");
    int bookNum;
    scanf("%d", &bookNum);

    // Check if book number is valid
    if(bookNum < 1 || bookNum > 3) {
        printf("Invalid book number!");
    } 
    else {
        // Read selected book
        printf("Opening your Ebook Reader...\n\n");
        printf("You have selected \"%s\" by %s\n", library[bookNum - 1].title, library[bookNum - 1].author);
        printf("Enjoy reading in %s format!\n", library[bookNum - 1].format);
    }

    return 0;
}