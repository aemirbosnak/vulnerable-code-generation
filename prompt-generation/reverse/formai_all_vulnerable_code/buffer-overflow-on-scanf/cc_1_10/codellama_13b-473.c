//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: happy
// Product Inventory System in C
#include <stdio.h>
#include <stdlib.h>

// Structure to store product details
struct Product {
  int id;
  char name[20];
  float price;
  int quantity;
};

// Function to add a new product
void addProduct(struct Product *product) {
  printf("Enter product ID: ");
  scanf("%d", &product->id);
  printf("Enter product name: ");
  scanf("%s", product->name);
  printf("Enter product price: ");
  scanf("%f", &product->price);
  printf("Enter product quantity: ");
  scanf("%d", &product->quantity);
}

// Function to display all products
void displayProducts(struct Product *products, int numProducts) {
  printf("List of products:\n");
  for (int i = 0; i < numProducts; i++) {
    printf("%d. %s - $%0.2f (%d in stock)\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
  }
}

// Function to find a product by ID
struct Product *findProduct(struct Product *products, int numProducts, int id) {
  for (int i = 0; i < numProducts; i++) {
    if (products[i].id == id) {
      return &products[i];
    }
  }
  return NULL;
}

// Function to update a product quantity
void updateProductQuantity(struct Product *product, int quantity) {
  product->quantity += quantity;
}

// Function to remove a product
void removeProduct(struct Product *products, int numProducts, int id) {
  for (int i = 0; i < numProducts; i++) {
    if (products[i].id == id) {
      products[i] = products[numProducts - 1];
      numProducts--;
      break;
    }
  }
}

int main() {
  // Initialize product array and number of products
  struct Product products[100];
  int numProducts = 0;

  // Add new products
  addProduct(&products[numProducts++]);
  addProduct(&products[numProducts++]);
  addProduct(&products[numProducts++]);

  // Display all products
  displayProducts(products, numProducts);

  // Find a product by ID
  struct Product *product = findProduct(products, numProducts, 1);
  if (product != NULL) {
    printf("Product found: %s - $%0.2f (%d in stock)\n", product->name, product->price, product->quantity);
  } else {
    printf("Product not found\n");
  }

  // Update a product quantity
  updateProductQuantity(&products[0], 5);
  printf("Updated product quantity: %d\n", products[0].quantity);

  // Remove a product
  removeProduct(products, numProducts, 2);
  printf("Removed product: %s - $%0.2f (%d in stock)\n", products[1].name, products[1].price, products[1].quantity);

  return 0;
}