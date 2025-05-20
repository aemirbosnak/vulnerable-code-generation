//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menuItems[5][20] = {"Coffee", "Tea", "Soda", "Water", "Juice"};
float menuPrices[5] = {1.50, 1.25, 1.00, 0.50, 1.25};

// Define the customer's order
int order[5] = {0, 0, 0, 0, 0};

// Function to print the menu
void printMenu() {
  printf("Welcome to our cafe!\n");
  printf("Here is our menu:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menuItems[i], menuPrices[i]);
  }
}

// Function to get the customer's order
void getOrder() {
  int choice;
  int quantity;

  printf("What would you like to order? (Enter the number of the item)\n");
  scanf("%d", &choice);

  printf("How many would you like?\n");
  scanf("%d", &quantity);

  order[choice - 1] += quantity;
}

// Function to calculate the total bill
float calculateTotal() {
  float total = 0.0;

  for (int i = 0; i < 5; i++) {
    total += menuPrices[i] * order[i];
  }

  return total;
}

// Function to print the receipt
void printReceipt() {
  float total = calculateTotal();

  printf("Here is your receipt:\n");
  for (int i = 0; i < 5; i++) {
    if (order[i] > 0) {
      printf("%d %s - $%.2f\n", order[i], menuItems[i], menuPrices[i] * order[i]);
    }
  }

  printf("Total: $%.2f\n", total);
}

// Main function
int main() {
  char choice;

  // Print the menu
  printMenu();

  // Get the customer's order
  do {
    getOrder();

    printf("Would you like to order anything else? (Y/N)\n");
    scanf(" %c", &choice);
  } while (choice == 'Y' || choice == 'y');

  // Calculate the total bill
  float total = calculateTotal();

  // Print the receipt
  printReceipt();

  return 0;
}