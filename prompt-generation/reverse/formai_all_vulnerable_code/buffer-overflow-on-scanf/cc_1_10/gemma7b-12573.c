//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[50];
  int quantity;
  double price;
} Item;

Item items[MAX_ITEMS];

void inventory_manage() {
  int i;
  for (i = 0; i < MAX_ITEMS; i++) {
    printf("%s: %d, $%.2lf\n", items[i].name, items[i].quantity, items[i].price);
  }
}

void item_add() {
  Item new_item;
  printf("Enter item name: ");
  scanf("%s", new_item.name);
  printf("Enter item quantity: ");
  scanf("%d", &new_item.quantity);
  printf("Enter item price: ");
  scanf("%lf", &new_item.price);

  int i = 0;
  for (; items[i].name[0] != '\0'; i++) {}

  items[i] = new_item;
}

void item_update() {
  char item_name[50];
  printf("Enter item name: ");
  scanf("%s", item_name);

  int i = 0;
  for (; items[i].name[0] != '\0'; i++) {
    if (strcmp(items[i].name, item_name) == 0) {
      printf("Enter new item quantity: ");
      scanf("%d", &items[i].quantity);
      printf("Enter new item price: ");
      scanf("%lf", &items[i].price);
    }
  }
}

void item_delete() {
  char item_name[50];
  printf("Enter item name: ");
  scanf("%s", item_name);

  int i = 0;
  for (; items[i].name[0] != '\0'; i++) {
    if (strcmp(items[i].name, item_name) == 0) {
      items[i] = items[i+1];
    }
  }
}

int main() {
  int choice;

  printf("Welcome to the Romantic Warehouse Management System!\n");
  printf("Please select an option:\n");
  printf("1. Inventory Management\n");
  printf("2. Item Add\n");
  printf("3. Item Update\n");
  printf("4. Item Delete\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      inventory_manage();
      break;
    case 2:
      item_add();
      break;
    case 3:
      item_update();
      break;
    case 4:
      item_delete();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}