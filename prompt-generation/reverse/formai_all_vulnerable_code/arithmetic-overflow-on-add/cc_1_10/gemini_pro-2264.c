//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int length;
  char *text;
} Book;

Book *read_book(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    return NULL;
  }

  Book *book = malloc(sizeof(Book));
  if (book == NULL) {
    perror("malloc");
    fclose(fp);
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  book->length = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  book->text = malloc(book->length + 1);
  if (book->text == NULL) {
    perror("malloc");
    fclose(fp);
    free(book);
    return NULL;
  }

  fread(book->text, 1, book->length, fp);
  book->text[book->length] = '\0';

  fclose(fp);

  return book;
}

void free_book(Book *book) {
  if (book->name != NULL) {
    free(book->name);
  }
  if (book->text != NULL) {
    free(book->text);
  }
  free(book);
}

void print_book(Book *book) {
  printf("%s\n", book->name);
  printf("%d\n", book->length);
  printf("%s\n", book->text);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  Book *book = read_book(argv[1]);
  if (book == NULL) {
    return EXIT_FAILURE;
  }

  print_book(book);

  free_book(book);

  return EXIT_SUCCESS;
}