//FormAI DATASET v1.0 Category: Ebook reader ; Style: visionary
#include<stdio.h>
#include<string.h>

// Define the maximum length of the book title and author name
#define MAX_LENGTH 50

// Define the structure for storing information about the book
struct Book {
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    int pages;
    float price;
};

int main() {
    // Declare an array of Book structures to hold multiple books
    struct Book library[100];

    int num_books;

    // Prompt the user for the number of books they want to add to the library
    printf("How many books do you want to add to your library?\n");
    scanf("%d", &num_books);

    // Loop through each book and prompt the user for book details
    for(int i = 0; i < num_books; i++) {
        printf("Enter details for book %d:\n", i+1);
        printf("Title: ");

        // Read in the book title
        scanf("%s", library[i].title);

        printf("Author: ");

        // Read in the author name
        scanf("%s", library[i].author);

        printf("Number of pages: ");

        // Read in the number of pages
        scanf("%d", &library[i].pages);

        printf("Price: ");

        // Read in the price
        scanf("%f", &library[i].price);
    }

    // Display the books in the library
    printf("\nYour library: \n\n");
    printf("Book Title\tAuthor Name\tPages\tPrice\n");
    for(int i = 0; i < num_books; i++) {
        printf("%s\t%s\t\t%d\t%.2f\n", library[i].title, library[i].author, library[i].pages, library[i].price);
    }

    return 0;
}