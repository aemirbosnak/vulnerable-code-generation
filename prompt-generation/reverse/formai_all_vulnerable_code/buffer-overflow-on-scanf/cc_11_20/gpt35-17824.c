//FormAI DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

struct product {
   char name[50];
   int itemId;
   float price;
   int quantity;
};

int main() {
   struct product inventory[100];
   int currSize = 0;
   int choice;

   while(1) {
      printf("\n\n\t\t# My Product Inventory System #\n\n");
      printf("\t\t1. Add a new product to inventory\n");
      printf("\t\t2. Remove an existing product from inventory\n");
      printf("\t\t3. Update an existing product in inventory\n");
      printf("\t\t4. View entire inventory\n");
      printf("\t\t5. Exit program\n");
      printf("\n\t\tWhat would you like to do? ");

      scanf("%d", &choice);

      switch(choice) {
         case 1: {
            printf("\n\t\t# Adding a new product to inventory #\n\n");

            printf("\t\tEnter product name: ");
            scanf("%s", inventory[currSize].name);

            printf("\t\tEnter product ID number: ");
            scanf("%d", &inventory[currSize].itemId);

            printf("\t\tEnter product price: ");
            scanf("%f", &inventory[currSize].price);

            printf("\t\tEnter product quantity: ");
            scanf("%d", &inventory[currSize].quantity);

            printf("\n\t\tProduct added successfully!\n\n");

            currSize++;

            break;
         }

         case 2: {
            int itemToRemove, removeIndex = -1;

            printf("\n\t\t# Removing an existing product from inventory #\n\n");

            printf("\t\tEnter product ID number to remove: ");
            scanf("%d", &itemToRemove);

            for(int i = 0; i < currSize; i++) {
               if(inventory[i].itemId == itemToRemove) {
                  removeIndex = i;
                  break;
               }
            }

            if(removeIndex == -1) {
               printf("\n\t\tProduct ID number not found!\n\n");
            } else {
               for(int i = removeIndex; i < currSize - 1; i++) {
                  inventory[i] = inventory[i+1];
               }

               currSize--;

               printf("\n\t\tProduct removed successfully!\n\n");
            }

            break;
         }

         case 3: {
            int itemToUpdate, updateIndex = -1;

            printf("\n\t\t# Updating an existing product in inventory #\n\n");

            printf("\t\tEnter product ID number to update: ");
            scanf("%d", &itemToUpdate);

            for(int i = 0; i < currSize; i++) {
               if(inventory[i].itemId == itemToUpdate) {
                  updateIndex = i;
                  break;
               }
            }

            if(updateIndex == -1) {
               printf("\n\t\tProduct ID number not found!\n\n");
            } else {
               printf("\n\t\tEnter product name: ");
               scanf("%s", inventory[updateIndex].name);

               printf("\t\tEnter product price: ");
               scanf("%f", &inventory[updateIndex].price);

               printf("\t\tEnter product quantity: ");
               scanf("%d", &inventory[updateIndex].quantity);

               printf("\n\t\tProduct updated successfully!\n\n");
            }

            break;
         }

         case 4: {
            printf("\n\t\t# Viewing entire inventory #\n\n");

            if(currSize == 0) {
               printf("\n\t\tInventory is empty!\n\n");
            } else {
               printf("\t\t%-15s %-15s %-15s %-15s\n\n", "Product Name", "Product ID", "Price", "Quantity");

               for(int i = 0; i < currSize; i++) {
                  printf("\t\t%-15s %-15d %-15.2f %-15d\n", inventory[i].name, inventory[i].itemId, inventory[i].price, inventory[i].quantity);
               }

               printf("\n");
            }

            break;
         }

         case 5: {
            printf("\n\t\tThank you for using my Product Inventory System!\n\n");

            exit(0);
         }

         default: {
            printf("\n\t\tInvalid option. Please try again.\n\n");
         }
      }
   }

   return 0;
}