//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOK_SIZE 1024 * 1024

typedef struct {
  char *title;
  char *author;
  char *text;
  int size;
} Book;

void print_book(Book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Text:\n");
  printf("%s", book->text);
}

Book *load_book(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the title
  char title[MAX_LINE_LENGTH];
  if (fgets(title, MAX_LINE_LENGTH, file) == NULL) {
    perror("Error reading title");
    fclose(file);
    return NULL;
  }
  title[strlen(title) - 1] = '\0'; // Remove the newline character

  // Read the author
  char author[MAX_LINE_LENGTH];
  if (fgets(author, MAX_LINE_LENGTH, file) == NULL) {
    perror("Error reading author");
    fclose(file);
    return NULL;
  }
  author[strlen(author) - 1] = '\0'; // Remove the newline character

  // Read the text
  int size = 0;
  char *text = malloc(MAX_BOOK_SIZE);
  if (text == NULL) {
    perror("Error allocating memory for text");
    fclose(file);
    return NULL;
  }
  while (fgets(text + size, MAX_BOOK_SIZE - size, file) != NULL) {
    size += strlen(text + size);
  }
  text[size] = '\0'; // Null-terminate the text

  fclose(file);

  // Create the book
  Book *book = malloc(sizeof(Book));
  if (book == NULL) {
    perror("Error allocating memory for book");
    free(text);
    return NULL;
  }
  book->title = malloc(strlen(title) + 1);
  book->author = malloc(strlen(author) + 1);
  book->text = malloc(size + 1);
  if (book->title == NULL || book->author == NULL || book->text == NULL) {
    perror("Error allocating memory for book fields");
    free(book);
    free(text);
    return NULL;
  }
  strcpy(book->title, title);
  strcpy(book->author, author);
  strcpy(book->text, text);
  book->size = size;

  return book;
}

void free_book(Book *book) {
  free(book->title);
  free(book->author);
  free(book->text);
  free(book);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  Book *book = load_book(argv[1]);
  if (book == NULL) {
    return EXIT_FAILURE;
  }

  print_book(book);

  free_book(book);

  return EXIT_SUCCESS;
}