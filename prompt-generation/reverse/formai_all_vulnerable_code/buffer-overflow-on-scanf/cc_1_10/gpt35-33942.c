//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Initialize the warehouse inventory
struct Items {
   char name[20];
   int quantity;
   float price;
}item[100];

//Initialize the main menu
int menu() {
   int choice;
   printf("\n\n\t\t\tWarehouse Management System\n");
   printf("\n\t\t\t==MAIN MENU==");
   printf("\n\t(1) Add an Item to Warehouse");
   printf("\n\t(2) Delete an Item from Warehouse");
   printf("\n\t(3) Update Item Price");
   printf("\n\t(4) Display All Items in Warehouse");
   printf("\n\t(5) Search for an Item in Warehouse");
   printf("\n\t(0) Exit");
   printf("\n\tEnter Your Choice: ");
   scanf("%d", &choice);
   return choice;
}

//Initialize the Add Item function
void addItem() {
   int i, n;
   printf("Enter the number of items to be added: ");
   scanf("%d", &n);
   for (i = 0; i < n; i++) {
      printf("\nEnter the name of the Item: ");
      scanf("%s", item[i].name);
      printf("Enter the quantity of the Item: ");
      scanf("%d", &item[i].quantity);
      printf("Enter the price of the Item: ");
      scanf("%f", &item[i].price);
   }
   printf("\nItems added successfully!");
}

//Initialize the Delete Item function
void deleteItem() {
   int i, j, n;
   char itemName[20];
   printf("\nEnter the name of the Item to delete: ");
   scanf("%s", itemName);
   n = strlen(itemName);
   for (i = 0; i < n; i++) {
      for (j = 0; j < 100; j++) {
         if (strcmp(itemName, item[j].name) == 0) {
            item[j].quantity = 0;
            item[j].price = 0.0;
            printf("\nItem deleted successfully!");
            break;
         }
      }
   }
   if (j == 100) {
      printf("\nItem not found in the warehouse!");
   }
}

//Initialize the Update Item function
void updatePrice() {
   int i, j, n;
   char itemName[20];
   float newPrice;
   printf("\nEnter the name of the Item to update: ");
   scanf("%s", itemName);
   n = strlen(itemName);
   for (i = 0; i < n; i++) {
      for (j = 0; j < 100; j++) {
         if (strcmp(itemName, item[j].name) == 0) {
            printf("Enter the new price of the Item: ");
            scanf("%f", &newPrice);
            item[j].price = newPrice;
            printf("\nPrice updated successfully!");
            break;
         }
      }
   }
   if (j == 100) {
      printf("\nItem not found in the warehouse!");
   }
}

//Initialize the Display Items function
void displayItems() {
   int i;
   printf("\n\n\t\t==== Items in Warehouse ====");
   printf("\n\t%-20s %-20s %-20s", "Name", "Quantity", "Price");
   for (i = 0; i < 100; i++) {
      if (item[i].quantity != 0) {
         printf("\n\t%-20s %-20d %-20.2f", item[i].name, item[i].quantity, item[i].price);
      }
   }
}

//Initialize the Search Item function
void searchItem() {
   int i, j, n;
   char itemName[20];
   printf("\nEnter the name of the Item to search: ");
   scanf("%s", itemName);
   n = strlen(itemName);
   for (i = 0; i < n; i++) {
      for (j = 0; j < 100; j++) {
         if (strcmp(itemName, item[j].name) == 0) {
            printf("\n\t%-20s %-20d %-20.2f", item[j].name, item[j].quantity, item[j].price);
            break;
         }
      }
   }
   if (j == 100) {
      printf("\nItem not found in the warehouse!");
   }
}

//Main function
int main() {
   int choice;
   do {
      choice = menu(); //Display main menu
      switch (choice) {
         case 1:
            addItem(); //Add an Item function
            break;
         case 2:
            deleteItem(); //Delete an Item function
            break;
         case 3:
            updatePrice(); //Update Item Price function
            break;
         case 4:
            displayItems(); //Display All Items function
            break;
         case 5:
            searchItem(); //Search for an Item function
            break;
         case 0:
            printf("\nThank you for using the Warehouse Management System.");
            break;
         default:
            printf("\nInvalid Choice! Try Again!");
            break;
      }
   } while (choice != 0);
   return 0;
}