//FormAI DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>

// Defining maximum number of products that inventory system can hold
#define MAX_PRODUCTS 100

// Defining a structure for product details
typedef struct Product {
  int id;
  char name[50];
  float price;
  int stock;
} Product;

// Defining global variables
Product products[MAX_PRODUCTS];
int num_products = 0;

// Function to add a product
void add_product() {
  if(num_products == MAX_PRODUCTS) {
    printf("Inventory system is full. Cannot add more products.\n");
    return;
  }
  
  printf("Enter product details (id, name, price, stock): ");
  scanf("%d %s %f %d", &products[num_products].id, products[num_products].name, &products[num_products].price, &products[num_products].stock);
  
  num_products++;
  
  printf("Product added successfully.\n");
}

// Function to remove a product
void remove_product() {
  int id, index;
  
  printf("Enter product id: ");
  scanf("%d", &id);
  
  for(int i=0; i<num_products; i++) {
    if(products[i].id == id) {
      index = i;
      break;
    }
    
    if(i == num_products-1) {
      printf("Product not found.\n");
      return;
    }
  }
  
  for(int i=index; i<num_products-1; i++) {
    products[i] = products[i+1];
  }
  
  num_products--;
  
  printf("Product removed successfully.\n");
}

// Function to display all products
void display_products() {
  if(num_products == 0) {
    printf("Inventory system is empty.\n");
    return;
  }
  
  printf("ID\tName\tPrice\tStock\n");
  for(int i=0; i<num_products; i++) {
    printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].stock);
  }
}

// Function to search for a product by name
void search_product() {
  char name[50];
  int found = 0;
  
  printf("Enter product name: ");
  scanf("%s", name);
  
  for(int i=0; i<num_products; i++) {
    if(strcmp(products[i].name, name) == 0) {
      found = 1;
      printf("ID\tName\tPrice\tStock\n");
      printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].stock);
    }
  }
  
  if(!found) {
    printf("Product not found.\n");
  }
}

// Function to update stock for a product
void update_stock() {
  int id, stock, found = 0;
  
  printf("Enter product id: ");
  scanf("%d", &id);
  
  for(int i=0; i<num_products; i++) {
    if(products[i].id == id) {
      found = 1;
      printf("Enter stock: ");
      scanf("%d", &stock);
      products[i].stock = stock;
      printf("Stock updated successfully.\n");
    }
  }
  
  if(!found) {
    printf("Product not found.\n");
  }
}

// Main function
int main() {
  int choice;
  
  while(1) {
    printf("\nEnter your choice:\n");
    printf("1- Add a product\n2- Remove a product\n3- Display all products\n4- Search for a product\n5- Update stock for a product\n6- Exit\n");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        add_product();
        break;
      case 2:
        remove_product();
        break;
      case 3:
        display_products();
        break;
      case 4:
        search_product();
        break;
      case 5:
        update_stock();
        break;
      case 6:
        printf("Exiting program.\n");
        return 0;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }
  
  return 0;
}