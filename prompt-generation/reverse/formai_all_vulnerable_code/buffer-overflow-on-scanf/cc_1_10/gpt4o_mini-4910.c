//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50

// Structure to hold book information
typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
} Book;

// Global variables
Book library[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void addBook();
void displayBooks();
void searchBookById();
void welcomeMessage();

int main() {
    int choice;

    welcomeMessage();
    
    do {
        printf("\n=== Book Database ===\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBookById();
                break;
            case 4:
                printf("Thank you for using the Book Database. Happy reading!\n");
                break;
            default:
                printf("Oops! Please enter a valid option (1-4).\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to display a cheerful welcome message
void welcomeMessage() {
    printf("Welcome to the Happy Book Database System!\n");
    printf("Here you can manage your favorite books with a smile!\n");
}

// Function to add a book to the database
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Oh no! The database is full! Can't add more books.\n");
        return;
    }

    Book newBook;

    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    printf("Enter Book Title: ");
    getchar(); // Consume leftover newline
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline
    printf("Enter Author Name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    library[bookCount++] = newBook;

    printf("Yay! You have successfully added the book: \"%s\" by %s!\n", newBook.title, newBook.author);
}

// Function to display all books in the database
void displayBooks() {
    if (bookCount == 0) {
        printf("Oh no! You have no books in the database.\n");
        return;
    }

    printf("\n=== List of Books ===\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book ID: %d, Title: \"%s\", Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

// Function to search for a book by ID
void searchBookById() {
    int searchId;
    printf("Enter Book ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("Hooray! Found the book: \"%s\" by %s!\n", library[i].title, library[i].author);
            return;
        }
    }
    printf("Oops! No book found with ID %d.\n", searchId);
}