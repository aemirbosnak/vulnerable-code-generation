//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
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

// Function declarations
void initializeWarehouse(Warehouse *warehouse);
void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void updateItem(Warehouse *warehouse);
void displayItems(Warehouse *warehouse);
void searchItem(Warehouse *warehouse);
void menu();

int main() {
    Warehouse warehouse;
    int choice;

    initializeWarehouse(&warehouse);
   
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                removeItem(&warehouse);
                break;
            case 3:
                updateItem(&warehouse);
                break;
            case 4:
                displayItems(&warehouse);
                break;
            case 5:
                searchItem(&warehouse);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = warehouse->count + 1;
    
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    
    printf("Item added successfully with ID: %d\n", newItem.id);
}

void removeItem(Warehouse *warehouse) {
    int id;
    
    printf("Enter ID of the item to remove: ");
    scanf("%d", &id);
    
    if (id < 1 || id > warehouse->count) {
        printf("Item with ID %d does not exist.\n", id);
        return;
    }

    // Shift items left
    for (int i = id - 1; i < warehouse->count - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->count--;

    printf("Item with ID %d removed successfully.\n", id);
}

void updateItem(Warehouse *warehouse) {
    int id;
    
    printf("Enter ID of the item to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > warehouse->count) {
        printf("Item with ID %d does not exist.\n", id);
        return;
    }

    Item *item = &warehouse->items[id - 1];
    
    printf("Updating Item ID: %d\n", item->id);
    printf("Current name: %s\n", item->name);
    printf("Enter new name (or press Enter to keep current): ");
    char newName[NAME_LENGTH];
    fgets(newName, NAME_LENGTH, stdin);
    if (strlen(newName) > 1) {
        sscanf(newName, "%s", item->name);
    }

    printf("Current quantity: %d\n", item->quantity);
    printf("Enter new quantity (or -1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        item->quantity = newQuantity;
    }
    
    printf("Current price: %.2f\n", item->price);
    printf("Enter new price (or -1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice != -1) {
        item->price = newPrice;
    }

    printf("Item updated successfully.\n");
}

void displayItems(Warehouse *warehouse) {
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------\n");
    
    for (int i = 0; i < warehouse->count; i++) {
        Item item = warehouse->items[i];
        printf("%d\t%s\t\t%d\t\t%.2f\n", item.id, item.name, item.quantity, item.price);
    }
}

void searchItem(Warehouse *warehouse) {
    char searchName[NAME_LENGTH];
    
    printf("Enter item name to search: ");
    scanf("%s", searchName);
    
    printf("Search Results:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------\n");

    int found = 0;
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, searchName) == 0) {
            found = 1;
            Item item = warehouse->items[i];
            printf("%d\t%s\t\t%d\t\t%.2f\n", item.id, item.name, item.quantity, item.price);
        }
    }
    if (!found) {
        printf("No items found with the name: %s\n", searchName);
    }
}

void menu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Update Item\n");
    printf("4. Display All Items\n");
    printf("5. Search Item\n");
    printf("6. Exit\n");
}