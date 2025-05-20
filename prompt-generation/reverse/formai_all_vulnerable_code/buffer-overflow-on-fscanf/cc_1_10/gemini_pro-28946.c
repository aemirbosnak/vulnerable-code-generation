//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *title;
  char *author;
  char *content;
} Book;

Book *read_book(char *filename) {
  FILE *fp;
  Book *book;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  book = malloc(sizeof(Book));
  if (book == NULL) {
    fclose(fp);
    return NULL;
  }

  book->title = malloc(100);
  if (book->title == NULL) {
    free(book);
    fclose(fp);
    return NULL;
  }

  book->author = malloc(100);
  if (book->author == NULL) {
    free(book->title);
    free(book);
    fclose(fp);
    return NULL;
  }

  book->content = malloc(1000);
  if (book->content == NULL) {
    free(book->title);
    free(book->author);
    free(book);
    fclose(fp);
    return NULL;
  }

  fscanf(fp, "%s\n", book->title);
  fscanf(fp, "%s\n", book->author);
  fscanf(fp, "%[^\n]\n", book->content);

  fclose(fp);

  return book;
}

void print_book(Book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Content: %s\n", book->content);
}

int main(int argc, char **argv) {
  Book *book;

  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  book = read_book(argv[1]);
  if (book == NULL) {
    printf("Error reading book from file.\n");
    return 1;
  }

  print_book(book);

  free(book->title);
  free(book->author);
  free(book->content);
  free(book);

  return 0;
}