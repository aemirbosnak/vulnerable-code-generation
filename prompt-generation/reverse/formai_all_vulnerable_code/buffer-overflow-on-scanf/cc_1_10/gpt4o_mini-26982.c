//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int totalItems;
} Warehouse;

void addItem(Warehouse* warehouse) {
    if (warehouse->totalItems >= MAX_ITEMS) {
        printf("Neon-lit warning: Warehouse is at capacity! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter the name of the item (cyberware or consumable): ");
    scanf("%s", newItem.name);
    printf("Enter the quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter the price: ");
    scanf("%f", &newItem.price);

    warehouse->items[warehouse->totalItems] = newItem;
    warehouse->totalItems++;
    
    printf("Holographic interface: %s has been added to the warehouse.\n", newItem.name);
}

void removeItem(Warehouse* warehouse) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->totalItems; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Removing %s from the warehouse.\n", warehouse->items[i].name);
            for (int j = i; j < warehouse->totalItems - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->totalItems--;
            return;
        }
    }
    printf("Neon-lit alert: Item %s not found in the warehouse.\n", name);
}

void listItems(Warehouse* warehouse) {
    printf("\n--- Cyber Warehouse Inventory ---\n");
    if (warehouse->totalItems == 0) {
        printf("The warehouse is empty, nothing but echoes of past transactions...\n");
        return;
    }
    for (int i = 0; i < warehouse->totalItems; i++) {
        printf("Item Name: %s | Quantity: %d | Price: $%.2f\n", 
                warehouse->items[i].name, 
                warehouse->items[i].quantity, 
                warehouse->items[i].price);
    }
}

void displayMenu() {
    printf("\n=== Cyberpunk Warehouse Management System ===\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. List Items\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Warehouse warehouse = { .totalItems = 0 };
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                removeItem(&warehouse);
                break;
            case 3:
                listItems(&warehouse);
                break;
            case 4:
                printf("Shutting down the system... Disconnecting...\n");
                exit(0);
            default:
                printf("Neon-lit error: Invalid choice, enter a number between 1 and 4.\n");
                break;
        }
    }

    return 0;
}