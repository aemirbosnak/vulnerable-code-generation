//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  // Define struct for inventory item
  typedef struct {
    char* name;
    int quantity;
    float price;
  } item_t;

  // Define struct for inventory list
  typedef struct {
    int count;
    item_t* items;
  } inventory_t;

  // Function to add item to inventory
  void add_item(inventory_t* inventory, const char* name, int quantity, float price) {
    // Allocate memory for new item
    item_t* item = (item_t*)malloc(sizeof(item_t));

    // Initialize item fields
    item->name = strdup(name);
    item->quantity = quantity;
    item->price = price;

    // Add item to inventory list
    inventory->items = realloc(inventory->items, (inventory->count + 1) * sizeof(item_t));
    inventory->items[inventory->count++] = *item;
  }

  // Function to remove item from inventory
  void remove_item(inventory_t* inventory, const char* name) {
    // Find item in inventory list
    int index = -1;
    for (int i = 0; i < inventory->count; i++) {
      if (strcmp(inventory->items[i].name, name) == 0) {
        index = i;
        break;
      }
    }

    // Remove item from inventory list
    if (index >= 0) {
      for (int i = index; i < inventory->count - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
      }
      inventory->count--;
    }
  }

  // Function to display inventory
  void display_inventory(inventory_t* inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory->count; i++) {
      printf("%s - %d units, %.2f per unit\n", inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
  }

  int main() {
    // Initialize inventory list
    inventory_t inventory = {0};

    // Add some items to inventory
    add_item(&inventory, "Apples", 5, 1.50f);
    add_item(&inventory, "Bananas", 10, 0.75f);
    add_item(&inventory, "Oranges", 3, 2.00f);

    // Remove an item from inventory
    remove_item(&inventory, "Apples");

    // Display inventory
    display_inventory(&inventory);

    // Free memory
    for (int i = 0; i < inventory.count; i++) {
      free(inventory.items[i].name);
    }
    free(inventory.items);

    return 0;
  }