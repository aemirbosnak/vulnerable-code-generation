//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
  int id;
  char name[50];
  int quantity;
  float price;
};

int main() {
  int choice, count = 0, i, id;
  float price;
  char name[50];
  struct product products[100];

  while(1) {
    printf("\n\nC PRODUCT INVENTORY SYSTEM\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product Quantity\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter product name: ");
        scanf("%s", name);
        printf("Enter product price: ");
        scanf("%f", &price);

        products[count].id = count + 1;
        strcpy(products[count].name, name);
        products[count].quantity = 0;
        products[count].price = price;

        printf("\nProduct added successfully with ID %d.\n", products[count].id);
        count++;
        break;

      case 2:
        printf("\nPRODUCTS LIST\nID\tNAME\tQUANTITY\tPRICE\n");
        for(i = 0; i < count; i++) {
          printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, 
              products[i].quantity, products[i].price);
        }
        break;

      case 3:
        printf("\nEnter product ID: ");
        scanf("%d", &id);
        for(i = 0; i < count; i++) {
          if(products[i].id == id) {
            printf("\nEnter new quantity: ");
            scanf("%d", &products[i].quantity);
            printf("\nQuantity updated successfully.\n");
            break;
          }
        }
        if(i == count) {
          printf("\nProduct with ID %d not found.\n", id);
        }
        break;

      case 4:
        printf("\nEnter product ID: ");
        scanf("%d", &id);
        for(i = 0; i < count; i++) {
          if(products[i].id == id) {
            for(int j = i; j < count - 1; j++) {
              products[j] = products[j+1];
            }
            count--;
            printf("\nProduct deleted successfully.\n");
            break;
          }
        }
        if(i == count) {
          printf("\nProduct with ID %d not found.\n", id);
        }
        break;

      case 5:
        printf("\nExiting program...\n");
        exit(0);
        break;

      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  }

  return 0;
}