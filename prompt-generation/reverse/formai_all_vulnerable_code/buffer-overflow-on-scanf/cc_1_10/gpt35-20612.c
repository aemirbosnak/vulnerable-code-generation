//FormAI DATASET v1.0 Category: Product Inventory System ; Style: genious
/* 
   This is a genius C Product Inventory System example program.
   It's designed to manage a small shop with items, quantities, 
   and prices.
   
   Made by: Your Name
   Date: Today's Date
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the information of each item
struct item {
  char name[50];
  int quantity;
  float price;
};

// Function to display the main menu and get the user's choice
int displayMenu() {
  int choice;
  
  printf("\nProduct Inventory System\n");
  printf("------------------------\n");
  printf("1. Add item\n");
  printf("2. Remove item\n");
  printf("3. Display inventory\n");
  printf("4. Exit\n");
  printf("Enter choice: ");
  
  scanf("%d", &choice); // Get the user's choice
  
  return choice;
}

// Function to add an item to the inventory
void addItem(struct item itemList[], int *pItemCount) {
  char name[50];
  int quantity;
  float price;
  
  printf("\nEnter item name: ");
  scanf("%s", name);
  
  printf("Enter quantity: ");
  scanf("%d", &quantity);
  
  printf("Enter price: ");
  scanf("%f", &price);
  
  // Add the item to the list
  struct item newItem;
  
  strcpy(newItem.name, name);
  newItem.quantity = quantity;
  newItem.price = price;
  
  itemList[*pItemCount] = newItem;
  (*pItemCount)++;
  
  printf("\nItem added successfully!\n");
}

// Function to remove an item from the inventory
void removeItem(struct item itemList[], int *pItemCount) {
  char name[50];
  int foundIndex = -1;
  
  printf("\nEnter name of item to remove: ");
  scanf("%s", name);
  
  // Search for the item in the list
  for (int i = 0; i < *pItemCount; i++) {
    if (strcmp(itemList[i].name, name) == 0) {
      foundIndex = i;
      break;
    }
  }
  
  // Remove the item if found
  if (foundIndex != -1) {
    // Shift all elements after the found index one index to the left
    for (int i = foundIndex + 1; i < *pItemCount; i++) {
      itemList[i - 1] = itemList[i];
    }
    
    (*pItemCount)--;
    
    printf("\nItem removed successfully!\n");
  } else {
    printf("\nItem not found!\n");  
  }
}

// Function to display the inventory
void displayInventory(struct item itemList[], int itemCount) {
  if (itemCount == 0) {
    printf("\nInventory is empty!\n");
    return;
  }
  
  printf("\n%-20s%-10s%-10s\n", "Name", "Quantity", "Price");
  printf("----------------------------------------\n");
  
  for (int i = 0; i < itemCount; i++) {
    printf("%-20s%-10d$%.2f\n", itemList[i].name, itemList[i].quantity, itemList[i].price);
  }
}

int main() {
  struct item itemList[100]; // Array to hold all the items
  int itemCount = 0; // Number of items in the inventory
  
  while (1) {
    int choice = displayMenu(); // Display the main menu and get the user's choice
    
    switch (choice) {
      case 1: // Add item
        addItem(itemList, &itemCount);
        break;
      case 2: // Remove item
        removeItem(itemList, &itemCount);
        break;
      case 3: // Display inventory
        displayInventory(itemList, itemCount);
        break;
      case 4: // Exit
        printf("\nThank you for using the Product Inventory System!\n");
        return 0;
      default:
        printf("\nInvalid choice! Please try again.\n");
        break;
    }
  }
  
  return 0;
}