//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Menu items
struct MenuItem {
  char name[20];
  float price;
};

// Table order
struct TableOrder {
  int tableNumber;
  int numItems;
  struct MenuItem items[10];
};

// Cafe billing system
int main() {
  // Welcome message
  printf("Welcome to the Retro Cafe!\n");

  // Initialize the menu
  struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Cake", 3.00},
    {"Pie", 4.00},
    {"Sandwich", 5.00}
  };
  int numMenuItems = sizeof(menuItems) / sizeof(struct MenuItem);

  // Get the table number
  int tableNumber;
  printf("Enter table number: ");
  scanf("%d", &tableNumber);

  // Create a new table order
  struct TableOrder tableOrder;
  tableOrder.tableNumber = tableNumber;
  tableOrder.numItems = 0;

  // Get the order
  char itemName[20];
  int quantity;
  while (1) {
    printf("Enter item name (or 'q' to quit): ");
    scanf("%s", itemName);
    if (strcmp(itemName, "q") == 0) {
      break;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Add the item to the order
    int itemIndex = -1;
    for (int i = 0; i < numMenuItems; i++) {
      if (strcmp(itemName, menuItems[i].name) == 0) {
        itemIndex = i;
        break;
      }
    }

    if (itemIndex == -1) {
      printf("Invalid item name.\n");
    } else {
      tableOrder.items[tableOrder.numItems] = menuItems[itemIndex];
      tableOrder.numItems++;
    }
  }

  // Calculate the total bill
  float totalBill = 0.0;
  for (int i = 0; i < tableOrder.numItems; i++) {
    totalBill += tableOrder.items[i].price * quantity;
  }

  // Print the bill
  printf("\nTable %d\n", tableOrder.tableNumber);
  printf("--------------------\n");
  for (int i = 0; i < tableOrder.numItems; i++) {
    printf("%s x%d: $%.2f\n", tableOrder.items[i].name, quantity, tableOrder.items[i].price * quantity);
  }
  printf("--------------------\n");
  printf("Total: $%.2f\n", totalBill);

  return 0;
}