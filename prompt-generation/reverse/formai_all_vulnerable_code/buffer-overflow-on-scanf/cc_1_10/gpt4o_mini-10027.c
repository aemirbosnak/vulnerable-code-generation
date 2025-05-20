//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

typedef struct {
    Book *books;
    int count;
    int capacity;
} Library;

// Function prototypes
Library* create_library(int capacity);
void add_book(Library *library, const char *title, const char *author, int year);
void display_books(const Library *library);
void free_library(Library *library);
void clear_input_buffer();

int main() {
    int initial_capacity = 5;
    Library *library = create_library(initial_capacity);
    
    if (library == NULL) {
        fprintf(stderr, "Error: Could not create library.\n");
        return EXIT_FAILURE;
    }

    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
    char choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                clear_input_buffer(); // Clear the input buffer
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                strtok(title, "\n"); // Remove newline character

                printf("Enter book author: ");
                fgets(author, sizeof(author), stdin);
                strtok(author, "\n"); // Remove newline character

                printf("Enter publication year: ");
                scanf("%d", &year);

                add_book(library, title, author, year);
                break;
            case '2':
                display_books(library);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != '3');

    free_library(library);
    return EXIT_SUCCESS;
}

Library* create_library(int capacity) {
    Library *library = (Library *)malloc(sizeof(Library));
    if (library == NULL) {
        return NULL;
    }
    library->books = (Book *)malloc(capacity * sizeof(Book));
    if (library->books == NULL) {
        free(library);
        return NULL;
    }
    library->count = 0;
    library->capacity = capacity;
    return library;
}

void add_book(Library *library, const char *title, const char *author, int year) {
    if (library->count >= library->capacity) {
        // Resize the array if capacity is reached
        library->capacity *= 2;
        library->books = (Book *)realloc(library->books, library->capacity * sizeof(Book));
        if (library->books == NULL) {
            fprintf(stderr, "Error: Could not allocate memory for books.\n");
            return;
        }
    }
    strncpy(library->books[library->count].title, title, MAX_TITLE_LENGTH);
    strncpy(library->books[library->count].author, author, MAX_AUTHOR_LENGTH);
    library->books[library->count].year = year;
    library->count++;
}

void display_books(const Library *library) {
    if (library->count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nList of Books:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n",
               library->books[i].title,
               library->books[i].author,
               library->books[i].year);
    }
}

void free_library(Library *library) {
    free(library->books);
    free(library);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Discard characters until new line or EOF
}