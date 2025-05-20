//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
  int id;
  char name[100];
  float price;
};

struct Inventory {
  int count;
  struct Product *products;
};

void addProduct(struct Inventory *inv, int id, char *name, float price) {
  inv->count++;
  inv->products = realloc(inv->products, inv->count * sizeof(struct Product));
  struct Product *newProduct = &inv->products[inv->count - 1];
  newProduct->id = id;
  strcpy(newProduct->name, name);
  newProduct->price = price;
}

void removeProduct(struct Inventory *inv, int id) {
  for (int i = 0; i < inv->count; i++) {
    if (inv->products[i].id == id) {
      for (int j = i; j < inv->count - 1; j++) {
        inv->products[j] = inv->products[j + 1];
      }
      inv->count--;
      break;
    }
  }
}

void printInventory(struct Inventory *inv) {
  printf("Inventory:\n");
  for (int i = 0; i < inv->count; i++) {
    printf("%d: %s (%.2f)\n", inv->products[i].id, inv->products[i].name, inv->products[i].price);
  }
}

int main() {
  struct Inventory inv = {0};
  addProduct(&inv, 1, "Apple", 1.5);
  addProduct(&inv, 2, "Banana", 2.5);
  addProduct(&inv, 3, "Orange", 3.5);
  removeProduct(&inv, 2);
  printInventory(&inv);
  return 0;
}