//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menuItems[][20] = {"Coffee", "Tea", "Soda", "Water", "Muffin", "Cookie"};
float menuPrices[] = {1.50, 1.25, 1.00, 0.50, 2.00, 1.00};

// Get the number of items ordered
int getNumItems() {
  int numItems;
  printf("How many items would you like to order? ");
  scanf("%d", &numItems);
  return numItems;
}

// Get the order from the user
void getOrder(int numItems, int order[]) {
  for (int i = 0; i < numItems; i++) {
    printf("Enter the item number of item %d: ", i + 1);
    scanf("%d", &order[i]);
  }
}

// Calculate the total price of the order
float calculateTotal(int numItems, int order[]) {
  float total = 0.0;
  for (int i = 0; i < numItems; i++) {
    total += menuPrices[order[i] - 1];
  }
  return total;
}

// Print the receipt
void printReceipt(int numItems, int order[], float total) {
  printf("\nHere is your receipt:\n");
  for (int i = 0; i < numItems; i++) {
    printf("%s: %.2f\n", menuItems[order[i] - 1], menuPrices[order[i] - 1]);
  }
  printf("Total: %.2f\n", total);
}

// Main function
int main() {
  // Get the number of items ordered
  int numItems = getNumItems();

  // Get the order from the user
  int order[numItems];
  getOrder(numItems, order);

  // Calculate the total price of the order
  float total = calculateTotal(numItems, order);

  // Print the receipt
  printReceipt(numItems, order, total);

  return EXIT_SUCCESS;
}