//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
/* Welcome to our Warehouse Management System!
   This program allows users to manage inventory in a warehouse.

   The program uses a linked list data structure to store inventory items and their quantities.
   Users can add new items, remove existing items, and update quantities.

   Happy managing!

   - The WMS Team */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define inventory item struct
typedef struct Item {
  char name[100];
  int quantity;
  struct Item* next;
} Item;

// Define global head of linked list
Item* head = NULL;

// Function to create new inventory item
Item* createItem(char* name, int quantity) {
  Item* newItem = (Item*)malloc(sizeof(Item));
  strcpy(newItem->name, name);
  newItem->quantity = quantity;
  newItem->next = NULL;
  return newItem;
}

// Function to display current inventory
void displayInventory() {
  Item* current = head;
  while(current != NULL) {
    printf("%s: %d\n", current->name, current->quantity);
    current = current->next;
  }
}

// Function to add new item to inventory
void addItem(char* name, int quantity) {
  Item* newItem = createItem(name, quantity);
  newItem->next = head;
  head = newItem;
  printf("Added %s x%d to inventory.\n", name, quantity);
}

// Function to remove item from inventory
void removeItem(char* name) {
  Item* prev = NULL;
  Item* current = head;
  while(current != NULL) {
    if(strcmp(current->name, name) == 0) {
      if(prev == NULL) {
        head = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      printf("Removed %s from inventory.\n", name);
      return;
    }
    prev = current;
    current = current->next;
  }
  printf("%s not found in inventory.\n", name);
}

// Function to update item quantity in inventory
void updateItemQuantity(char* name, int newQuantity) {
  Item* current = head;
  while(current != NULL) {
    if(strcmp(current->name, name) == 0) {
      current->quantity = newQuantity;
      printf("Updated %s quantity to %d.\n", name, newQuantity);
      return;
    }
    current = current->next;
  }
  printf("%s not found in inventory.\n", name);
}

// Main function
int main() {
  int choice;
  char name[100];
  int quantity;
  int newQuantity;
  
  // Display menu and wait for user input
  printf("Welcome to the Warehouse Management System!\n");
  printf("------------------------------------------------------\n");
  printf("1. Display current inventory\n");
  printf("2. Add new item to inventory\n");
  printf("3. Remove item from inventory\n");
  printf("4. Update item quantity\n");
  printf("5. Exit program\n");
  printf("------------------------------------------------------\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Repeat menu until user chooses to exit
  while(choice != 5) {
    switch(choice) {
      case 1:
        displayInventory();
        break;
      case 2:
        printf("Enter item name: ");
        scanf("%s", name);
        printf("Enter item quantity: ");
        scanf("%d", &quantity);
        addItem(name, quantity);
        break;
      case 3:
        printf("Enter item name: ");
        scanf("%s", name);
        removeItem(name);
        break;
      case 4:
        printf("Enter item name: ");
        scanf("%s", name);
        printf("Enter new quantity: ");
        scanf("%d", &newQuantity);
        updateItemQuantity(name, newQuantity);
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
    printf("------------------------------------------------------\n");
    printf("1. Display current inventory\n");
    printf("2. Add new item to inventory\n");
    printf("3. Remove item from inventory\n");
    printf("4. Update item quantity\n");
    printf("5. Exit program\n");
    printf("------------------------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
  }

  // Free memory and exit program
  Item* current = head;
  while(current != NULL) {
    Item* temp = current->next;
    free(current);
    current = temp;
  }
  printf("Exiting program. Goodbye!\n");
  return 0;
}