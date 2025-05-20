//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: grateful
// Warehouse Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Product {
  char name[50];
  int quantity;
  float price;
};

struct Warehouse {
  struct Product *products;
  int capacity;
  int count;
};

struct Warehouse *create_warehouse(int capacity) {
  struct Warehouse *warehouse = malloc(sizeof(struct Warehouse));
  warehouse->capacity = capacity;
  warehouse->count = 0;
  warehouse->products = malloc(sizeof(struct Product) * capacity);
  return warehouse;
}

void add_product(struct Warehouse *warehouse, struct Product product) {
  if (warehouse->count >= warehouse->capacity) {
    printf("Warehouse is full\n");
    return;
  }
  warehouse->products[warehouse->count] = product;
  warehouse->count++;
}

void remove_product(struct Warehouse *warehouse, char *name) {
  int i;
  for (i = 0; i < warehouse->count; i++) {
    if (strcmp(warehouse->products[i].name, name) == 0) {
      warehouse->products[i] = warehouse->products[warehouse->count - 1];
      warehouse->count--;
      return;
    }
  }
  printf("Product not found\n");
}

void print_products(struct Warehouse *warehouse) {
  int i;
  for (i = 0; i < warehouse->count; i++) {
    printf("%s: %d x %f\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
  }
}

int main() {
  struct Warehouse *warehouse = create_warehouse(10);
  struct Product product1 = {"Apple", 10, 10.00};
  struct Product product2 = {"Banana", 20, 5.00};
  add_product(warehouse, product1);
  add_product(warehouse, product2);
  remove_product(warehouse, "Banana");
  print_products(warehouse);
  free(warehouse);
  return 0;
}