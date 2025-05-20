//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the medical item data
struct medical_item {
    char name[50];  // Name of the medical item
    int quantity;   // Quantity of the medical item
    float price;    // Price of the medical item
};

// Function to add a new medical item to the inventory
void add_item(struct medical_item *inventory, int *num_items) {
    // Get the item details from the user
    printf("Enter the name of the medical item: ");
    scanf(" %s", inventory[*num_items].name);
    printf("Enter the quantity of the medical item: ");
    scanf(" %d", &inventory[*num_items].quantity);
    printf("Enter the price of the medical item: ");
    scanf(" %f", &inventory[*num_items].price);

    // Increment the number of items in the inventory
    (*num_items)++;
}

// Function to display the inventory
void display_inventory(struct medical_item *inventory, int num_items) {
    // Header
    printf("\n** Medical Store Inventory **\n");
    printf("-----------------------------------------\n");
    printf("| Name | Quantity | Price |\n");
    printf("-----------------------------------------\n");

    // Loop through the inventory and display the items
    for (int i = 0; i < num_items; i++) {
        printf("| %-20s | %-8d | %-6.2f |\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    // Footer
    printf("-----------------------------------------\n");
}

// Function to search for an item in the inventory by name
int search_item(struct medical_item *inventory, int num_items, char *item_name) {
    // Loop through the inventory and search for the item
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, item_name) == 0) {
            return i;  // Return the index of the item
        }
    }

    // Item not found
    return -1;
}

// Function to update the quantity of an item in the inventory
void update_quantity(struct medical_item *inventory, int num_items, char *item_name, int new_quantity) {
    // Search for the item in the inventory
    int item_index = search_item(inventory, num_items, item_name);

    // If the item was found, update the quantity
    if (item_index != -1) {
        inventory[item_index].quantity = new_quantity;
    } else {
        printf("Item not found.\n");
    }
}

// Function to delete an item from the inventory
void delete_item(struct medical_item *inventory, int *num_items, char *item_name) {
    // Search for the item in the inventory
    int item_index = search_item(inventory, *num_items, item_name);

    // If the item was found, delete it
    if (item_index != -1) {
        for (int i = item_index; i < *num_items - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        (*num_items)--;
    } else {
        printf("Item not found.\n");
    }
}

// Function to main menu
void main_menu() {
    printf("\n** Medical Store Management System **\n");
    printf("-----------------------------------------\n");
    printf("1. Add a new medical item\n");
    printf("2. Display the inventory\n");
    printf("3. Search for an item\n");
    printf("4. Update the quantity of an item\n");
    printf("5. Delete an item\n");
    printf("6. Exit\n");
    printf("-----------------------------------------\n");
    printf("Enter your choice: ");
}

// Main function
int main() {
    // Declare the inventory array
    struct medical_item inventory[100];
    int num_items = 0;

    // Main loop
    int choice;
    char item_name[50];
    int new_quantity;
    do {
        main_menu();
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                add_item(inventory, &num_items);
                break;
            case 2:
                display_inventory(inventory, num_items);
                break;
            case 3:
                printf("Enter the name of the item you want to search for: ");
                scanf(" %s", item_name);
                int item_index = search_item(inventory, num_items, item_name);
                if (item_index != -1) {
                    printf("Item found:\n");
                    printf("Name: %s\n", inventory[item_index].name);
                    printf("Quantity: %d\n", inventory[item_index].quantity);
                    printf("Price: %.2f\n", inventory[item_index].price);
                } else {
                    printf("Item not found.\n");
                }
                break;
            case 4:
                printf("Enter the name of the item you want to update: ");
                scanf(" %s", item_name);
                printf("Enter the new quantity: ");
                scanf(" %d", &new_quantity);
                update_quantity(inventory, num_items, item_name, new_quantity);
                break;
            case 5:
                printf("Enter the name of the item you want to delete: ");
                scanf(" %s", item_name);
                delete_item(inventory, &num_items, item_name);
                break;
            case 6:
                printf("Thank you for using the Medical Store Management System.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}