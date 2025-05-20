//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: random
/*
 * Medical Store Management System
 *
 * A simple program to manage medical supplies and inventory.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

// Structure to represent a medical item
typedef struct {
  char name[30];
  int quantity;
  double price;
} Item;

// Function to add a new item to the inventory
void addItem(Item *items, int *count) {
  printf("Enter item name: ");
  scanf("%s", items[*count].name);
  printf("Enter item quantity: ");
  scanf("%d", &items[*count].quantity);
  printf("Enter item price: ");
  scanf("%lf", &items[*count].price);
  (*count)++;
}

// Function to display the inventory
void displayInventory(Item *items, int count) {
  printf("Inventory:\n");
  for (int i = 0; i < count; i++) {
    printf("%s: %d (%lf)\n", items[i].name, items[i].quantity, items[i].price);
  }
}

// Function to update the quantity of an item
void updateQuantity(Item *items, int count, char *name, int quantity) {
  for (int i = 0; i < count; i++) {
    if (strcmp(items[i].name, name) == 0) {
      items[i].quantity += quantity;
      break;
    }
  }
}

// Function to update the price of an item
void updatePrice(Item *items, int count, char *name, double price) {
  for (int i = 0; i < count; i++) {
    if (strcmp(items[i].name, name) == 0) {
      items[i].price = price;
      break;
    }
  }
}

// Function to remove an item from the inventory
void removeItem(Item *items, int *count, char *name) {
  for (int i = 0; i < *count; i++) {
    if (strcmp(items[i].name, name) == 0) {
      items[i] = items[*count - 1];
      (*count)--;
      break;
    }
  }
}

int main() {
  Item items[MAX_ITEMS];
  int count = 0;

  // Add some initial items to the inventory
  addItem(items, &count);
  addItem(items, &count);
  addItem(items, &count);

  // Display the inventory
  displayInventory(items, count);

  // Update the quantity of an item
  updateQuantity(items, count, "Penicillin", 50);

  // Update the price of an item
  updatePrice(items, count, "Antibiotics", 10.50);

  // Remove an item from the inventory
  removeItem(items, &count, "Aspirin");

  // Display the updated inventory
  displayInventory(items, count);

  return 0;
}