//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book.
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char *text;
} Book;

// Create a new book.
Book *new_book(char *title, char *author, int num_pages, char *text) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->text = strdup(text);
    return book;
}

// Free the memory allocated for a book.
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Print the information about a book.
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text:\n%s\n", book->text);
}

// Read a book from a file.
Book *read_book(char *filename) {
    // Open the file.
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title.
    char title[1024];
    if (fgets(title, sizeof(title), fp) == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the author.
    char author[1024];
    if (fgets(author, sizeof(author), fp) == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the number of pages.
    int num_pages;
    if (fscanf(fp, "%d", &num_pages) != 1) {
        fclose(fp);
        return NULL;
    }

    // Read the text.
    char *text = malloc(sizeof(char) * 1024 * num_pages);
    if (text == NULL) {
        fclose(fp);
        return NULL;
    }
    if (fread(text, sizeof(char), 1024 * num_pages, fp) != 1024 * num_pages) {
        fclose(fp);
        free(text);
        return NULL;
    }

    // Close the file.
    fclose(fp);

    // Create a new book.
    Book *book = new_book(title, author, num_pages, text);

    // Return the book.
    return book;
}

// Write a book to a file.
int write_book(char *filename, Book *book) {
    // Open the file.
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }

    // Write the title.
    if (fprintf(fp, "%s\n", book->title) < 0) {
        fclose(fp);
        return -1;
    }

    // Write the author.
    if (fprintf(fp, "%s\n", book->author) < 0) {
        fclose(fp);
        return -1;
    }

    // Write the number of pages.
    if (fprintf(fp, "%d\n", book->num_pages) < 0) {
        fclose(fp);
        return -1;
    }

    // Write the text.
    if (fwrite(book->text, sizeof(char), 1024 * book->num_pages, fp) != 1024 * book->num_pages) {
        fclose(fp);
        return -1;
    }

    // Close the file.
    fclose(fp);

    // Return 0 to indicate success.
    return 0;
}

// The main function.
int main(int argc, char *argv[]) {
    // Check if the user has provided a filename.
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the book from the file.
    Book *book = read_book(argv[1]);
    if (book == NULL) {
        printf("Error: could not read book from file.\n");
        return 1;
    }

    // Print the information about the book.
    print_book(book);

    // Free the memory allocated for the book.
    free_book(book);

    // Return 0 to indicate success.
    return 0;
}