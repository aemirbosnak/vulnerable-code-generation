//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100 // Maximum number of items to be stored in the warehouse

typedef struct Item { // Defining the structure for an item in the warehouse
    int id; 
    char name[50];
    int quantity;
    float cost;
} Item;

typedef struct Warehouse { // Defining the structure for the warehouse
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void addItem(Warehouse *warehouse) { // Function to add an item to the warehouse
    Item item;

    printf("Enter item ID: ");
    scanf("%d", &item.id);

    printf("Enter item name: ");
    scanf("%s", item.name);

    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter item cost: ");
    scanf("%f", &item.cost);

    warehouse->items[warehouse->count++] = item;
}

void displayItems(Warehouse warehouse) { // Function to display all the items in the warehouse
    printf("=== Items in warehouse ===\n\n");

    for(int i = 0; i < warehouse.count; i++) {
        Item item = warehouse.items[i];

        printf("Item ID: %d\n", item.id);
        printf("Item name: %s\n", item.name);
        printf("Item quantity: %d\n", item.quantity);
        printf("Item cost: $%.2f\n\n", item.cost);
    }
}

void displayItem(Warehouse warehouse) { // Function to display a specific item in the warehouse
    int id;

    printf("Enter item ID: ");
    scanf("%d", &id);

    printf("\n");

    for(int i = 0; i < warehouse.count; i++) {
        Item item = warehouse.items[i];

        if(item.id == id) {
            printf("Item ID: %d\n", item.id);
            printf("Item name: %s\n", item.name);
            printf("Item quantity: %d\n", item.quantity);
            printf("Item cost: $%.2f\n\n", item.cost);
            return;
        }
    }

    printf("Item with ID %d not found in warehouse.\n\n", id);
}

int main() {
    Warehouse warehouse;
    warehouse.count = 0;

    int choice;

    do {
        printf("Warehouse Management System\n\n");
        printf("1. Add item\n");
        printf("2. Display all items\n");
        printf("3. Display item\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                displayItems(warehouse);
                break;
            case 3:
                displayItem(warehouse);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while(choice != 4);

    return 0;
}