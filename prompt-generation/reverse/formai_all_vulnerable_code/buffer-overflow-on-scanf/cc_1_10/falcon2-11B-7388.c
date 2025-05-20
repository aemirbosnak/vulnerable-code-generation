//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>

// Define the maximum number of books the library can hold
#define MAX_BOOKS 100

// Define a structure to hold information about a book
typedef struct {
    char title[100];
    char author[100];
    int available;
} Book;

// Define a function to add a new book to the library
void addBook(Book* books, int size) {
    // Check if the library is full
    if (size == MAX_BOOKS) {
        printf("Library is full\n");
        return;
    }

    // Prompt the user for the title and author of the new book
    printf("Enter the title of the book: ");
    scanf("%s", books[size].title);

    printf("Enter the author of the book: ");
    scanf("%s", books[size].author);

    books[size].available = 1;

    printf("Book added successfully!\n");
}

// Define a function to remove a book from the library
void removeBook(Book* books, int size) {
    // Prompt the user for the title of the book to remove
    printf("Enter the title of the book to remove: ");
    scanf("%s", books[size].title);

    // Find the index of the book to remove in the library
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(books[i].title, books[size].title) == 0) {
            index = i;
            break;
        }
    }

    // If the book was not found, print an error message
    if (index == -1) {
        printf("Book not found\n");
        return;
    }

    // If the book was found, remove it from the library and print a success message
    books[index].available = 0;
    printf("Book removed successfully!\n");
}

// Define a function to display all the books in the library
void displayBooks(Book* books, int size) {
    int bookCount = 0;

    printf("Books in the library:\n");
    for (int i = 0; i < size; i++) {
        if (books[i].available) {
            printf("%s by %s (%d available)\n", books[i].title, books[i].author, books[i].available);
            bookCount++;
        }
    }

    printf("There are %d books in the library.\n", bookCount);
}

int main() {
    Book books[MAX_BOOKS];
    int size = 0;

    // Initialize the library
    for (int i = 0; i < MAX_BOOKS; i++) {
        books[i].available = 1;
    }

    // Add a few books to the library
    addBook(books, size);
    addBook(books, size);
    addBook(books, size);
    addBook(books, size);
    addBook(books, size);

    // Remove a book from the library
    removeBook(books, size);

    // Display all the books in the library
    displayBooks(books, size);

    return 0;
}