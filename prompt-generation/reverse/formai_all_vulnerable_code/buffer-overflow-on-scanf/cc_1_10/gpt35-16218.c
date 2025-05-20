//FormAI DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_FILENAME 100

struct Book {
  char title[100];
  char author[50];
  int year_published;
  char filename[MAX_FILENAME];
};

const char* BOOKS_DB_FILENAME = "books.dat";

void show_menu() {
  printf("Welcome to My Ebook Reader App\n");
  printf("1. List all books\n");
  printf("2. Add a book\n");
  printf("3. Open a book\n");
  printf("4. Quit\n");
}

void list_books() {
  FILE* fp = fopen(BOOKS_DB_FILENAME, "rb");
  if (fp == NULL) {
    printf("Error opening books database file.\n");
    return;
  }

  struct Book books[MAX_BOOKS];
  int n = 0;

  while (fread(&books[n], sizeof(struct Book), 1, fp) > 0) {
    printf("%d. %s by %s (%d)\n", n + 1, books[n].title, books[n].author, books[n].year_published);
    n++;
    if (n >= MAX_BOOKS)
      break;
  }

  fclose(fp);
}

void add_book() {
  struct Book book;
  printf("Enter title: ");
  fgets(book.title, 100, stdin);
  book.title[strlen(book.title) - 1] = '\0';
  printf("Enter author: ");
  fgets(book.author, 50, stdin);
  book.author[strlen(book.author) - 1] = '\0';
  printf("Enter year published: ");
  scanf("%d", &book.year_published);
  printf("Enter filename: ");
  scanf("%s", book.filename);

  FILE* fp = fopen(BOOKS_DB_FILENAME, "ab");
  if (fp == NULL) {
    printf("Error opening books database file.\n");
    return;
  }

  fwrite(&book, sizeof(struct Book), 1, fp);
  fclose(fp);
}

void open_book() {
  char filename[MAX_FILENAME];
  printf("Enter filename: ");
  scanf("%s", filename);
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening book file.\n");
    return;
  }

  char c;
  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }

  fclose(fp);
}

int main() {
  int choice;
  do {
    show_menu();
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        list_books();
        break;
      case 2:
        add_book();
        break;
      case 3:
        open_book();
        break;
      case 4:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 4);

  return 0;
}