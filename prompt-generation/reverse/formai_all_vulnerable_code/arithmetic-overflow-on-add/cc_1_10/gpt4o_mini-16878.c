//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    char description[100];
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Alas, the warehouse cannot hold more items!\n");
        return;
    }
    
    Item *newItem = &warehouse->items[warehouse->count];
    
    printf("Elementary! Let's add a new item.\n");
    printf("Enter the name of the item: ");
    scanf(" %[^\n]", newItem->name);
    
    printf("The quantity of %s: ", newItem->name);
    scanf("%d", &newItem->quantity);
    
    printf("A brief description of %s: ", newItem->name);
    scanf(" %[^\n]", newItem->description);
    
    warehouse->count++;
    
    printf("The item \"%s\" has been successfully added to the warehouse.\n", newItem->name);
}

void searchItem(const Warehouse *warehouse) {
    char searchName[NAME_LENGTH];
    
    printf("Tell me the name of the item you wish to search: ");
    scanf(" %[^\n]", searchName);
    
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, searchName) == 0) {
            printf("The item \"%s\" was found in the warehouse.\n", searchName);
            printf("Quantity: %d\nDescription: %s\n", warehouse->items[i].quantity, warehouse->items[i].description);
            return;
        }
    }
    printf("Alas, the item \"%s\" is not found in the warehouse.\n", searchName);
}

void removeItem(Warehouse *warehouse) {
    char removeName[NAME_LENGTH];
    
    printf("Which item do you wish to remove from the warehouse? ");
    scanf(" %[^\n]", removeName);
    
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, removeName) == 0) {
            printf("The item \"%s\" has been found and shall be removed.\n", removeName);
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("The item has been successfully removed from the warehouse.\n");
            return;
        }
    }
    printf("Alas! The item \"%s\" could not be located in the warehouse.\n", removeName);
}

void displayWarehouse(const Warehouse *warehouse) {
    printf("List of items in the warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Item %d: \"%s\" | Quantity: %d | Description: %s\n",
               i + 1, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].description);
    }
    if (warehouse->count == 0) {
        printf("The warehouse is as empty as a detective's pocket!\n");
    }
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    int choice;
    
    printf("Welcome to Inspector Holmes' Warehouse Management System!\n");
    do {
        printf("\nChoose an action:\n");
        printf("1. Add Item\n");
        printf("2. Search Item\n");
        printf("3. Remove Item\n");
        printf("4. Display All Items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                searchItem(&warehouse);
                break;
            case 3:
                removeItem(&warehouse);
                break;
            case 4:
                displayWarehouse(&warehouse);
                break;
            case 5:
                printf("Exit! Until next time...\n");
                break;
            default:
                printf("The path you chose is quite nonsensical! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}