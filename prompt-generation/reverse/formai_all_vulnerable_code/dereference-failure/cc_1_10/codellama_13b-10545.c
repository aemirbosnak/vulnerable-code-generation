//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: systematic
// C Warehouse Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structs
typedef struct {
  int id;
  char name[50];
  int quantity;
  int price;
} Product;

typedef struct {
  int id;
  char name[50];
  int quantity;
  int price;
} Inventory;

// Define the functions
void addProduct(Product *products, int *numProducts, char name[50], int quantity, int price) {
  Product *newProduct = malloc(sizeof(Product));
  newProduct->id = *numProducts + 1;
  strcpy(newProduct->name, name);
  newProduct->quantity = quantity;
  newProduct->price = price;
  products[*numProducts] = *newProduct;
  *numProducts = *numProducts + 1;
  free(newProduct);
}

void addInventory(Inventory *inventories, int *numInventories, char name[50], int quantity, int price) {
  Inventory *newInventory = malloc(sizeof(Inventory));
  newInventory->id = *numInventories + 1;
  strcpy(newInventory->name, name);
  newInventory->quantity = quantity;
  newInventory->price = price;
  inventories[*numInventories] = *newInventory;
  *numInventories = *numInventories + 1;
  free(newInventory);
}

void updateInventory(Inventory *inventories, int numInventories, char name[50], int quantity, int price) {
  for (int i = 0; i < numInventories; i++) {
    if (strcmp(inventories[i].name, name) == 0) {
      inventories[i].quantity = quantity;
      inventories[i].price = price;
      break;
    }
  }
}

void removeInventory(Inventory *inventories, int *numInventories, char name[50]) {
  for (int i = 0; i < *numInventories; i++) {
    if (strcmp(inventories[i].name, name) == 0) {
      for (int j = i; j < *numInventories - 1; j++) {
        inventories[j] = inventories[j + 1];
      }
      *numInventories = *numInventories - 1;
      break;
    }
  }
}

void printInventory(Inventory *inventories, int numInventories) {
  for (int i = 0; i < numInventories; i++) {
    printf("%s: %d units, $%d each\n", inventories[i].name, inventories[i].quantity, inventories[i].price);
  }
}

int main() {
  Product products[100];
  Inventory inventories[100];
  int numProducts = 0;
  int numInventories = 0;

  // Add products to the system
  addProduct(products, &numProducts, "Apple", 10, 5);
  addProduct(products, &numProducts, "Banana", 20, 3);
  addProduct(products, &numProducts, "Orange", 30, 2);

  // Add inventory to the system
  addInventory(inventories, &numInventories, "Apple", 5, 5);
  addInventory(inventories, &numInventories, "Banana", 10, 3);
  addInventory(inventories, &numInventories, "Orange", 15, 2);

  // Update inventory
  updateInventory(inventories, numInventories, "Banana", 15, 4);

  // Remove inventory
  removeInventory(inventories, &numInventories, "Apple");

  // Print inventory
  printInventory(inventories, numInventories);

  return 0;
}