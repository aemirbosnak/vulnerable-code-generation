//FormAI DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void readEbook(char* ebookName) {
  FILE* ebookFile = fopen(ebookName, "r");
  char* line = calloc(100, sizeof(char)); // Allocate 100 characters for each line
  while (fgets(line, 100, ebookFile)) { // Read each line of the file
    printf("%s", line); // Print the contents of each line
  }
  fclose(ebookFile); // Close the file
  free(line); // Free the memory allocated for the line
}

void browseEbook(char* ebookName, int currentPage, int totalPages) {
  printf("You are on page %d of %d.\n", currentPage, totalPages);
  printf("Press N for Next, P for Previous, or Q to Quit.\n");

  char input = getchar();
  if (input == 'n' || input == 'N') {
    if (currentPage < totalPages) {
      browseEbook(ebookName, currentPage + 1, totalPages); // Recursive call to browse the next page
    } else {
      printf("You have reached the end of the book.\n");
    }
  } else if (input == 'p' || input == 'P') {
    if (currentPage > 1) {
      browseEbook(ebookName, currentPage - 1, totalPages); // Recursive call to browse the previous page
    } else {
      printf("You are already on the first page.\n");
    }
  } else if (input == 'q' || input == 'Q') {
    printf("Goodbye!\n");
    return;
  } else {
    printf("Invalid input. Please try again.\n");
    browseEbook(ebookName, currentPage, totalPages); // Recursive call to try again
  }
}

int main() {
  printf("Welcome to the Ebook Reader!\n");
  printf("Please enter the name of the file you wish to read: ");

  char ebookName[100]; // Allocate 100 characters for the name of the ebook file
  scanf("%s", ebookName);

  FILE* ebookFile = fopen(ebookName, "r");
  if (ebookFile == NULL) { // If the file cannot be opened
    printf("Error: File could not be opened.\n");
    return 1;
  } else {
    int totalPages = 0;
    char* line = calloc(100, sizeof(char));
    while (fgets(line, 100, ebookFile)) { // Iterate through the file and count the number of pages
      totalPages++;
    }
    fclose(ebookFile);
    free(line);

    printf("This book has %d pages.\n", totalPages);

    browseEbook(ebookName, 1, totalPages); // Start browsing the ebook from the first page
    return 0;
  }
}