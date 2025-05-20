//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int quantity;
  float price;
} Item;

Item items[MAX_ITEMS];

void initializeItems() {
  for (int i = 0; i < MAX_ITEMS; i++) {
    items[i].name[0] = '\0';
    items[i].quantity = 0;
    items[i].price = 0.0f;
  }
}

void displayItems() {
  printf("Items:\n");
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].name[0] != '\0') {
      printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
  }
}

void addItem() {
  Item item;
  printf("Enter item name:");
  scanf("%s", item.name);
  printf("Enter item quantity:");
  scanf("%d", &item.quantity);
  printf("Enter item price:");
  scanf("%f", &item.price);

  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].name[0] == '\0') {
      items[i] = item;
      break;
    }
  }
}

void updateItemQuantity(char* name, int quantity) {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (strcmp(items[i].name, name) == 0) {
      items[i].quantity = quantity;
      break;
    }
  }
}

void deleteItem(char* name) {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (strcmp(items[i].name, name) == 0) {
      items[i].name[0] = '\0';
      items[i].quantity = 0;
      items[i].price = 0.0f;
      break;
    }
  }
}

int main() {
  initializeItems();
  displayItems();
  addItem();
  displayItems();
  updateItemQuantity("Item 1", 10);
  displayItems();
  deleteItem("Item 2");
  displayItems();

  return 0;
}