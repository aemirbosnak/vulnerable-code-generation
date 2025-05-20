//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 50
#define MAX_PUBLISHER_LEN 50
#define MAX_YEAR_LEN 4

typedef struct {
  char title[MAX_TITLE_LEN + 1];
  char author[MAX_AUTHOR_LEN + 1];
  char publisher[MAX_PUBLISHER_LEN + 1];
  int year;
} book;

void print_book(book *b) {
  printf("Title: %s\n", b->title);
  printf("Author: %s\n", b->author);
  printf("Publisher: %s\n", b->publisher);
  printf("Year: %d\n", b->year);
}

int main() {
  book books[MAX_BOOKS];
  int num_books = 0;

  // Read books from file
  FILE *fp = fopen("books.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  char line[MAX_TITLE_LEN + MAX_AUTHOR_LEN + MAX_PUBLISHER_LEN + MAX_YEAR_LEN + 5];
  while (fgets(line, sizeof(line), fp) != NULL) {
    book b;
    char *title = strtok(line, " ");
    char *author = strtok(NULL, " ");
    char *publisher = strtok(NULL, " ");
    char *year = strtok(NULL, " ");

    strcpy(b.title, title);
    strcpy(b.author, author);
    strcpy(b.publisher, publisher);
    b.year = atoi(year);

    books[num_books++] = b;
  }
  fclose(fp);

  // Print books
  for (int i = 0; i < num_books; i++) {
    print_book(&books[i]);
  }

  return 0;
}