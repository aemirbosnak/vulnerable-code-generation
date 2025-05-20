//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line in the book
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines in the book
#define MAX_LINES 1000

// Define the structure of a book
typedef struct {
  char title[100];
  char author[100];
  int num_lines;
  char lines[MAX_LINES][MAX_LINE_LENGTH];
} Book;

// Load a book from a file
Book *load_book(char *filename) {
  // Allocate memory for the book
  Book *book = malloc(sizeof(Book));

  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Read the title and author from the file
  fscanf(file, "%s %s", book->title, book->author);

  // Read the number of lines in the book
  fscanf(file, "%d", &book->num_lines);

  // Read the lines from the file
  for (int i = 0; i < book->num_lines; i++) {
    fgets(book->lines[i], MAX_LINE_LENGTH, file);
  }

  // Close the file
  fclose(file);

  // Return the book
  return book;
}

// Print a book to the console
void print_book(Book *book) {
  // Print the title and author of the book
  printf("%s by %s\n", book->title, book->author);

  // Print the lines of the book
  for (int i = 0; i < book->num_lines; i++) {
    printf("%s", book->lines[i]);
  }
}

// Free the memory allocated for a book
void free_book(Book *book) {
  // Free the memory allocated for the book's lines
  for (int i = 0; i < book->num_lines; i++) {
    free(book->lines[i]);
  }

  // Free the memory allocated for the book
  free(book);
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided a filename
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Load the book from the file
  Book *book = load_book(argv[1]);

  // Check if the book was loaded successfully
  if (book == NULL) {
    printf("Error loading book from file %s\n", argv[1]);
    return 1;
  }

  // Print the book to the console
  print_book(book);

  // Free the memory allocated for the book
  free_book(book);

  return 0;
}