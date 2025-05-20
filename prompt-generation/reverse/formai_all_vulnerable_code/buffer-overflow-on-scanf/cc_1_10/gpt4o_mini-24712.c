//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

// Function Prototypes
void initializeWarehouse(Warehouse *warehouse);
void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void displayItems(const Warehouse *warehouse);
void searchItem(const Warehouse *warehouse);
void menu();

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    do {
        menu();
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
                searchItem(&warehouse);
                break;
            case 5:
                printf("Exiting the Warehouse Management System...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

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
    printf("Enter item name: ");
    getchar(); // Clear the newline character from the input buffer
    fgets(newItem.name, ITEM_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove trailing newline

    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item added successfully!\n");
}

void removeItem(Warehouse *warehouse) {
    char name[ITEM_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    getchar();
    fgets(name, ITEM_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found in the warehouse!\n");
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("The warehouse is empty!\n");
        return;
    }
    
    printf("\nItems in Warehouse:\n");
    printf("---------------------------------------------------------\n");
    printf("| Item Name                       | Quantity  | Price   |\n");
    printf("---------------------------------------------------------\n");
    
    for (int i = 0; i < warehouse->count; i++) {
        printf("| %-30s | %-9d | $%.2f |\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }

    printf("---------------------------------------------------------\n");
}

void searchItem(const Warehouse *warehouse) {
    char name[ITEM_NAME_LENGTH];
    printf("Enter item name to search: ");
    getchar();
    fgets(name, ITEM_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Item found!\n");
            printf("Item Name: %s\n", warehouse->items[i].name);
            printf("Quantity: %d\n", warehouse->items[i].quantity);
            printf("Price: $%.2f\n", warehouse->items[i].price);
            return;
        }
    }
    printf("Item not found in the warehouse!\n");
}

void menu() {
    printf("\n--- Warehouse Management System Menu ---\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Items\n");
    printf("4. Search Item\n");
    printf("5. Exit\n");
    printf("-----------------------------------------\n");
}