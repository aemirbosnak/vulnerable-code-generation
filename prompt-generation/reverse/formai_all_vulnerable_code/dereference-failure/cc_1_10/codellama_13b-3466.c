//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: configurable
// Warehouse Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Defining structs for items and inventory
typedef struct {
  char name[50];
  int quantity;
  int unit_price;
} Item;

typedef struct {
  Item* items;
  int size;
  int capacity;
} Inventory;

// Defining functions for inventory management
void add_item(Inventory* inventory, Item item) {
  if (inventory->size < inventory->capacity) {
    inventory->items[inventory->size] = item;
    inventory->size++;
  } else {
    printf("Inventory is full\n");
  }
}

void remove_item(Inventory* inventory, char* item_name) {
  for (int i = 0; i < inventory->size; i++) {
    if (strcmp(inventory->items[i].name, item_name) == 0) {
      inventory->items[i] = inventory->items[inventory->size - 1];
      inventory->size--;
      break;
    }
  }
}

void update_quantity(Inventory* inventory, char* item_name, int quantity) {
  for (int i = 0; i < inventory->size; i++) {
    if (strcmp(inventory->items[i].name, item_name) == 0) {
      inventory->items[i].quantity = quantity;
      break;
    }
  }
}

// Defining function for displaying inventory
void display_inventory(Inventory* inventory) {
  for (int i = 0; i < inventory->size; i++) {
    printf("%s: %d\n", inventory->items[i].name, inventory->items[i].quantity);
  }
}

int main() {
  // Creating an inventory with capacity for 10 items
  Inventory inventory = {
    .items = (Item*)malloc(10 * sizeof(Item)),
    .size = 0,
    .capacity = 10
  };

  // Adding items to inventory
  Item item1 = {
    .name = "Apple",
    .quantity = 10,
    .unit_price = 5
  };
  add_item(&inventory, item1);

  Item item2 = {
    .name = "Banana",
    .quantity = 20,
    .unit_price = 3
  };
  add_item(&inventory, item2);

  Item item3 = {
    .name = "Orange",
    .quantity = 5,
    .unit_price = 6
  };
  add_item(&inventory, item3);

  // Updating quantity of item2
  update_quantity(&inventory, "Banana", 25);

  // Removing item3
  remove_item(&inventory, "Orange");

  // Displaying inventory
  display_inventory(&inventory);

  return 0;
}