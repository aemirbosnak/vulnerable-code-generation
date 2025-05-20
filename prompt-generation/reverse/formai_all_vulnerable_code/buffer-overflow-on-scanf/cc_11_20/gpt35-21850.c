//FormAI DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int quantity;
  float price;
} Product;

int main() {
  int choice, num_products = 0, i;
  float total_value = 0;
  Product products[100];
  
  printf("Welcome to our Product Inventory System!\n");
  
  do {
    printf("\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. List all products\n");
    printf("4. Check total value of inventory\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1: // Add a product
        printf("\nEnter product name: ");
        scanf("%s", products[num_products].name);
        
        printf("Enter product quantity: ");
        scanf("%d", &products[num_products].quantity);
        
        printf("Enter product price: ");
        scanf("%f", &products[num_products].price);
        
        num_products++;
        printf("\nProduct added successfully!\n");
        break;
        
      case 2: // Remove a product
        if (num_products == 0) {
          printf("\nNo products to remove.\n");
          break;
        }
        
        char name[50];
        int found = 0, j;
        printf("\nEnter product name: ");
        scanf("%s", name);
        
        for (j = 0; j < num_products; j++) {
          if (strcmp(name, products[j].name) == 0) {
            found = 1;
            printf("Removed product: %s\n", name);
            total_value -= (products[j].price * products[j].quantity);
            
            for (i = j; i < num_products - 1; i++) {
              strcpy(products[i].name, products[i+1].name);
              products[i].quantity = products[i+1].quantity;
              products[i].price = products[i+1].price;
            }
            
            num_products--;
            break;
          }
        }
        
        if (found == 0) {
          printf("\nProduct not found.\n");
        }
        
        break;
        
      case 3: // List all products
        if (num_products == 0) {
          printf("\nNo products to list.\n");
          break;
        }
        
        printf("\n%-50s %-10s %-10s\n", "Name", "Quantity", "Price");
        for (i = 0; i < num_products; i++) {
          printf("%-50s %-10d $%-9.2f\n", products[i].name, products[i].quantity, products[i].price);
        }
        
        break;
        
      case 4: // Check total value of inventory
        if (num_products == 0) {
          printf("\nInventory is empty.\n");
          break;
        }
        
        total_value = 0;
        for (i = 0; i < num_products; i++) {
          total_value += (products[i].price * products[i].quantity);
        }
        
        printf("\nTotal inventory value: $%.2f\n", total_value);
        break;
        
      case 5: // Exit
        printf("\nThank you for using our Product Inventory System!\n");
        break;
        
      default:
        printf("\nInvalid choice, please try again.\n");
        break;
    }
    
  } while (choice != 5);
  
  return 0;
}