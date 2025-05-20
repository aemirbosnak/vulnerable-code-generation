//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
// Welcome to the Warehouse of Wonders!

#include <stdio.h>

// Our enchanted warehouse stores all sorts of magical items.
typedef struct Item {
  char *name;
  int quantity;
  double price;
} Item;

// Our inventory is a collection of these items.
Item inventory[] = {
  {"Fireball", 10, 50.0},
  {"Healing Potion", 20, 20.0},
  {"Sword of Justice", 1, 1000.0}
};
const int NUM_ITEMS = sizeof(inventory) / sizeof(Item);

// We have some helpful functions to manage our inventory.
void printInventory() {
  printf("Behold, our wondrous inventory:\n");
  for (int i = 0; i < NUM_ITEMS; i++) {
    printf("  - %s: %d in stock, %.2f gold each\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
  }
}

void restock(char *item_name, int quantity) {
  for (int i = 0; i < NUM_ITEMS; i++) {
    if (strcmp(inventory[i].name, item_name) == 0) {
      inventory[i].quantity += quantity;
      printf("Restocked %d %s(s)!\n", quantity, item_name);
      break;
    }
  }
}

void sellItem(char *item_name, int quantity) {
  for (int i = 0; i < NUM_ITEMS; i++) {
    if (strcmp(inventory[i].name, item_name) == 0) {
      if (inventory[i].quantity >= quantity) {
        inventory[i].quantity -= quantity;
        printf("Sold %d %s(s) for a total of %.2f gold!\n", quantity, item_name, quantity * inventory[i].price);
      }
      else {
        printf("Sorry, we don't have that many %s(s) in stock.\n", item_name);
      }
      break;
    }
  }
}

void runWarehouse() {
  // We open our doors to brave adventurers.
  printf("Welcome to the Warehouse of Wonders! What can we do for you today?\n");

  // We handle their requests until they leave.
  char command[100];
  while (strcmp(command, "quit") != 0) {
    printf("> ");
    scanf("%s", command);

    // They can browse our inventory.
    if (strcmp(command, "inventory") == 0) {
      printInventory();
    }
    // Or they can ask us to restock.
    else if (strcmp(command, "restock") == 0) {
      char item_name[100];
      int quantity;
      scanf("%s %d", item_name, &quantity);
      restock(item_name, quantity);
    }
    // They can even buy our magical items!
    else if (strcmp(command, "sell") == 0) {
      char item_name[100];
      int quantity;
      scanf("%s %d", item_name, &quantity);
      sellItem(item_name, quantity);
    }
    // Or they can just leave.
    else if (strcmp(command, "quit") == 0) {
      printf("Thank you for visiting the Warehouse of Wonders! Come again soon!\n");
    }
    // If they ask for something else, we're a bit confused.
    else {
      printf("Sorry, I don't understand that command.\n");
    }
  }
}

int main() {
  runWarehouse();
  return 0;
}