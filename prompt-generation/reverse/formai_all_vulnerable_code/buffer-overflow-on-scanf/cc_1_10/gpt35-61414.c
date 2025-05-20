//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct WarehouseItem {
    int id;
    char name[50];
    int quantity;
    float price;
} WarehouseItem;

typedef struct Warehouse {
    int id;
    char location[50];
    WarehouseItem *items;
    int numItems;
} Warehouse;

void addNewItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void printInventory(Warehouse *warehouse);
void updateItemPrice(Warehouse *warehouse);
void updateItemQuantity(Warehouse *warehouse);

int main() {

    //initialize warehouse
    Warehouse myWarehouse;
    printf("Enter the warehouse ID: ");
    scanf("%d", &myWarehouse.id);
    printf("Enter the location of the warehouse: ");
    scanf("%s", myWarehouse.location);
    myWarehouse.items = NULL;
    myWarehouse.numItems = 0;

    int choice = 0;
    while (choice != 6) {
        printf("\n\n");
        printf("       #############################\n");
        printf("       #  WAREHOUSE MANAGEMENT SYS #\n");
        printf("       #############################\n\n");
        printf("1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. Update item price\n");
        printf("4. Update item quantity\n");
        printf("5. Print inventory\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewItem(&myWarehouse);
                break;
            case 2:
                removeItem(&myWarehouse);
                break;
            case 3:
                updateItemPrice(&myWarehouse);
                break;
            case 4:
                updateItemQuantity(&myWarehouse);
                break;
            case 5:
                printInventory(&myWarehouse);
                break;
            case 6:
                printf("Exiting program...\n");
                free(myWarehouse.items);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void addNewItem(Warehouse *warehouse) {
    WarehouseItem newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    warehouse->numItems++;
    warehouse->items = realloc(warehouse->items, warehouse->numItems*sizeof(WarehouseItem));
    warehouse->items[warehouse->numItems-1] = newItem;
    printf("\nItem %s added to inventory.\n", newItem.name);
}

void removeItem(Warehouse *warehouse) {
    int idToRemove;
    printf("Enter item ID to remove: ");
    scanf("%d", &idToRemove);

    for (int i = 0; i < warehouse->numItems; i++) {
        if (warehouse->items[i].id == idToRemove) {
            printf("\nItem %s removed from inventory.\n", warehouse->items[i].name);
            for (int j = i; j < warehouse->numItems-1; j++) {
                warehouse->items[j] = warehouse->items[j+1];
            }
            warehouse->numItems--;
            warehouse->items = realloc(warehouse->items, warehouse->numItems*sizeof(WarehouseItem));
            return;
        }
    }
    printf("\nItem not found.\n");
}

void updateItemPrice(Warehouse *warehouse) {
    int idToUpdate;
    printf("Enter item ID to update price: ");
    scanf("%d", &idToUpdate);

    for (int i = 0; i < warehouse->numItems; i++) {
        if (warehouse->items[i].id == idToUpdate) {
            printf("\nEnter new price for item %s: ", warehouse->items[i].name);
            scanf("%f", &warehouse->items[i].price);
            printf("\nPrice updated for item %s.\n", warehouse->items[i].name);
            return;
        }
    }
    printf("\nItem not found.\n");
}

void updateItemQuantity(Warehouse *warehouse) {
    int idToUpdate;
    printf("Enter item ID to update quantity: ");
    scanf("%d", &idToUpdate);

    for (int i = 0; i < warehouse->numItems; i++) {
        if (warehouse->items[i].id == idToUpdate) {
            printf("\nEnter new quantity for item %s: ", warehouse->items[i].name);
            scanf("%d", &warehouse->items[i].quantity);
            printf("\nQuantity updated for item %s.\n", warehouse->items[i].name);
            return;
        }
    }
    printf("\nItem not found.\n");
}

void printInventory(Warehouse *warehouse) {
    printf("\n\n       #############\n");
    printf("       # INVENTORY #\n");
    printf("       #############\n\n");
    printf("%-15s | %-15s | %-10s | %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < warehouse->numItems; i++) {
        printf("%-15d | %-15s | %-10d | $%-10.2f\n", 
            warehouse->items[i].id,
            warehouse->items[i].name,
            warehouse->items[i].quantity,
            warehouse->items[i].price
        );
    }
}