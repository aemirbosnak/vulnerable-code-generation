//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

struct Item {
   int id; // item id
   char name[20]; // item name
   float price; // item price
   int quantity; // item quantity
   int rackNo; // rack no. where the item is stored
};

int main() {
   struct Item items[MAX_SIZE]; // array of items
   int n, choice, id, i, flag, count=0;
   char name[20];
   float price;
   int quantity, rackNo;

   // Seed the random number generator with current time
   srand(time(NULL));

   // Display the main menu and get user's choice
   do {
      printf("\n=== Warehouse Management System ===\n");
      printf("1. Add Item\n");
      printf("2. Display All Items\n");
      printf("3. Search Item By ID\n");
      printf("4. Search Item By Name\n");
      printf("5. Delete Item\n");
      printf("6. Quit\n");

      printf("\nEnter your choice: ");
      scanf("%d", &choice);

      // Process user's choice
      switch (choice) {
         case 1: // Add Item
            printf("\nEnter item name: ");
            scanf("%s", name);
            printf("Enter item price: ");
            scanf("%f", &price);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            printf("Enter rack no.: ");
            scanf("%d", &rackNo);

            // Generate a random item id between 1000 and 9999
            id = rand() % 9000 + 1000;

            // Create a new item with the entered data
            items[count].id = id;
            strcpy(items[count].name, name);
            items[count].price = price;
            items[count].quantity = quantity;
            items[count].rackNo = rackNo;
            count++; // Increment the item count
            printf("\nItem added successfully!\n");
            break;

         case 2: // Display All Items
            printf("\nID\tNAME\tPRICE\tQUANTITY\tRACK NO.\n");
            for (i=0; i<count; i++) {
               printf("%d\t%s\t%.2f\t%d\t\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity, items[i].rackNo);
            }
            break;

         case 3: // Search Item By ID
            printf("\nEnter item id: ");
            scanf("%d", &id);
            flag = 0;
            for (i=0; i<count; i++) {
               if (items[i].id == id) {
                  // Display the details of the item and set the flag
                  printf("\nID\tNAME\tPRICE\tQUANTITY\tRACK NO.\n");
                  printf("%d\t%s\t%.2f\t%d\t\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity, items[i].rackNo);
                  flag = 1;
                  break;
               }
            }
            if (flag == 0) {
               printf("\nItem not found!\n");
            }
            break;

         case 4: // Search Item By Name
            printf("\nEnter item name: ");
            scanf("%s", name);
            flag = 0;
            for (i=0; i<count; i++) {
               if (strcmp(items[i].name, name) == 0) {
                  // Display the details of the item and set the flag
                  printf("\nID\tNAME\tPRICE\tQUANTITY\tRACK NO.\n");
                  printf("%d\t%s\t%.2f\t%d\t\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity, items[i].rackNo);
                  flag = 1;
               }
            }
            if (flag == 0) {
               printf("\nItem not found!\n");
            }
            break;

         case 5: // Delete Item
            printf("\nEnter item id: ");
            scanf("%d", &id);
            flag = 0;
            for (i=0; i<count; i++) {
               if (items[i].id == id) {
                  // Shift the items in the array to delete the current item
                  for (int j=i; j<count-1; j++) {
                     items[j] = items[j+1];
                  }
                  count--; // Decrement the item count
                  flag = 1;
                  printf("\nItem deleted successfully!\n");
                  break;
               }
            }
            if (flag == 0) {
               printf("\nItem not found!\n");
            }
            break;

         case 6: // Quit
            printf("\nThank you for using the Warehouse Management System!\n");
            break;

         default:
            printf("\nInvalid choice! Try again.\n");
      }

   } while(choice != 6);

   return 0;
}