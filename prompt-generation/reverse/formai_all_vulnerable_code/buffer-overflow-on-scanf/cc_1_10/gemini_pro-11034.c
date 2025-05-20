//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
char menuItems[][20] = {"Coffee", "Tea", "Pastry", "Sandwich"};
float menuPrices[] = {1.50, 1.25, 2.00, 4.50};

// Define the function to print the menu
void printMenu() {
  printf("Welcome to our cafe!\n\n");
  printf("Here is our menu:\n\n");
  for (int i = 0; i < 4; i++) {
    printf("%s: $%.2f\n", menuItems[i], menuPrices[i]);
  }
  printf("\n");
}

// Define the function to get the user's order
void getOrder(char order[], float *total) {
  char item[20];
  int quantity;
  float price;

  printf("What would you like to order? ");
  scanf("%s", item);

  // Find the price of the item
  for (int i = 0; i < 4; i++) {
    if (strcmp(item, menuItems[i]) == 0) {
      price = menuPrices[i];
      break;
    }
  }

  // Get the quantity of the item
  printf("How many would you like? ");
  scanf("%d", &quantity);

  // Calculate the total price of the order
  *total += price * quantity;

  // Print the order
  printf("You ordered %d %s for a total of $%.2f\n\n", quantity, item, price * quantity);
}

// Define the function to print the bill
void printBill(float total) {
  printf("Your total is $%.2f\n", total);
  printf("Thank you for your patronage!\n");
  printf("Please come again soon!\n\n");
}

// Define the main function
int main() {
  char order[20];
  float total = 0.0;

  // Print the menu
  printMenu();

  // Get the user's order
  while (strcmp(order, "quit") != 0) {
    getOrder(order, &total);
  }

  // Print the bill
  printBill(total);

  return 0;
}