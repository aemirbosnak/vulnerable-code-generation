//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a coffee item
typedef struct CoffeeItem {
  char name[20];
  float price;
  int quantity;
} CoffeeItem;

// Create an array of coffee items
CoffeeItem coffeeItems[] = {
  {"Cappuccino", 3.50, 0},
  {"Latte", 2.50, 0},
  {"Americano", 2.00, 0},
  {"Macchiato", 3.00, 0},
  {"Frappuccino", 4.00, 0}
};

// Define the function to calculate the total cost of a order
float calculateTotalCost(CoffeeItem item) {
  return item.price * item.quantity;
}

// Define the function to print the order summary
void printOrderSummary(CoffeeItem item) {
  printf("Item: %s\n", item.name);
  printf("Quantity: %d\n", item.quantity);
  printf("Price: %.2f\n", item.price);
  printf("Total Cost: %.2f\n", calculateTotalCost(item));
  printf("\n");
}

int main() {
  // Create a variable to store the total cost of the order
  float totalCost = 0.0;

  // Print the menu of coffee items
  printf("Menu:\n");
  for (int i = 0; i < 5; i++) {
    printOrderSummary(coffeeItems[i]);
  }

  // Get the user's order
  printf("Enter the name of your coffee item: ");
  char itemName[20];
  scanf("%s", itemName);

  // Find the coffee item in the array
  CoffeeItem item;
  for (int i = 0; i < 5; i++) {
    if (strcmp(itemName, coffeeItems[i].name) == 0) {
      item = coffeeItems[i];
      break;
    }
  }

  // If the item was not found, print an error message
  if (item.name == NULL) {
    printf("Error: Item not found.\n");
    return 1;
  }

  // Get the user's quantity of the item
  printf("Enter the quantity of your item: ");
  int quantity;
  scanf("%d", &quantity);

  // Update the item's quantity
  item.quantity = quantity;

  // Calculate the total cost of the order
  totalCost = calculateTotalCost(item) + totalCost;

  // Print the order summary
  printOrderSummary(item);

  // Print the total cost of the order
  printf("Total Cost: %.2f\n", totalCost);

  return 0;
}