//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

// Structure to hold item information
typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    int id;
} Item;

// Warehouse structure to manage items
typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

// Function prototypes
void initiateWarehouse(Warehouse *warehouse);
void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void displayItems(Warehouse *warehouse);
void findItem(Warehouse *warehouse);
void saveWarehouse(Warehouse *warehouse);
void loadWarehouse(Warehouse *warehouse);

int main() {
    Warehouse warehouse;
    int choice;

    initiateWarehouse(&warehouse);
    loadWarehouse(&warehouse);

    // Main loop for warehouse operations
    do {
        printf("\n--- Post-Apocalyptic Warehouse Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Find Item\n");
        printf("5. Save Warehouse\n");
        printf("6. Load Warehouse\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                removeItem(&warehouse);
                break;
            case 3:
                displayItems(&warehouse);
                break;
            case 4:
                findItem(&warehouse);
                break;
            case 5:
                saveWarehouse(&warehouse);
                break;
            case 6:
                loadWarehouse(&warehouse);
                break;
            case 0:
                printf("Abandoning the Warehouse Management System... Remember your survival skills!\n");
                break;
            default:
                printf("Invalid choice! Survive another day...\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to initialize the warehouse
void initiateWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

// Function to add item to the warehouse
void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse full! Can't add more items.\n");
        return;
    }
    Item newItem;
    newItem.id = warehouse->count + 1;

    printf("Enter item name: ");
    scanf("%s", newItem.name);
    
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item added successfully!\n");
}

// Function to remove item from the warehouse
void removeItem(Warehouse *warehouse) {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    
    if (id < 1 || id > warehouse->count) {
        printf("Invalid item ID!\n");
        return;
    }
    
    for (int i = id - 1; i < warehouse->count - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    
    warehouse->count--;
    printf("Item removed successfully!\n");
}

// Function to display all items in the warehouse
void displayItems(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in the warehouse!\n");
        return;
    }
    
    printf("\n--- Items in Warehouse ---\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", 
                warehouse->items[i].id, 
                warehouse->items[i].name, 
                warehouse->items[i].quantity);
    }
}

// Function to find an item in the warehouse
void findItem(Warehouse *warehouse) {
    char name[NAME_LENGTH];
    printf("Enter item name to find: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Found Item - ID: %d, Name: %s, Quantity: %d\n", 
                    warehouse->items[i].id, 
                    warehouse->items[i].name, 
                    warehouse->items[i].quantity);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Item not found in the warehouse!\n");
    }
}

// Function to save warehouse data to a file
void saveWarehouse(Warehouse *warehouse) {
    FILE *file = fopen("warehouse_data.txt", "w");
    if (!file) {
        printf("Failed to save warehouse data!\n");
        return;
    }
    fwrite(warehouse, sizeof(Warehouse), 1, file);
    fclose(file);
    printf("Warehouse data saved successfully!\n");
}

// Function to load warehouse data from a file
void loadWarehouse(Warehouse *warehouse) {
    FILE *file = fopen("warehouse_data.txt", "r");
    if (!file) {
        printf("Failed to load warehouse data! Starting fresh.\n");
        return;
    }
    fread(warehouse, sizeof(Warehouse), 1, file);
    fclose(file);
    printf("Warehouse data loaded successfully!\n");
}