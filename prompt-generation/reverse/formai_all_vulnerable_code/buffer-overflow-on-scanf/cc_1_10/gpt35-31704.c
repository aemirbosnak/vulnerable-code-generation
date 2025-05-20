//FormAI DATASET v1.0 Category: Product Inventory System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

struct Product {
  int product_id;
  char name[50];
  int stock_quantity;
  float price;
};

struct Product inventory[MAX_PRODUCTS];
int num_products = 0;

// Function to add a new product to inventory
void add_product() {
  struct Product p;

  printf("Enter product name: ");
  scanf("%s", p.name);

  printf("Enter stock quantity: ");
  scanf("%d", &p.stock_quantity);

  printf("Enter price: ");
  scanf("%f", &p.price);

  // Assign a unique id to each product
  p.product_id = num_products + 1;

  inventory[num_products] = p;
  num_products++;

  printf("Product added successfully!\n");
}

// Function to search for a product by name and return its index
int search_product(char *name) {
  for (int i = 0; i < num_products; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to remove a product from inventory
void remove_product() {
  char name[50];
  printf("Enter product name: ");
  scanf("%s", name);

  int index = search_product(name);

  if (index == -1) {
    printf("Product not found!\n");
  } else {
    // Remove the product from inventory by shifting elements to the left
    for (int i = index; i < num_products - 1; i++) {
      inventory[i] = inventory[i + 1];
    }
    num_products--;
    printf("Product removed successfully!\n");
  }
}

// Function to display all products in inventory
void display_inventory() {
  printf("ProductID\tName\t\tStockQuantity\tPrice\n");
  for (int i = 0; i < num_products; i++) {
    printf("%d\t\t%s\t%d\t\t%.2f\n", inventory[i].product_id, inventory[i].name,
           inventory[i].stock_quantity, inventory[i].price);
  }
}

// Function to update the stock quantity of a product
void update_stock_quantity() {
  char name[50];
  printf("Enter product name: ");
  scanf("%s", name);

  int index = search_product(name);

  if (index == -1) {
    printf("Product not found!\n");
  } else {
    printf("Enter new stock quantity: ");
    scanf("%d", &inventory[index].stock_quantity);
    printf("Stock quantity updated successfully!\n");
  }
}

// Main function
int main() {
  int choice;

  do {
    printf("\nChoose an option:\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Display inventory\n");
    printf("4. Update stock quantity\n");
    printf("5. Exit\n\n");

    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_product();
        break;
      case 2:
        remove_product();
        break;
      case 3:
        display_inventory();
        break;
      case 4:
        update_stock_quantity();
        break;
      case 5:
        printf("Exiting program...\n");
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 5);

  return 0;
}