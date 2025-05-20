//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
  char title[100];
  char author[100];
  int num_pages;
  char *text;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *text) {
  Book *book = (Book *)malloc(sizeof(Book));
  strcpy(book->title, title);
  strcpy(book->author, author);
  book->num_pages = num_pages;
  book->text = (char *)malloc(strlen(text) + 1);
  strcpy(book->text, text);
  return book;
}

// Function to read a book from a file
Book *read_book_from_file(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the title, author, and number of pages
  char title[100];
  char author[100];
  int num_pages;
  fscanf(fp, "%s %s %d", title, author, &num_pages);

  // Read the text of the book
  char *text = (char *)malloc(100000);
  while (!feof(fp)) {
    fgets(text, 100000, fp);
  }

  fclose(fp);

  // Create the book
  Book *book = create_book(title, author, num_pages, text);

  return book;
}

// Function to print a book
void print_book(Book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Number of pages: %d\n", book->num_pages);
  printf("Text: %s\n", book->text);
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
  free(book->text);
  free(book);
}

int main() {
  // Read the book from a file
  Book *book = read_book_from_file("book.txt");

  // Print the book
  print_book(book);

  // Free the memory allocated for the book
  free_book(book);

  return 0;
}