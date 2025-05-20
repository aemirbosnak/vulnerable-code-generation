//FormAI DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 20 // Maximum number of books to store
#define MAX_TITLE_LENGTH 50 // Maximum length of title for a book
#define MAX_AUTHOR_LENGTH 50 // Maximum length of author name for a book
#define MAX_FILENAME_LENGTH 100 // Maximum length of filename for a book

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char filename[MAX_FILENAME_LENGTH];
} Book;

Book books[MAX_BOOKS]; // Array of books
int num_books = 0; // Number of books

void read_books_info();
void print_books_info();
void search_book();

int main() {
    int choice;

    printf("\nWelcome to My Ebook Reader\n");

    // Read information about books from file
    read_books_info();

    // Main loop for user interactions
    do {
        printf("\n-- Main Menu --\n");
        printf("1. List all books\n");
        printf("2. Search for a book\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_books_info();
                break;
            case 2:
                search_book();
                break;
            case 3:
                printf("\nThank you for using My Ebook Reader\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to read information about books from a file
void read_books_info() {
    FILE* fp_books = fopen("books.txt", "r");

    if (fp_books == NULL) {
        printf("\nError: Could not open file \"books.txt\"\n");
        exit(EXIT_FAILURE);
    }

    while (num_books < MAX_BOOKS) {
        if (fscanf(fp_books, "%s %s %s",
            books[num_books].title,
            books[num_books].author,
            books[num_books].filename) == EOF) {
            break;
        }
        num_books++;
    }

    fclose(fp_books);
}

// Function to print information about all books
void print_books_info() {
    if (num_books == 0) {
        printf("\nThere are no books available\n");
        return;
    }

    printf("\n-- List of Books --\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n", i+1, books[i].title, books[i].author);
    }
}

// Function to search for a book
void search_book() {
    char query[MAX_TITLE_LENGTH];
    int results[MAX_BOOKS];
    int num_results = 0;

    printf("\nEnter the title of the book to search: ");
    scanf("%s", query);

    for (int i = 0; i < num_books; i++) {
        if (strstr(books[i].title, query) != NULL) {
            results[num_results++] = i;
        }
    }

    if (num_results == 0) {
        printf("\nNo results found for \"%s\"\n", query);
    } else {
        printf("\n-- Search Results for \"%s\" --\n", query);
        for (int i = 0; i < num_results; i++) {
            printf("%d. %s by %s\n", i+1, books[results[i]].title, books[results[i]].author);
        }
    }
}