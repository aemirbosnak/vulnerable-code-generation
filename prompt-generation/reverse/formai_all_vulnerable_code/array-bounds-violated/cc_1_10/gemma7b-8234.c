//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 10

typedef struct Book {
  char title[50];
  char author[50];
  char genre[50];
  int quantity;
  int id;
} Book;

typedef struct Member {
  char name[50];
  char address[100];
  int membership_id;
  int books_borrowed;
} Member;

Book books[MAX_BOOKS];
Member members[MAX_MEMBERS];

void addBook(Book book) {
  int i = 0;
  for (; i < MAX_BOOKS && books[i].id != -1; i++) {}
  books[i] = book;
}

void addMember(Member member) {
  int i = 0;
  for (; i < MAX_MEMBERS && members[i].membership_id != -1; i++) {}
  members[i] = member;
}

void borrowBook(Book book, Member member) {
  book.quantity--;
  member.books_borrowed++;
}

void returnBook(Book book, Member member) {
  book.quantity++;
  member.books_borrowed--;
}

int main() {
  time_t t = time(NULL);
  srand(t);

  Book book1 = {"The Lord of the Flies", "William Golding", "Classic", 5, -1};
  addBook(book1);

  Member member1 = {"John Doe", "123 Main St", 1, 0};
  addMember(member1);

  borrowBook(book1, member1);

  returnBook(book1, member1);

  return 0;
}