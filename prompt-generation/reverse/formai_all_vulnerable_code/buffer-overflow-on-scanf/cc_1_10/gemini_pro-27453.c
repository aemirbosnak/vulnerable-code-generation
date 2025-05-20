//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

// Structure to store item details
typedef struct {
    int item_code;
    char item_name[50];
    int quantity;
    float price;
} Item;

// Function to add an item to the inventory
void add_item(Item *inventory, int *num_items) {
    // Get item details from the user
    int item_code;
    char item_name[50];
    int quantity;
    float price;
    printf("Enter item code: ");
    scanf("%d", &item_code);
    printf("Enter item name: ");
    scanf("%s", item_name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%f", &price);

    // Check if item code already exists
    for (int i = 0; i < *num_items; i++) {
        if (inventory[i].item_code == item_code) {
            printf("Item code already exists.\n");
            return;
        }
    }

    // Add the item to the inventory
    inventory[*num_items].item_code = item_code;
    strcpy(inventory[*num_items].item_name, item_name);
    inventory[*num_items].quantity = quantity;
    inventory[*num_items].price = price;

    // Increment the number of items
    (*num_items)++;
}

// Function to delete an item from the inventory
void delete_item(Item *inventory, int *num_items) {
    // Get item code from the user
    int item_code;
    printf("Enter item code to delete: ");
    scanf("%d", &item_code);

    // Find the item in the inventory
    int index = -1;
    for (int i = 0; i < *num_items; i++) {
        if (inventory[i].item_code == item_code) {
            index = i;
            break;
        }
    }

    // Check if item was found
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    // Shift the items after the deleted item to the left
    for (int i = index; i < *num_items - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    // Decrement the number of items
    (*num_items)--;
}

// Function to update an item in the inventory
void update_item(Item *inventory, int *num_items) {
    // Get item code from the user
    int item_code;
    printf("Enter item code to update: ");
    scanf("%d", &item_code);

    // Find the item in the inventory
    int index = -1;
    for (int i = 0; i < *num_items; i++) {
        if (inventory[i].item_code == item_code) {
            index = i;
            break;
        }
    }

    // Check if item was found
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    // Get updated item details from the user
    int quantity;
    float price;
    printf("Enter updated quantity: ");
    scanf("%d", &quantity);
    printf("Enter updated price: ");
    scanf("%f", &price);

    // Update the item details
    inventory[index].quantity = quantity;
    inventory[index].price = price;
}

// Function to search for an item in the inventory
void search_item(Item *inventory, int *num_items) {
    // Get item code from the user
    int item_code;
    printf("Enter item code to search for: ");
    scanf("%d", &item_code);

    // Find the item in the inventory
    int index = -1;
    for (int i = 0; i < *num_items; i++) {
        if (inventory[i].item_code == item_code) {
            index = i;
            break;
        }
    }

    // Check if item was found
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    // Print the item details
    printf("Item code: %d\n", inventory[index].item_code);
    printf("Item name: %s\n", inventory[index].item_name);
    printf("Quantity: %d\n", inventory[index].quantity);
    printf("Price: %.2f\n", inventory[index].price);
}

// Function to display the inventory
void display_inventory(Item *inventory, int *num_items) {
    printf("Inventory:\n");
    for (int i = 0; i < *num_items; i++) {
        printf("%d %s %d %.2f\n", inventory[i].item_code, inventory[i].item_name, inventory[i].quantity, inventory[i].price);
    }
}

// Main function
int main() {
    // Initialize the inventory
    Item inventory[MAX_ITEMS];
    int num_items = 0;

    // Menu-driven program
    int choice;
    do {
        printf("1. Add item\n");
        printf("2. Delete item\n");
        printf("3. Update item\n");
        printf("4. Search for item\n");
        printf("5. Display inventory\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(inventory, &num_items);
                break;
            case 2:
                delete_item(inventory, &num_items);
                break;
            case 3:
                update_item(inventory, &num_items);
                break;
            case 4:
                search_item(inventory, &num_items);
                break;
            case 5:
                display_inventory(inventory, &num_items);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}