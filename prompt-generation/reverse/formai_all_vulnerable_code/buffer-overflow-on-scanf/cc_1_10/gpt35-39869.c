//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: real-life
#include <stdio.h>

// Define the maximum capacity of the warehouse
#define MAX_CAPACITY 10000

// Declare the warehouse array
int warehouse[MAX_CAPACITY];

// Declare some variables
int num_items = 0;
int current_capacity = 0;

// Function to add items to the warehouse
void add_item(int item) {
    // Check if there is enough space in the warehouse
    if (current_capacity + 1 > MAX_CAPACITY) {
        printf("Sorry, the warehouse is full.\n");
        return;
    }
    
    // Add the item to the warehouse
    warehouse[num_items] = item;
    num_items++;
    current_capacity++;
    
    printf("Item added successfully.\n");
}

// Function to remove items from the warehouse
void remove_item(int item) {
    // Check if the item is in the warehouse
    int found_item = 0;
    for (int i = 0; i < num_items; i++) {
        if (warehouse[i] == item) {
            found_item = 1;
            // Remove the item from the warehouse
            for (int j = i; j < num_items - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            num_items--;
            current_capacity--;
            printf("Item removed successfully.\n");
            break;
        }
    }
    
    if (!found_item) {
        printf("Sorry, the item was not found in the warehouse.\n");
    }
}

// Function to display the items in the warehouse
void display_items() {
    if (num_items == 0) {
        printf("The warehouse is currently empty.\n");
        return;
    }
    
    printf("The items in the warehouse are:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\n", warehouse[i]);
    }
}

int main() {
    // Display the menu options
    printf("Welcome to the Warehouse Management System!\n");
    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        
        // Get the user's choice
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                // Get the item to add to the warehouse
                int item;
                printf("Enter the item to add: ");
                scanf("%d", &item);
                add_item(item);
                break;
            }
            case 2: {
                // Get the item to remove from the warehouse
                int item;
                printf("Enter the item to remove: ");
                scanf("%d", &item);
                remove_item(item);
                break;
            }
            case 3: {
                display_items();
                break;
            }
            case 4: {
                printf("Thank you for using the Warehouse Management System!\n");
                return 0;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
}