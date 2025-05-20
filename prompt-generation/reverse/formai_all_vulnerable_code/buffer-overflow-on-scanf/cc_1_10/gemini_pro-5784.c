//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menuItems[10][20] = {"Coffee", "Tea", "Water", "Sandwich", "Salad", "Soup", "Pizza", "Burger", "Fries", "Cake"};
float menuPrices[10] = {1.50, 1.25, 1.00, 5.00, 4.50, 3.75, 7.50, 6.00, 2.50, 3.00};

// Define the tax rate
float taxRate = 0.07;

// Function to print the menu
void printMenu() {
  printf("Menu:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menuItems[i], menuPrices[i]);
  }
}

// Function to get the user's order
int getOrder() {
  int order;
  printf("Enter the number of the item you would like to order (1-10): ");
  scanf("%d", &order);
  return order;
}

// Function to calculate the total cost of the order
float calculateTotal(int order) {
  float total = menuPrices[order - 1];
  total += total * taxRate;
  return total;
}

// Function to print the receipt
void printReceipt(int order, float total) {
  printf("Receipt:\n");
  printf("Item: %s\n", menuItems[order - 1]);
  printf("Price: $%.2f\n", menuPrices[order - 1]);
  printf("Tax: $%.2f\n", total * taxRate);
  printf("Total: $%.2f\n", total);
}

// Main function
int main() {
  // Print the menu
  printMenu();

  // Get the user's order
  int order = getOrder();

  // Calculate the total cost of the order
  float total = calculateTotal(order);

  // Print the receipt
  printReceipt(order, total);

  return 0;
}