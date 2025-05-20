//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <string.h>

struct Product {
  char name[20];
  int id;
  float price;
  int stock;
};

int main() {
  int choice, n = 0;
  struct Product inventory[50];
  char searchName[20];
  
  do {
    printf("\n====== C Product Inventory System ======\n");
    printf("\n1. Add new product to inventory\n");
    printf("2. Search product in inventory\n");
    printf("3. Update product stock\n");
    printf("4. Display inventory\n");
    printf("5. Exit\n");
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\n===== Adding New Product =====\n");
        printf("\nEnter product name: ");
        scanf("%s", inventory[n].name);
        printf("Enter product id: ");
        scanf("%d", &inventory[n].id);
        printf("Enter product price: ");
        scanf("%f", &inventory[n].price);
        printf("Enter product stock: ");
        scanf("%d", &inventory[n].stock);
        n++;
        break;
      
      case 2:
        printf("\n===== Searching Product =====\n");
        printf("Enter product name to search: ");
        scanf("%s", searchName);
        int found = 0;
        for(int i=0; i<n; i++) {
          if(strcmp(searchName, inventory[i].name) == 0) {
            printf("\nProduct found in inventory!\n");
            printf("Name: %s\n", inventory[i].name);
            printf("ID: %d\n", inventory[i].id);
            printf("Price: $%.2f\n", inventory[i].price);
            printf("Stock: %d\n", inventory[i].stock);
            found = 1;
            break;
          }
        }
        if(found == 0) {
          printf("\nProduct not found in inventory.\n");
        }
        break;

      case 3:
        printf("\n===== Updating Product Stock =====\n");
        printf("Enter product name to update stock: ");
        scanf("%s", searchName);
        found = 0;
        for(int i=0; i<n; i++) {
          if(strcmp(searchName, inventory[i].name) == 0) {
            printf("\nProduct found in inventory!\n");
            printf("Current stock: %d\n", inventory[i].stock);
            printf("Enter new stock: ");
            scanf("%d", &inventory[i].stock);
            printf("Stock updated!\n");
            found = 1;
            break;
          }
        }
        if(found == 0) {
          printf("\nProduct not found in inventory.\n");
        }
        break;

      case 4:
        printf("\n===== Displaying Inventory =====\n");
        if(n == 0) {
          printf("\nInventory is empty.\n");
        } else {
          printf("\n%-20s %-10s %-10s %-10s\n", "Product Name", "ID", "Price", "Stock");
          for(int i=0; i<n; i++) {
            printf("%-20s %-10d $%-9.2f %-10d\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].stock);
          }
        }
        break;

      case 5:
        printf("\nExiting Program...");
        break;

      default:
        printf("\nInvalid choice. Please enter a number from 1 to 5.\n");
        break;
    }

  } while(choice != 5);

  return 0;
}