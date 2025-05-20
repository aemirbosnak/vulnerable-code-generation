//FormAI DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
  char* bookTitle;
  int pageCount;

  printf("Enter the title of the book: ");
  scanf("%s", bookTitle);

  printf("Enter the number of pages in the book: ");
  scanf("%d", &pageCount);

  FILE* book = fopen("book.txt", "r");
  if (book == NULL) {
    printf("Error: Unable to open book file.\n");
    return 1;
  }

  char* contents = (char*)malloc(sizeof(char) * (pageCount + 1));
  if (contents == NULL) {
    printf("Error: Unable to allocate memory.\n");
    return 1;
  }

  fread(contents, sizeof(char), pageCount, book);

  printf("--------------------------------------------------\n");
  printf("%s\n", bookTitle);
  printf("--------------------------------------------------\n");

  int currentPage = 1;
  char command = '\0';

  while (command != 'q') {
    printf("Page %d:\n", currentPage);
    printf("%.*s\n", 80, contents + (currentPage - 1) * 80);

    printf("Commands: 'n' for next page, 'p' for previous page, 'q' to quit.\n");
    scanf("%c", &command);

    switch (command) {
      case 'n':
        if (currentPage < pageCount) {
          currentPage++;
        }
        break;
      case 'p':
        if (currentPage > 1) {
          currentPage--;
        }
        break;
      case 'q':
        break;
      default:
        printf("Error: Invalid command.\n");
        break;
    }
  }

  free(contents);
  fclose(book);
  return 0;
}