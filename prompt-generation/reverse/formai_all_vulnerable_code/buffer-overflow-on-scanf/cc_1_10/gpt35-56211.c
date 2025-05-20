//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 10000
#define MAX_WIDTH 20

int main() {
  srand(time(NULL));

  // Initialize warehouse
  char warehouse[MAX_ITEMS][MAX_WIDTH];
  int num_items = 0;

  // Display greeting message
  printf("Welcome to the Wacky Warehouse!\n");

  // Loop until user quits
  while (1) {
    // Display menu
    printf("\n");
    printf("1. Add item to warehouse\n");
    printf("2. Remove item from warehouse\n");
    printf("3. Check inventory status\n");
    printf("4. Quit\n");

    // Get user's choice
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Handle user's choice
    switch (choice) {
      case 1: {
        // Add item to warehouse
        if (num_items < MAX_ITEMS) {
          printf("Enter item name: ");
          scanf("%s", warehouse[num_items]);
          printf("Item %s added to warehouse!\n", warehouse[num_items]);
          num_items++;
        } else {
          printf("Sorry, the warehouse is full!\n");
        }
        break;
      }

      case 2: {
        // Remove item from warehouse
        if (num_items > 0) {
          int item_index = rand() % num_items;
          printf("Removing item %s from warehouse...\n", warehouse[item_index]);
          for (int i = item_index; i < num_items - 1; i++) {
            strcpy(warehouse[i], warehouse[i + 1]);
          }
          num_items--;
        } else {
          printf("Sorry, the warehouse is empty!\n");
        }
        break;
      }

      case 3: {
        // Check inventory status
        printf("The warehouse currently has %d items:\n", num_items);
        for (int i = 0; i < num_items; i++) {
          printf("- %s\n", warehouse[i]);
        }
        break;
      }

      case 4: {
        // Quit
        printf("Goodbye!\n");
        exit(0);
      }

      default: {
        // Invalid choice
        printf("Sorry, that is not a valid choice!\n");
      }
    }
  }

  return 0;
}