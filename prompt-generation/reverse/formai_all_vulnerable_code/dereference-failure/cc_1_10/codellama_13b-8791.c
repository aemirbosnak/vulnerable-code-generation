//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store book information
typedef struct {
  char* title;
  char* author;
  char* genre;
  char* publisher;
  int pages;
} Book;

// Function to print book information
void print_book(Book* book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Genre: %s\n", book->genre);
  printf("Publisher: %s\n", book->publisher);
  printf("Pages: %d\n", book->pages);
}

// Function to read book information from file
void read_book_from_file(Book* book, char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }
  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char* field = strtok(line, ",");
    if (field == NULL) {
      break;
    }
    if (strcmp(field, "title") == 0) {
      field = strtok(NULL, ",");
      book->title = strdup(field);
    } else if (strcmp(field, "author") == 0) {
      field = strtok(NULL, ",");
      book->author = strdup(field);
    } else if (strcmp(field, "genre") == 0) {
      field = strtok(NULL, ",");
      book->genre = strdup(field);
    } else if (strcmp(field, "publisher") == 0) {
      field = strtok(NULL, ",");
      book->publisher = strdup(field);
    } else if (strcmp(field, "pages") == 0) {
      field = strtok(NULL, ",");
      book->pages = atoi(field);
    }
  }
  fclose(fp);
}

// Function to save book information to file
void save_book_to_file(Book* book, char* filename) {
  FILE* fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }
  fprintf(fp, "title,%s\n", book->title);
  fprintf(fp, "author,%s\n", book->author);
  fprintf(fp, "genre,%s\n", book->genre);
  fprintf(fp, "publisher,%s\n", book->publisher);
  fprintf(fp, "pages,%d\n", book->pages);
  fclose(fp);
}

// Main function
int main(int argc, char* argv[]) {
  Book book;
  read_book_from_file(&book, argv[1]);
  print_book(&book);
  save_book_to_file(&book, argv[2]);
  return 0;
}