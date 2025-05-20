//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>

int main() {
  // Initialization
  int itemsSold = 0;
  float price = 0;
  float total = 0;
  
  int option;
  do {
    // Display menu
    printf("\n------ C Cafe Billing System ------\n");
    printf("1. Add item to bill\n");
    printf("2. Show total bill\n");
    printf("3. Exit\n");
    printf("\nEnter an option: ");
    scanf("%d", &option);

    // Process menu options
    switch (option) {
      case 1:
        // Ask for item price and add to total
        printf("\nEnter item price: ");
        scanf("%f", &price);
        total += price;
        itemsSold++;
        printf("Item added to bill.\n");
        break;

      case 2:
        // Show total bill
        if (itemsSold == 0) {
          printf("\nNo items in bill yet.\n");
        } else {
          printf("\nTotal: $%.2f\n", total);
        }
        break;

      case 3:
        // Exit
        printf("\nExiting C Cafe Billing System...\n");
        break;

      default:
        printf("\nInvalid option. Please try again.\n");
        break;
    }
  } while (option != 3);

  return 0;
}