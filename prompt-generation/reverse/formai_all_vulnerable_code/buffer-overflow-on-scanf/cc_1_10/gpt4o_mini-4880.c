//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_LOCATION_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    char location[MAX_LOCATION_LEN];
    char description[100];
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

// Function Prototypes
void initializeWarehouse(Warehouse *warehouse);
void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void displayItems(const Warehouse *warehouse);
void searchItem(const Warehouse *warehouse);
void updateItemQuantity(Warehouse *warehouse);
void futuristicUI();

// Main Function
int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice;
    do {
        futuristicUI();
        printf("Enter your choice (1-6, 0 to exit): ");
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
                searchItem(&warehouse);
                break;
            case 5:
                updateItemQuantity(&warehouse);
                break;
            case 0:
                printf("Exiting... Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Initialize the warehouse
void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

// Add a new item to the warehouse
void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter storage location: ");
    scanf("%s", newItem.location);
    printf("Enter item description: ");
    scanf(" %[^\n]", newItem.description);

    warehouse->items[warehouse->itemCount++] = newItem;
    printf("Item added successfully!\n");
}

// Remove an item from the warehouse
void removeItem(Warehouse *warehouse) {
    char name[MAX_NAME_LEN];
    printf("Enter item name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[--warehouse->itemCount]; // Replace with last item
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found in warehouse.\n");
}

// Display all items in the warehouse
void displayItems(const Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("Warehouse is empty!\n");
        return;
    }

    printf("\nItems in the warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Name: %s, Quantity: %d, Location: %s, Description: %s\n",
               warehouse->items[i].name,
               warehouse->items[i].quantity,
               warehouse->items[i].location,
               warehouse->items[i].description);
    }
}

// Search for an item in the warehouse
void searchItem(const Warehouse *warehouse) {
    char name[MAX_NAME_LEN];
    printf("Enter item name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Item found: Name: %s, Quantity: %d, Location: %s, Description: %s\n",
                   warehouse->items[i].name,
                   warehouse->items[i].quantity,
                   warehouse->items[i].location,
                   warehouse->items[i].description);
            return;
        }
    }
    printf("Item not found in warehouse.\n");
}

// Update the quantity of an item in the warehouse
void updateItemQuantity(Warehouse *warehouse) {
    char name[MAX_NAME_LEN];
    printf("Enter item name to update quantity: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Current quantity: %d\n", warehouse->items[i].quantity);
            int newQuantity;
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            warehouse->items[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Item not found in warehouse.\n");
}

// Futuristic User Interface
void futuristicUI() {
    printf("\n=== Futuristic Warehouse Management System ===\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display All Items\n");
    printf("4. Search Item\n");
    printf("5. Update Item Quantity\n");
    printf("0. Exit\n");
    printf("===============================================\n");
}