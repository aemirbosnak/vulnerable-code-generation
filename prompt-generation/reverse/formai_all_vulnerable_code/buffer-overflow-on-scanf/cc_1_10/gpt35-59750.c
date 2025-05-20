//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

struct Item {
  int item_id;
  char *name;
  int quantity;
};

typedef struct Item Item;

void check_delivery(Item *inventory, int size) {
  int delivered;
  printf("Enter the number of items being delivered: ");
  scanf("%d", &delivered);

  for (int i = 0; i < delivered; i++) {
    inventory[i].quantity += 1;
    printf("Item delivered: %s\nUpdated quantity: %d\n\n", inventory[i].name, inventory[i].quantity);
  }
}

void check_stock(Item *inventory, int size) {
  printf("Available stock:\n");
  for (int i = 0; i < size; i++)
    printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
  printf("\n");
}

void ship_order(Item *inventory, int size) {
  int item_id, shipped;
  printf("Enter the item ID to be shipped (or 0 to cancel): ");
  scanf("%d", &item_id);

  while (item_id != 0) {
    printf("Enter the number of items to be shipped: ");
    scanf("%d", &shipped);

    for (int i = 0; i < size; i++) {
      if (inventory[i].item_id == item_id) {
        if (inventory[i].quantity < shipped)
          printf("Not enough stock available.\n\n");
        else {
          inventory[i].quantity -= shipped;
          printf("%d %s shipped.\n\n", shipped, inventory[i].name);
        }
        break;
      }
    }

    printf("Enter the item ID to be shipped (or 0 to cancel): ");
    scanf("%d", &item_id);
  }
}

int main() {
  Item inventory[] = {
    {1, "Widget", 100},
    {2, "Gadget", 50},
    {3, "Doodad", 75},
  };

  int size = sizeof(inventory) / sizeof(Item);

  int choice;
  do {
    printf("1) Check delivery\n2) Check stock\n3) Ship order\n4) Quit\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: check_delivery(inventory, size); break;
      case 2: check_stock(inventory, size); break;
      case 3: ship_order(inventory, size); break;
    }
  } while (choice != 4);

  return 0;
}