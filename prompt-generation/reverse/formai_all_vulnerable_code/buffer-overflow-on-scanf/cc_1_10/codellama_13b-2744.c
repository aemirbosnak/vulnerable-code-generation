//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: paranoid
// Paranoid Ebook Reader Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the book data
struct book {
  char title[50];
  char author[50];
  char genre[50];
  char year[50];
};

// Function to read the book data from the user
void read_book(struct book *b) {
  printf("Enter the book title: ");
  fgets(b->title, 50, stdin);
  printf("Enter the book author: ");
  fgets(b->author, 50, stdin);
  printf("Enter the book genre: ");
  fgets(b->genre, 50, stdin);
  printf("Enter the book year: ");
  fgets(b->year, 50, stdin);
}

// Function to display the book data
void display_book(struct book b) {
  printf("Book Title: %s\n", b.title);
  printf("Book Author: %s\n", b.author);
  printf("Book Genre: %s\n", b.genre);
  printf("Book Year: %s\n", b.year);
}

// Function to search for a book
void search_book(struct book *b, int n) {
  char search_title[50];
  char search_author[50];
  char search_genre[50];
  char search_year[50];

  printf("Enter the book title to search: ");
  fgets(search_title, 50, stdin);
  printf("Enter the book author to search: ");
  fgets(search_author, 50, stdin);
  printf("Enter the book genre to search: ");
  fgets(search_genre, 50, stdin);
  printf("Enter the book year to search: ");
  fgets(search_year, 50, stdin);

  for (int i = 0; i < n; i++) {
    if (strcmp(b[i].title, search_title) == 0 &&
        strcmp(b[i].author, search_author) == 0 &&
        strcmp(b[i].genre, search_genre) == 0 &&
        strcmp(b[i].year, search_year) == 0) {
      display_book(b[i]);
    }
  }
}

int main() {
  struct book books[100];
  int n = 0;

  printf("Enter the number of books: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    read_book(&books[i]);
  }

  printf("Enter the search criteria: ");
  search_book(books, n);

  return 0;
}