//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

// Structure for the book record
typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

// Global array to hold the books and a count of how many we've got
Book library[MAX_BOOKS];
int book_count = 0;

// Function declarations
void add_book();
void search_book();
void display_books();
void index_books();

// Main function
int main() {
    int choice;
    do {
        printf("\n*** Welcome to Outstanding Library Database! ***\n");
        printf("1. Add a Book\n");
        printf("2. Search for a Book\n");
        printf("3. Display All Books\n");
        printf("4. Index Books\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                search_book();
                break;
            case 3:
                display_books();
                break;
            case 4:
                index_books();
                break;
            case 5:
                printf("Exiting the Library Database. Happy Reading!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

// Function to add a book to the library
void add_book() {
    if (book_count < MAX_BOOKS) {
        Book new_book;
        new_book.id = book_count + 1;

        printf("Enter the title of the book: ");
        scanf(" %[^\n]", new_book.title); // Read title with spaces

        printf("Enter the author of the book: ");
        scanf(" %[^\n]", new_book.author); // Read author with spaces

        // Add the new book to the library
        library[book_count++] = new_book;
        printf("Successfully added \"%s\" by %s (ID: %d) to the library!\n", new_book.title, new_book.author, new_book.id);
    } else {
        printf("Library is full! Cannot add more books.\n");
    }
}

// Function to search for a book by title
void search_book() {
    char search_title[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    scanf(" %[^\n]", search_title);

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, search_title) == 0) { // Case insensitive comparison
            printf("Found: \"%s\" by %s (ID: %d)\n", library[i].title, library[i].author, library[i].id);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book titled \"%s\" not found in the library!\n", search_title);
    }
}

// Function to display all books in the library
void display_books() {
    if (book_count == 0) {
        printf("No books in the library yet!\n");
    } else {
        printf("\n--- List of Books in the Library ---\n");
        for (int i = 0; i < book_count; i++) {
            printf("ID: %d | Title: \"%s\" | Author: %s\n", library[i].id, library[i].title, library[i].author);
        }
    }
}

// Function to index books and display sorted titles
void index_books() {
    // Simple index of titles
    printf("\n--- Indexing Books ---\n");
    char *titles[MAX_BOOKS];
    for (int i = 0; i < book_count; i++) {
        titles[i] = library[i].title;
    }

    // Simple Bubble Sort for titles
    for (int i = 0; i < book_count - 1; i++) {
        for (int j = 0; j < book_count - i - 1; j++) {
            if (strcasecmp(titles[j], titles[j + 1]) > 0) {
                // Swap titles
                char *temp = titles[j];
                titles[j] = titles[j + 1];
                titles[j + 1] = temp;
            }
        }
    }

    // Display the indexed titles
    for (int i = 0; i < book_count; i++) {
        printf("%d: %s\n", i + 1, titles[i]);
    }
}