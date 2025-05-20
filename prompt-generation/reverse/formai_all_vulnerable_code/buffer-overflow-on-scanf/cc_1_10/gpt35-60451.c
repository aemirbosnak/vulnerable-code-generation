//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct Product {
  char name[MAX_NAME_LENGTH];
  int quantity;
} Product;

Product inventory[MAX_PRODUCTS]; // Global inventory 

// Function declarations 
void addProduct(char* name, int quantity);
void removeProduct(char* name, int quantity);
void showInventory();

int main() {
  int option, quantity;
  char name[MAX_NAME_LENGTH];

  printf("Welcome to Warehouse Management System\n");

  while(1) {
    printf("\nMenu:\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Show Inventory\n");
    printf("4. Exit\n");
    printf("Select an option: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        printf("Enter name of the product: ");
        scanf("%s", name);
        printf("Enter quantity of the product: ");
        scanf("%d", &quantity);
        addProduct(name, quantity);
        break;
      case 2:
        printf("Enter name of the product: ");
        scanf("%s", name);
        printf("Enter quantity of the product: ");
        scanf("%d", &quantity);
        removeProduct(name, quantity);
        break;
      case 3:
        showInventory();
        break;
      case 4:
        printf("Exiting the program...\n");
        exit(0);
        break;
      default:
        printf("Invalid option!\n");
        break;
    }
  }

  return 0;
}

// Function definitions 
void addProduct(char* name, int quantity) {
  int i = 0;
  while(i < MAX_PRODUCTS && inventory[i].quantity != 0) {
    if(strcmp(name, inventory[i].name) == 0) { // If product already exists
          inventory[i].quantity += quantity;
          printf("%d %s added to inventory. Total: %d\n", quantity, name, inventory[i].quantity);
          return;
    }
    i++;
  }

  if(i == MAX_PRODUCTS) { // Maximum inventory reached
    printf("Maximum inventory reached. Cannot add %s\n", name);
    return;
  }

  // Adding a new product 
  strcpy(inventory[i].name, name);
  inventory[i].quantity = quantity;
  printf("%d %s added to inventory. Total: %d\n", quantity, name, inventory[i].quantity);
}

void removeProduct(char* name, int quantity) {
  int i = 0;
  while(i < MAX_PRODUCTS && inventory[i].quantity != 0) {
    if(strcmp(name, inventory[i].name) == 0) { // If product found in inventory
      if(quantity > inventory[i].quantity) { // If removing more than current quantity
        printf("Cannot remove %d %s. Only %d available in the inventory.\n", quantity, name, inventory[i].quantity);
        return;
      }
      inventory[i].quantity -= quantity;
      printf("%d %s removed from inventory. Total: %d\n", quantity, name, inventory[i].quantity);
      if(inventory[i].quantity == 0) {
        printf("%s removed from inventory since it is now empty.\n", name);
      }
      return;
    }
    i++;
  }

  if(i == MAX_PRODUCTS) { // Maximum inventory reached
    printf("%s not found in inventory.", name);
    return;
  }

  printf("%s not found in inventory.", name);
}

void showInventory() {
  printf("Inventory:\n");
  for(int i = 0; i < MAX_PRODUCTS && inventory[i].quantity != 0; i++) {
    printf("%s - %d\n", inventory[i].name, inventory[i].quantity);
  }
}