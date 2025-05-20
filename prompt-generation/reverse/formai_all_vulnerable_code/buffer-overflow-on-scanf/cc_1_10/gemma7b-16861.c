//Gemma-7B DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK_SIZE 1024

typedef struct Book {
  char title[MAX_BOOK_SIZE];
  char content[MAX_BOOK_SIZE];
  int page_number;
} Book;

Book books[MAX_BOOK_SIZE] = {
  {"The Lord of the Flies", "A tale of a group of stranded boys...", 1},
  {"The Hobbit", "A journey of a hobbit to reclaim his stolen treasure...", 2},
  {"The Harry Potter and the Sorcerer's Stone", "The story of a young wizard...", 3}
};

void read_book(Book *book) {
  printf("You are reading: %s\n", book->title);
  printf("Page number: %d\n", book->page_number);
  printf("Content: %s\n", book->content);
}

void write_book(Book *book) {
  printf("Enter title: ");
  scanf("%s", book->title);
  printf("Enter content: ");
  scanf("%s", book->content);
  printf("Enter page number: ");
  scanf("%d", &book->page_number);
}

int main() {
  int choice;
  Book *book = &books[0];

  printf("Welcome to the Book Vault!\n");
  printf("1. Read Book\n");
  printf("2. Write Book\n");
  printf("Enter your choice: ");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      read_book(book);
      break;
    case 2:
      write_book(book);
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}