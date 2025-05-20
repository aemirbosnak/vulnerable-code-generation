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
  char genre[50];
};

int main() {
  FILE *fp;
  struct Book books[100];
  int numBooks = 0;

  fp = fopen("books.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  while (!feof(fp)) {
    fscanf(fp, "%s %s %d %s", books[numBooks].title, books[numBooks].author, &books[numBooks].pages, books[numBooks].genre);
    numBooks++;
  }

  fclose(fp);

  char searchTitle[50];
  printf("Enter book title: ");
  scanf("%s", searchTitle);

  int found = 0;
  for (int i = 0; i < numBooks; i++) {
    if (strcmp(books[i].title, searchTitle) == 0) {
      found = 1;
      printf("Title: %s\n", books[i].title);
      printf("Author: %s\n", books[i].author);
      printf("Pages: %d\n", books[i].pages);
      printf("Genre: %s\n", books[i].genre);
    }
  }

  if (!found) {
    printf("Book not found.\n");
  }

  return 0;
}
