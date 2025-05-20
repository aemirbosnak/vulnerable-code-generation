//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    char *text;
    int num_pages;
} Book;

// Create a new book
Book *new_book(char *title, char *author, char *text, int num_pages) {
    Book *book = (Book *)malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->text = strdup(text);
    book->num_pages = num_pages;
    return book;
}

// Free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Print the information about a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->num_pages);
}

// Read a book from a file
Book *read_book(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char *title = NULL;
    char *author = NULL;
    char *text = NULL;
    int num_pages = 0;

    // Read the title of the book
    size_t len = 0;
    getline(&title, &len, file);

    // Read the author of the book
    getline(&author, &len, file);

    // Read the text of the book
    while (1) {
        char *line = NULL;
        size_t len = 0;
        int status = getline(&line, &len, file);
        if (status == -1) {
            break;
        }
        text = realloc(text, strlen(text) + strlen(line) + 1);
        strcat(text, line);
        free(line);
    }

    // Read the number of pages in the book
    fscanf(file, "%d", &num_pages);

    // Close the file
    fclose(file);

    // Create a new book with the information from the file
    Book *book = new_book(title, author, text, num_pages);

    // Free the memory allocated for the title, author, and text
    free(title);
    free(author);
    free(text);

    return book;
}

// Write a book to a file
void write_book(Book *book, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }

    // Write the title of the book
    fprintf(file, "%s\n", book->title);

    // Write the author of the book
    fprintf(file, "%s\n", book->author);

    // Write the text of the book
    fprintf(file, "%s", book->text);

    // Write the number of pages in the book
    fprintf(file, "%d", book->num_pages);

    // Close the file
    fclose(file);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the book from the file
    Book *book = read_book(argv[1]);
    if (book == NULL) {
        printf("Error: could not read book from file\n");
        return 1;
    }

    // Print the information about the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}