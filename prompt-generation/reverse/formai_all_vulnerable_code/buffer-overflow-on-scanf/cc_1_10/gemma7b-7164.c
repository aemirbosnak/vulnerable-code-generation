//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void main() {
  int choice, quantity, total_price = 0, item_price;
  char item_name[20];

  // Display menu items
  printf("*** Welcome to C Cafe ***\n");
  printf("-------------------\n");
  printf("1. Coffee\t\tPrice: $5\n");
  printf("2. Tea\t\tPrice: $3\n");
  printf("3. Juice\t\tPrice: $4\n");
  printf("4. Smoothie\t\tPrice: $6\n");
  printf("-------------------\n");

  // Get user input
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Calculate item price based on user choice
  switch (choice) {
    case 1:
      item_price = 5;
      strcpy(item_name, "Coffee");
      break;
    case 2:
      item_price = 3;
      strcpy(item_name, "Tea");
      break;
    case 3:
      item_price = 4;
      strcpy(item_name, "Juice");
      break;
    case 4:
      item_price = 6;
      strcpy(item_name, "Smoothie");
      break;
    default:
      printf("Invalid choice.\n");
      return;
  }

  // Get quantity
  printf("Enter the quantity: ");
  scanf("%d", &quantity);

  // Calculate total price
  total_price = item_price * quantity;

  // Display receipt
  printf("-------------------\n");
  printf("Item: %s\n", item_name);
  printf("Quantity: %d\n", quantity);
  printf("Total Price: $%d\n", total_price);
  printf("Thank you for your visit!\n");
  printf("-------------------\n");

  return;
}