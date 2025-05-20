//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  typedef struct {
    char *name;
    int quantity;
    float price;
  } Product;

  typedef struct {
    Product *products;
    int num_products;
  } Warehouse;

  Warehouse *create_warehouse(int num_products) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->products = malloc(num_products * sizeof(Product));
    warehouse->num_products = num_products;
    return warehouse;
  }

  void add_product(Warehouse *warehouse, char *name, int quantity, float price) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
      if (strcmp(warehouse->products[i].name, name) == 0) {
        warehouse->products[i].quantity += quantity;
        warehouse->products[i].price = price;
        return;
      }
    }
    warehouse->products[warehouse->num_products].name = name;
    warehouse->products[warehouse->num_products].quantity = quantity;
    warehouse->products[warehouse->num_products].price = price;
    warehouse->num_products++;
  }

  void remove_product(Warehouse *warehouse, char *name, int quantity) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
      if (strcmp(warehouse->products[i].name, name) == 0) {
        warehouse->products[i].quantity -= quantity;
        if (warehouse->products[i].quantity <= 0) {
          warehouse->num_products--;
          for (int j = i; j < warehouse->num_products; j++) {
            warehouse->products[j] = warehouse->products[j + 1];
          }
        }
        return;
      }
    }
  }

  void print_products(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->num_products; i++) {
      printf("%s: %d units @ $%f\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
    }
  }

  int main() {
    Warehouse *warehouse = create_warehouse(5);
    add_product(warehouse, "Apples", 10, 2.50);
    add_product(warehouse, "Bananas", 5, 1.50);
    add_product(warehouse, "Oranges", 8, 3.00);
    add_product(warehouse, "Apples", 3, 2.50);
    add_product(warehouse, "Bananas", 2, 1.50);
    remove_product(warehouse, "Apples", 2);
    print_products(warehouse);
    return 0;
  }