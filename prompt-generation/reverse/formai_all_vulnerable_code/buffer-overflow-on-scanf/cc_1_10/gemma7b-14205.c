//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[50];
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

  items[MAX_ITEMS - 1] = item;
}

void list_items() {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].name[0] != '\0') {
      printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
  }
}

void search_item() {
  char item_name[50];

  printf("Enter item name: ");
  scanf("%s", item_name);

  for (int i = 0; i < MAX_ITEMS; i++) {
    if (strcmp(items[i].name, item_name) == 0) {
      printf("Item name: %s\n", items[i].name);
      printf("Item quantity: %d\n", items[i].quantity);
      printf("Item price: %.2f\n", items[i].price);
    }
  }
}

int main() {
  int choice;

  printf("Welcome to the Sherlock Holmes Medical Store Management System!\n");

  while (1) {
    printf("Please select an option:\n");
    printf("1. Add item\n");
    printf("2. List items\n");
    printf("3. Search item\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_item();
        break;
      case 2:
        list_items();
        break;
      case 3:
        search_item();
        break;
      case 4:
        exit(0);
    }
  }

  return 0;
}