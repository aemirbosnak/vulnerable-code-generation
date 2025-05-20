//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ITEMS 100  // Maximum number of items in the warehouse
#define MAX_NAME_LENGTH 20  // Maximum length of the item name

// Structure to hold information about each item in the warehouse
typedef struct item {
    int id;  // Unique identifier for the item
    char name[MAX_NAME_LENGTH];  // Name of the item
    int quantity;  // Quantity of the item in the warehouse
} Item;

// Function to add a new item to the warehouse
void add_item(Item *items, int *num_items) {
    // Check if the warehouse is already full
    if (*num_items == MAX_ITEMS) {
        printf("Warehouse already at maximum capacity.\n");
        return;
    }
    
    // Get information about the new item from the user
    Item new_item;
    printf("Enter name of item: ");
    scanf("%s", new_item.name);
    printf("Enter quantity of item: ");
    scanf("%d", &new_item.quantity);
    
    // Assign a unique identifier to the item
    new_item.id = *num_items + 1;
    
    // Add the item to the warehouse and increment the number of items
    items[*num_items] = new_item;
    *num_items += 1;
    
    printf("Item successfully added.\n");
}

// Function to remove an item from the warehouse
void remove_item(Item *items, int *num_items) {
    // Get the ID of the item to remove from the user
    int id;
    printf("Enter ID of item to remove: ");
    scanf("%d", &id);
    
    // Find the index of the item in the array
    int index = -1;
    for (int i = 0; i < *num_items; i++) {
        if (items[i].id == id) {
            index = i;
            break;
        }
    }
    
    // If the item was not found, return an error message
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }
    
    // Shift all items after the removed item down one index
    for (int i = index; i < *num_items - 1; i++) {
        items[i] = items[i + 1];
    }
    
    // Decrement the number of items
    *num_items -= 1;
    
    printf("Item successfully removed.\n");
}

// Function to display a list of all items in the warehouse
void list_items(Item *items, int num_items) {
    printf("ID\tName\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t%d\n", items[i].id, items[i].name, items[i].quantity);
    }
}

int main() {
    // Initialize the item array and the number of items to zero
    Item items[MAX_ITEMS];
    int num_items = 0;
    
    // Loop to display the main menu and get user input
    bool running = true;
    while (running) {
        printf("\nWarehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. List items\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        int option;
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                remove_item(items, &num_items);
                break;
            case 3:
                list_items(items, num_items);
                break;
            case 4:
                running = false;
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    
    return 0;
}