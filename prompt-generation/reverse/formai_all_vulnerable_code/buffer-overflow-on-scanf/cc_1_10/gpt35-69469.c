//FormAI DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the book title and author name
#define MAX_TITLE_SIZE 100
#define MAX_AUTHOR_SIZE 50

// Define a structure for each book
typedef struct book {
    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_SIZE];
    int num_pages;
} Book;

int main() {
    // Declare a pointer to a book
    Book *book_ptr;
    // Declare variables to store the number of books and the currently selected book
    int num_books = 0, selection = 0;
    
    // Prompt the user for the number of books
    printf("Enter the number of books: ");
    scanf("%d", &num_books);
    
    // Dynamically allocate memory for the array of books
    book_ptr = (Book *)malloc(num_books * sizeof(Book));
    
    // Prompt the user to enter the details of each book
    for (int i = 0; i < num_books; i++) {
        printf("\nBOOK %d\n", i+1);
        printf("Title: ");
        scanf("%s", (book_ptr+i)->title);
        printf("Author: ");
        scanf("%s", (book_ptr+i)->author);
        printf("Number of pages: ");
        scanf("%d", &(book_ptr+i)->num_pages);
    }
    
    // Display a menu for the user to select a book
    while (selection != -1) {
        printf("\nPlease select a book (1-%d) to open or enter -1 to exit:\n", num_books);
        for (int i = 0; i < num_books; i++) {
            printf("%d: %s by %s\n", i+1, (book_ptr+i)->title, (book_ptr+i)->author);
        }
        scanf("%d", &selection);
        
        // If a valid selection was made, display the book details
        if (selection > 0 && selection <= num_books) {
            printf("\n%s by %s\n", (book_ptr+selection-1)->title, (book_ptr+selection-1)->author);
            printf("Number of pages: %d\n", (book_ptr+selection-1)->num_pages);
            printf("Opening %s...\n", (book_ptr+selection-1)->title);
            // Code to open the ebook reader would go here
            printf("%s closed.\n", (book_ptr+selection-1)->title);
        }
        else if (selection != -1) {
            printf("Invalid selection.\n");
        }
    }
    
    free(book_ptr); // Free the dynamically allocated memory
    
    return 0;
}