//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menu[][20] = {"Americano", "Cappuccino", "Espresso", "Flat White", "Latte", "Mocha"};
float prices[] = {2.50, 3.00, 2.00, 3.50, 3.25, 3.75};

// Function to display the menu
void displayMenu() {
  printf("\nWelcome to the Cafe! Here's our menu:\n");
  for (int i = 0; i < 6; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menu[i], prices[i]);
  }
  printf("\n");
}

// Function to take the order
void takeOrder(int *order, int *quantity) {
  int choice;
  printf("Enter the number corresponding to the item you want to order: ");
  scanf("%d", &choice);
  printf("Enter the quantity: ");
  scanf("%d", &quantity[choice - 1]);
  order[choice - 1] = 1;
}

// Function to calculate the total bill
float calculateBill(int *order, int *quantity) {
  float total = 0;
  for (int i = 0; i < 6; i++) {
    if (order[i]) {
      total += prices[i] * quantity[i];
    }
  }
  return total;
}

// Function to print the receipt
void printReceipt(int *order, int *quantity) {
  printf("\nYour receipt:\n");
  for (int i = 0; i < 6; i++) {
    if (order[i]) {
      printf("%d. %s - $%.2f x %d = $%.2f\n", i + 1, menu[i], prices[i], quantity[i], prices[i] * quantity[i]);
    }
  }
  printf("\nTotal: $%.2f\n", calculateBill(order, quantity));
}

// Main function
int main() {
  // Variables to store the order and quantity
  int order[6] = {0};
  int quantity[6] = {0};

  // Display the menu
  displayMenu();

  // Take the order
  for (int i = 0; i < 3; i++) {
    takeOrder(order, quantity);
  }

  // Calculate the total bill
  float total = calculateBill(order, quantity);

  // Print the receipt
  printReceipt(order, quantity);

  return 0;
}