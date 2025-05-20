//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Array of beverages
char* beverages[] = {"Cappuccino", "Espresso", "Mocha", "Latte", "Americano"};

// Array of prices
float prices[] = {3.50, 2.50, 4.00, 3.00, 2.00};

// Function to get the user's order
int getOrder() {
  int choice;
  printf("Welcome to the Cafe! What would you like to order?\n");
  for (int i = 0; i < 5; i++) {
    printf("%d. %s - $%.2f\n", i + 1, beverages[i], prices[i]);
  }
  printf("Please enter your choice (1-5): ");
  scanf("%d", &choice);
  return choice;
}

// Function to calculate the total bill
float calculateBill(int order, int quantity) {
  float total = prices[order - 1] * quantity;
  return total;
}

// Function to print the receipt
void printReceipt(int order, int quantity, float total) {
  printf("-----------------------------------------\n");
  printf("Cafe Receipt\n");
  printf("-----------------------------------------\n");
  printf("Item: %s\n", beverages[order - 1]);
  printf("Quantity: %d\n", quantity);
  printf("Total: $%.2f\n", total);
  printf("-----------------------------------------\n");
  printf("Thank you for your order! Come again soon!\n");
}

// Main function
int main() {
  int order, quantity;
  float total;
  
  // Get the user's order
  order = getOrder();

  // Get the quantity of the order
  printf("How many %ss would you like? ", beverages[order - 1]);
  scanf("%d", &quantity);
  
  // Calculate the total bill
  total = calculateBill(order, quantity);

  // Print the receipt
  printReceipt(order, quantity, total);

  return 0;
}