//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define constant values for warehouse inventory
#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

// Define struct for items
typedef struct Item {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

// Define global array to hold inventory
Item warehouse[MAX_ITEMS];

// Define function prototypes
void add_item();
void remove_item();
void view_inventory();

int main() {
    int choice;

    do {
        // Print main menu
        printf("--- Warehouse Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Inventory\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");

        // Get user choice
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                view_inventory();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void add_item() {
    // Check if warehouse is full
    if (MAX_ITEMS == sizeof(warehouse)/sizeof(warehouse[0])) {
        printf("Warehouse is full.\n");
        return;
    }

    // Get item information from user
    char name[MAX_NAME_LEN];
    int quantity;
    printf("\nEnter item name: ");
    scanf("%s", name);
    printf("\nEnter item quantity: ");
    scanf("%d", &quantity);

    // Add item to warehouse
    Item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    warehouse[sizeof(warehouse)/sizeof(warehouse[0])] = new_item;

    printf("\nItem added to warehouse.\n");
}

void remove_item() {
    // Check if warehouse is empty
    if (sizeof(warehouse)/sizeof(warehouse[0]) == 0) {
        printf("Warehouse is empty.\n");
        return;
    }

    // Get item name from user
    char name[MAX_NAME_LEN];
    printf("\nEnter item name to remove: ");
    scanf("%s", name);

    // Find item in warehouse and remove it
    for (int i = 0; i < sizeof(warehouse)/sizeof(warehouse[0]); i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            for (int j = i; j < sizeof(warehouse)/sizeof(warehouse[0])-1; j++) {
                warehouse[j] = warehouse[j+1];
            }
            printf("\nItem removed from warehouse.\n");
            return;
        }
    }

    printf("\nItem not found in warehouse.\n");
}

void view_inventory() {
    // Check if warehouse is empty
    if (sizeof(warehouse)/sizeof(warehouse[0]) == 0) {
        printf("Warehouse is empty.\n");
        return;
    }

    // Print inventory
    printf("\n--- Warehouse Inventory ---\n");
    for (int i = 0; i < sizeof(warehouse)/sizeof(warehouse[0]); i++) {
        printf("%s: %d\n", warehouse[i].name, warehouse[i].quantity);
    }
}