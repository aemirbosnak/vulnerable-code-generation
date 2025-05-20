//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
  char name[50];
  int quantity;
  float price;
} Item;

typedef struct Warehouse {
  Item *items;
  int numItems;
  int totalQuantity;
  float totalPrice;
} Warehouse;

// Function to add an item to the warehouse
void addItem(Warehouse *warehouse, char *name, int quantity, float price) {
  Item item;
  strcpy(item.name, name);
  item.quantity = quantity;
  item.price = price;
  
  // Increase the number of items in the warehouse
  warehouse->numItems++;
  
  // Reallocate the memory for the items array
  warehouse->items = (Item*) realloc(warehouse->items, warehouse->numItems * sizeof(Item));
  
  // Add the item to the items array
  warehouse->items[warehouse->numItems - 1] = item;
  
  // Update the total quantity and price of the warehouse
  warehouse->totalQuantity += quantity;
  warehouse->totalPrice += price * quantity;
}

// Function to remove an item from the warehouse
void removeItem(Warehouse *warehouse, char *name) {
  int i, found = 0;
  
  // Locate the item in the items array
  for (i = 0; i < warehouse->numItems; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      found = 1;
      break;
    }
  }
  
  if (found) {
    // Decrease the number of items in the warehouse
    warehouse->numItems--;
    
    // Remove the item from the items array
    memmove(&warehouse->items[i], &warehouse->items[i+1], (warehouse->numItems - i) * sizeof(Item));
    
    // Update the total quantity and price of the warehouse
    warehouse->totalQuantity -= warehouse->items[i].quantity;
    warehouse->totalPrice -= warehouse->items[i].price * warehouse->items[i].quantity;
  }
}

int main() {
  Warehouse warehouse;
  warehouse.items = NULL;
  warehouse.numItems = 0;
  warehouse.totalQuantity = 0;
  warehouse.totalPrice = 0.0;
  
  // Add some items to the warehouse
  addItem(&warehouse, "Keyboard", 10, 20.0);
  addItem(&warehouse, "Mouse", 15, 10.0);
  
  // Remove the keyboard from the warehouse
  removeItem(&warehouse, "Keyboard");
  
  // Print the contents of the warehouse
  printf("Total items: %d\n", warehouse.numItems);
  printf("Total quantity: %d\n", warehouse.totalQuantity);
  printf("Total price: $%.2f\n", warehouse.totalPrice);

  return 0;
}