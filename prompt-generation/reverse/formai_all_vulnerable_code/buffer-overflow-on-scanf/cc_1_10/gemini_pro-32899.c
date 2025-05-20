//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
struct MenuItem {
  char name[50];
  float price;
};

struct MenuItem menuItems[] = {
  {"Espresso", 2.50},
  {"Americano", 3.00},
  {"Cappuccino", 3.50},
  {"Latte", 4.00},
  {"Mocha", 4.50},
  {"Hot Chocolate", 3.00},
  {"Tea", 2.00},
  {"Juice", 3.00},
  {"Soda", 2.50},
  {"Water", 1.50}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order
struct Order {
  struct MenuItem items[MAX_ITEMS];
  int numItems;
  float total;
};

// Get the user's input and store it in the order
void getOrder(struct Order *order) {
  int i;
  char input[50];

  // Get the number of items in the order
  printf("How many items would you like to order? ");
  scanf("%d", &order->numItems);

  // Get the items in the order
  for (i = 0; i < order->numItems; i++) {
    printf("Enter the name of item %d: ", i + 1);
    scanf("%s", input);

    // Find the item in the menu
    int j;
    for (j = 0; j < sizeof(menuItems) / sizeof(struct MenuItem); j++) {
      if (strcmp(input, menuItems[j].name) == 0) {
        order->items[i] = menuItems[j];
        break;
      }
    }

    // If the item was not found, print an error message
    if (j == sizeof(menuItems) / sizeof(struct MenuItem)) {
      printf("Invalid item name. Please enter a valid item name.\n");
      i--;
    }
  }

  // Calculate the total price of the order
  order->total = 0.0;
  for (i = 0; i < order->numItems; i++) {
    order->total += order->items[i].price;
  }
}

// Print the order
void printOrder(struct Order *order) {
  int i;

  printf("Your order:\n");
  for (i = 0; i < order->numItems; i++) {
    printf("  %s: $%.2f\n", order->items[i].name, order->items[i].price);
  }

  printf("Total: $%.2f\n", order->total);
}

int main() {
  struct Order order;

  // Get the user's input
  getOrder(&order);

  // Print the order
  printOrder(&order);

  return 0;
}