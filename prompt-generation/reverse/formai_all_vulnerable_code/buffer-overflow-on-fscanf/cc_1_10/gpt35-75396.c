//FormAI DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the book title
#define MAX_TITLE_LENGTH 50

// Define the maximum number of books that can be stored
#define MAX_BOOKS 100

// Define a structure for our book data
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_TITLE_LENGTH];
    int num_pages;
    char* content;
} Book;

// Define a function for loading a book from a file
int load_book(Book* book, char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 0;
    }

    // Read the title from the file
    fgets(book->title, MAX_TITLE_LENGTH, file);

    // Remove the newline character at the end of the title
    book->title[strlen(book->title) - 1] = '\0';

    // Read the author from the file
    fgets(book->author, MAX_TITLE_LENGTH, file);

    // Remove the newline character at the end of the author
    book->author[strlen(book->author) - 1] = '\0';

    // Read the number of pages from the file
    fscanf(file, "%d", &book->num_pages);

    // Allocate memory for the content
    book->content = (char*) malloc(book->num_pages * sizeof(char));

    if (book->content == NULL) {
        printf("Error: Could not allocate memory for book content\n");
        fclose(file);
        return 0;
    }

    // Read the content from the file
    fgets(book->content, book->num_pages + 1, file);

    fclose(file);
    return 1;
}

// Define a function for printing a book's information
void print_book_info(Book* book) {
    printf("-----------------\n");
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("-----------------\n");
}

int main() {
    Book library[MAX_BOOKS];
    int num_books = 0;

    printf("Welcome to our Ebook library!\n\n");

    while (1) {
        // Print the available options to the user
        printf("Please choose an option:\n");
        printf("1. Add a book\n");
        printf("2. Print all books\n");
        printf("3. Load a book from file\n");
        printf("4. Quit\n");

        // Read the user's choice
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            // Add a book to the library

            if (num_books == MAX_BOOKS) {
                printf("Error: The library is full!\n\n");
                continue;
            }

            printf("Please enter the title of the book:\n");
            char title[MAX_TITLE_LENGTH];
            scanf("%s", title);

            printf("Please enter the author of the book:\n");
            char author[MAX_TITLE_LENGTH];
            scanf("%s", author);

            printf("Please enter the number of pages in the book:\n");
            int num_pages;
            scanf("%d", &num_pages);

            // Allocate memory for the content
            char* content = (char*) malloc(num_pages * sizeof(char));

            if (content == NULL) {
                printf("Error: Could not allocate memory for book content\n");
                continue;
            }

            printf("Please enter the content of the book:\n");
            scanf(" %[^\n]", content);

            // Add the book to the library
            strcpy(library[num_books].title, title);
            strcpy(library[num_books].author, author);
            library[num_books].num_pages = num_pages;
            library[num_books].content = content;
            num_books++;

            printf("The book has been added to the library!\n\n");
        } else if (choice == 2) {
            // Print all the books in the library

            if (num_books == 0) {
                printf("There are no books in the library!\n\n");
                continue;
            }

            for (int i = 0; i < num_books; i++) {
                print_book_info(&library[i]);
            }
        } else if (choice == 3) {
            // Load a book from a file

            if (num_books == MAX_BOOKS) {
                printf("Error: The library is full!\n\n");
                continue;
            }

            printf("Please enter the filename of the book:\n");
            char filename[MAX_TITLE_LENGTH];
            scanf("%s", filename);

            Book book;
            int success = load_book(&book, filename);

            if (!success) {
                continue;
            }

            // Add the book to the library
            library[num_books] = book;
            num_books++;

            printf("The book '%s' has been loaded into the library!\n\n", book.title);
        } else if (choice == 4) {
            // Quit the program
            break;
        } else {
            printf("Error: Invalid choice! Please choose a valid option.\n\n");
        }
    }

    return 0;
}