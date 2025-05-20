//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayBookList(char **books) {
  int i = 0;
  printf("Here is your book list:\n");
  for (i = 0; books[i] != NULL; i++) {
    printf("%s\n", books[i]);
  }
}

void addBook(char **books) {
  char *newBook = malloc(50);
  printf("Enter the name of the new book: ");
  scanf("%s", newBook);
  books = realloc(books, (strlen(books) + 1) * sizeof(char *));
  books[strlen(books)] = newBook;
}

void searchBook(char **books) {
  char searchTerm[50];
  printf("Enter the search term: ");
  scanf("%s", searchTerm);
  int i = 0;
  for (i = 0; books[i] != NULL; i++) {
    if (strstr(books[i], searchTerm) != NULL) {
      printf("%s\n", books[i]);
    }
  }
}

int main() {
  char **books = NULL;
  int choice;

  while (1) {
    printf("1. Display book list\n");
    printf("2. Add a book\n");
    printf("3. Search for a book\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        displayBookList(books);
        break;
      case 2:
        addBook(books);
        break;
      case 3:
        searchBook(books);
        break;
      default:
        printf("Invalid input.\n");
        break;
    }

    printf("Do you want to continue? (Y/N): ");
    char continueChoice;
    scanf("%c", &continueChoice);

    if (continueChoice == 'N') {
      break;
    }
  }

  return 0;
}