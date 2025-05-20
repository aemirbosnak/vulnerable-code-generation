//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
// Warehouse Management System Example Program
#include <stdio.h>
#include <stdlib.h>

// Structures for storing data
typedef struct {
  int id;
  char* name;
  char* address;
  int capacity;
} Warehouse;

typedef struct {
  int id;
  char* name;
  char* address;
  int quantity;
} Inventory;

// Function to add a new warehouse
void addWarehouse(Warehouse** warehouses, int* num_warehouses, char* name, char* address, int capacity) {
  Warehouse* new_warehouse = malloc(sizeof(Warehouse));
  new_warehouse->id = *num_warehouses;
  new_warehouse->name = strdup(name);
  new_warehouse->address = strdup(address);
  new_warehouse->capacity = capacity;
  warehouses[*num_warehouses] = new_warehouse;
  (*num_warehouses)++;
}

// Function to add a new inventory item
void addInventory(Inventory** inventory, int* num_inventory, char* name, char* address, int quantity) {
  Inventory* new_inventory = malloc(sizeof(Inventory));
  new_inventory->id = *num_inventory;
  new_inventory->name = strdup(name);
  new_inventory->address = strdup(address);
  new_inventory->quantity = quantity;
  inventory[*num_inventory] = new_inventory;
  (*num_inventory)++;
}

// Function to display all warehouses and inventory items
void displayWarehouses(Warehouse** warehouses, int num_warehouses, Inventory** inventory, int num_inventory) {
  printf("Warehouses:\n");
  for (int i = 0; i < num_warehouses; i++) {
    printf("%d: %s (%s, capacity %d)\n", warehouses[i]->id, warehouses[i]->name, warehouses[i]->address, warehouses[i]->capacity);
  }
  printf("Inventory:\n");
  for (int i = 0; i < num_inventory; i++) {
    printf("%d: %s (%s, quantity %d)\n", inventory[i]->id, inventory[i]->name, inventory[i]->address, inventory[i]->quantity);
  }
}

// Main function
int main() {
  // Initialize warehouses and inventory
  int num_warehouses = 0;
  Warehouse** warehouses = malloc(sizeof(Warehouse*) * 100);
  int num_inventory = 0;
  Inventory** inventory = malloc(sizeof(Inventory*) * 100);

  // Add some warehouses and inventory items
  addWarehouse(warehouses, &num_warehouses, "Warehouse 1", "123 Main St", 1000);
  addWarehouse(warehouses, &num_warehouses, "Warehouse 2", "456 Elm St", 500);
  addInventory(inventory, &num_inventory, "Product A", "Warehouse 1", 100);
  addInventory(inventory, &num_inventory, "Product B", "Warehouse 2", 200);

  // Display all warehouses and inventory items
  displayWarehouses(warehouses, num_warehouses, inventory, num_inventory);

  // Free memory
  for (int i = 0; i < num_warehouses; i++) {
    free(warehouses[i]);
  }
  free(warehouses);
  for (int i = 0; i < num_inventory; i++) {
    free(inventory[i]);
  }
  free(inventory);

  return 0;
}