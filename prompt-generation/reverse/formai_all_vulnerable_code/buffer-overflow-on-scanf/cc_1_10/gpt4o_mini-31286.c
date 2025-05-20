//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count < MAX_ITEMS) {
        Item newItem;
        
        printf("Enter Item ID: ");
        scanf("%d", &newItem.id);
        getchar();  // to consume the newline character

        printf("Enter Item Name: ");
        fgets(newItem.name, NAME_LENGTH, stdin);
        newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove newline character

        printf("Enter Item Quantity: ");
        scanf("%d", &newItem.quantity);

        printf("Enter Item Price: ");
        scanf("%f", &newItem.price);

        warehouse->items[warehouse->count] = newItem;
        warehouse->count++;
        
        printf("Item added successfully!\n");
    } else {
        printf("Warehouse full! Cannot add more items.\n");
    }
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in warehouse.\n");
        return;
    }

    printf("\nItems in Warehouse:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", 
            warehouse->items[i].id, 
            warehouse->items[i].name, 
            warehouse->items[i].quantity, 
            warehouse->items[i].price);
    }
}

void updateItem(Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter Item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;

            printf("Updating item: %s\n", warehouse->items[i].name);
            printf("Enter new Quantity: ");
            scanf("%d", &warehouse->items[i].quantity);

            printf("Enter new Price: ");
            scanf("%f", &warehouse->items[i].price);

            printf("Item updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item not found!\n");
    }
}

void removeItem(Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter Item ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1]; // Shift items left
            }
            warehouse->count--;
            printf("Item removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item not found!\n");
    }
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Item\n");
        printf("4. Remove Item\n");
        printf("5. Exit\n");
        printf("Choose an action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                displayItems(&warehouse);
                break;
            case 3:
                updateItem(&warehouse);
                break;
            case 4:
                removeItem(&warehouse);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}