//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

// Define the size of the buffer for reading the file
#define BUFFER_SIZE 4096

// Define the maximum number of lines in the file
#define MAX_LINES 1000

// Define the maximum length of a line in the file
#define MAX_LINE_LENGTH 1024

// Define the structure of a page in the book
typedef struct {
  char *text;
  int num_lines;
} Page;

// Define the structure of a book
typedef struct {
  char *title;
  int num_pages;
  Page *pages;
} Book;

// Create a new book
Book *new_book(char *title, int num_pages) {
  Book *book = malloc(sizeof(Book));
  book->title = strdup(title);
  book->num_pages = num_pages;
  book->pages = malloc(sizeof(Page) * num_pages);
  return book;
}

// Free the memory allocated for a book
void free_book(Book *book) {
  free(book->title);
  for (int i = 0; i < book->num_pages; i++) {
    free(book->pages[i].text);
  }
  free(book->pages);
  free(book);
}

// Load a book from a file
Book *load_book(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the title of the book
  char title[MAX_LINE_LENGTH];
  if (fgets(title, MAX_LINE_LENGTH, fp) == NULL) {
    perror("Error reading title");
    fclose(fp);
    return NULL;
  }

  // Read the number of pages in the book
  int num_pages;
  if (fscanf(fp, "%d", &num_pages) != 1) {
    perror("Error reading number of pages");
    fclose(fp);
    return NULL;
  }

  // Create a new book
  Book *book = new_book(title, num_pages);

  // Read the text of each page
  for (int i = 0; i < num_pages; i++) {
    // Allocate memory for the text of the page
    book->pages[i].text = malloc(BUFFER_SIZE);
    book->pages[i].num_lines = 0;

    // Read the text of the page
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
      // Append the text of the line to the page
      strcat(book->pages[i].text, buffer);

      // Increment the number of lines in the page
      book->pages[i].num_lines++;
    }
  }

  // Close the file
  fclose(fp);

  return book;
}

// Print a book
void print_book(Book *book) {
  // Print the title of the book
  printf("Title: %s\n", book->title);

  // Print the number of pages in the book
  printf("Number of pages: %d\n", book->num_pages);

  // Print the text of each page
  for (int i = 0; i < book->num_pages; i++) {
    printf("Page %d:\n", i + 1);
    printf("%s", book->pages[i].text);
  }
}

// Main function
int main(int argc, char **argv) {
  // Check the number of arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Load the book from the file
  Book *book = load_book(argv[1]);
  if (book == NULL) {
    return EXIT_FAILURE;
  }

  // Print the book
  print_book(book);

  // Free the memory allocated for the book
  free_book(book);

  return EXIT_SUCCESS;
}