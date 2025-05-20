#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

struct Book {
  char title[256];
  char author[256];
  int pages;
};

int main() {
  FILE *fp = fopen("books.txt", "r");
  if (fp == NULL) {
    return 1;
  }

  int numBooks = 0;
  struct Book *books = NULL;

  fscanf(fp, "%d", &numBooks);

  books = malloc(numBooks * sizeof(struct Book));

  for (int i = 0; i < numBooks; i++) {
    fscanf(fp, "%s %s %d", books[i].title, books[i].author, &books[i].pages);
  }

  fclose(fp);

  char searchTitle[256];
  printf("Enter book title: ");
  scanf("%s", searchTitle);

  int found = 0;
  for (int i = 0; i < numBooks; i++) {
    if (strcmp(books[i].title, searchTitle) == 0) {
      found = 1;
      printf("Book title: %s\n", books[i].title);
      printf("Author: %s\n", books[i].author);
      printf("Pages: %d\n", books[i].pages);
    }
  }

  if (!found) {
    printf("Book not found.\n");
  }

  return 0;
}
