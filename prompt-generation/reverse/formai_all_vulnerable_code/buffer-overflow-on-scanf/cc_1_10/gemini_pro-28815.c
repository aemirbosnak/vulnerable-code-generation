//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menuItems[][50] = {"Espresso", "Americano", "Cappuccino", "Latte", "Macchiato", "Cold Brew", "Iced Coffee", "Hot Chocolate"};
float prices[] = {2.50, 3.00, 3.50, 4.00, 4.50, 4.00, 4.00, 5.00};

// Get the number of items ordered
int getNumItems() {
  int numItems;
  printf("How many items would you like to order? ");
  scanf("%d", &numItems);
  return numItems;
}

// Get the order details
void getOrderDetails(int numItems, int order[], float orderPrices[]) {
  printf("Enter the item numbers and quantities of your order:\n");
  for (int i = 0; i < numItems; i++) {
    printf("Item %d: ", i + 1);
    scanf("%d", &order[i]);
    printf("Quantity: ");
    scanf("%d", &orderPrices[i]);
  }
}

// Calculate the total bill
float calculateTotal(int numItems, int order[], float orderPrices[]) {
  float total = 0;
  for (int i = 0; i < numItems; i++) {
    total += orderPrices[i] * prices[order[i] - 1];
  }
  return total;
}

// Print the bill
void printBill(int numItems, int order[], float orderPrices[], float total) {
  printf("\nYour order:\n");
  for (int i = 0; i < numItems; i++) {
    printf("%d %s x %.2f = %.2f\n", order[i], menuItems[order[i] - 1], orderPrices[i], orderPrices[i] * prices[order[i] - 1]);
  }
  printf("Total: %.2f\n", total);
}

// Main function
int main() {
  // Get the number of items ordered
  int numItems = getNumItems();

  // Get the order details
  int order[numItems];
  float orderPrices[numItems];
  getOrderDetails(numItems, order, orderPrices);

  // Calculate the total bill
  float total = calculateTotal(numItems, order, orderPrices);

  // Print the bill
  printBill(numItems, order, orderPrices, total);

  return 0;
}