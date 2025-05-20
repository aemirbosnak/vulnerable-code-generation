//FormAI DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 500

typedef struct {
  char title[MAX_TITLE_LENGTH];
  char author[MAX_AUTHOR_LENGTH];
  int pages;
} Book;

typedef struct {
  Book* books[MAX_PAGES];
  int num_books;
} Library;

int main() {
  Library library;
  library.num_books = 0;

  char user_input[50];
  while (1) {
    printf("Enter 'add' to add a book or 'view' to view all books: ");
    fgets(user_input, 50, stdin);

    if (strcmp(user_input, "add\n") == 0) {
      if (library.num_books == MAX_PAGES) {
        printf("Sorry, the library is full!\n");
        continue;
      }

      Book* new_book = malloc(sizeof(Book));
      printf("Enter the title of the book: ");
      fgets(new_book->title, MAX_TITLE_LENGTH, stdin);
      printf("Enter the author of the book: ");
      fgets(new_book->author, MAX_AUTHOR_LENGTH, stdin);
      printf("Enter the number of pages in the book: ");
      scanf("%d", &new_book->pages);
      getchar(); // Remove newline character from input buffer

      library.books[library.num_books] = new_book;
      library.num_books++;
    } else if (strcmp(user_input, "view\n") == 0) {
      if (library.num_books == 0) {
        printf("The library is empty!\n");
        continue;
      }

      for (int i = 0; i < library.num_books; i++) {
        Book* current_book = library.books[i];
        printf("%s by %s - %d pages\n", current_book->title, current_book->author, current_book->pages);
      }
    } else {
      printf("Invalid input!\n");
      continue;
    }
  }
  return 0;
}