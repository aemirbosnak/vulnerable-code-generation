//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int quantity;
  float price;
} Item;

Item items[MAX_ITEMS];

void add_item() {
  Item item;
  printf("Enter item name: ");
  scanf("%s", item.name);
  printf("Enter item quantity: ");
  scanf("%d", &item.quantity);
  printf("Enter item price: ");
  scanf("%f", &item.price);
  items[0] = item;
}

void list_items() {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].quantity > 0) {
      printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
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
    }
  }
}

int main() {
  int choice;
  printf("Welcome to the Medical Store Management System.\n");
  printf("Please select an option:\n");
  printf("1. Add item\n");
  printf("2. List items\n");
  printf("3. Update item\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      add_item();
      break;
    case 2:
      list_items();
      break;
    case 3:
      update_item();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}