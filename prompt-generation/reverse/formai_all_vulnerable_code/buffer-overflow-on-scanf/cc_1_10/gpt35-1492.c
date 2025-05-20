//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 20

typedef struct {
   char name[MAX_NAME_LENGTH];
   int quantity;
} Item;

Item inventory[MAX_ITEMS];
int numItems = 0;

void addItem(char name[], int quantity);
void removeItem(char name[]);
void displayItems();

int main() {
   int choice, quantity;
   char name[MAX_NAME_LENGTH];
   
   do {
      printf("Warehouse Management System\n"
             "1. Add Item\n"
             "2. Remove Item\n"
             "3. Display Items\n"
             "4. Exit\n");
      scanf("%d", &choice);
      
      switch (choice) {
         case 1:   // Add Item
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            addItem(name, quantity);
            break;
         
         case 2:   // Remove Item
            printf("Enter item name: ");
            scanf("%s", name);
            removeItem(name);
            break;
         
         case 3:   // Display Items
            displayItems();
            break;
         
         case 4:   // Exit
            printf("Exiting Warehouse Management System...\n");
            break;
         
         default:
            printf("Invalid choice. Please try again.\n");
      }
   } while (choice != 4);
   
   return 0;
}

void addItem(char name[], int quantity) {
   if (numItems == MAX_ITEMS) {  // Array is full
      printf("Inventory is full. Cannot add more items.\n");
      return;
   }
   
   for (int i = 0; i < numItems; i++) {
      if (strcmp(name, inventory[i].name) == 0) {
         inventory[i].quantity += quantity;  // Item already exists, update quantity
         printf("%s quantity increased to %d.\n", name, inventory[i].quantity);
         return;
      }
   }
   
   // Item doesn't exist, add to inventory
   strcpy(inventory[numItems].name, name);
   inventory[numItems].quantity = quantity;
   numItems++;
   printf("%s added to inventory.\n", name);
}

void removeItem(char name[]) {
   for (int i = 0; i < numItems; i++) {
      if (strcmp(name, inventory[i].name) == 0) {
         inventory[i].quantity--;  // Decrement quantity
         if (inventory[i].quantity == 0) {  // Remove item if quantity is zero
            for (int j = i; j < numItems-1; j++) {
               inventory[j] = inventory[j+1];  // Shift remaining items to the left
            }
            numItems--;
            printf("%s removed from inventory.\n", name);
         }
         else {
            printf("%s quantity decreased to %d.\n", name, inventory[i].quantity);
         }
         return;
      }
   }
   
   // Item not found
   printf("%s not found in inventory.\n", name);
}

void displayItems() {
   if (numItems == 0) {  // Array is empty
      printf("Inventory is empty.\n");
      return;
   }
   
   // Sort inventory alphabetically by item name
   for (int i = 0; i < numItems-1; i++) {
      for (int j = i+1; j < numItems; j++) {
         if (strcmp(inventory[i].name, inventory[j].name) > 0) {
            Item temp = inventory[i];
            inventory[i] = inventory[j];
            inventory[j] = temp;
         }
      }
   }
   
   // Display inventory
   printf("Inventory:\n");
   for (int i = 0; i < numItems; i++) {
      printf("%s - %d\n", inventory[i].name, inventory[i].quantity);
   }
}