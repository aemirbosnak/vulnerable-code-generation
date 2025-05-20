//FormAI DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max length of book title
#define TITLE_LEN 100

// Max length of author's name
#define AUTHOR_LEN 50

// Max number of eBooks we can store
#define MAX_BOOKS 100

// Structure to store information about each book
struct Book {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    char fileName[50];
};

// Function to add a new book to our collection
void addBook(struct Book books[], int *numBooks) {
    // Make sure we haven't exceeded our maximum number of books
    if (*numBooks >= MAX_BOOKS) {
        printf("Sorry, we can't add any more books!\n");
        return;
    }
    
    // Prompt the user for the book's information
    printf("Enter the book's title: ");
    fgets(books[*numBooks].title, TITLE_LEN, stdin);
    printf("Enter the book's author: ");
    fgets(books[*numBooks].author, AUTHOR_LEN, stdin);
    printf("Enter the file name: ");
    fgets(books[*numBooks].fileName, 50, stdin);
    
    // Increment the number of books we have
    (*numBooks)++;
}

// Function to display all the eBooks in our collection
void displayBooks(struct Book books[], int numBooks) {
    printf("Our collection of eBooks:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. \"%s\" by %s\n", i+1, books[i].title, books[i].author);
    }
}

// Main function
int main() {
    // Create an array to hold our eBooks
    struct Book books[MAX_BOOKS];
    int numBooks = 0;
    
    // Loop until the user chooses to exit
    int choice = 0;
    while (choice != 3) {
        // Display the menu options
        printf("Choose an option:\n");
        printf("1. Add a new book\n");
        printf("2. Display all books\n");
        printf("3. Quit\n");
        printf("> ");
        
        // Read the user's choice
        scanf("%d", &choice);
        getchar(); // remove the newline from the input buffer
        
        // Handle the user's choice
        switch (choice) {
            case 1:
                addBook(books, &numBooks);
                break;
            case 2:
                displayBooks(books, numBooks);
                break;
            case 3:
                // Do nothing - the loop will exit after this iteration
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    // Exit the program
    printf("Goodbye!\n");
    return 0;
}