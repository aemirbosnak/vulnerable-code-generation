//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
  char title[50];
  char author[50];
  int quantity;
  struct Book* next;
} Book;

Book* insertBook(Book* head) {
  Book* newBook = malloc(sizeof(Book));
  newBook->quantity = 0;

  printf("Enter book title: ");
  scanf("%s", newBook->title);

  printf("Enter book author: ");
  scanf("%s", newBook->author);

  newBook->next = head;
  head = newBook;

  return head;
}

void searchBook(Book* head, char* title) {
  Book* currentBook = head;

  while (currentBook) {
    if (strcmp(currentBook->title, title) == 0) {
      printf("Book found: %s by %s\n", currentBook->title, currentBook->author);
      printf("Quantity: %d\n", currentBook->quantity);
      break;
    }

    currentBook = currentBook->next;
  }

  if (currentBook == NULL) {
    printf("Book not found.\n");
  }
}

int main() {
  Book* head = NULL;

  while (1) {
    printf("Enter command: ");
    char command[20];
    scanf("%s", command);

    if (strcmp(command, "insert") == 0) {
      head = insertBook(head);
    } else if (strcmp(command, "search") == 0) {
      char title[50];
      printf("Enter book title: ");
      scanf("%s", title);
      searchBook(head, title);
    } else if (strcmp(command, "exit") == 0) {
      exit(0);
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}