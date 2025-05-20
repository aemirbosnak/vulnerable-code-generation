//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
// C Ebook reader example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about a book
struct Book {
  char title[100];
  char author[100];
  char genre[100];
  int pages;
};

// Function to print information about a book
void print_book(struct Book book) {
  printf("Title: %s\n", book.title);
  printf("Author: %s\n", book.author);
  printf("Genre: %s\n", book.genre);
  printf("Pages: %d\n", book.pages);
}

// Function to read a book from a file
struct Book read_book(FILE *file) {
  struct Book book;
  fscanf(file, "%s %s %s %d", book.title, book.author, book.genre, &book.pages);
  return book;
}

// Function to print all the books in a library
void print_library(struct Book *books, int num_books) {
  for (int i = 0; i < num_books; i++) {
    print_book(books[i]);
    printf("\n");
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Open the book file
  FILE *file = fopen("books.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read the books from the file
  int num_books;
  fscanf(file, "%d", &num_books);
  struct Book *books = malloc(num_books * sizeof(struct Book));
  for (int i = 0; i < num_books; i++) {
    books[i] = read_book(file);
  }

  // Print the books
  print_library(books, num_books);

  // Close the file
  fclose(file);

  // Free the memory
  free(books);

  return 0;
}