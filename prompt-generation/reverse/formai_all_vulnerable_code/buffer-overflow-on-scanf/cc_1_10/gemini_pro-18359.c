//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menuItems[10][20] = {"Espresso", "Americano", "Cappuccino", "Latte", "Mocha", "Hot Chocolate", "Tea", "Pastry", "Muffin", "Cookie"};
float menuPrices[10] = {2.50, 3.00, 3.50, 4.00, 4.50, 2.00, 1.50, 1.00, 1.50, 1.00};

// Function to display the menu
void displayMenu() {
  printf("Cafe Menu\n");
  for (int i = 0; i < 10; i++) {
    printf("%d. %s - $%.2f\n", i + 1, menuItems[i], menuPrices[i]);
  }
}

// Function to get the user's order
int getOrder() {
  int choice;
  printf("Enter the number of the item you would like to order: ");
  scanf("%d", &choice);
  return choice;
}

// Function to calculate the total bill
float calculateTotal(int order[], int quantity[]) {
  float total = 0;
  for (int i = 0; i < 10; i++) {
    total += menuPrices[i] * quantity[i];
  }
  return total;
}

// Function to print the receipt
void printReceipt(int order[], int quantity[]) {
  printf("Cafe Receipt\n");
  for (int i = 0; i < 10; i++) {
    if (quantity[i] > 0) {
      printf("%d. %s - $%.2f x %d = $%.2f\n", i + 1, menuItems[i], menuPrices[i], quantity[i], menuPrices[i] * quantity[i]);
    }
  }
  printf("Total: $%.2f\n", calculateTotal(order, quantity));
}

// Main function
int main() {
  // Welcome the user
  printf("Welcome to the Cafe!\n");

  // Display the menu
  displayMenu();

  // Get the user's order
  int order[10] = {0};
  int quantity[10] = {0};
  int choice;
  do {
    choice = getOrder();
    if (choice >= 1 && choice <= 10) {
      printf("Enter the quantity: ");
      scanf("%d", &quantity[choice - 1]);
      order[choice - 1] = 1;
    } else {
      printf("Invalid choice! Please enter a number between 1 and 10.\n");
    }
  } while (choice != 0);

  // Calculate the total bill
  float total = calculateTotal(order, quantity);

  // Print the receipt
  printReceipt(order, quantity);

  // Thank the user
  printf("Thank you for your order!\n");

  return 0;
}