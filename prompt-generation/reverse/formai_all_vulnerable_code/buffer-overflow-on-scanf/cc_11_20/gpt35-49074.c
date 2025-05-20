//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
#include <stdio.h>

#define MAX_ITEMS 10

int main() {
  // Introduction
  printf("Welcome to the Warehouse Management System!\n");
  printf("This system will help you keep track of all the items in your warehouse.\n");
  
  // Initialize items array
  int items[MAX_ITEMS] = {0};
  int numItems = 0;
  
  // Main loop
  int done = 0;
  while (!done) {
    // Display options
    printf("\nWhat would you like to do?\n");
    printf("1. Add an item\n");
    printf("2. Remove an item\n");
    printf("3. Display all items\n");
    printf("4. Exit\n");
    
    // Get user input
    int choice;
    scanf("%d", &choice);
    
    // Respond to user input
    switch (choice) {
      case 1:
        // Add an item
        if (numItems < MAX_ITEMS) {
          printf("\nEnter the item number: ");
          scanf("%d", &items[numItems]);
          printf("Item %d added to the warehouse.\n", items[numItems]);
          numItems++;
        } else {
          printf("\nThe warehouse is full, cannot add new items.\n");
        }
        break;
      case 2:
        // Remove an item
        if (numItems > 0) {
          printf("\nEnter the item number to remove: ");
          int itemToRemove;
          scanf("%d", &itemToRemove);
          int found = 0;
          for (int i = 0; i < numItems; i++) {
            if (items[i] == itemToRemove) {
              // Shift all remaining items over
              for (int j = i; j < numItems - 1; j++) {
                items[j] = items[j+1];
              }
              numItems--;
              found = 1;
              break;
            }
          }
          if (found) {
            printf("Item %d removed from the warehouse.\n", itemToRemove);
          } else {
            printf("Item %d not found in the warehouse.\n", itemToRemove);
          }
        } else {
          printf("\nThe warehouse is empty, cannot remove items.\n");
        }
        break;
      case 3:
        // Display all items
        if (numItems > 0) {
          printf("\nItems in the warehouse:\n");
          for (int i = 0; i < numItems; i++) {
            printf("%d\n", items[i]);
          }
        } else {
          printf("\nThe warehouse is empty, no items to display.\n");
        }
        break;
      case 4:
        // Exit the program
        done = 1;
        printf("Farewell! May you always find what you seek in this warehouse...\n");
        break;
      default:
        printf("\nInvalid choice, please try again.\n");
        break;
    }
  }
  
  return 0;
}