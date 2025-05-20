//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

struct product { // Define the product structure
   char name[50];
   int quantity;
   float price;
};

void addProduct(struct product inventory[], int *index) { // Add a new product to the inventory
   printf("What is the name of the new product? ");
   scanf("%s", inventory[*index].name);
   printf("How many %ss are being added? ", inventory[*index].name);
   scanf("%d", &inventory[*index].quantity);
   printf("What is the price per %s? ", inventory[*index].name);
   scanf("%f", &inventory[*index].price);

   printf("%d %ss have been added to the inventory at %.2f dollars each.\n", inventory[*index].quantity, inventory[*index].name, inventory[*index].price);
   *index += 1;
}

void viewInventory(struct product inventory[], int index) { // Display the current inventory
   printf("Current Product Inventory:\n");
   for (int i = 0; i < index; i++) {
      printf("%s: %d, $%.2f each\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
   }
}

void sellProduct(struct product inventory[], int index) { // Sell a product from the inventory
   char name[50];
   int quantity;
   printf("What product are you selling? ");
   scanf("%s", name);
   printf("How many %ss are you selling? ", name);
   scanf("%d", &quantity);
   for (int i = 0; i < index; i++) {
      if (strcmp(name, inventory[i].name) == 0) {
         if (inventory[i].quantity >= quantity) {
            float total = quantity * inventory[i].price;
            inventory[i].quantity -= quantity;
            printf("%d %ss have been sold for a total sale of $%.2f.\n", quantity, name, total);
            return;
         } else {
            printf("There are only %d %ss in stock.\n", inventory[i].quantity, name);
            return;
         }
      }
   }
   printf("Sorry, the %s is not in stock.", name);
}

int main() {
   struct product inventory[100];
   int choice, index = 0;

   printf("Welcome to the Product Inventory System!\n");
   printf("What would you like to do?\n");

   do {
      printf("\n1. Add a new product\n");
      printf("2. View current inventory\n");
      printf("3. Sell a product\n");
      printf("4. Exit\n");
      printf("Choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1: // Add a new product
            addProduct(inventory, &index);
            break;
         case 2: // View current inventory
            viewInventory(inventory, index);
            break;
         case 3: // Sell a product
            sellProduct(inventory, index);
            break;
         case 4: // Exit the program
            printf("Thank you for using the Product Inventory System!\n");
            break;
         default: // Invalid choice
            printf("Invalid choice.\n");
            break;
      }
   } while (choice != 4);

   return 0;
}