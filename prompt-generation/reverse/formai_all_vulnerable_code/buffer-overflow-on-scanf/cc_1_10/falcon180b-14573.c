//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct {
    char title[100];
    char author[100];
    int numPages;
    char genre[50];
} Book;

// Function to read a book from a file
void readBook(FILE* file, Book* book) {
    fscanf(file, "%s %s %d %s", book->title, book->author, &book->numPages, book->genre);
}

// Function to display a book's information
void displayBook(Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of Pages: %d\n", book->numPages);
    printf("Genre: %s\n", book->genre);
}

// Function to search for a book by title
int searchBook(Book* books, int numBooks, char* title) {
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Open the book file
    FILE* file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open book file.\n");
        return 1;
    }

    // Read the number of books from the file
    int numBooks;
    fscanf(file, "%d", &numBooks);

    // Allocate memory for the books array
    Book* books = (Book*) malloc(numBooks * sizeof(Book));

    // Read each book from the file
    for (int i = 0; i < numBooks; i++) {
        readBook(file, &books[i]);
    }

    // Close the book file
    fclose(file);

    // Example usage of the program
    char title[100];
    printf("Enter a book title to search for: ");
    scanf("%s", title);

    int index = searchBook(books, numBooks, title);
    if (index!= -1) {
        displayBook(&books[index]);
    } else {
        printf("Book not found.\n");
    }

    // Free the memory allocated for the books array
    free(books);

    return 0;
}