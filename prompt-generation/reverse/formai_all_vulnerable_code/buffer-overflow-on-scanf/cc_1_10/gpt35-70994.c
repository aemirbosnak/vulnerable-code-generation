//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

/* define the maximum number of products that can be stored in the warehouse */
#define MAX_PRODUCTS 1000

/* structure to store information about a particular product */
struct Product {
  int id;
  char name[50];
  float price;
  int quantity;
};

/* array to store all the available products in the warehouse */
struct Product products[MAX_PRODUCTS];

/* variable to keep track of the total number of products in the warehouse */
int num_products = 0;

/* function to add a new product to the warehouse */
void add_product() {
  /* check if the warehouse is already full */
  if (num_products >= MAX_PRODUCTS) {
    printf("Error: Warehouse is full!\n");
    return;
  }
  
  /* ask the user to enter the details of the new product */
  printf("Enter details of new product:\n");
  printf("ID: ");
  scanf("%d", &products[num_products].id);
  printf("Name: ");
  scanf("%s", products[num_products].name);
  printf("Price: ");
  scanf("%f", &products[num_products].price);
  printf("Quantity: ");
  scanf("%d", &products[num_products].quantity);
  
  /* increment the number of products in the warehouse */
  num_products++;
  
  printf("Product added successfully!\n");
}

/* function to display all the available products in the warehouse */
void display_products() {
  /* check if there are any products in the warehouse */
  if (num_products == 0) {
    printf("No products available in the warehouse.\n");
    return;
  }
  
  /* display the details of all the available products */
  printf("ID\tName\tPrice\tQuantity\n");
  printf("--\t----\t-----\t--------\n");
  for (int i = 0; i < num_products; i++) {
    printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
  }
}

/* function to search for a product by its ID */
void search_product() {
  /* ask the user to enter the ID of the product to be searched for */
  int id;
  printf("Enter ID of product to search for: ");
  scanf("%d", &id);
  
  /* search for the product with the given ID */
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      /* display the details of the product */
      printf("ID\tName\tPrice\tQuantity\n");
      printf("--\t----\t-----\t--------\n");
      printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
      return;
    }
  }
  
  /* if the product was not found */
  printf("Product not found in the warehouse.\n");
}

/* function to remove a product from the warehouse */
void remove_product() {
  /* ask the user to enter the ID of the product to be removed */
  int id;
  printf("Enter ID of product to remove: ");
  scanf("%d", &id);
  
  /* search for the product with the given ID */
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      /* remove the product by shifting all the products after it one position to the left */
      for (int j = i; j < num_products - 1; j++) {
        products[j] = products[j+1];
      }
      num_products--;
      printf("Product removed from the warehouse.\n");
      return;
    }
  }
  
  /* if the product was not found */
  printf("Product not found in the warehouse.\n");
}

int main() {
  /* display the main menu and ask the user to enter a choice */
  while (1) {
    printf("\n");
    printf("Warehouse Management System (WMS)\n");
    printf("---------------------------------\n");
    printf("1. Add new product\n");
    printf("2. Display all products\n");
    printf("3. Search for a product\n");
    printf("4. Remove a product\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        add_product();
        break;
        
      case 2:
        display_products();
        break;
        
      case 3:
        search_product();
        break;
        
      case 4:
        remove_product();
        break;
        
      case 5:
        printf("Goodbye!\n");
        exit(0);
        
      default:
        printf("Invalid choice, try again.\n");
        break;
    }
  }
  
  return 0;
}