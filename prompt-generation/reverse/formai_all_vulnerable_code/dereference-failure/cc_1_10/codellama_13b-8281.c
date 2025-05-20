//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct product {
  char* name;
  int quantity;
  float price;
};

struct warehouse {
  struct product* products;
  int num_products;
};

void add_product(struct warehouse* warehouse, char* name, int quantity, float price) {
  warehouse->num_products++;
  warehouse->products = realloc(warehouse->products, sizeof(struct product) * warehouse->num_products);
  warehouse->products[warehouse->num_products - 1].name = name;
  warehouse->products[warehouse->num_products - 1].quantity = quantity;
  warehouse->products[warehouse->num_products - 1].price = price;
}

void update_product(struct warehouse* warehouse, char* name, int quantity, float price) {
  for (int i = 0; i < warehouse->num_products; i++) {
    if (strcmp(warehouse->products[i].name, name) == 0) {
      warehouse->products[i].quantity = quantity;
      warehouse->products[i].price = price;
      return;
    }
  }
}

void remove_product(struct warehouse* warehouse, char* name) {
  for (int i = 0; i < warehouse->num_products; i++) {
    if (strcmp(warehouse->products[i].name, name) == 0) {
      for (int j = i; j < warehouse->num_products - 1; j++) {
        warehouse->products[j] = warehouse->products[j + 1];
      }
      warehouse->num_products--;
      warehouse->products = realloc(warehouse->products, sizeof(struct product) * warehouse->num_products);
      return;
    }
  }
}

void print_warehouse(struct warehouse* warehouse) {
  printf("Warehouse:\n");
  for (int i = 0; i < warehouse->num_products; i++) {
    printf("%s: %d x %f\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
  }
}

int main() {
  struct warehouse warehouse = {0};

  add_product(&warehouse, "Apple", 10, 5.0);
  add_product(&warehouse, "Orange", 20, 3.0);
  add_product(&warehouse, "Banana", 30, 2.0);

  update_product(&warehouse, "Apple", 5, 6.0);

  remove_product(&warehouse, "Banana");

  print_warehouse(&warehouse);

  return 0;
}