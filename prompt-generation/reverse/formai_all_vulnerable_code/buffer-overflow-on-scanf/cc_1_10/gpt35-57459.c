//FormAI DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the Product
typedef struct Product {
  int id;
  char name[30];
  char category[20];
  float price;
  int qty;
} product;

// Global Variables
int productCount = 0;
product inventory[100];

// Function to Display Main Menu
void displayMain() {
  printf("\n=======================");
  printf("\nPRODUCT INVENTORY SYSTEM");
  printf("\n=======================\n");
  printf("\n1. Add Product");
  printf("\n2. Display All Products");
  printf("\n3. Search Product");
  printf("\n4. Update Product");
  printf("\n5. Delete Product");
  printf("\n0. Exit\n");
}

// Function to Add a Product
void addProduct() {
  product newProduct;
  newProduct.id = productCount + 1;

  printf("\nEnter Product Name: ");
  scanf("%s", newProduct.name);

  printf("Enter Category: ");
  scanf("%s", newProduct.category);

  printf("Enter Price: ");
  scanf("%f", &newProduct.price);

  printf("Enter Quantity: ");
  scanf("%d", &newProduct.qty);

  inventory[productCount] = newProduct;
  productCount++;

  printf("\n*** Product Added Successfully! ***\n");
}

// Function to Display All Products
void viewProducts() {
  printf("\nPRODUCT(S) IN INVENTORY\n\n");
  printf("ID\tNAME\t\tCATEGORY\tPRICE\tQUANTITY\n");
  printf("==\t====\t\t========\t=====\t========\n");
  
  for (int i = 0; i < productCount; i++) {
    product p = inventory[i];
    printf("%d\t%s\t\t%s\t\t%.2f\t%d\n", p.id, p.name, p.category, p.price, p.qty);
  }
}

// Function to Search Product
void searchProduct() {
  int id;
  printf("\nEnter Product ID: ");
  scanf("%d", &id);

  for (int i = 0; i < productCount; i++) {
    product p = inventory[i];
    if (p.id == id) {
      printf("\nSEARCH RESULT\n\n");
      printf("ID\tNAME\t\tCATEGORY\tPRICE\tQUANTITY\n");
      printf("==\t====\t\t========\t=====\t========\n");
      printf("%d\t%s\t\t%s\t\t%.2f\t%d\n", p.id, p.name, p.category, p.price, p.qty);
      return;
    }
  }
  printf("\n*** Product Not Found! ***\n");
}

// Function to Update Product
void updateProduct() {
  int id, index = -1;
  printf("\nEnter Product ID: ");
  scanf("%d", &id);

  for (int i = 0; i < productCount; i++) {
    if (inventory[i].id == id) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("\n*** Product Not Found! ***\n");
    return;
  }

  product p = inventory[index];
  printf("\nEnter New Product Name [Leave empty to skip]: ");
  char newName[30];
  fgets(newName, sizeof(newName), stdin);
  if (strcmp(newName, "\n") != 0) {
    newName[strlen(newName) - 1] = '\0';
    strcpy(p.name, newName);
  }

  printf("Enter New Category [Leave empty to skip]: ");
  char newCategory[20];
  fgets(newCategory, sizeof(newCategory), stdin);
  if (strcmp(newCategory, "\n") != 0) {
    newCategory[strlen(newCategory) - 1] = '\0';
    strcpy(p.category, newCategory);
  }
  
  printf("Enter New Price [Leave 0 to skip]: ");
  float newPrice;
  scanf("%f", &newPrice);
  if (newPrice != 0) {
    p.price = newPrice;
  }

  printf("Enter New Quantity [Leave 0 to skip]: ");
  int newQty;
  scanf("%d", &newQty);
  if (newQty != 0) {
    p.qty = newQty;
  }

  inventory[index] = p;

  printf("\n*** Product Updated Successfully! ***\n");
}

// Function to Delete Product
void deleteProduct() {
  int id, index = -1;
  printf("\nEnter Product ID: ");
  scanf("%d", &id);

  for (int i = 0; i < productCount; i++) {
    if (inventory[i].id == id) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("\n*** Product Not Found! ***\n");
    return;
  }

  for (int i = index; i < productCount - 1; i++) {
    inventory[i] = inventory[i + 1];
  }
  productCount--;

  printf("\n*** Product Deleted Successfully! ***\n");
}

// Main Function
int main() {
  int choice;

  while (1) {
    displayMain();

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: addProduct(); break;
      case 2: viewProducts(); break;
      case 3: searchProduct(); break;
      case 4: updateProduct(); break;
      case 5: deleteProduct(); break;
      case 0: exit(0);
      default: printf("\n*** Invalid Choice! Try Again. ***\n"); break;
    }
  }
  return 0;
}