//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
  #include <stdlib.h>

  struct Product {
    int id;
    char name[20];
    float price;
    int quantity;
  };

  struct Warehouse {
    int id;
    char name[20];
    struct Product* products;
    int num_products;
  };

  int main() {
    struct Warehouse warehouse;
    warehouse.id = 1;
    strcpy(warehouse.name, "ABC Warehouse");
    warehouse.products = malloc(100 * sizeof(struct Product));
    warehouse.num_products = 0;

    struct Product product;
    product.id = 1;
    strcpy(product.name, "Apple");
    product.price = 10.99;
    product.quantity = 100;
    warehouse.products[warehouse.num_products++] = product;

    product.id = 2;
    strcpy(product.name, "Banana");
    product.price = 1.99;
    product.quantity = 200;
    warehouse.products[warehouse.num_products++] = product;

    product.id = 3;
    strcpy(product.name, "Orange");
    product.price = 2.99;
    product.quantity = 300;
    warehouse.products[warehouse.num_products++] = product;

    printf("Warehouse %d: %s\n", warehouse.id, warehouse.name);
    for (int i = 0; i < warehouse.num_products; i++) {
      printf("  Product %d: %s (%f)\n", warehouse.products[i].id, warehouse.products[i].name, warehouse.products[i].price);
    }

    return 0;
  }