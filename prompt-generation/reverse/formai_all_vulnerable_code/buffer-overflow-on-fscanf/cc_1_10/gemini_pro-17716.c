//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store the book
typedef struct book {
    char title[100];
    char author[100];
    char content[10000];
    int num_pages;
} book;

// Function to read the book from a file
book* read_book(char* filename) {
    FILE *fp;
    book *b;

    // Allocate memory for the book
    b = malloc(sizeof(book));

    // Open the file
    fp = fopen(filename, "r");

    // Read the title
    fscanf(fp, "%s", b->title);

    // Read the author
    fscanf(fp, "%s", b->author);

    // Read the content
    char line[100];
    while (fgets(line, 100, fp)) {
        strcat(b->content, line);
    }

    // Close the file
    fclose(fp);

    // Return the book
    return b;
}

// Function to print the book
void print_book(book *b) {
    // Print the title
    printf("%s\n", b->title);

    // Print the author
    printf("%s\n", b->author);

    // Print the content
    printf("%s\n", b->content);
}

// Function to free the memory allocated for the book
void free_book(book *b) {
    // Free the memory allocated for the book
    free(b);
}

// Main function
int main() {
    // Read the book from a file
    book *b = read_book("book.txt");

    // Print the book
    print_book(b);

    // Free the memory allocated for the book
    free_book(b);

    return 0;
}