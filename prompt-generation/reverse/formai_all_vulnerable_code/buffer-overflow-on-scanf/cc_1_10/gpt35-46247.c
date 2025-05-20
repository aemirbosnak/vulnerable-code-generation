//FormAI DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold product information
struct Product {
  int id;
  char name[50];
  int quantity;
  float price;
};

// Function to add a new product
void addProduct(struct Product inventory[], int *prodCount) {
  printf("Enter product name: ");
  scanf("%s", inventory[*prodCount].name);
  printf("Enter price: ");
  scanf("%f", &inventory[*prodCount].price);
  printf("Enter quantity: ");
  scanf("%d", &inventory[*prodCount].quantity);
  inventory[*prodCount].id = *prodCount + 1;
  (*prodCount)++;
  printf("\nProduct added successfully.\n");
}

// Function to display inventory
void displayInventory(struct Product inventory[], int prodCount) {
  printf("\nID   NAME              PRICE   QUANTITY\n");
  for (int i = 0; i < prodCount; i++) {
    printf("%-4d %-16s %.2f    %-4d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
  }
}

// Function to search for a product by name
void searchProduct(struct Product inventory[], int prodCount) {
  char name[50];
  printf("Enter product name to search: ");
  scanf("%s", name);
  int found = 0;
  for (int i = 0; i < prodCount; i++) {
    if (strcmp(name, inventory[i].name) == 0) {
      printf("\nID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
      found = 1;
    }
  }
  if (!found) {
    printf("\nProduct not found.\n");
  }
}

int main() {
  printf("Welcome to the Product Inventory System!\n\n");
  int choice, prodCount = 0, maxProducts = 100;
  struct Product inventory[maxProducts];
  do {
    printf("1. Add new product\n");
    printf("2. Display inventory\n");
    printf("3. Search for a product\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        addProduct(inventory, &prodCount);
        break;
      case 2:
        displayInventory(inventory, prodCount);
        break;
      case 3:
        searchProduct(inventory, prodCount);
        break;
      case 4:
        printf("\nThank you for using the Product Inventory System!");
        break;
      default:
        printf("\nInvalid choice. Please try again.");
        break;
    }
    printf("\n");
  } while(choice != 4);
  return 0;
}