//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOK_SIZE 100000

// Structure to represent a book
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char *text;
} book;

// Structure to represent the current state of the reader
typedef struct reader {
    book *current_book;
    int current_page;
} reader;

// Function to create a new book
book *create_book(char *title, char *author, int num_pages, char *text) {
    book *new_book = malloc(sizeof(book));
    new_book->title = strdup(title);
    new_book->author = strdup(author);
    new_book->num_pages = num_pages;
    new_book->text = strdup(text);
    return new_book;
}

// Function to destroy a book
void destroy_book(book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Function to create a new reader
reader *create_reader() {
    reader *new_reader = malloc(sizeof(reader));
    new_reader->current_book = NULL;
    new_reader->current_page = 0;
    return new_reader;
}

// Function to destroy a reader
void destroy_reader(reader *reader) {
    if (reader->current_book != NULL) {
        destroy_book(reader->current_book);
    }
    free(reader);
}

// Function to open a book
bool open_book(reader *reader, char *filename) {
    // Try to open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }

    // Read the title, author, and number of pages from the file
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    int num_pages;
    fscanf(file, "%s %s %d", title, author, &num_pages);

    // Read the text of the book from the file
    char text[MAX_BOOK_SIZE];
    int i = 0;
    while (fgets(text + i, MAX_LINE_LENGTH, file) != NULL) {
        i += strlen(text + i);
    }

    // Close the file
    fclose(file);

    // Create a new book from the data read from the file
    book *new_book = create_book(title, author, num_pages, text);

    // Set the current book and page in the reader
    reader->current_book = new_book;
    reader->current_page = 0;

    return true;
}

// Function to close the current book
void close_book(reader *reader) {
    if (reader->current_book != NULL) {
        destroy_book(reader->current_book);
        reader->current_book = NULL;
        reader->current_page = 0;
    }
}

// Function to go to a specific page in the current book
void go_to_page(reader *reader, int page) {
    if (reader->current_book == NULL) {
        return;
    }

    if (page < 1 || page > reader->current_book->num_pages) {
        return;
    }

    reader->current_page = page;
}

// Function to get the text of the current page
char *get_current_page(reader *reader) {
    if (reader->current_book == NULL) {
        return NULL;
    }

    char *page_text = malloc(MAX_LINE_LENGTH);
    int start_index = (reader->current_page - 1) * MAX_LINE_LENGTH;
    int end_index = start_index + MAX_LINE_LENGTH;
    strncpy(page_text, reader->current_book->text + start_index, end_index - start_index);
    page_text[end_index - start_index] = '\0';

    return page_text;
}

// Function to print the current page
void print_current_page(reader *reader) {
    char *page_text = get_current_page(reader);
    if (page_text != NULL) {
        printf("%s\n", page_text);
        free(page_text);
    }
}

// Main function
int main() {
    // Create a new reader
    reader *reader = create_reader();

    // Open a book
    if (open_book(reader, "book.txt")) {
        // Go to page 1
        go_to_page(reader, 1);

        // Print the current page
        print_current_page(reader);

        // Go to page 2
        go_to_page(reader, 2);

        // Print the current page
        print_current_page(reader);

        // Close the book
        close_book(reader);
    }

    // Destroy the reader
    destroy_reader(reader);

    return 0;
}