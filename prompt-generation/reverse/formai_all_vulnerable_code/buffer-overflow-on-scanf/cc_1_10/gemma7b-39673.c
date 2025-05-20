//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *items[] = {"Apple", "Banana", "Orange", "Peach", "Pear"};
  int item_count = 5;
  int warehouse_size = 10;
  int current_stock = 0;
  int available_space = warehouse_size - current_stock;

  // Receive item name and quantity from user
  char item_name[20];
  int item_quantity;

  // Loop until item name is valid
  while (1) {
    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < item_count; i++) {
      if (strcmp(item_name, items[i]) == 0) {
        printf("Item name is valid.\n");
        break;
      }
    }

    if (strcmp(item_name, "") == 0) {
      printf("Item name is not valid.\n");
    }
  }

  // Loop until item quantity is valid
  while (1) {
    printf("Enter item quantity: ");
    scanf("%d", &item_quantity);

    if (item_quantity > available_space) {
      printf("Item quantity is too large.\n");
    } else if (item_quantity <= 0) {
      printf("Item quantity is not valid.\n");
    } else {
      break;
    }
  }

  // Calculate total number of items
  int total_items = current_stock + item_quantity;

  // Update current stock and available space
  current_stock += item_quantity;
  available_space -= item_quantity;

  // Print order confirmation
  printf("Order confirmed.\n");
  printf("Total items: %d\n", total_items);
  printf("Current stock: %d\n", current_stock);
  printf("Available space: %d\n", available_space);

  return 0;
}