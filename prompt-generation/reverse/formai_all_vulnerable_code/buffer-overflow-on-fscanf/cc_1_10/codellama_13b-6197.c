//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: decentralized
// Decentralized Ebook Reader
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing book data
typedef struct {
  char title[100];
  char author[100];
  char genre[100];
  char content[1000];
} Book;

// Function to read a book from a file
void read_book(Book *book, char *file_name) {
  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }
  fscanf(fp, "%s %s %s %s", book->title, book->author, book->genre, book->content);
  fclose(fp);
}

// Function to display a book's information
void display_book(Book book) {
  printf("Title: %s\nAuthor: %s\nGenre: %s\nContent: %s\n", book.title, book.author, book.genre, book.content);
}

// Function to search for a book by title or author
void search_book(Book *books, int num_books, char *search_term) {
  for (int i = 0; i < num_books; i++) {
    if (strstr(books[i].title, search_term) || strstr(books[i].author, search_term)) {
      display_book(books[i]);
    }
  }
}

int main() {
  // Initialize book data
  Book books[100];
  int num_books = 0;

  // Read book files
  for (int i = 1; i <= 100; i++) {
    char file_name[100];
    sprintf(file_name, "book%d.txt", i);
    read_book(&books[num_books], file_name);
    num_books++;
  }

  // Search for a book
  char search_term[100];
  printf("Enter search term: ");
  scanf("%s", search_term);
  search_book(books, num_books, search_term);

  return 0;
}