//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surprised
#include <stdio.h>

typedef struct { 
   int id; 
   char name[20]; 
   float price; 
   int quantity; 
} product;

int main() {
   int choice, i = 0, count = 0;
   product inventory[50];
   
   do {
      printf("Enter option:\n1. Add product\n2. Display products\n3. Search product\n4. Delete product\n5. Exit\n");
      scanf("%d", &choice);

      switch(choice) {
       // adding a product to inventory
         case 1: {
            printf("Enter product name:\n");
            scanf("%s", inventory[i].name);
            printf("Enter product price:\n");
            scanf("%f", &inventory[i].price);
            printf("Enter product quantity:\n");
            scanf("%d", &inventory[i].quantity);
            // assigning a unique ID to each product
            inventory[i].id = count + 1;
            count++;
            i++;
            printf("Product added successfully!\n");
            break;
         }
       // displaying all products in inventory
         case 2: {
            // checking if inventory is empty
            if(count == 0) {
               printf("Inventory is empty!\n");
               break;
            }
            printf("ID\tName\t\tPrice\tQuantity\n");
            for(int j=0;j<i;j++) {
               printf("%d\t%s\t%0.2f\t%d\n", inventory[j].id, inventory[j].name, inventory[j].price, inventory[j].quantity);
            }
            break;
         }
       // searching for a product in inventory
         case 3: {
            int id, found = 0;
            printf("Enter product ID to search:\n");
            scanf("%d", &id);
            // searching for the product based on ID entered
            for(int j=0;j<i;j++) {
               if(inventory[j].id == id) {
                  printf("ID\tName\t\tPrice\tQuantity\n");
                  printf("%d\t%s\t%0.2f\t%d\n", inventory[j].id, inventory[j].name, inventory[j].price, inventory[j].quantity);
                  found = 1;
                  break;
               }
            }
            if(!found) {
               printf("Product not found!\n");
            }
            break;
         }
       // deleting a product from inventory
         case 4: {
            int id, found = 0;
            printf("Enter product ID to delete:\n");
            scanf("%d", &id);
            for(int j=0;j<i;j++) {
               if(inventory[j].id == id) {
                  // removing the product from inventory and shifting all the remaining ones to occupy its place
                  for(int k=j;k<i-1;k++) {
                     inventory[k] = inventory[k+1];
                  }
                  count--;
                  found = 1;
                  printf("Product deleted successfully!\n");
                  i--;
                  break;
               }
            }
            if(!found) {
               printf("Product not found!\n");
            }
            break;
         }
       // terminating the program
         case 5: {
            printf("Exiting program...\n");
            break;
         }
         default: {
            printf("Please enter a valid option!\n");
         }
      }
   }while(choice != 5);

   return 0;
}