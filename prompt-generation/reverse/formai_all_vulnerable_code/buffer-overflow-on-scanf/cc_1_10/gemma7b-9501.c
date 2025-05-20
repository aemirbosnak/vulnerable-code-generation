//Gemma-7B DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 255

typedef struct Book {
  char title[255];
  char author[255];
  int pages;
  double price;
} Book;

int main() {
  Book books[] = {
    {"The Lord of the Flies", "William Golding", 320, 15.99},
    {"The Great Gatsby", "F. Scott Fitzgerald", 200, 20.00},
    {"To Kill a Mockingbird", "Harper Lee", 352, 12.99},
    {"The Catcher in the Rye", "J.D. Salinger", 200, 18.00}
  };

  char query[MAX_QUERY_LENGTH];

  printf("Enter your query: ");
  scanf("%s", query);

  int result = searchBooks(books, query);

  if (result) {
    printf("Books found:\n");
    for (int i = 0; i < result; i++) {
      printf("%s by %s, %d pages, $%.2lf\n", books[i].title, books[i].author, books[i].pages, books[i].price);
    }
  } else {
    printf("No books found.\n");
  }

  return 0;
}

int searchBooks(Book *books, char *query) {
  int numBooks = sizeof(books) / sizeof(Book);
  for (int i = 0; i < numBooks; i++) {
    if (strstr(books[i].title, query) || strstr(books[i].author, query)) {
      return i + 1;
    }
  }

  return 0;
}