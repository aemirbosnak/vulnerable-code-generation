//FormAI DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
  char title[100];
  char author[100];
  char publisher[100];
  int year;
  float price;
} book_t;

typedef struct {
  char title[100];
  int pageNumber;
  int currentPage;
  int bookmarked;
} ebook_t;

int main() {
  book_t library[MAX_BOOKS];
  ebook_t currentBook;
  int numBooks = 0;
  char fileName[MAX_FILE_NAME_LENGTH];
  FILE *fp;

  // Read books from file
  printf("Enter filename to load books: ");
  scanf("%s", fileName);
  fp = fopen(fileName, "r");
  if (fp != NULL) {
    while (!feof(fp) && numBooks < MAX_BOOKS) {
      fscanf(fp, "%[^,],%[^,],%[^,],%d,%f\n", library[numBooks].title,
             library[numBooks].author, library[numBooks].publisher,
             &library[numBooks].year, &library[numBooks].price);
      numBooks++;
    }
    fclose(fp);
  } else {
    printf("File not found.\n");
  }

  // Select book to read
  printf("Choose a book:\n");
  for (int i = 0; i < numBooks; i++) {
    printf("%d. %s\n", i, library[i].title);
  }
  int bookChoice;
  scanf("%d", &bookChoice);
  strcpy(currentBook.title, library[bookChoice].title);
  currentBook.pageNumber = 1;
  currentBook.currentPage = 1;
  currentBook.bookmarked = 0;

  // Display book
  printf("\nReading: %s\n", currentBook.title);
  printf("Page %d of %d\n\n", currentBook.currentPage, currentBook.pageNumber);
  printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec auctor "
         "eleifend turpis non pulvinar. Ut euismod nisl eu ipsum tincidunt "
         "aliquam. Morbi hendrerit in nibh nec porta. Sed tristique, purus a "
         "rhoncus malesuada, orci dolor fermentum lorem, eget dictum odio ex a "
         "elit. Aliquam velit tellus, faucibus et libero in, interdum molestie "
         "ante. Vestibulum vestibulum metus in ligula semper, in rutrum purus "
         "facilisis. Donec in congue dui. Vivamus ac est finibus, consectetur "
         "urna vitae, aliquam libero. Sed volutpat vestibulum eleifend. "
         "Suspendisse potenti. Sed id nibh vitae eros interdum vestibulum ut "
         "eget dui.");

  // Allow user to navigate ebook
  char selection;
  while (1) {
    printf("\n\nMenu:\n");
    printf("N - Next Page\n");
    printf("B - Bookmark\n");
    printf("G - Go to Page\n");
    printf("Q - Quit\n");
    scanf(" %c", &selection);
    if (selection == 'N') {
      if (currentBook.currentPage < currentBook.pageNumber) {
        currentBook.currentPage++;
      } else {
        printf("\nEnd of book.\n");
      }
    } else if (selection == 'B') {
      if (currentBook.bookmarked) {
        printf("\nBookmark removed.\n");
        currentBook.bookmarked = 0;
      } else {
        printf("\nBookmark set.\n");
        currentBook.bookmarked = 1;
      }
    } else if (selection == 'G') {
      printf("\nEnter page number: ");
      scanf("%d", &currentBook.currentPage);
      if (currentBook.currentPage < 1) {
        printf("\nInvalid page number.\n");
        currentBook.currentPage = 1;
      } else if (currentBook.currentPage > currentBook.pageNumber) {
        printf("\nPage number exceeds number of pages in book.\n");
        currentBook.currentPage = currentBook.pageNumber;
      }
    } else if (selection == 'Q') {
      break;
    } else {
      printf("\nInvalid selection.\n");
    }
    printf("\nReading: %s\n", currentBook.title);
    printf("Page %d of %d\n", currentBook.currentPage, currentBook.pageNumber);
    if (currentBook.bookmarked) {
      printf("Bookmarked\n");
    }
  }

  return 0;
}