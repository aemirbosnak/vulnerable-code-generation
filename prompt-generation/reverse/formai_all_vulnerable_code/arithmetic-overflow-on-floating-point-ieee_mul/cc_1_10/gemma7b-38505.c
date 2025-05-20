//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a menu item
typedef struct MenuItem {
  char name[20];
  float price;
  int quantity;
} MenuItem;

// Define a function to calculate the total cost of an order
float calculateTotalCost(MenuItem *items, int numItems) {
  float totalCost = 0.0;
  for (int i = 0; i < numItems; i++) {
    totalCost += items[i].price * items[i].quantity;
  }
  return totalCost;
}

// Define a function to print the menu
void printMenu(MenuItem *items, int numItems) {
  printf("Menu:\n");
  for (int i = 0; i < numItems; i++) {
    printf("%s - %f, %d\n", items[i].name, items[i].price, items[i].quantity);
  }
}

int main() {
  // Create an array of menu items
  MenuItem items[] = {
    {"Coffee", 2.0, 10},
    {"Tea", 1.5, 8},
    {"Juice", 1.2, 6},
    {"Soda", 1.8, 7}
  };

  // Print the menu
  printMenu(items, 4);

  // Get the customer's order
  int numItems = 0;
  MenuItem *order = NULL;
  printf("Enter the number of items you want to order: ");
  scanf("%d", &numItems);

  // Allocate memory for the order
  order = (MenuItem *)malloc(numItems * sizeof(MenuItem));

  // Get the customer's order details
  for (int i = 0; i < numItems; i++) {
    printf("Enter the name of the item you want to order: ");
    scanf("%s", order[i].name);

    printf("Enter the quantity of the item you want to order: ");
    scanf("%d", &order[i].quantity);
  }

  // Calculate the total cost of the order
  float totalCost = calculateTotalCost(order, numItems);

  // Print the total cost of the order
  printf("Total cost: $%.2f\n", totalCost);

  // Free the memory allocated for the order
  free(order);

  return 0;
}