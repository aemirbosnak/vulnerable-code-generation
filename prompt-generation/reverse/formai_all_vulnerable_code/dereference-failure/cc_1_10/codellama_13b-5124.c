//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct Product {
  int id;
  char name[100];
  float price;
  int quantity;
};

struct Inventory {
  struct Product* products;
  int num_products;
};

void print_inventory(struct Inventory* inv) {
  for (int i = 0; i < inv->num_products; i++) {
    printf("%d. %s (%d) - %f\n", inv->products[i].id, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
  }
}

void add_product(struct Inventory* inv, struct Product product) {
  inv->products[inv->num_products] = product;
  inv->num_products++;
}

void remove_product(struct Inventory* inv, int id) {
  for (int i = 0; i < inv->num_products; i++) {
    if (inv->products[i].id == id) {
      inv->products[i] = inv->products[inv->num_products - 1];
      inv->num_products--;
      break;
    }
  }
}

int main() {
  struct Inventory inv = {0};
  inv.num_products = 3;
  struct Product products[] = {
    {1, "Apple", 2.5, 5},
    {2, "Banana", 1.5, 10},
    {3, "Orange", 3.5, 7}
  };
  inv.products = products;
  print_inventory(&inv);
  add_product(&inv, (struct Product){4, "Pear", 5.0, 2});
  print_inventory(&inv);
  remove_product(&inv, 3);
  print_inventory(&inv);
  return 0;
}