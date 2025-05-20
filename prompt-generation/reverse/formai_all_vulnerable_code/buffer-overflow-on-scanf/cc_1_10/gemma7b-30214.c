//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
  char name[20];
  int quantity;
  float price;
} Item;

void update_inventory(Item *items, int num_items) {
  printf("Enter item name: ");
  scanf("%s", items[num_items].name);

  printf("Enter item quantity: ");
  scanf("%d", &items[num_items].quantity);

  printf("Enter item price: ");
  scanf("%f", &items[num_items].price);

  num_items++;
}

void display_inventory(Item *items, int num_items) {
  printf("Inventory:\n");

  for (int i = 0; i < num_items; i++) {
    printf("%s: %d at $%.2f\n", items[i].name, items[i].quantity, items[i].price);
  }
}

int main() {
  Item items[10];
  int num_items = 0;

  printf("Welcome to the C Product Inventory System!\n");

  while (1) {
    printf("Enter 'add' to add an item, 'display' to display the inventory, or 'quit' to quit: ");
    char command[20];
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
      update_inventory(items, num_items);
    } else if (strcmp(command, "display") == 0) {
      display_inventory(items, num_items);
    } else if (strcmp(command, "quit") == 0) {
      break;
    } else {
      printf("Invalid command.\n");
    }
  }

  printf("Thank you for using the C Product Inventory System!\n");

  return 0;
}