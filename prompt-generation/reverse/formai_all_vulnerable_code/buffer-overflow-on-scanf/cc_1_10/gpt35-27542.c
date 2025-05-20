//FormAI DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 100
#define MAX_CHAPTERS 10

typedef struct Chapter {
  char title[MAX_STR_LEN];
  int pages;
  char* content;
} Chapter;

typedef struct Book {
  char title[MAX_STR_LEN];
  char author[MAX_STR_LEN];
  int num_chapters;
  Chapter* chapters[MAX_CHAPTERS];
} Book;

void read_chapter(Chapter* chapter) {
  printf("Enter chapter title:\n");
  scanf("%s", chapter->title);

  printf("Enter number of pages:\n");
  scanf("%d", &chapter->pages);

  printf("Enter chapter content:\n");
  chapter->content = (char*) malloc(sizeof(char) * (chapter->pages + 1));
  scanf(" %[^\n]s", chapter->content);
}

void read_book(Book* book) {
  printf("Enter book title:\n");
  scanf("%s", book->title);

  printf("Enter author name:\n");
  scanf("%s", book->author);

  printf("Enter number of chapters:\n");
  scanf("%d", &book->num_chapters);

  for(int i = 0; i < book->num_chapters; i++) {
    book->chapters[i] = (Chapter*) malloc(sizeof(Chapter));
    printf("\nEnter details of chapter %d\n", i+1);
    read_chapter(book->chapters[i]);
  }
}

void print_chapter(Chapter* chapter) {
  printf("\n---Chapter %s---\n", chapter->title);
  printf("%s\n", chapter->content);
}

void print_book(Book* book) {
  printf("\n----- %s by %s -----\n", book->title, book->author);

  for(int i = 0; i < book->num_chapters; i++) {
    print_chapter(book->chapters[i]);
  }
}

void free_book(Book* book) {
  for(int i = 0; i < book->num_chapters; i++) {
    free(book->chapters[i]->content);
    free(book->chapters[i]);
  }
}

int main() {
  Book book;
  read_book(&book);

  print_book(&book);

  free_book(&book);

  return 0;
}