//FormAI DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>

int main() {
  char bookTitle[50];
  int numPages;
  float price;
  
  printf("Please enter the title of the book: ");
  scanf("%s", bookTitle);
  printf("Please enter the number of pages in %s: ", bookTitle);
  scanf("%d", &numPages);
  printf("Please enter the price of %s: $", bookTitle);
  scanf("%f", &price);

  printf("\n\n%s is %d pages long and costs $%.2f.\n", bookTitle, numPages, price);

  int currentPage = 1;
  printf("Starting Ebook Reader...\n");
  printf("Press:\n");
  printf("1 for |<<\n");
  printf("2 for <<\n");
  printf("3 for >>\n");
  printf("4 for >>|\n");
  
  int choice;
  do {
    printf("\nEnter choice (5 to exit): ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        currentPage = 1;
        printf("Back to Cover\n");
        break;
      case 2:
        if (currentPage > 1) {
          currentPage--;
          printf("Page %d\n", currentPage);
        } else {
          printf("Already at first page\n");
        }
        break;
      case 3:
        if (currentPage < numPages) {
          currentPage++;
          printf("Page %d\n", currentPage);
        } else {
          printf("Already at last page\n");
        }
        break;
      case 4:
        currentPage = numPages;
        printf("Last Page\n");
        break;
      case 5:
        printf("Exiting Ebook Reader...\n");
        break;
      default:
        printf("Invalid choice, please try again\n");
        break;
    }
    
  } while(choice != 5);

  return 0;
}