//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
typedef struct MenuItem {
  char name[20];
  float price;
} MenuItem;

MenuItem menu[] = {
  {"Coffee", 1.50},
  {"Tea", 1.25},
  {"Hot chocolate", 1.75},
  {"Espresso", 2.00},
  {"Cappuccino", 2.50},
  {"Latte", 2.75},
  {"Mocha", 3.00},
  {"Americano", 2.25},
  {"Macchiato", 2.50},
  {"Ristretto", 2.00}
};

// Define the table of orders
typedef struct Order {
  int tableNumber;
  int quantity[10];
  float total;
} Order;

Order orders[10];

// Define the current order
Order currentOrder;

// Print the menu
void printMenu() {
  printf("\n\nMenu:\n");
  printf("-------------------\n");
  for (int i = 0; i < 10; i++) {
    printf("%2d. %-15s %5.2f\n", i + 1, menu[i].name, menu[i].price);
  }
}

// Get the user's input
void getInput() {
  int tableNumber;
  int itemNumber;
  int quantity;

  printf("\nEnter the table number: ");
  scanf("%d", &tableNumber);

  printf("Enter the item number: ");
  scanf("%d", &itemNumber);

  printf("Enter the quantity: ");
  scanf("%d", &quantity);

  // Add the item to the order
  currentOrder.tableNumber = tableNumber;
  currentOrder.quantity[itemNumber - 1] += quantity;
}

// Calculate the total price of the order
void calculateTotal() {
  currentOrder.total = 0.0;
  for (int i = 0; i < 10; i++) {
    currentOrder.total += menu[i].price * currentOrder.quantity[i];
  }
}

// Print the order
void printOrder() {
  printf("\n\nOrder for table %d:\n", currentOrder.tableNumber);
  printf("-------------------------\n");
  for (int i = 0; i < 10; i++) {
    if (currentOrder.quantity[i] > 0) {
      printf("%2d. %-15s %5d %5.2f\n", i + 1, menu[i].name, currentOrder.quantity[i], menu[i].price * currentOrder.quantity[i]);
    }
  }
  printf("Total: %5.2f\n", currentOrder.total);
}

// Main function
int main() {
  // Print the menu
  printMenu();

  // Get the user's input
  getInput();

  // Calculate the total price of the order
  calculateTotal();

  // Print the order
  printOrder();

  return 0;
}