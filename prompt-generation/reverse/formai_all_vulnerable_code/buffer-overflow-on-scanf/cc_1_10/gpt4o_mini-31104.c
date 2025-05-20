//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold book information
typedef struct {
    int id;
    char title[100];
    char author[100];
    int year;
} Book;

// Function prototypes
void addBook(Book* books, int* count);
void displayBooks(Book* books, int count);
void searchBookByAuthor(Book* books, int count);
int menu();

// Main function
int main() {
    Book books[100];
    int count = 0;
    int choice;

    while ((choice = menu()) != 4) {
        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                searchBookByAuthor(books, count);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    printf("Thank you for using the book database! Goodbye!\n");
    return 0;
}

// Function to display the menu
int menu() {
    int choice;
    printf("\n***** Welcome to the Book Database *****\n");
    printf("1. Add a Book\n");
    printf("2. Display All Books\n");
    printf("3. Search Book by Author\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a book
void addBook(Book* books, int* count) {
    if (*count < 100) {
        books[*count].id = *count + 1; // Assign an ID
        printf("Enter the title of the book: ");
        getchar(); // Clear the newline character
        fgets(books[*count].title, 100, stdin);
        strtok(books[*count].title, "\n"); // Remove newline character
        
        printf("Enter the author of the book: ");
        fgets(books[*count].author, 100, stdin);
        strtok(books[*count].author, "\n");

        printf("Enter the year of publication: ");
        scanf("%d", &books[*count].year);

        (*count)++;
        printf("Book added successfully!\n");
    } else {
        printf("Database is full! Can't add more books.\n");
    }
}

// Function to display all books
void displayBooks(Book* books, int count) {
    if (count == 0) {
        printf("No books available in the database.\n");
        return;
    }

    printf("\nList of All Books:\n");
    printf("ID\tTitle\t\tAuthor\t\tYear\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%d\n", books[i].id, books[i].title, books[i].author, books[i].year);
    }
}

// Function to search for a book by author
void searchBookByAuthor(Book* books, int count) {
    char searchAuthor[100];
    printf("Enter the author's name to search: ");
    getchar(); // Clear the newline character
    fgets(searchAuthor, 100, stdin);
    strtok(searchAuthor, "\n"); // Remove newline character

    printf("\nSearching for books by '%s':\n", searchAuthor);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(books[i].author, searchAuthor) != NULL) {
            printf("ID: %d, Title: %s, Year: %d\n", books[i].id, books[i].title, books[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found by author '%s'.\n", searchAuthor);
    }
}