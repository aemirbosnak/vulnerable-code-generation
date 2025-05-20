//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items with their prices
char menu[][32] = {"Coffee", "Tea", "Latte", "Cappuccino", "Espresso", "Hot Chocolate", "Muffin", "Croissant", "Biscuit", "Bagel"};
float prices[] = {2.50, 1.50, 3.00, 3.50, 2.00, 2.75, 1.75, 2.25, 1.00, 1.25};

// Function to display the menu
void displayMenu() {
  printf("Welcome to the Coffee Shop!\n\n");
  printf("Menu:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menu[i], prices[i]);
  }
  printf("\n");
}

// Function to get the user's order
int getOrder() {
  int choice;
  printf("Enter the number of the item you want to order: ");
  scanf("%d", &choice);
  return choice;
}

// Function to calculate the total bill
float calculateBill(int order[], int quantities[]) {
  float total = 0;
  for (int i = 0; i < 10; i++) {
    total += prices[i] * quantities[i];
  }
  return total;
}

// Function to print the receipt
void printReceipt(int order[], int quantities[], float total) {
  printf("\nReceipt:\n");
  for (int i = 0; i < 10; i++) {
    if (quantities[i] > 0) {
      printf("%d x %s - $%.2f\n", quantities[i], menu[i], prices[i] * quantities[i]);
    }
  }
  printf("Total: $%.2f\n", total);
}

// Main function
int main() {
  // Initialize the order and quantity arrays
  int order[10] = {0};
  int quantities[10] = {0};

  // Display the menu
  displayMenu();

  // Get the user's order
  int choice = getOrder();

  // While the user enters a valid choice, keep adding items to the order
  while (choice > 0 && choice <= 10) {
    quantities[choice - 1]++;
    choice = getOrder();
  }

  // Calculate the total bill
  float total = calculateBill(order, quantities);

  // Print the receipt
  printReceipt(order, quantities, total);

  return 0;
}