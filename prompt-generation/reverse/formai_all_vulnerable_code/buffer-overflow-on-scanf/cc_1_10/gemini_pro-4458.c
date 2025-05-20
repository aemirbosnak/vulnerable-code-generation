//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
struct MenuItem {
  char name[20];
  float price;
};

struct MenuItem menuItems[] = {
  {"Coffee", 2.0},
  {"Tea", 1.5},
  {"Soda", 1.0},
  {"Juice", 1.5},
  {"Water", 0.5}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the struct for the order
struct Order {
  struct MenuItem items[MAX_ITEMS];
  int numItems;
  float total;
};

// Function to print the menu
void printMenu() {
  printf("Menu:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s: $%.2f\n", menuItems[i].name, menuItems[i].price);
  }
}

// Function to get the user's order
struct Order getOrder() {
  struct Order order;
  order.numItems = 0;
  order.total = 0.0;

  char itemName[20];
  int quantity;

  printf("Enter the item name (or 'q' to quit): ");
  scanf("%s", itemName);

  while (strcmp(itemName, "q") != 0) {
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // Find the item in the menu
    int itemIndex = -1;
    for (int i = 0; i < 5; i++) {
      if (strcmp(itemName, menuItems[i].name) == 0) {
        itemIndex = i;
        break;
      }
    }

    // If the item was not found, print an error message
    if (itemIndex == -1) {
      printf("Invalid item name.\n");
    } else {
      // Add the item to the order
      order.items[order.numItems] = menuItems[itemIndex];
      order.numItems++;
      order.total += quantity * menuItems[itemIndex].price;
    }

    printf("Enter the item name (or 'q' to quit): ");
    scanf("%s", itemName);
  }

  return order;
}

// Function to print the order
void printOrder(struct Order order) {
  printf("Order:\n");
  for (int i = 0; i < order.numItems; i++) {
    printf("%s: $%.2f\n", order.items[i].name, order.items[i].price);
  }
  printf("Total: $%.2f\n", order.total);
}

// Main function
int main() {
  // Print the menu
  printMenu();

  // Get the user's order
  struct Order order = getOrder();

  // Print the order
  printOrder(order);

  return 0;
}