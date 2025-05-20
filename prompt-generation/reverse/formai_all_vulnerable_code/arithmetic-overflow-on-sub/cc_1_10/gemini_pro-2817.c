//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book struct
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
} Book;

// Create a new book
Book* create_book(char *title, char *author, int num_pages) {
    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        return NULL;
    }

    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;

    return book;
}

// Destroy a book
void destroy_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book);
}

// Print a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
}

// Read a book from a file
Book* read_book_from_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    // Read the title
    nread = getline(&line, &len, fp);
    if (nread == -1) {
        fclose(fp);
        return NULL;
    }
    line[nread - 1] = '\0'; // Remove newline character

    // Read the author
    nread = getline(&line, &len, fp);
    if (nread == -1) {
        fclose(fp);
        return NULL;
    }
    line[nread - 1] = '\0'; // Remove newline character

    // Read the number of pages
    int num_pages;
    nread = getline(&line, &len, fp);
    if (nread == -1) {
        fclose(fp);
        return NULL;
    }
    num_pages = atoi(line);

    // Create the book
    Book *book = create_book(line, line, num_pages);
    if (book == NULL) {
        fclose(fp);
        return NULL;
    }

    // Close the file
    fclose(fp);

    return book;
}

// Write a book to a file
int write_book_to_file(char *filename, Book *book) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }

    // Write the title
    fprintf(fp, "%s\n", book->title);

    // Write the author
    fprintf(fp, "%s\n", book->author);

    // Write the number of pages
    fprintf(fp, "%d\n", book->num_pages);

    // Close the file
    fclose(fp);

    return 0;
}

// Main function
int main() {
    // Create a book
    Book *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184);

    // Print the book
    print_book(book);

    // Write the book to a file
    if (write_book_to_file("book.txt", book) == 0) {
        printf("Book successfully written to file.\n");
    } else {
        printf("Error writing book to file.\n");
    }

    // Read the book from a file
    Book *book2 = read_book_from_file("book.txt");
    if (book2 != NULL) {
        printf("Book successfully read from file.\n");
        print_book(book2);
        destroy_book(book2);
    } else {
        printf("Error reading book from file.\n");
    }

    // Destroy the book
    destroy_book(book);

    return 0;
}