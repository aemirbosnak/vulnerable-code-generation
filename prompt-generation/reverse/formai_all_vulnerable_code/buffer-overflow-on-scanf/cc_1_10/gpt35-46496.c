//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
  int id;
  char name[50];
  float price;
  int quantity;
};

struct product inventory[MAX_PRODUCTS];
int num_products = 0;

void addProduct() {
  struct product newProduct;
  printf("Enter product name: ");
  scanf("%s", newProduct.name);
  printf("Enter product price: ");
  scanf("%f", &newProduct.price);
  printf("Enter product quantity: ");
  scanf("%d", &newProduct.quantity);

  newProduct.id = num_products + 1;
  inventory[num_products] = newProduct;
  num_products++;

  printf("Product added successfully.\n");
}

void printProducts() {
  printf("ID\tName\tPrice\tQuantity\n");
  for(int i = 0; i < num_products; i++) {
    printf("%d\t%s\t%g\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
  }
}

int findProductIndex(int id) {
  for(int i = 0; i < num_products; i++) {
    if(inventory[i].id == id) {
      return i;
    }
  }
  return -1;
}

void updateProduct() {
  int id, qty;
  printf("Enter product ID to update: ");
  scanf("%d", &id);
  int index = findProductIndex(id);
  if(index == -1) {
    printf("Product not found.\n");
  } else {
    printf("Enter new quantity: ");
    scanf("%d", &qty);
    inventory[index].quantity = qty;
    printf("Product updated successfully.\n");
  }
}

void deleteProduct() {
  int id;
  printf("Enter product ID to delete: ");
  scanf("%d", &id);
  int index = findProductIndex(id);
  if(index == -1) {
    printf("Product not found.\n");
  } else {
    for(int i = index; i < num_products - 1; i++) {
      inventory[i] = inventory[i + 1];
    }
    num_products--;
    printf("Product deleted successfully.\n");
  }
}

void mainMenu() {
  printf("Welcome to the Product Inventory System!\n");
  printf("1. Add a product\n");
  printf("2. Print all products\n");
  printf("3. Update a product quantity\n");
  printf("4. Delete a product\n");
  printf("5. Exit\n");

  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      addProduct();
      break;
    case 2:
      printProducts();
      break;
    case 3:
      updateProduct();
      break;
    case 4:
      deleteProduct();
      break;
    case 5:
      printf("Exiting...\n");
      return;
    default:
      printf("Invalid choice.\n");
  }
  mainMenu();
}

int main() {
  mainMenu();
  return 0;
}