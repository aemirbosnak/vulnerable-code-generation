//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a warehouse item
typedef struct WarehouseItem {
  int id;
  char *name;
  int quantity;
  float price;
} WarehouseItem;

// Array of warehouse items
WarehouseItem items[] = {
  {1, "Apples", 100, 0.50},
  {2, "Oranges", 50, 0.75},
  {3, "Bananas", 25, 0.25},
  {4, "Grapes", 75, 0.60},
  {5, "Strawberries", 10, 1.00},
};

// Function to print the warehouse items
void printItems() {
  printf("ID | Name | Quantity | Price\n");
  printf("-----------------------------\n");
  for (int i = 0; i < 5; i++) {
    printf("%2d | %-10s | %7d | $%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
  }
  printf("\n");
}

// Function to add an item to the warehouse
void addItem() {
  int id;
  char name[256];
  int quantity;
  float price;

  printf("Enter the item ID: ");
  scanf("%d", &id);

  printf("Enter the item name: ");
  scanf("%s", name);

  printf("Enter the item quantity: ");
  scanf("%d", &quantity);

  printf("Enter the item price: ");
  scanf("%f", &price);

  // Create a new item
  WarehouseItem item = {id, name, quantity, price};

  // Add the item to the array
  items[5] = item;

  printf("Item added successfully!\n\n");
}

// Function to remove an item from the warehouse
void removeItem() {
  int id;

  printf("Enter the ID of the item to remove: ");
  scanf("%d", &id);

  // Find the item in the array
  int index = -1;
  for (int i = 0; i < 5; i++) {
    if (items[i].id == id) {
      index = i;
      break;
    }
  }

  // Check if the item was found
  if (index == -1) {
    printf("Item not found!\n\n");
    return;
  }

  // Remove the item from the array
  for (int i = index; i < 4; i++) {
    items[i] = items[i + 1];
  }

  printf("Item removed successfully!\n\n");
}

// Function to update an item in the warehouse
void updateItem() {
  int id;
  int choice;

  printf("Enter the ID of the item to update: ");
  scanf("%d", &id);

  // Find the item in the array
  int index = -1;
  for (int i = 0; i < 5; i++) {
    if (items[i].id == id) {
      index = i;
      break;
    }
  }

  // Check if the item was found
  if (index == -1) {
    printf("Item not found!\n\n");
    return;
  }

  // Get the user's choice
  printf("What would you like to update?\n");
  printf("1. Name\n");
  printf("2. Quantity\n");
  printf("3. Price\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Update the item
  switch (choice) {
    case 1:
      printf("Enter the new name: ");
      scanf("%s", items[index].name);
      break;
    case 2:
      printf("Enter the new quantity: ");
      scanf("%d", &items[index].quantity);
      break;
    case 3:
      printf("Enter the new price: ");
      scanf("%f", &items[index].price);
      break;
    default:
      printf("Invalid choice!\n\n");
  }

  printf("Item updated successfully!\n\n");
}

// Main function
int main() {
  int choice;

  do {
    // Print the menu
    printf("Welcome to the Warehouse Management System!\n");
    printf("----------------------------------------\n");
    printf("1. Print items\n");
    printf("2. Add item\n");
    printf("3. Remove item\n");
    printf("4. Update item\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Call the appropriate function based on the user's choice
    switch (choice) {
      case 1:
        printItems();
        break;
      case 2:
        addItem();
        break;
      case 3:
        removeItem();
        break;
      case 4:
        updateItem();
        break;
      case 5:
        printf("Thank you for using the Warehouse Management System!\n");
        break;
      default:
        printf("Invalid choice!\n\n");
    }
  } while (choice != 5);

  return 0;
}