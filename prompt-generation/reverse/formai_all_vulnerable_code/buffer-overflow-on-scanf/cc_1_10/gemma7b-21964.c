//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void introspective_ebook_reader() {
  char book_title[200];
  char book_author[200];
  int pages_read = 0;
  int pages_total = 0;
  char current_chapter[200];
  char reading_status[200];

  printf("Enter the title of the book you are reading:");
  scanf("%s", book_title);

  printf("Enter the author of the book:");
  scanf("%s", book_author);

  printf("Enter the total number of pages in the book:");
  scanf("%d", &pages_total);

  printf("Enter the number of pages you have read:");
  scanf("%d", &pages_read);

  printf("Enter the current chapter you are reading:");
  scanf("%s", current_chapter);

  printf("Enter your reading status:");
  scanf("%s", reading_status);

  printf("\nBook Information:");
  printf("Title: %s\n", book_title);
  printf("Author: %s\n", book_author);
  printf("Total Pages: %d\n", pages_total);
  printf("Pages Read: %d\n", pages_read);
  printf("Current Chapter: %s\n", current_chapter);
  printf("Reading Status: %s\n", reading_status);

  printf("\nWould you like to continue reading? (Y/N)");
  char continue_reading;
  scanf("%c", &continue_reading);

  if (continue_reading == 'Y') {
    introspective_ebook_reader();
  } else {
    printf("Thank you for reading!\n");
  }
}

int main() {
  introspective_ebook_reader();

  return 0;
}