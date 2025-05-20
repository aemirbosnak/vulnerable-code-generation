//FormAI DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

struct Product {
  int id;
  char name[50];
  float price;
  int quantity;
};

struct Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct() {
  int id, quantity;
  char name[50];
  float price;

  printf("Enter product id: ");
  scanf("%d", &id);

  printf("Enter product name: ");
  scanf("%s", name);

  printf("Enter product price: ");
  scanf("%f", &price);

  printf("Enter product quantity: ");
  scanf("%d", &quantity);

  struct Product p;
  p.id = id;
  strcpy(p.name, name);
  p.price = price;
  p.quantity = quantity;

  products[numProducts++] = p;

  printf("Product added successfully.\n");
}

void listProducts() {
  printf("id\tname\t\tprice\tquantity\n");

  for(int i = 0; i < numProducts; ++i) {
    printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
  }
}

void removeProduct() {
  int id, found = 0;

  printf("Enter product id to remove: ");
  scanf("%d", &id);

  for(int i = 0; i < numProducts; ++i) {
    if (products[i].id == id) {
      found = 1;

      for(int j = i+1; j < numProducts; ++j) {
        products[j-1] = products[j];
      }

      --numProducts;

      printf("Product removed successfully.\n");

      break;
    }
  }

  if (!found) {
    printf("Product with id %d not found.\n", id);
  }
}

void updateProductQuantity() {
  int id, quantity, found = 0;

  printf("Enter product id to update quantity: ");
  scanf("%d", &id);

  printf("Enter new quantity: ");
  scanf("%d", &quantity);

  for(int i = 0; i < numProducts; ++i) {
    if (products[i].id == id) {
      found = 1;

      products[i].quantity = quantity;

      printf("Product quantity updated successfully.\n");

      break;
    }
  }

  if (!found) {
    printf("Product with id %d not found.\n", id);
  }
}

int main() {
  int choice;

  do {
    printf("\nProduct inventory system\n");
    printf("1. Add product\n");
    printf("2. List products\n");
    printf("3. Remove product\n");
    printf("4. Update product quantity\n");
    printf("5. Exit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addProduct();
        break;
      case 2:
        listProducts();
        break;
      case 3:
        removeProduct();
        break;
      case 4:
        updateProductQuantity();
        break;
      case 5:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  } while(choice != 5);

  return 0;
}