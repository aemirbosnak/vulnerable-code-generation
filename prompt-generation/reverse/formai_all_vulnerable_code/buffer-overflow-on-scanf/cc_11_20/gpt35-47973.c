//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure to hold item information
struct item {
  char name[20];
  int quantity;
  float price;
};

int main() {
  // Create array of items
  struct item inventory[100];
  int num_items = 0;

  // Initialize variables for menu selection and loop control
  int selection = 0;
  int quit = 0;

  // Loop until user chooses to quit
  while(!quit) {
    // Display menu options
    printf("Warehouse Management System\n");
    printf("---------------------------\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Update Item\n");
    printf("4. View Inventory\n");
    printf("5. Quit\n");

    // Get user selection
    printf("Enter selection: ");
    scanf("%d", &selection);

    // Handle user selection
    switch(selection) {
      case 1:
        // Add Item
        printf("Enter item name: ");
        scanf("%s", inventory[num_items].name);
        printf("Enter item quantity: ");
        scanf("%d", &inventory[num_items].quantity);
        printf("Enter item price: ");
        scanf("%f", &inventory[num_items].price);
        num_items++;
        printf("Item added successfully!\n\n");
        break;
      case 2:
        // Remove Item
        if(num_items == 0) {
          printf("Inventory is empty.\n\n");
        } else {
          int item_index;
          printf("Enter item index to remove: ");
          scanf("%d", &item_index);
          if(item_index < 0 || item_index >= num_items) {
            printf("Invalid index.\n\n");
          } else {
            for(int i=item_index; i<num_items-1; i++) {
              inventory[i] = inventory[i+1];
            }
            num_items--;
            printf("Item removed successfully!\n\n");
          }
        }
        break;
      case 3:
        // Update Item
        if(num_items == 0) {
          printf("Inventory is empty.\n\n");
        } else {
          int item_index;
          printf("Enter item index to update: ");
          scanf("%d", &item_index);
          if(item_index < 0 || item_index >= num_items) {
            printf("Invalid index.\n\n");
          } else {
            printf("Enter new quantity (0 to keep current): ");
            scanf("%d", &inventory[item_index].quantity);
            printf("Enter new price (0.0 to keep current): ");
            scanf("%f", &inventory[item_index].price);
            printf("Item updated successfully!\n\n");
          }
        }
        break;
      case 4:
        // View Inventory
        printf("Inventory:\n");
        printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
        for(int i=0; i<num_items; i++) {
          printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
        printf("\n");
        break;
      case 5:
        // Quit
        quit = 1;
        break;
      default:
        printf("Invalid selection.\n\n");
    }
  }

  return 0;
}