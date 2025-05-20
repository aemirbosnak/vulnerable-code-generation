//FormAI DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining structure for a product
struct product {
  char name[50];
  int id;
  float price;
  int quantity;
};

// function prototypes
void add_product();
void list_products();
void update_product();
void delete_product();

// global variable for product inventory
struct product inventory[100];
int inventory_size = 0;

int main() {
  int choice;

  printf("Welcome to the Product Inventory System!\n\n");

  do {
    // menu for user
    printf("Please select an option:\n");
    printf("1. Add a new product\n");
    printf("2. List all products\n");
    printf("3. Update a product\n");
    printf("4. Delete a product\n");
    printf("5. Exit the program\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_product();
        break;
      case 2:
        list_products();
        break;
      case 3:
        update_product();
        break;
      case 4:
        delete_product();
        break;
      case 5:
        printf("Thank you for using the Product Inventory System!\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 5);

  return 0;
}

void add_product() {
  // adding a new product to inventory
  printf("Please enter the following information for the new product:\n");

  printf("Name: ");
  scanf("%s", inventory[inventory_size].name);

  printf("ID: ");
  scanf("%d", &inventory[inventory_size].id);

  printf("Price: ");
  scanf("%f", &inventory[inventory_size].price);

  printf("Quantity: ");
  scanf("%d", &inventory[inventory_size].quantity);

  printf("New product added to inventory!\n");

  inventory_size++;
}

void list_products() {
  // listing all products in inventory
  printf("Current Inventory:\n\n");

  for (int i = 0; i < inventory_size; i++) {
    printf("Name: %s\n", inventory[i].name);
    printf("ID: %d\n", inventory[i].id);
    printf("Price: %.2f\n", inventory[i].price);
    printf("Quantity: %d\n\n", inventory[i].quantity);
  }
}

void update_product() {
  // updating an existing product in inventory
  int id, index;

  printf("Please enter the ID of the product you would like to update: ");
  scanf("%d", &id);

  // finding the index of product in inventory
  for (int i = 0; i < inventory_size; i++) {
    if (inventory[i].id == id) {
      index = i;
      break;
    }
  }

  // updating the product information
  printf("Please enter the new information for the product:\n");

  printf("Name: ");
  scanf("%s", inventory[index].name);

  printf("Price: ");
  scanf("%f", &inventory[index].price);

  printf("Quantity: ");
  scanf("%d", &inventory[index].quantity);

  printf("Product information has been updated!\n");
}

void delete_product() {
  // deleting an existing product from inventory
  int id, index;

  printf("Please enter the ID of the product you would like to delete: ");
  scanf("%d", &id);

  // finding the index of product in inventory
  for (int i = 0; i < inventory_size; i++) {
    if (inventory[i].id == id) {
      index = i;
      break;
    }
  }

  // shifting array elements to remove the deleted product
  for (int i = index; i < inventory_size - 1; i++) {
    inventory[i] = inventory[i + 1];
  }

  inventory_size--;

  printf("Product has been deleted from inventory!\n");
}