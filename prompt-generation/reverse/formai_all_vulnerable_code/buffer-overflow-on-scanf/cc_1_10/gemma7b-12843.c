//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
  char title[50];
  char author[50];
  char genre[50];
  int quantity;
  struct Book* next;
};

struct Book* InsertBook(struct Book* head, char* title, char* author, char* genre, int quantity);
struct Book* SearchBook(struct Book* head, char* title);
struct Book* DeleteBook(struct Book* head, char* title);

int main() {
  struct Book* head = NULL;
  char command;
  char title[50];
  char author[50];
  char genre[50];
  int quantity;

  while (1) {
    printf("Enter command (add/search/delete/exit): ");
    scanf("%c", &command);

    switch (command) {
      case 'a':
        printf("Enter book title: ");
        scanf("%s", title);
        printf("Enter author's name: ");
        scanf("%s", author);
        printf("Enter genre: ");
        scanf("%s", genre);
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        InsertBook(head, title, author, genre, quantity);
        break;
      case 's':
        printf("Enter book title: ");
        scanf("%s", title);
        struct Book* book = SearchBook(head, title);
        if (book) {
          printf("Book title: %s\n", book->title);
          printf("Author: %s\n", book->author);
          printf("Genre: %s\n", book->genre);
          printf("Quantity: %d\n", book->quantity);
        } else {
          printf("Book not found.\n");
        }
        break;
      case 'd':
        printf("Enter book title: ");
        scanf("%s", title);
        DeleteBook(head, title);
        break;
      case 'e':
        exit(0);
    }
  }

  return 0;
}

struct Book* InsertBook(struct Book* head, char* title, char* author, char* genre, int quantity) {
  struct Book* newBook = malloc(sizeof(struct Book));
  strcpy(newBook->title, title);
  strcpy(newBook->author, author);
  strcpy(newBook->genre, genre);
  newBook->quantity = quantity;
  newBook->next = NULL;

  if (head == NULL) {
    head = newBook;
  } else {
    struct Book* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newBook;
  }

  return head;
}

struct Book* SearchBook(struct Book* head, char* title) {
  struct Book* book = head;
  while (book) {
    if (strcmp(book->title, title) == 0) {
      return book;
    }
    book = book->next;
  }

  return NULL;
}

struct Book* DeleteBook(struct Book* head, char* title) {
  struct Book* book = head;
  struct Book* previousBook = NULL;

  while (book) {
    if (strcmp(book->title, title) == 0) {
      if (previousBook) {
        previousBook->next = book->next;
      } else {
        head = book->next;
      }
      free(book);
      return head;
    }
    previousBook = book;
    book = book->next;
  }

  return head;
}