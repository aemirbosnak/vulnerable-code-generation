//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    char *content;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *content) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->content = strdup(content);
    return book;
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

// Function to print the details of a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Content:\n%s\n", book->content);
}

// Function to read a book from a file
Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the title of the book
    char title[256];
    if (fgets(title, 256, fp) == NULL) {
        perror("Error reading title");
        fclose(fp);
        return NULL;
    }
    title[strlen(title) - 1] = '\0'; // Remove the newline character

    // Read the author of the book
    char author[256];
    if (fgets(author, 256, fp) == NULL) {
        perror("Error reading author");
        fclose(fp);
        return NULL;
    }
    author[strlen(author) - 1] = '\0'; // Remove the newline character

    // Read the number of pages in the book
    int num_pages;
    if (fscanf(fp, "%d", &num_pages) != 1) {
        perror("Error reading number of pages");
        fclose(fp);
        return NULL;
    }

    // Read the content of the book
    char *content = malloc(num_pages * 256); // Allocate enough memory to store the content of the book
    if (content == NULL) {
        perror("Error allocating memory for content");
        fclose(fp);
        return NULL;
    }
    if (fread(content, 1, num_pages * 256, fp) != num_pages * 256) {
        perror("Error reading content");
        free(content);
        fclose(fp);
        return NULL;
    }

    // Close the file
    fclose(fp);

    // Create a new book object and return it
    return create_book(title, author, num_pages, content);
}

// Function to write a book to a file
int write_book(Book *book, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write the title of the book
    if (fprintf(fp, "%s\n", book->title) < 0) {
        perror("Error writing title");
        fclose(fp);
        return -1;
    }

    // Write the author of the book
    if (fprintf(fp, "%s\n", book->author) < 0) {
        perror("Error writing author");
        fclose(fp);
        return -1;
    }

    // Write the number of pages in the book
    if (fprintf(fp, "%d\n", book->num_pages) < 0) {
        perror("Error writing number of pages");
        fclose(fp);
        return -1;
    }

    // Write the content of the book
    if (fwrite(book->content, 1, book->num_pages * 256, fp) != book->num_pages * 256) {
        perror("Error writing content");
        fclose(fp);
        return -1;
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the book from the file
    Book *book = read_book(argv[1]);
    if (book == NULL) {
        return 1;
    }

    // Print the details of the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}