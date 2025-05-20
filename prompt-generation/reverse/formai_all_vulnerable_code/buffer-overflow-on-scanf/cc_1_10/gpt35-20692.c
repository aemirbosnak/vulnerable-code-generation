//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 50
#define MAX_QTY 10

struct Item {
   int code;
   char name[20];
   int qty;
};

struct Item items[MAX_ITEMS];
int numItems = 0;

void AddItem() {
   if (numItems == MAX_ITEMS) {
       printf("The warehouse is full.\n");
       return;
   }
   int code, qty;
   char name[20];
   printf("Enter item code, name and quantity: ");
   scanf("%d%s%d", &code, name, &qty);
   items[numItems].code = code;
   strcpy(items[numItems].name, name);
   items[numItems].qty = qty;
   numItems++;
   printf("Item added successfully.\n");
}

void ListItems() {
   if (numItems == 0) {
       printf("There are no items in the warehouse.\n");
       return;
   }
   printf("Item Code\tItem Name\tItem Quantity\n");
   for (int i = 0; i < numItems; i++)
       printf("%d\t\t%s\t\t%d\n", items[i].code, items[i].name, items[i].qty);
}

void UpdateItem() {
   if (numItems == 0) {
       printf("There are no items to update in the warehouse.\n");
       return;
   }
   int code, qty, found = 0;
   printf("Enter the item code to update: ");
   scanf("%d", &code);
   for (int i = 0; i < numItems; i++) {
       if (items[i].code == code) {
           printf("Enter the new quantity: ");
           scanf("%d", &qty);
           items[i].qty = qty;
           printf("Item updated successfully.\n");
           found = 1;
           break;
       }
   }
   if (!found) printf("Item not found in the warehouse.\n");
}

void RemoveItem() {
   if (numItems == 0) {
       printf("There are no items to remove in the warehouse.\n");
       return;
   }
   int code, found = 0;
   printf("Enter the item code to remove: ");
   scanf("%d", &code);
   for (int i = 0; i < numItems; i++) {
       if (items[i].code == code) {
           for (int j = i; j < numItems-1; j++)
               items[j] = items[j+1];
           numItems--;
           printf("Item removed successfully.\n");
           found = 1;
           break;
       }
   }
   if (!found) printf("Item not found in the warehouse.\n");
}

void Quit() {
   printf("Goodbye!\n");
   exit(0);
}

int main() {
   while (1) {
       printf("\nWhat would you like to do?\n");
       printf("1. Add Item\n");
       printf("2. List Items\n");
       printf("3. Update Item\n");
       printf("4. Remove Item\n");
       printf("5. Quit\n");
       printf("Enter your selection: ");
       int choice;
       scanf("%d", &choice);
       switch (choice) {
           case 1: AddItem(); break;
           case 2: ListItems(); break;
           case 3: UpdateItem(); break;
           case 4: RemoveItem(); break;
           case 5: Quit(); break;
           default: printf("Invalid selection. Please try again.\n");
       }
   }
   return 0;
}