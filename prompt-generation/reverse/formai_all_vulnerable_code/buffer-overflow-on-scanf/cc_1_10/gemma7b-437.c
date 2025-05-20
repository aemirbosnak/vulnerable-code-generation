//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int inventory_size = 10;
char inventory[10][20];
int quantity[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
float price[10] = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0};

// Function to add item to inventory
void add_item() {
  printf("Enter item name: ");
  scanf("%s", inventory[inventory_size - 1]);

  printf("Enter item quantity: ");
  scanf("%d", &quantity[inventory_size - 1]);

  printf("Enter item price: ");
  scanf("%f", &price[inventory_size - 1]);

  inventory_size++;
}

// Function to search item
void search_item() {
  char item_name[20];

  printf("Enter item name: ");
  scanf("%s", item_name);

  int found = 0;
  for (int i = 0; i < inventory_size; i++) {
    if (strcmp(item_name, inventory[i]) == 0) {
      found = 1;
      printf("Item name: %s\n", inventory[i]);
      printf("Item quantity: %d\n", quantity[i]);
      printf("Item price: %.2f\n", price[i]);
    }
  }

  if (!found) {
    printf("Item not found.\n");
  }
}

// Function to update item quantity
void update_item_quantity() {
  char item_name[20];

  printf("Enter item name: ");
  scanf("%s", item_name);

  int found = 0;
  for (int i = 0; i < inventory_size; i++) {
    if (strcmp(item_name, inventory[i]) == 0) {
      found = 1;
      printf("Enter new item quantity: ");
      scanf("%d", &quantity[i]);
    }
  }

  if (!found) {
    printf("Item not found.\n");
  }
}

// Function to update item price
void update_item_price() {
  char item_name[20];

  printf("Enter item name: ");
  scanf("%s", item_name);

  int found = 0;
  for (int i = 0; i < inventory_size; i++) {
    if (strcmp(item_name, inventory[i]) == 0) {
      found = 1;
      printf("Enter new item price: ");
      scanf("%f", &price[i]);
    }
  }

  if (!found) {
    printf("Item not found.\n");
  }
}

// Main menu loop
int main() {
  int choice;

  while (1) {
    printf("Enter 1 to add item, 2 to search item, 3 to update item quantity, 4 to update item price, or 5 to exit: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_item();
        break;
      case 2:
        search_item();
        break;
      case 3:
        update_item_quantity();
        break;
      case 4:
        update_item_price();
        break;
      case 5:
        exit(0);
    }
  }

  return 0;
}