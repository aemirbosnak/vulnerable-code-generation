//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: innovative
// Welcome to the C Medical Store Management System!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medical item details
typedef struct medical_item {
    int item_id;
    char item_name[50];
    int quantity;
    float price;
} medical_item;

// Function to add a new medical item
void add_item(medical_item *items, int *num_items) {
    // Get the item details from the user
    printf("Enter the item ID: ");
    scanf("%d", &items[*num_items].item_id);
    printf("Enter the item name: ");
    scanf("%s", items[*num_items].item_name);
    printf("Enter the quantity: ");
    scanf("%d", &items[*num_items].quantity);
    printf("Enter the price: ");
    scanf("%f", &items[*num_items].price);

    // Increment the number of items
    (*num_items)++;
}

// Function to display all medical items
void display_items(medical_item *items, int num_items) {
    // Print the header
    printf("%-10s %-20s %-10s %-10s\n", "Item ID", "Item Name", "Quantity", "Price");

    // Print each item
    for (int i = 0; i < num_items; i++) {
        printf("%-10d %-20s %-10d %.2f\n", items[i].item_id, items[i].item_name, items[i].quantity, items[i].price);
    }
}

// Function to search for a medical item by ID
int search_item_by_id(medical_item *items, int num_items, int item_id) {
    // Iterate through the items
    for (int i = 0; i < num_items; i++) {
        // If the item ID matches, return the index
        if (items[i].item_id == item_id) {
            return i;
        }
    }

    // Return -1 if the item is not found
    return -1;
}

// Function to edit a medical item by ID
void edit_item_by_id(medical_item *items, int num_items, int item_id) {
    // Get the index of the item to edit
    int index = search_item_by_id(items, num_items, item_id);

    // If the item is not found, print an error message
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    // Get the new item details from the user
    printf("Enter the new item name: ");
    scanf("%s", items[index].item_name);
    printf("Enter the new quantity: ");
    scanf("%d", &items[index].quantity);
    printf("Enter the new price: ");
    scanf("%f", &items[index].price);
}

// Function to delete a medical item by ID
void delete_item_by_id(medical_item *items, int *num_items, int item_id) {
    // Get the index of the item to delete
    int index = search_item_by_id(items, *num_items, item_id);

    // If the item is not found, print an error message
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    // Shift the items after the deleted item to the left
    for (int i = index; i < *num_items - 1; i++) {
        items[i] = items[i + 1];
    }

    // Decrement the number of items
    (*num_items)--;
}

// Main function
int main() {
    // Declare an array of medical items
    medical_item items[100];

    // Initialize the number of items to 0
    int num_items = 0;

    // Main loop
    while (1) {
        // Display the menu
        printf("\n\nMedical Store Management System\n");
        printf("-------------------------------\n");
        printf("1. Add a new medical item\n");
        printf("2. Display all medical items\n");
        printf("3. Search for a medical item by ID\n");
        printf("4. Edit a medical item by ID\n");
        printf("5. Delete a medical item by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Switch statement to handle the user's choice
        switch (choice) {
            case 1:
                // Add a new medical item
                add_item(items, &num_items);
                break;
            case 2:
                // Display all medical items
                display_items(items, num_items);
                break;
            case 3:
                // Search for a medical item by ID
                printf("Enter the item ID to search for: ");
                int item_id;
                scanf("%d", &item_id);

                int index = search_item_by_id(items, num_items, item_id);

                if (index == -1) {
                    printf("Item not found.\n");
                } else {
                    printf("Item found:\n");
                    printf("%-10s %-20s %-10s %-10s\n", "Item ID", "Item Name", "Quantity", "Price");
                    printf("%-10d %-20s %-10d %.2f\n", items[index].item_id, items[index].item_name, items[index].quantity, items[index].price);
                }
                break;
            case 4:
                // Edit a medical item by ID
                printf("Enter the item ID to edit: ");
                scanf("%d", &item_id);

                edit_item_by_id(items, num_items, item_id);
                break;
            case 5:
                // Delete a medical item by ID
                printf("Enter the item ID to delete: ");
                scanf("%d", &item_id);

                delete_item_by_id(items, &num_items, item_id);
                break;
            case 6:
                // Exit the program
                printf("Exiting the program.\n");
                return 0;
            default:
                // Handle invalid choices
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}