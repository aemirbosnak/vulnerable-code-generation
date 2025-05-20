//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
/*
 * A unique C Medical Store Management System example program in a Dennis Ritchie style.
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for menu options
#define EXIT 0
#define ADD_ITEM 1
#define SELL_ITEM 2
#define SHOW_INVENTORY 3
#define SHOW_BILL 4

// Define a structure for a medicine item
typedef struct {
  char name[50];
  int quantity;
  double price;
} Medicine;

// Define a function to add a medicine item to the inventory
void addMedicine(Medicine* inventory, int* size) {
  printf("Enter the name of the medicine: ");
  scanf("%s", inventory[*size].name);
  printf("Enter the quantity of the medicine: ");
  scanf("%d", &inventory[*size].quantity);
  printf("Enter the price of the medicine: ");
  scanf("%lf", &inventory[*size].price);
  *size += 1;
}

// Define a function to sell a medicine item from the inventory
void sellMedicine(Medicine* inventory, int* size) {
  printf("Enter the name of the medicine to sell: ");
  scanf("%s", inventory[*size].name);
  if (inventory[*size].quantity > 0) {
    inventory[*size].quantity -= 1;
  } else {
    printf("The medicine is out of stock.\n");
  }
}

// Define a function to show the inventory
void showInventory(Medicine* inventory, int size) {
  for (int i = 0; i < size; i++) {
    printf("Medicine %d: %s\nQuantity: %d\nPrice: %lf\n\n", i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
  }
}

// Define a function to show the bill
void showBill(Medicine* inventory, int size) {
  double total = 0;
  for (int i = 0; i < size; i++) {
    total += inventory[i].price * inventory[i].quantity;
  }
  printf("Total: %lf\n", total);
}

int main() {
  Medicine inventory[100];
  int size = 0;
  int choice;
  while (1) {
    printf("1. Add medicine item\n");
    printf("2. Sell medicine item\n");
    printf("3. Show inventory\n");
    printf("4. Show bill\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case ADD_ITEM:
        addMedicine(inventory, &size);
        break;
      case SELL_ITEM:
        sellMedicine(inventory, &size);
        break;
      case SHOW_INVENTORY:
        showInventory(inventory, size);
        break;
      case SHOW_BILL:
        showBill(inventory, size);
        break;
      case EXIT:
        return 0;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }
  return 0;
}