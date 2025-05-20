//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Declare the menu items and prices
char menuItems[][20] = {"Coffee", "Tea", "Espresso", "Latte", "Cappuccino", "Americano"};
float menuPrices[] = {1.50, 1.25, 2.00, 2.50, 2.75, 2.25};

// Declare the customer order
int customerOrder[6];

// Declare the total bill
float totalBill = 0.0;

// Get the customer order
void getCustomerOrder() {
  int i;

  printf("Welcome to the Cafe!\n");
  printf("What would you like to order today?\n");

  for (i = 0; i < 6; i++) {
    printf("%s: ", menuItems[i]);
    scanf("%d", &customerOrder[i]);
  }
}

// Calculate the total bill
void calculateTotalBill() {
  int i;

  for (i = 0; i < 6; i++) {
    totalBill += customerOrder[i] * menuPrices[i];
  }
}

// Print the receipt
void printReceipt() {
  int i;

  printf("\nYour order:\n");

  for (i = 0; i < 6; i++) {
    if (customerOrder[i] > 0) {
      printf("%s: %d\n", menuItems[i], customerOrder[i]);
    }
  }

  printf("\nTotal: $%.2f\n", totalBill);
}

// Main function
int main() {
  // Get the customer order
  getCustomerOrder();

  // Calculate the total bill
  calculateTotalBill();

  // Print the receipt
  printReceipt();

  return 0;
}