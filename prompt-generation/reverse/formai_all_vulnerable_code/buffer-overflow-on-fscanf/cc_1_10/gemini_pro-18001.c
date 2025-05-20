//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct Book {
  char *title;
  char *author;
  int num_pages;
  char *text;
} Book;

// Open a book from a file
Book *open_book(const char *filename) {
  // Allocate memory for the book
  Book *book = malloc(sizeof(Book));
  if (!book) {
    return NULL;
  }

  // Open the file
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    free(book);
    return NULL;
  }

  // Read the title
  char *title = malloc(100);
  if (!title) {
    fclose(fp);
    free(book);
    return NULL;
  }
  fscanf(fp, "%s", title);
  book->title = title;

  // Read the author
  char *author = malloc(100);
  if (!author) {
    fclose(fp);
    free(book->title);
    free(book);
    return NULL;
  }
  fscanf(fp, "%s", author);
  book->author = author;

  // Read the number of pages
  int num_pages;
  fscanf(fp, "%d", &num_pages);
  book->num_pages = num_pages;

  // Read the text
  char *text = malloc(num_pages * 100);
  if (!text) {
    fclose(fp);
    free(book->title);
    free(book->author);
    free(book);
    return NULL;
  }
  fscanf(fp, "%s", text);
  book->text = text;

  // Close the file
  fclose(fp);

  // Return the book
  return book;
}

// Close a book
void close_book(Book *book) {
  // Free the memory allocated for the book
  free(book->title);
  free(book->author);
  free(book->text);
  free(book);
}

// Print a book
void print_book(Book *book) {
  // Print the title and author
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);

  // Print the text
  printf("%s\n", book->text);
}

// Main function
int main() {
  // Open a book
  Book *book = open_book("book.txt");
  if (!book) {
    printf("Error opening book\n");
    return 1;
  }

  // Print the book
  print_book(book);

  // Close the book
  close_book(book);

  return 0;
}