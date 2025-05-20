//FormAI DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <string.h>

// Define maximum number of books the user can read
#define MAX_BOOKS 20

// Define the book structure
struct Book {
    char title[50];
    char author[50];
    int year;
    int pages;
    char format[10];
};

int main() {
    // Declare variable for number of books user wants to read
    int num_books;
    
    // Declare array to hold books
    struct Book books[MAX_BOOKS];
    
    // Ask user for number of books they want to read
    printf("How many books would you like to read? (Maximum of %d)\n", MAX_BOOKS);
    scanf("%d", &num_books);
    
    // Check if user entered a valid number of books
    if(num_books < 1 || num_books > MAX_BOOKS) {
        printf("Invalid number of books entered. Exiting program.\n");
        return 0;
    }
    
    // Ask user for details about each book
    for(int i = 0; i < num_books; i++) {
        printf("\nEnter details for Book %d:\n", i+1);
        printf("Title: ");
        getchar();
        fgets(books[i].title, 50, stdin);
        
        printf("Author: ");
        fgets(books[i].author, 50, stdin);
        
        printf("Year: ");
        scanf("%d", &books[i].year);
        
        printf("Pages: ");
        scanf("%d", &books[i].pages);
        
        printf("Format (e.g. epub, pdf, mobi): ");
        getchar();
        fgets(books[i].format, 10, stdin);
    }
    
    // Print details of each book
    printf("\n\n========================================\n");
    printf("        Your Ebook Collection\n");
    printf("========================================\n\n");
    
    for(int i = 0; i < num_books; i++) {
        printf("Book %d:\n", i+1);
        printf("Title: %s", books[i].title);
        printf("Author: %s", books[i].author);
        printf("Year: %d\n", books[i].year);
        printf("Pages: %d\n", books[i].pages);
        printf("Format: %s", books[i].format);
        printf("\n");
    }
    
    return 0;
}