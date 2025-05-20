//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BOOKS 100

typedef struct Book {
  char title[50];
  char author[50];
  int quantity;
} Book;

Book books[MAX_BOOKS];

void scan_book(Book *book) {
  printf("Enter book title: ");
  scanf("%s", book->title);

  printf("Enter book author: ");
  scanf("%s", book->author);

  printf("Enter book quantity: ");
  scanf("%d", &book->quantity);
}

void update_book(Book *book) {
  printf("Enter new book title: ");
  scanf("%s", book->title);

  printf("Enter new book author: ");
  scanf("%s", book->author);

  printf("Enter new book quantity: ");
  scanf("%d", &book->quantity);
}

void delete_book(Book *book) {
  printf("Enter book title: ");
  scanf("%s", book->title);

  printf("Are you sure you want to delete this book? (Y/N): ");
  char answer;
  scanf("%c", &answer);

  if (answer == 'Y') {
    book->quantity = 0;
  }
}

void inventory() {
  printf("Inventory:\n");
  for (int i = 0; i < MAX_BOOKS; i++) {
    if (books[i].quantity > 0) {
      printf("%s by %s (Quantity: %d)\n", books[i].title, books[i].author, books[i].quantity);
    }
  }
}

int main() {
  int choice;

  printf("Welcome to the Paranoid Book Management System!\n");

  while (1) {
    printf("Please select an option:\n");
    printf("1. Scan Book\n");
    printf("2. Update Book\n");
    printf("3. Delete Book\n");
    printf("4. Inventory\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        scan_book(&books[0]);
        break;
      case 2:
        update_book(&books[0]);
        break;
      case 3:
        delete_book(&books[0]);
        break;
      case 4:
        inventory();
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }

  return 0;
}