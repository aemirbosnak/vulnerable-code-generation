//FormAI DATASET v1.0 Category: Ebook reader ; Style: irregular
// Welcome to the C Ebook Reader!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 5
#define MAX_TITLE_LENGTH 50
#define MAX_FILE_LENGTH 100

// Define a Book struct
typedef struct Book {
    char title[MAX_TITLE_LENGTH];
    char filename[MAX_FILE_LENGTH];
} Book;

// Define a function that displays the main menu
void displayMainMenu() {
    printf("\n");
    printf("=== C Ebook Reader ===\n");
    printf("1. View Books\n");
    printf("2. Add Book\n");
    printf("3. Remove Book\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Define a function that reads in a book title and filename from the user
void readBookInfo(Book *book) {
    printf("\nEnter the title of the book: ");
    fgets(book->title, MAX_TITLE_LENGTH, stdin);
    strtok(book->title, "\n"); // Remove the newline character at the end of the title
    printf("Enter the filename of the book: ");
    fgets(book->filename, MAX_FILE_LENGTH, stdin);
    strtok(book->filename, "\n"); // Remove the newline character at the end of the filename
}

int main() {
    int choice;
    int numBooks = 0; // Counter for the number of books in the library
    Book library[MAX_BOOKS]; // Array to hold the library of books
    
    // Loop until the user chooses to exit
    do {
        displayMainMenu();
        scanf("%d", &choice); // Read in the user's choice
        
        switch (choice) {
            case 1: // View Books
                if (numBooks == 0) {
                    printf("\nThe library is currently empty.\n");
                } else {
                    printf("\nThe library contains the following books:\n");
                    for (int i = 0; i < numBooks; i++) {
                        printf("%d. %s\n", i+1, library[i].title);
                    }
                }
                break;
                
            case 2: // Add Book
                if (numBooks < MAX_BOOKS) {
                    printf("\nAdding a new book:\n");
                    readBookInfo(&library[numBooks]); // Read in the new book's information
                    numBooks++; // Increment the book counter
                } else {
                    printf("\nThe library is already full!\n");
                }
                break;
                
            case 3: // Remove Book
                if (numBooks == 0) {
                    printf("\nThe library is currently empty.\n");
                } else {
                    int bookIndex;
                    printf("\nEnter the number of the book to remove: ");
                    scanf("%d", &bookIndex);
                    
                    if (bookIndex > 0 && bookIndex <= numBooks) { // Check that the book number is valid
                        printf("Removing the book [%s]...\n", library[bookIndex-1].title);
                        
                        // Shift all the books after the removed book to fill in the gap in the array
                        for (int i = bookIndex-1; i < numBooks-1; i++) {
                            library[i] = library[i+1];
                        }
                        
                        numBooks--; // Decrement the book counter
                    } else {
                        printf("Invalid book number. Please try again.\n");
                    }
                }
                break;
                
            case 4: // Exit
                printf("\nExiting...\n");
                break;
                
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
        // Clear the input buffer before the next loop
        while ((getchar()) != '\n');
        
    } while (choice != 4);
    
    return 0;
}