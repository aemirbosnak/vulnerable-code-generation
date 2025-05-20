//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[50];
  int quantity;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, int quantity) {
  if (num_items < MAX_ITEMS) {
    strcpy(inventory[num_items].name, name);
    inventory[num_items].quantity = quantity;
    num_items++;
  }
}

void remove_item(char *name) {
  int i;
  for (i = 0; i < num_items; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      inventory[i] = inventory[num_items - 1];
      num_items--;
      break;
    }
  }
}

void print_inventory() {
  int i;
  for (i = 0; i < num_items; i++) {
    printf("%s\t%d\n", inventory[i].name, inventory[i].quantity);
  }
}

int main() {
  char input[100];
  int quantity;

  while (1) {
    printf("\n\nWarehouse Management System\n\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Print inventory\n");
    printf("4. Exit\n");
    printf("\n\nEnter your choice: ");
    gets(input);

    switch (atoi(input)) {
      case 1:
        printf("\nEnter item name: ");
        gets(input);
        printf("\nEnter quantity: ");
        scanf("%d", &quantity);
        add_item(input, quantity);
        break;
      case 2:
        printf("\nEnter item name: ");
        gets(input);
        remove_item(input);
        break;
      case 3:
        print_inventory();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("\nInvalid choice\n");
    }
  }

  return 0;
}