//FormAI DATASET v1.0 Category: Product Inventory System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Define the Product struct
typedef struct Product {
  int id;
  char name[50];
  float price;
  int quantity;
} Product;

// Declare the function prototypes
void printMenu();
void addProduct(Product *products, int *numProducts);
void removeProduct(Product *products, int *numProducts);
void displayProducts(Product *products, int numProducts);
void searchProduct(Product *products, int numProducts);
void updateProduct(Product *products, int numProducts);

int main() {
  // Initialize the inventory
  Product products[MAX_PRODUCTS];
  int numProducts = 0;

  // Loop over the program until the user chooses to quit
  int choice;
  do {
    printMenu();
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addProduct(products, &numProducts);
        break;
      case 2:
        removeProduct(products, &numProducts);
        break;
      case 3:
        displayProducts(products, numProducts);
        break;
      case 4:
        searchProduct(products, numProducts);
        break;
      case 5:
        updateProduct(products, numProducts);
        break;
      case 6:
        printf("Exiting program\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }
  } while (choice != 6);

  return 0;
}

// Define the function to print the menu
void printMenu() {
  printf("\n");
  printf("Welcome to the Product Inventory System!\n");
  printf("----------------------------------------\n");
  printf("1. Add a product\n");
  printf("2. Remove a product\n");
  printf("3. Display all products\n");
  printf("4. Search for a product\n");
  printf("5. Update a product\n");
  printf("6. Quit\n");
  printf("\n");
  printf("Enter your choice: ");
}

// Define the function to add a product
void addProduct(Product *products, int *numProducts) {
  printf("\n");
  printf("Enter the product name: ");
  scanf("%s", products[*numProducts].name);
  printf("Enter the product price: ");
  scanf("%f", &products[*numProducts].price);
  printf("Enter the product quantity: ");
  scanf("%d", &products[*numProducts].quantity);
  printf("Product added successfully with ID %d\n", *numProducts+1);
  
  // Increment the number of products
  *numProducts += 1;
}

// Define the function to remove a product
void removeProduct(Product *products, int *numProducts) {
  int id;
  printf("\n");
  printf("Enter the product ID: ");
  scanf("%d", &id);

  // Check if the ID is valid
  if (id < 1 || id > *numProducts) {
    printf("Invalid product ID\n");
    return;
  }

  // Remove the product at the specified ID
  for (int i = id-1; i < *numProducts-1; i++) {
    products[i] = products[i+1];
  }

  // Decrement the number of products
  *numProducts -= 1;
  printf("Product removed successfully\n");
}

// Define the function to display all products
void displayProducts(Product *products, int numProducts) {
  printf("\n");
  printf("ID  | Name                         | Price    | Quantity\n");
  printf("-------------------------------------------------------\n");
  for (int i = 0; i < numProducts; i++) {
    printf("%-3d | %-28s | %-8.2f | %d\n", products[i].id+1, products[i].name, products[i].price, products[i].quantity);
  }
}

// Define the function to search for a product by name
void searchProduct(Product *products, int numProducts) {
  char name[50];
  printf("\n");
  printf("Enter the product name: ");
  scanf("%s", name);

  // Search for a product with the specified name
  for (int i = 0; i < numProducts; i++) {
    if (strcmp(products[i].name, name) == 0) {
      printf("ID: %d\n", products[i].id+1);
      printf("Name: %s\n", products[i].name);
      printf("Price: %.2f\n", products[i].price);
      printf("Quantity: %d\n", products[i].quantity);
      return;
    }
  }
  printf("Product not found\n");
}

// Define the function to update a product
void updateProduct(Product *products, int numProducts) {
  int id;
  printf("\n");
  printf("Enter the product ID: ");
  scanf("%d", &id);

  // Check if the ID is valid
  if (id < 1 || id > numProducts) {
    printf("Invalid product ID\n");
    return;
  }

  // Get the updated information for the specified product
  printf("Enter the product name: ");
  scanf("%s", products[id-1].name);
  printf("Enter the product price: ");
  scanf("%f", &products[id-1].price);
  printf("Enter the product quantity: ");
  scanf("%d", &products[id-1].quantity);

  printf("Product updated successfully\n");
}