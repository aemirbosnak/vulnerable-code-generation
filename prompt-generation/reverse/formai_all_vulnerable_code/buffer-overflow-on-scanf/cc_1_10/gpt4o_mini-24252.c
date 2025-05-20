//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: genius
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
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse *warehouse, int id, const char *name, int quantity, float price) {
    if(warehouse->itemCount < MAX_ITEMS) {
        warehouse->items[warehouse->itemCount].id = id;
        strncpy(warehouse->items[warehouse->itemCount].name, name, NAME_LENGTH - 1);
        warehouse->items[warehouse->itemCount].name[NAME_LENGTH - 1] = '\0';  // Ensure null-termination
        warehouse->items[warehouse->itemCount].quantity = quantity;
        warehouse->items[warehouse->itemCount].price = price;
        warehouse->itemCount++;
        printf("Item %s added to the warehouse.\n", name);
    } else {
        printf("Warehouse is full, cannot add more items.\n");
    }
}

void removeItem(Warehouse *warehouse, int id) {
    for(int i = 0; i < warehouse->itemCount; i++) {
        if(warehouse->items[i].id == id) {
            for(int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            printf("Item with ID %d removed from the warehouse.\n", id);
            return;
        }
    }
    printf("Item with ID %d not found in the warehouse.\n", id);
}

void displayWarehouse(const Warehouse *warehouse) {
    if(warehouse->itemCount == 0) {
        printf("The warehouse is empty.\n");
        return;
    }
    printf("\n====== Warehouse Inventory ======\n");
    for(int i = 0; i < warehouse->itemCount; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n", 
               warehouse->items[i].id, 
               warehouse->items[i].name,
               warehouse->items[i].quantity, 
               warehouse->items[i].price);
    }
    printf("==================================\n");
}

void updateQuantity(Warehouse *warehouse, int id, int newQuantity) {
    for(int i = 0; i < warehouse->itemCount; i++) {
        if(warehouse->items[i].id == id) {
            warehouse->items[i].quantity = newQuantity;
            printf("Quantity for item ID %d updated to %d.\n", id, newQuantity);
            return;
        }
    }
    printf("Item with ID %d not found for updating quantity.\n", id);
}

void calculateTotalValue(const Warehouse *warehouse) {
    float totalValue = 0.0f;
    for(int i = 0; i < warehouse->itemCount; i++) {
        totalValue += warehouse->items[i].quantity * warehouse->items[i].price;
    }
    printf("Total value of items in warehouse: %.2f\n", totalValue);
}

int main() {
    Warehouse warehouse;
    int choice, id, quantity;
    char name[NAME_LENGTH];
    float price;

    initializeWarehouse(&warehouse);

    while(1) {
        printf("\n======= Warehouse Management System =======\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Update Quantity\n");
        printf("5. Calculate Total Value\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addItem(&warehouse, id, name, quantity, price);
                break;

            case 2:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, id);
                break;

            case 3:
                displayWarehouse(&warehouse);
                break;

            case 4:
                printf("Enter item ID to update quantity: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateQuantity(&warehouse, id, quantity);
                break;

            case 5:
                calculateTotalValue(&warehouse);
                break;

            case 0:
                printf("Exiting the Warehouse Management System.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}