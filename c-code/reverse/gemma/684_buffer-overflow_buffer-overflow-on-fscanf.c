#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

struct Book {
  char title[50];
  char author[50];
  int pages;
};

void readBooks(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return;
  }

  int numBooks = 0;
  fscanf(fp, "Number of books: %d", &numBooks);

  struct Book *books = malloc(numBooks * sizeof(struct Book));
  if (books == NULL) {
    return;
  }

  for (int i = 0; i < numBooks; i++) {
    fscanf(fp, "Title: %s", books[i].title);
    fscanf(fp, "Author: %s", books[i].author);
    fscanf(fp, "Pages: %d", &books[i].pages);
  }

  fclose(fp);
  return books;
}

int main() {
  readBooks("books.txt");
  return 0;
}
