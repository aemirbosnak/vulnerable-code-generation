//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR 20

struct book {
  char title[50];
  char author[50];
  int quantity;
  int id;
};

struct book books[MAX_BOOKS];

void addBook() {
  books[MAX_BOOKS - 1].id = MAX_BOOKS - 1;
  printf("Enter book title: ");
  scanf("%s", books[MAX_BOOKS - 1].title);
  printf("Enter book author: ");
  scanf("%s", books[MAX_BOOKS - 1].author);
  printf("Enter book quantity: ");
  scanf("%d", &books[MAX_BOOKS - 1].quantity);
  books[MAX_BOOKS - 1].quantity++;
}

void searchBook() {
  char title[50];
  printf("Enter book title: ");
  scanf("%s", title);
  int found = 0;
  for (int i = 0; i < MAX_BOOKS; i++) {
    if (strcmp(books[i].title, title) == 0) {
      found = 1;
      printf("Book title: %s\n", books[i].title);
      printf("Book author: %s\n", books[i].author);
      printf("Book quantity: %d\n", books[i].quantity);
    }
  }
  if (!found) {
    printf("Book not found.\n");
  }
}

void updateBookQuantity() {
  char title[50];
  printf("Enter book title: ");
  scanf("%s", title);
  int found = 0;
  for (int i = 0; i < MAX_BOOKS; i++) {
    if (strcmp(books[i].title, title) == 0) {
      found = 1;
      printf("Enter new book quantity: ");
      scanf("%d", &books[i].quantity);
    }
  }
  if (!found) {
    printf("Book not found.\n");
  }
}

void deleteBook() {
  char title[50];
  printf("Enter book title: ");
  scanf("%s", title);
  int found = 0;
  for (int i = 0; i < MAX_BOOKS; i++) {
    if (strcmp(books[i].title, title) == 0) {
      found = 1;
      books[i].quantity--;
    }
  }
  if (!found) {
    printf("Book not found.\n");
  }
}

int main() {
  int choice;
  printf("Welcome to the Music Library Management System!\n");
  printf("1. Add Book\n");
  printf("2. Search Book\n");
  printf("3. Update Book Quantity\n");
  printf("4. Delete Book\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      addBook();
      break;
    case 2:
      searchBook();
      break;
    case 3:
      updateBookQuantity();
      break;
    case 4:
      deleteBook();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}