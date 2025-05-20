//FormAI DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
  char name[50];
  int quantity;
  float price;
};

int main() {
  struct Product inventory[MAX_PRODUCTS];
  int numProducts = 0;
  char option;

  printf("Welcome to the Product Inventory System!\n");

  do {
    printf("\nChoose an option:\n");
    printf("1 - Add a product\n");
    printf("2 - Remove a product\n");
    printf("3 - Update product quantity\n");
    printf("4 - Display inventory\n");
    printf("q - Quit program\n");

    scanf(" %c", &option);

    switch(option) {
      case '1': {
        if(numProducts < MAX_PRODUCTS) {
          printf("\nEnter product name: ");
          scanf("%s", inventory[numProducts].name);

          printf("Enter product quantity: ");
          scanf("%d", &inventory[numProducts].quantity);

          printf("Enter product price: ");
          scanf("%f", &inventory[numProducts].price);

          numProducts++;
        } else {
          printf("\nError: maximum number of products reached (%d)\n", MAX_PRODUCTS);
        }
        break;
      }

      case '2': {
        if(numProducts > 0) {
          char productName[50];
          int found = 0;

          printf("\nEnter product name to remove: ");
          scanf("%s", productName);

          for(int i = 0; i < numProducts; i++) {
            if(strcmp(inventory[i].name, productName) == 0) {
              found = 1;
              inventory[i] = inventory[numProducts - 1];
              numProducts--;
              printf("\nProduct removed successfully.\n");
              break;
            }
          }

          if(!found) {
            printf("\nError: product not found\n");
          }
        } else {
          printf("\nError: no products in inventory\n");
        }
        break;
      }

      case '3': {
        if(numProducts > 0) {
          char productName[50];
          int found = 0;

          printf("\nEnter product name to update quantity: ");
          scanf("%s", productName);

          for(int i = 0; i < numProducts; i++) {
            if(strcmp(inventory[i].name, productName) == 0) {
              found = 1;
              int newQuantity;
              printf("Enter new quantity: ");
              scanf("%d", &newQuantity);
              inventory[i].quantity = newQuantity;
              printf("\nQuantity updated successfully.\n");
              break;
            }
          }

          if(!found) {
            printf("\nError: product not found\n");
          }
        } else {
          printf("\nError: no products in inventory\n");
        }
        break;
      }

      case '4': {
        if(numProducts > 0) {
          printf("\n%-30s%-10s%s\n", "Product", "Quantity", "Price");

          for(int i = 0; i < numProducts; i++) {
            printf("%-30s%-10d%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
          }
        } else {
          printf("\nError: no products in inventory\n");
        }
        break;
      }

      case 'q': {
        break; // exit loop and program will end
      }

      default: {
        printf("\nError: invalid option\n");
        break;
      }
    }
  } while(option != 'q');

  printf("\nThank you for using the Product Inventory System!\n");

  return 0;
}