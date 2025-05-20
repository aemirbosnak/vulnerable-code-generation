//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: systematic
// Inventory System Example Program

#include <stdio.h>
#include <stdlib.h>

// Structures
struct Product {
  char name[50];
  int price;
  int quantity;
};

struct Inventory {
  struct Product *products;
  int capacity;
  int size;
};

// Functions
void addProduct(struct Inventory *inventory, struct Product product) {
  if (inventory->size < inventory->capacity) {
    inventory->products[inventory->size] = product;
    inventory->size++;
  }
}

void removeProduct(struct Inventory *inventory, char name[]) {
  for (int i = 0; i < inventory->size; i++) {
    if (strcmp(inventory->products[i].name, name) == 0) {
      inventory->products[i] = inventory->products[inventory->size - 1];
      inventory->size--;
      break;
    }
  }
}

void printInventory(struct Inventory *inventory) {
  for (int i = 0; i < inventory->size; i++) {
    printf("%s: $%d x %d\n", inventory->products[i].name, inventory->products[i].price, inventory->products[i].quantity);
  }
}

int main() {
  struct Inventory inventory;
  inventory.capacity = 10;
  inventory.size = 0;
  inventory.products = malloc(inventory.capacity * sizeof(struct Product));

  struct Product product1;
  strcpy(product1.name, "Apple");
  product1.price = 5;
  product1.quantity = 10;

  struct Product product2;
  strcpy(product2.name, "Banana");
  product2.price = 2;
  product2.quantity = 5;

  addProduct(&inventory, product1);
  addProduct(&inventory, product2);

  printInventory(&inventory);

  removeProduct(&inventory, "Apple");

  printInventory(&inventory);

  return 0;
}