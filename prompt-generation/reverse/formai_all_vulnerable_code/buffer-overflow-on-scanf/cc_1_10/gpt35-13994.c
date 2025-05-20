//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a warehouse item.
typedef struct {
   char name[50];
   int quantity;
   float price;
} Item;

// Function signatures.
void addItem(Item **items, int *size);
void listItems(Item *items, int size);
void sellItem(Item *items, int size);

int main() 
{
   // Initialize the items array and its size.
   Item *items = NULL;
   int size = 0;

   // Menu loop.
   int choice;
   do {
      printf("=== Warehouse Management System ===\n");
      printf("1. Add Item\n");
      printf("2. List Items\n");
      printf("3. Sell Item\n");
      printf("4. Exit\n");
      printf("Choose an option: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1: addItem(&items, &size); break;
         case 2: listItems(items, size); break;
         case 3: sellItem(items, size); break;
         case 4: 
            // Free the memory allocated for the items array.
            for (int i = 0; i < size; i++) {
               free(items[i].name);
            }
            free(items);
            break;
         default: printf("Invalid choice. Try again.\n"); break;
      }

   } while (choice != 4);

   return 0;
}

// Prompts the user to add an item to the warehouse.
void addItem(Item **items, int *size) 
{
   // Reallocate the items array with space for one more item.
   *items = realloc(*items, (*size + 1) * sizeof(Item));

   // Prompt the user for the item's properties.
   Item newItem;
   printf("Enter the name of the item: ");
   scanf("%s", newItem.name);
   printf("Enter the quantity of the item: ");
   scanf("%d", &newItem.quantity);
   printf("Enter the price of the item: ");
   scanf("%f", &newItem.price);

   // Copy the new item into the items array.
   (*items)[*size] = newItem;
   *size += 1;

   printf("New item added successfully.\n");
}

// Lists all the items in the warehouse.
void listItems(Item *items, int size) 
{
   if (size == 0) {
      printf("There are no items in the warehouse.\n");
      return;
   }

   printf("|%-20s |%10s |%10s|\n", "Name", "Quantity", "Price");
   printf("+---------------------+------------+------------+\n");

   for (int i = 0; i < size; i++) {
      printf("|%-20s |%10d |%10.2f|\n", items[i].name, items[i].quantity, items[i].price);
   }
}

// Prompts the user to sell an item from the warehouse.
void sellItem(Item *items, int size) 
{
   if (size == 0) {
      printf("There are no items in the warehouse.\n");
      return;
   }

   // Prompt the user for the name of the item to sell.
   char itemName[50];
   printf("Enter the name of the item to sell: ");
   scanf("%s", itemName);

   // Find the item in the items array.
   Item *itemToSell = NULL;
   for (int i = 0; i < size; i++) {
      if (strcmp(itemName, items[i].name) == 0) {
         itemToSell = &items[i];
         break;
      }
   }

   // Check if the item was found.
   if (itemToSell == NULL) {
      printf("Item not found.\n");
      return;
   }

   // Prompt the user for the quantity to sell.
   int sellQuantity;
   printf("Enter the quantity to sell: ");
   scanf("%d", &sellQuantity);

   // Check if there is enough quantity to sell.
   if (sellQuantity > itemToSell->quantity) {
      printf("There is not enough quantity to sell.\n");
      return;
   }

   // Update the item's quantity.
   itemToSell->quantity -= sellQuantity;

   printf("Sold %d units of %s for %d.\n", sellQuantity, itemToSell->name, (int)(sellQuantity * itemToSell->price));
}