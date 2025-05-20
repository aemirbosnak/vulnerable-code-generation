//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 100 // Maximum number of products that can be stored
#define MAX_NAME_LENGTH 50 // Maximum length of a product name
#define MAX_DESCRIPTION_LENGTH 100 // Maximum length of a product description
#define MAX_SUPPLIER_LENGTH 50 // Maximum length of a supplier name

struct product {
  int id;
  char name[MAX_NAME_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
  char supplier[MAX_SUPPLIER_LENGTH];
  int quantity;
  float price;
};

struct product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
  if (num_products >= MAX_PRODUCTS) {
    printf("Error: Maximum number of products reached.\n");
  } else {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter supplier name: ");
    scanf("%s", products[num_products].supplier);
    printf("Enter quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter price: ");
    scanf("%f", &products[num_products].price);
    products[num_products].id = num_products + 1;
    num_products++;
    printf("Product added successfully.\n");
  }
}

void list_products() {
  if (num_products == 0) {
    printf("No products found.\n");
  } else {
    printf("%-5s %-20s %-30s %-20s %-10s %-10s\n", "ID", "Name", "Description", "Supplier", "Quantity", "Price");
    for (int i = 0; i < num_products; i++) {
      printf("%-5d %-20s %-30s %-20s %-10d $%.2f\n", products[i].id, products[i].name, products[i].description, products[i].supplier, products[i].quantity, products[i].price);
    }
  }
}

void search_product() {
  char name[MAX_NAME_LENGTH];
  printf("Enter product name: ");
  scanf("%s", name);
  int found = 0;
  for (int i = 0; i < num_products; i++) {
    if (strcmp(products[i].name, name) == 0) {
      printf("%-5s %-20s %-30s %-20s %-10s %-10s\n", "ID", "Name", "Description", "Supplier", "Quantity", "Price");
      printf("%-5d %-20s %-30s %-20s %-10d $%.2f\n", products[i].id, products[i].name, products[i].description, products[i].supplier, products[i].quantity, products[i].price);
      found = 1;
    }
  }
  if (!found) {
    printf("Product not found.\n");
  }
}

void sell_product() {
  int id, found = 0;
  printf("Enter product ID: ");
  scanf("%d", &id);
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      printf("Enter quantity to sell: ");
      int quantity;
      scanf("%d", &quantity);
      if (products[i].quantity >= quantity) {
        products[i].quantity -= quantity;
        printf("Total price: $%.2f\n", quantity * products[i].price);
        found = 1;
      } else {
        printf("Error: Insufficient quantity.\n");
      }
    }
  }
  if (!found) {
    printf("Product not found.\n");
  }
}

void menu() {
  printf("Product Inventory System\n");
  printf("1. Add product\n");
  printf("2. List products\n");
  printf("3. Search product\n");
  printf("4. Sell product\n");
  printf("5. Exit\n");
}

int main() {
  int option;
  do {
    menu();
    printf("Enter an option: ");
    scanf("%d", &option);
    switch(option) {
      case 1:
        add_product();
        break;
      case 2:
        list_products();
        break;
      case 3:
        search_product();
        break;
      case 4:
        sell_product();
        break;
      case 5:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid option.\n");
    }
  } while(option != 5);
  return 0;
}