//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char product[20];
   int quantity;
} Item;

typedef struct {
   char name[20];
   Item items[100];
   int numOfItems;
} Warehouse;

Warehouse warehouses[10];
int numOfWarehouses = 0;

void printMenu() {
   printf("----WAREHOUSE MANAGEMENT SYSTEM----\n");
   printf("1. Create a new warehouse\n");
   printf("2. Add an item to a warehouse\n");
   printf("3. Remove an item from a warehouse\n");
   printf("4. List all warehouses\n");
   printf("5. List all items in a warehouse\n");
   printf("6. Exit\n");
   printf("----------------------------------\n");
}

void createWarehouse(char name[]) {
   if (numOfWarehouses >= 10) {
      printf("Maximum number of warehouses reached.\n");
      return;
   }
   int i;
   for (i = 0; i < numOfWarehouses; i++) {
      if (strcmp(warehouses[i].name, name) == 0) {
         printf("Warehouse already exists.\n");
         return;
      }
   }
   Warehouse newWarehouse;
   strcpy(newWarehouse.name, name);
   newWarehouse.numOfItems = 0;
   warehouses[numOfWarehouses++] = newWarehouse;
   printf("Warehouse created successfully.\n");
}

void addItem(char name[], Item item) {
   int i, index = -1;
   for (i = 0; i < numOfWarehouses; i++) {
      if (strcmp(warehouses[i].name, name) == 0) {
         index = i;
         break;
      }
   }
   if (index == -1) {
      printf("Warehouse not found.\n");
      return;
   }
   for (i = 0; i < warehouses[index].numOfItems; i++) {
      if (strcmp(warehouses[index].items[i].product, item.product) == 0) {
         warehouses[index].items[i].quantity += item.quantity;
         printf("Item quantity updated.\n");
         return;
      }
   }
   warehouses[index].items[warehouses[index].numOfItems++] = item;
   printf("Item added successfully.\n");
}

void removeItem(char name[], char product[]) {
   int i, j, index = -1;
   for (i = 0; i < numOfWarehouses; i++) {
      if (strcmp(warehouses[i].name, name) == 0) {
         index = i;
         break;
      }
   }
   if (index == -1) {
      printf("Warehouse not found.\n");
      return;
   }
   for (i = 0; i < warehouses[index].numOfItems; i++) {
      if (strcmp(warehouses[index].items[i].product, product) == 0) {
         for (j = i; j < warehouses[index].numOfItems - 1; j++) {
            warehouses[index].items[j] = warehouses[index].items[j + 1];
         }
         warehouses[index].numOfItems--;
         printf("Item removed successfully.\n");
         return;
      }
   }
   printf("Item not found in warehouse.\n");
}

void listWarehouses() {
   int i;
   printf("Warehouses:\n");
   for (i = 0; i < numOfWarehouses; i++) {
      printf("%s\n", warehouses[i].name);
   }
}

void listItems(char name[]) {
   int i, index = -1;
   for (i = 0; i < numOfWarehouses; i++) {
      if (strcmp(warehouses[i].name, name) == 0) {
         index = i;
         break;
      }
   }
   if (index == -1) {
      printf("Warehouse not found.\n");
      return;
   }
   printf("Items in warehouse %s:\n", name);
   for (i = 0; i < warehouses[index].numOfItems; i++) {
      printf("%-20s %d\n", warehouses[index].items[i].product, warehouses[index].items[i].quantity);
   }
}

int main() {
   int choice;
   do {
      printMenu();
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            {
               char name[20];
               printf("Enter the name of the warehouse: ");
               scanf("%s", name);
               createWarehouse(name);
               break;
            }
         case 2:
            {
               char name[20];
               Item item;
               printf("Enter the name of the warehouse: ");
               scanf("%s", name);
               printf("Enter the product name: ");
               scanf("%s", item.product);
               printf("Enter the quantity: ");
               scanf("%d", &item.quantity);
               addItem(name, item);
               break;
            }
         case 3:
            {
               char name[20], product[20];
               printf("Enter the name of the warehouse: ");
               scanf("%s", name);
               printf("Enter the product name: ");
               scanf("%s", product);
               removeItem(name, product);
               break;
            }
         case 4:
            {
               listWarehouses();
               break;
            }
         case 5:
            {
               char name[20];
               printf("Enter the name of the warehouse: ");
               scanf("%s", name);
               listItems(name);
               break;
            }
         case 6:
            {
               printf("Thank you for using the Warehouse Management System.\n");
               break;
            }
         default:
            {
               printf("Invalid choice. Please try again.\n");
               break;
            }
      }
   } while (choice != 6);
   return 0;
}