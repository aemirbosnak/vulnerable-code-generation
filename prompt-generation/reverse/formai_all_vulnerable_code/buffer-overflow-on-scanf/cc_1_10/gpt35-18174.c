//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include<stdio.h>

// Defining a structure inventory to keep the record of products in warehouse
struct inventory {
  char product_name[50];
  int product_id;
  int available_quantity;
  float price;
};

// Function to update the record of products in warehouse
void update_inventory(struct inventory products[], int num_of_products) {
  int id, qty;
  printf("\nEnter the product id to update the inventory: ");
  scanf("%d", &id);
  for(int i=0; i<num_of_products; i++) {
    if(products[i].product_id == id) {
      printf("Enter the available quantity for %s: ", products[i].product_name);
      scanf("%d", &qty);
      products[i].available_quantity = qty;
      printf("%s inventory updated successfully!\n", products[i].product_name);
      return;
    }
  }
  printf("Product id not found!\n");
}

// Function to print the current inventory of all products in warehouse
void print_inventory(struct inventory products[], int num_of_products) {
  printf("\n%-15s%-20s%-25s%-10s\n", "Product ID", "Product Name", "Available Quantity", "Price");
  for(int i=0; i<num_of_products; i++) {
    printf("%-15d%-20s%-25d%-10.2f\n", products[i].product_id, products[i].product_name, products[i].available_quantity, products[i].price);
  }
}


// Main function
int main() {
  int num_of_products;
  printf("Enter the number of products in warehouse: ");
  scanf("%d", &num_of_products);

  // Defining an array of structure inventory to store the record of products
  struct inventory products[num_of_products];

  // Taking input from user for each product
  for(int i=0; i<num_of_products; i++) {
    printf("\nEnter the details of product %d\n", i+1);
    printf("Product name: ");
    scanf("%s", products[i].product_name);
    printf("Product id: ");
    scanf("%d", &products[i].product_id);
    printf("Available quantity: ");
    scanf("%d", &products[i].available_quantity);
    printf("Price: ");
    scanf("%f", &products[i].price);
  }

  printf("\nWarehouse Management System\n");

  while(1) {
    printf("\n1. Update inventory\n");
    printf("2. Print inventory\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        update_inventory(products, num_of_products);
        break;

      case 2:
        print_inventory(products, num_of_products);
        break;

      case 3:
        printf("\nThank you for using our system!\n");
        return 0;
    
      default:
        printf("\nInvalid choice! Try again.\n");
    }
  }
  return 0;
}