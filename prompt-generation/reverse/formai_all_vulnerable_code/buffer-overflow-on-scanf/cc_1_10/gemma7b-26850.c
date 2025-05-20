//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int quantity;
  float price;
} Item;

Item items[MAX_ITEMS] = {
  {"Panadol", 10, 20.0f},
  {"Paracetamol", 5, 15.0f},
  {"Ibuprofen", 7, 18.0f},
  {"Gelusil", 2, 12.0f},
  {"Tefagen", 3, 22.0f},
  {"Ceftin", 4, 25.0f},
  {"Orlistad", 1, 30.0f},
  {"Diazepam", 6, 10.0f},
  {"Rivotril", 8, 16.0f},
  {"Valium", 9, 12.0f}
};

int main() {
  int i, item_index;
  char item_name[20];
  int item_quantity;
  float item_price;

  // Print item list
  printf("Item List:\n");
  for (i = 0; i < MAX_ITEMS; i++) {
    printf("%s (%d) - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
  }

  // Get item name and quantity
  printf("Enter item name:");
  scanf("%s", item_name);

  printf("Enter item quantity:");
  scanf("%d", &item_quantity);

  // Find item index
  item_index = -1;
  for (i = 0; i < MAX_ITEMS; i++) {
    if (strcmp(items[i].name, item_name) == 0) {
      item_index = i;
    }
  }

  // Update item quantity
  if (item_index != -1) {
    items[item_index].quantity += item_quantity;
  } else {
    printf("Item not found.\n");
  }

  // Print updated item list
  printf("Updated Item List:\n");
  for (i = 0; i < MAX_ITEMS; i++) {
    printf("%s (%d) - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
  }

  return 0;
}