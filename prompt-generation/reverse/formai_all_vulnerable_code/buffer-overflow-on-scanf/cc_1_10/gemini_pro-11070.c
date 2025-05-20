//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: retro
// Welcome to the Retro Cafe Billing System!

#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menuItems[][20] = {"Coffee", "Tea", "Soda", "Juice", "Muffin"};
int menuPrices[] = {200, 150, 100, 150, 120};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order item
typedef struct {
  char name[20];
  int price;
  int quantity;
} OrderItem;

// Get the user's order
void getOrder(OrderItem items[]) {
  int numItems;

  // Get the number of items ordered
  printf("How many items would you like to order? ");
  scanf("%d", &numItems);

  // Get the details of each item ordered
  for (int i = 0; i < numItems; i++) {
    printf("Enter the name of item %d: ", i + 1);
    scanf("%s", items[i].name);

    printf("Enter the quantity of item %d: ", i + 1);
    scanf("%d", &items[i].quantity);

    // Find the price of the item
    for (int j = 0; j < 5; j++) {
      if (strcmp(items[i].name, menuItems[j]) == 0) {
        items[i].price = menuPrices[j];
        break;
      }
    }
  }
}

// Calculate the total bill
int calculateBill(OrderItem items[], int numItems) {
  int totalBill = 0;

  // Calculate the total bill by multiplying the price of each item by its quantity
  for (int i = 0; i < numItems; i++) {
    totalBill += items[i].price * items[i].quantity;
  }

  return totalBill;
}

// Print the bill
void printBill(OrderItem items[], int numItems, int totalBill) {
  // Print the header of the bill
  printf("---------------------------------------------------------\n");
  printf("                   Cafe Billing System                   \n");
  printf("---------------------------------------------------------\n");

  // Print the details of each item ordered
  for (int i = 0; i < numItems; i++) {
    printf("%-20s %3d x %3d = %5d\n", items[i].name, items[i].quantity,
           items[i].price, items[i].quantity * items[i].price);
  }

  // Print the total bill
  printf("---------------------------------------------------------\n");
  printf("Total Bill: %d\n", totalBill);
  printf("---------------------------------------------------------\n");
}

// Main function
int main() {
  // Declare the array of order items
  OrderItem items[MAX_ITEMS];

  // Get the user's order
  getOrder(items);

  // Calculate the total bill
  int totalBill = calculateBill(items, MAX_ITEMS);

  // Print the bill
  printBill(items, MAX_ITEMS, totalBill);

  return 0;
}