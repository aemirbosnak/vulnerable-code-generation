//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[20];
  int quantity;
  float price;
} Item;

Item items[MAX_ITEMS];

void display_items() {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].quantity > 0) {
      printf("%s: %d @ %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
  }
}

void add_item() {
  Item new_item;
  printf("Enter item name: ");
  scanf("%s", new_item.name);

  printf("Enter item quantity: ");
  scanf("%d", &new_item.quantity);

  printf("Enter item price: ");
  scanf("%f", &new_item.price);

  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].quantity == 0) {
      items[i] = new_item;
      break;
    }
  }
}

void update_item() {
  char item_name[20];
  printf("Enter item name: ");
  scanf("%s", item_name);

  for (int i = 0; i < MAX_ITEMS; i++) {
    if (strcmp(items[i].name, item_name) == 0) {
      printf("Enter new item quantity: ");
      scanf("%d", &items[i].quantity);

      printf("Enter new item price: ");
      scanf("%f", &items[i].price);
      break;
    }
  }
}

void remove_item() {
  char item_name[20];
  printf("Enter item name: ");
  scanf("%s", item_name);

  for (int i = 0; i < MAX_ITEMS; i++) {
    if (strcmp(items[i].name, item_name) == 0) {
      items[i].quantity = 0;
      break;
    }
  }
}

int main() {
  int choice;

  printf("Welcome to the Inventory Management System!\n");

  while (1) {
    printf("Enter 1 to display items, 2 to add item, 3 to update item, 4 to remove item, or 5 to exit: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        display_items();
        break;
      case 2:
        add_item();
        break;
      case 3:
        update_item();
        break;
      case 4:
        remove_item();
        break;
      case 5:
        exit(0);
    }
  }

  return 0;
}