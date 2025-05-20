//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
/*
 * C Cafe Billing System Example Program
 *
 * This program is a simple example of a cafe billing system in C.
 * It allows customers to order food and drinks, and displays the total bill.
 *
 */

#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a menu item
typedef struct {
  char name[20];
  float price;
} MenuItem;

// Define an array of menu items
MenuItem menu[] = {
  { "Coffee", 2.50 },
  { "Tea", 2.00 },
  { "Cappuccino", 3.50 },
  { "Espresso", 3.00 },
  { "Latte", 4.00 },
  { "Mocha", 4.50 },
  { "Sandwich", 5.00 },
  { "Salad", 6.00 },
  { "Soup", 4.50 },
  { "Burger", 7.00 },
  { "Fries", 3.50 },
  { "Ice Cream", 3.50 },
  { "Soda", 2.50 },
  { "Water", 1.50 },
};

// Define a struct to represent a customer order
typedef struct {
  char item[20];
  int quantity;
} Order;

// Define an array of orders
Order orders[100];

// Define a function to display the menu
void displayMenu() {
  printf("Welcome to our cafe!\n");
  printf("Here is our menu:\n\n");
  for (int i = 0; i < sizeof(menu) / sizeof(MenuItem); i++) {
    printf("%s - $%.2f\n", menu[i].name, menu[i].price);
  }
}

// Define a function to take an order
void takeOrder(int *numItems) {
  printf("Enter the name of the item you would like to order: ");
  scanf("%s", orders[*numItems].item);
  printf("Enter the quantity of the item you would like to order: ");
  scanf("%d", &orders[*numItems].quantity);
  *numItems += 1;
}

// Define a function to calculate the total bill
float calculateBill(int numItems) {
  float total = 0.0;
  for (int i = 0; i < numItems; i++) {
    total += menu[i].price * orders[i].quantity;
  }
  return total;
}

// Define a function to display the bill
void displayBill(int numItems, float total) {
  printf("Here is your bill:\n\n");
  for (int i = 0; i < numItems; i++) {
    printf("%s - $%.2f\n", orders[i].item, menu[i].price * orders[i].quantity);
  }
  printf("Total: $%.2f\n", total);
}

int main() {
  // Display the menu
  displayMenu();

  // Take orders
  int numItems = 0;
  while (numItems < 100) {
    takeOrder(&numItems);
    printf("\n");
  }

  // Calculate the total bill
  float total = calculateBill(numItems);

  // Display the bill
  displayBill(numItems, total);

  return 0;
}