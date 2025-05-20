//FormAI DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
} Book;

void printBook(Book book) {
  printf("Title : %s\n", book.title);
  printf("Author : %s\n", book.author);
  printf("Subject : %s\n", book.subject);
  printf("Book ID : %d\n", book.book_id);
  printf("-----------------------\n");
}

void readEbookFile(char fileName[]) {
  FILE *file = fopen(fileName, "rb");
  if (file == NULL) {
    printf("Could not open file %s\n", fileName);
    return;
  }

  Book book;
  int booksCount = 0;
  while (fread(&book, sizeof(Book), 1, file)) {
    printBook(book);
    ++booksCount;
  }

  printf("\nTotal Books: %d\n", booksCount);
  fclose(file);
}

void writeEbookFile(char fileName[]) {
  FILE *file = fopen(fileName, "ab");
  if (file == NULL) {
    printf("Could not open file %s\n", fileName);
    return;
  }

  Book book;
  char answer;

  do {
    printf("Enter Book Title: ");
    scanf("%s", book.title);

    printf("Enter Book Author: ");
    scanf("%s", book.author);

    printf("Enter Book Subject: ");
    scanf("%s", book.subject);

    printf("Enter Book ID: ");
    scanf("%d", &book.book_id);

    fwrite(&book, sizeof(Book), 1, file);

    printf("Do you want to add another Book? (y/n): ");
    scanf(" %c", &answer);

  } while (answer != 'n');

  fclose(file);
}

int main() {
  char fileName[] = "ebooks.dat";
  char option;

  do {
    printf("Welcome to the Ebook Reader Program!\n");
    printf("Please select an option: \n");
    printf("1. Read Ebooks\n");
    printf("2. Write Ebooks\n");
    printf("3. Exit Program\n");

    scanf(" %c", &option);

    switch (option) {
      case '1':
        readEbookFile(fileName);
        break;
      case '2':
        writeEbookFile(fileName);
        break;
      case '3':
        printf("Thank you for using Ebook Reader!\n");
        break;
      default:
        printf("Invalid Option, please try again.\n");
        break;
    }
  } while (option != '3');

  return 0;
}