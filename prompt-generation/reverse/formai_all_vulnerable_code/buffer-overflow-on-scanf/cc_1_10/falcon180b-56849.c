//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

struct product {
  char name[MAX_NAME_LENGTH];
  int quantity;
};

void add_product(struct product* inventory, int count, char* name, int quantity) {
  int i;
  for (i = 0; i < count; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      inventory[i].quantity += quantity;
      return;
    }
  }
  strncpy(inventory[count].name, name, MAX_NAME_LENGTH);
  inventory[count].quantity = quantity;
  count++;
}

void remove_product(struct product* inventory, int count, char* name) {
  int i;
  for (i = 0; i < count; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      memmove(&inventory[i], &inventory[i + 1], (count - i - 1) * sizeof(struct product));
      count--;
      return;
    }
  }
}

void print_inventory(struct product* inventory, int count) {
  int i;
  for (i = 0; i < count; i++) {
    printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
  }
}

int main() {
  struct product inventory[MAX_PRODUCTS];
  int count = 0;
  char command[100];

  while (1) {
    printf("Enter command (add/remove/print/exit): ");
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
      printf("Enter product name: ");
      scanf("%s", command);
      printf("Enter quantity: ");
      scanf("%d", &inventory[count].quantity);
      strncpy(inventory[count].name, command, MAX_NAME_LENGTH);
      count++;
    } else if (strcmp(command, "remove") == 0) {
      printf("Enter product name: ");
      scanf("%s", command);
      remove_product(inventory, count, command);
    } else if (strcmp(command, "print") == 0) {
      print_inventory(inventory, count);
    } else if (strcmp(command, "exit") == 0) {
      break;
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}