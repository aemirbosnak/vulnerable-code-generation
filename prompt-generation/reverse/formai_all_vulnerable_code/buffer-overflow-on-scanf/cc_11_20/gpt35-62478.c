//FormAI DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include <stdio.h>
#include <string.h>

struct product {
  char name[50];
  int quantity;
};

int main() {
  int menu_choice = 0;
  struct product inventory[100];
  int num_products = 0;

  while (menu_choice != 4) {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. Display Inventory\n");
    printf("3. Remove Product\n");
    printf("4. Exit\n");

    printf("\nEnter menu choice (1-4): ");
    scanf("%d", &menu_choice);

    // Add Product
    if (menu_choice == 1) {
      printf("\nEnter product name: ");
      scanf("%s", inventory[num_products].name);

      printf("Enter quantity: ");
      scanf("%d", &inventory[num_products].quantity);

      printf("\nProduct added successfully!\n");
      num_products++;
    }
    // Display Inventory
    else if (menu_choice == 2) {
      if (num_products == 0) {
        printf("\nInventory is empty!\n");
      } else {
        printf("\n--- Inventory ---\n");
        printf("Product Name\tQuantity\n");
        for (int i = 0; i < num_products; i++) {
          printf("%s\t\t%d\n", inventory[i].name, inventory[i].quantity);
        }
      }
    }
    // Remove Product
    else if (menu_choice == 3) {
      char product_name[50];
      int found_product = 0;

      printf("\nEnter product name: ");
      scanf("%s", product_name);

      for (int i = 0; i < num_products; i++) {
        if (strcmp(product_name, inventory[i].name) == 0) {
          found_product = 1;
          printf("\nProduct \"%s\"\n", inventory[i].name);
          printf("Quantity: %d\n", inventory[i].quantity);
          printf("\nAre you sure you want to remove this product? (y/n): ");

          char confirm;
          scanf(" %c", &confirm);

          if (confirm == 'y') {
            // Remove product from inventory
            for (int j = i; j < num_products-1; j++) {
              strcpy(inventory[j].name, inventory[j+1].name);
              inventory[j].quantity = inventory[j+1].quantity;
            }
            num_products--;
            printf("\nProduct removed successfully!\n");
          } else {
            printf("\nProduct not removed.\n");
          }
        }
      }

      if (!found_product) {
        printf("\nProduct \"%s\" not found.\n", product_name);
      }
    }
    // Exit
    else if (menu_choice == 4) {
      printf("\nExiting...\n");
    }
    // Invalid menu choice
    else {
      printf("\nInvalid menu choice, please try again.\n");
    }
  }

  return 0;
}