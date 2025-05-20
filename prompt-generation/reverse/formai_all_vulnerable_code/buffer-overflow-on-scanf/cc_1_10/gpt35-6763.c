//FormAI DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>

int main() {
  // Greeting message
  printf("Welcome to the unique C Ebook reader!\n");

  // Initializing variables
  int numPages = 0;
  int currentPage = 1;
  float progress = 0.0;

  // Asking for number of pages in the book
  printf("How many pages does the book have?: ");
  scanf("%d", &numPages);

  // Main loop
  while (currentPage <= numPages) {
    // Printing current page number and progress
    printf("Page %d of %d\n", currentPage, numPages);
    printf("Progress: %.2f%%\n", progress);

    // Asking for user input
    printf("\nEnter N for next page, P for previous page or Q to quit: ");
    char input;
    scanf(" %c", &input);

    // Processing user input
    switch (input) {
      case 'N':
      case 'n':
        currentPage++;
        progress = (float) currentPage / numPages * 100.0;
        break;
      case 'P':
      case 'p':
        currentPage--;
        progress = (float) currentPage / numPages * 100.0;
        break;
      case 'Q':
      case 'q':
        // Quitting the program
        printf("Thanks for using the unique C Ebook reader!\n");
        return 0;
      default:
        // Handling invalid input
        printf("Invalid input, try again...\n");
    }
  }

  // Displaying end of the book message
  printf("\nCongratulations! You have reached the end of the book!\n");
  printf("Thanks for using the unique C Ebook reader!\n");
  return 0;
}