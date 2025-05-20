//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
// A unique C Ebook reader example program in an enthusiastic style

#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  int book_size;
  char* book_title;
  char* book_author;
  char* book_publisher;
  int book_pages;

  // Get book size
  printf("Enter book size (in MB): ");
  scanf("%d", &book_size);

  // Get book title
  printf("Enter book title: ");
  book_title = malloc(100 * sizeof(char));
  scanf("%s", book_title);

  // Get book author
  printf("Enter book author: ");
  book_author = malloc(100 * sizeof(char));
  scanf("%s", book_author);

  // Get book publisher
  printf("Enter book publisher: ");
  book_publisher = malloc(100 * sizeof(char));
  scanf("%s", book_publisher);

  // Get book pages
  printf("Enter number of pages: ");
  scanf("%d", &book_pages);

  // Display book information
  printf("Book Information:\n");
  printf("Title: %s\n", book_title);
  printf("Author: %s\n", book_author);
  printf("Publisher: %s\n", book_publisher);
  printf("Pages: %d\n", book_pages);

  // Free memory
  free(book_title);
  free(book_author);
  free(book_publisher);

  return 0;
}