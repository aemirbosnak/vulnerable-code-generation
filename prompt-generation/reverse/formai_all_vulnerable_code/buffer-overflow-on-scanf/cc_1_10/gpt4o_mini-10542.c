//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple structure to represent a Book
typedef struct {
    char title[50];
    char author[50];
    int year;
} Book;

// Function to allocate memory for a new book
Book* createBook(const char* title, const char* author, int year) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(newBook->title, title, sizeof(newBook->title) - 1);
    newBook->title[sizeof(newBook->title) - 1] = '\0';  // Ensure null termination
    strncpy(newBook->author, author, sizeof(newBook->author) - 1);
    newBook->author[sizeof(newBook->author) - 1] = '\0';  // Ensure null termination
    newBook->year = year;
    return newBook;
}

// Function to display book details
void displayBook(const Book* book) {
    if (book != NULL) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Year: %d\n", book->year);
    }
}

// Function to free allocated memory for a book
void deleteBook(Book* book) {
    free(book);
}

// Function to create an array of books dynamically
Book** createBookArray(int size) {
    Book** books = (Book**)malloc(size * sizeof(Book*));
    if (books == NULL) {
        printf("Memory allocation for book array failed!\n");
        exit(1);
    }
    return books;
}

// Function to initialize books in an array
void initializeBooks(Book** books, int size) {
    for (int i = 0; i < size; i++) {
        char title[50];
        char author[50];
        int year;

        printf("Enter title for book %d: ", i + 1);
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = 0;  // Remove newline character

        printf("Enter author for book %d: ", i + 1);
        fgets(author, sizeof(author), stdin);
        author[strcspn(author, "\n")] = 0;  // Remove newline character

        printf("Enter year for book %d: ", i + 1);
        scanf("%d", &year);
        getchar();  // Clear newline character from input buffer

        books[i] = createBook(title, author, year);
    }
}

// Function to display all books in an array
void displayBooks(Book** books, int size) {
    for (int i = 0; i < size; i++) {
        printf("\nBook %d:\n", i + 1);
        displayBook(books[i]);
    }
}

// Function to delete all books in an array
void deleteBookArray(Book** books, int size) {
    for (int i = 0; i < size; i++) {
        deleteBook(books[i]);
    }
    free(books);
}

// Main function: Entry point of the book management system
int main() {
    int numberOfBooks;

    printf("Enter the number of books you want to manage: ");
    scanf("%d", &numberOfBooks);
    getchar();  // Clear newline character from input buffer

    Book** books = createBookArray(numberOfBooks);
    
    printf("Enter details for each book:\n");
    initializeBooks(books, numberOfBooks);
    
    printf("\nDisplaying all books:\n");
    displayBooks(books, numberOfBooks);
    
    deleteBookArray(books, numberOfBooks);
    
    return 0;
}