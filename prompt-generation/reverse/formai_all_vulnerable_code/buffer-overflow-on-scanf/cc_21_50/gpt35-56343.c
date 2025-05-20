//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // Max number of items in the inventory

// Define structure to hold product details
struct product {
  int id;
  char name[20];
  int quantity;
  float price;
};

int main() {
  int choice, count = 0;
  struct product products[MAX_ITEMS];

  printf("Welcome to the Product Inventory System!\n");

  while (1) {
    printf("Choose an option:\n");
    printf("1. Add new product\n");
    printf("2. View all products\n");
    printf("3. Search product by ID\n");
    printf("4. Update product quantity\n");
    printf("5. Remove product by ID\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 0:
        printf("Exiting...");
        exit(EXIT_SUCCESS);
        break;
      
      case 1:
        printf("Enter product details:\n");

        // Get user input for new product
        struct product newProduct;
        newProduct.id = count + 1;

        printf("Name: ");
        scanf("%s", newProduct.name);

        printf("Quantity: ");
        scanf("%d", &newProduct.quantity);

        printf("Price: ");
        scanf("%f", &newProduct.price);

        // Add new item to inventory
        products[count] = newProduct;
        count++;

        printf("Product added!\n");
        break;

      case 2:
        if (count == 0) {
          printf("No products in inventory.\n");
          break;
        }

        // Print all products in inventory
        printf("Inventory:\n");
        for (int i = 0; i < count; i++) {
          printf("%d | %s | Quantity: %d | Price: $%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
        }
        break;
      
      case 3:
        if (count == 0) {
          printf("No products in inventory.\n");
          break;
        }

        // Get user input for product ID to search for
        int searchId;
        printf("Enter ID of product to search for: ");
        scanf("%d", &searchId);

        // Search for product by ID
        for (int i = 0; i < count; i++) {
          if (products[i].id == searchId) {
            printf("%d | %s | Quantity: %d | Price: $%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
            break;
          }
          if (i == count-1) {
            printf("Product not found.\n");
          }
        }
        break;

      case 4:
        if (count == 0) {
          printf("No products in inventory.\n");
          break;
        }

        // Get user input for product ID to update quantity of
        int updateId;
        printf("Enter ID of product to update quantity: ");
        scanf("%d", &updateId);

        // Search for product by ID and update quantity
        for (int i = 0; i < count; i++) {
          if (products[i].id == updateId) {
            printf("Current quantity of %s: %d\n", products[i].name, products[i].quantity);

            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);

            printf("Quantity updated!\n");
            break;
          }
          if (i == count-1) {
            printf("Product not found.\n");
          }
        }
        break;

      case 5:
        if (count == 0) {
          printf("No products in inventory.\n");
          break;
        }

        // Get user input for product ID to remove
        int removeId;
        printf("Enter ID of product to remove: ");
        scanf("%d", &removeId);

        // Search for product by ID and remove
        for (int i = 0; i < count; i++) {
          if (products[i].id == removeId) {
            for (int j = i; j < count-1; j++) {
              products[j] = products[j+1];
            }

            count--;
            printf("Product removed!\n");
            break;
          }
          if (i == count-1) {
            printf("Product not found.\n");
          }
        }
        break;

      default:
        printf("Invalid choice. Try again.\n");
        break;
    }
  }

  return 0;
}