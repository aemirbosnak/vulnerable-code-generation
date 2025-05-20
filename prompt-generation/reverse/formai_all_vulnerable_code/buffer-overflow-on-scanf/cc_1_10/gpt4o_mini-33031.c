//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50
#define DATE_LENGTH 11

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    char arrival_date[DATE_LENGTH];
} InventoryItem;

typedef struct {
    InventoryItem items[MAX_ITEMS];
    int count;
} Warehouse;

void initialize_warehouse(Warehouse* warehouse) {
    warehouse->count = 0;
}

int add_item(Warehouse* warehouse, const char* name, int quantity, const char* arrival_date) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Oh love, our garden of inventory has flourished too much!\n");
        return -1;
    }
    strcpy(warehouse->items[warehouse->count].name, name);
    warehouse->items[warehouse->count].quantity = quantity;
    strcpy(warehouse->items[warehouse->count].arrival_date, arrival_date);
    warehouse->count++;
    printf("A new item has graced our love-filled warehouse: %s\n", name);
    return 0;
}

void view_inventory(const Warehouse* warehouse) {
    printf("Let us gaze upon what our hearts have gathered:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Item #%d: %s - Quantity: %d - Arrival Date: %s\n", 
                i + 1, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].arrival_date);
    }
}

int remove_item(Warehouse* warehouse, const char* name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Alas! Removing %s from our sweet stock!\n", name);
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            return 0;
        }
    }
    printf("Oh dear! We have no item by the name of %s in our tender hearts.\n", name);
    return -1;
}

void romantic_menu() {
    printf("Welcome to the Love Warehouse Management System!\n");
    printf("1. Add Item\n");
    printf("2. View Inventory\n");
    printf("3. Remove Item\n");
    printf("4. Exit\n");
    printf("Choose your beloved option: ");
}

int main() {
    Warehouse myWarehouse;
    initialize_warehouse(&myWarehouse);

    int choice;
    char name[NAME_LENGTH];
    int quantity;
    char arrival_date[DATE_LENGTH];

    while (1) {
        romantic_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of your item of affection: ");
                scanf("%s", name);
                printf("Enter the quantity of love (quantity): ");
                scanf("%d", &quantity);
                printf("Enter the date of arrival (YYYY-MM-DD): ");
                scanf("%s", arrival_date);
                add_item(&myWarehouse, name, quantity, arrival_date);
                break;
            case 2:
                view_inventory(&myWarehouse);
                break;
            case 3:
                printf("Enter the name of the item you wish to release from our loving clutch: ");
                scanf("%s", name);
                remove_item(&myWarehouse, name);
                break;
            case 4:
                printf("Farewell, dear! Until we meet again in our warehouse of dreams.\n");
                exit(0);
            default:
                printf("Oh dearest, that option is but a whisper upon the wind. Please choose again.\n");
        }
    }

    return 0;
}