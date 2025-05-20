//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
  char* name;
  int quantity;
  float price;
};

struct Warehouse {
  struct Item* items;
  int num_items;
  int capacity;
};

void print_item(struct Item item) {
  printf("Name: %s\nQuantity: %d\nPrice: %.2f\n\n", item.name, item.quantity, item.price);
}

void print_warehouse(struct Warehouse warehouse) {
  for (int i = 0; i < warehouse.num_items; i++) {
    print_item(warehouse.items[i]);
  }
}

void add_item(struct Warehouse* warehouse, struct Item item) {
  if (warehouse->num_items < warehouse->capacity) {
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
  } else {
    printf("Warehouse is full. Cannot add more items.\n");
  }
}

void remove_item(struct Warehouse* warehouse, char* name) {
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      for (int j = i; j < warehouse->num_items - 1; j++) {
        warehouse->items[j] = warehouse->items[j + 1];
      }
      warehouse->num_items--;
      break;
    }
  }
}

void update_item_quantity(struct Warehouse* warehouse, char* name, int quantity) {
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->items[i].name, name) == 0) {
      warehouse->items[i].quantity = quantity;
      break;
    }
  }
}

int main() {
  struct Warehouse warehouse = { NULL, 0, 100 };
  struct Item item1 = { "Apple", 10, 5.00 };
  struct Item item2 = { "Banana", 20, 2.00 };
  struct Item item3 = { "Orange", 30, 3.00 };

  add_item(&warehouse, item1);
  add_item(&warehouse, item2);
  add_item(&warehouse, item3);

  print_warehouse(warehouse);

  remove_item(&warehouse, "Banana");
  update_item_quantity(&warehouse, "Apple", 15);

  print_warehouse(warehouse);

  return 0;
}