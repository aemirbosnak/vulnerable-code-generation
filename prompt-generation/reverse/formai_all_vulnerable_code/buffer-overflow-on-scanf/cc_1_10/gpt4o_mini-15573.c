//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

// Structure to represent a book
typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

// Function prototypes
void addBook(Book *library, int *count);
void viewBooks(Book *library, int count);
void searchBook(Book *library, int count);

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n*** Simple Library System ***\n");
        printf("1. Add a Book\n");
        printf("2. View All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                viewBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                printf("Exiting the library system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to add a book to the library
void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;
    newBook.id = *count + 1;

    printf("Enter the title of the book: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter the author of the book: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    printf("Enter the publication year: ");
    scanf("%d", &newBook.year);
    getchar(); // Consume newline character

    library[*count] = newBook;
    (*count)++;

    printf("Book added successfully with ID %d!\n", newBook.id);
}

// Function to view all books in the library
void viewBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", library[i].id);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n", library[i].year);
        printf("--------------------------\n");
    }
}

// Function to search for a book by title or author
void searchBook(Book *library, int count) {
    if (count == 0) {
        printf("No books in the library to search.\n");
        return;
    }

    char query[TITLE_LENGTH];
    printf("Enter title or author name to search: ");
    fgets(query, TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = 0; // Remove newline character

    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].author, query)) {
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Year: %d\n", library[i].year);
            printf("--------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No matches found for \"%s\".\n", query);
    }
}