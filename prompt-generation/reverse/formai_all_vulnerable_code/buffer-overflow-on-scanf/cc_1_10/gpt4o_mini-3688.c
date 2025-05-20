//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initialize(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Cannot add more items, warehouse is full!\n");
        return;
    }
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item added successfully!\n");
}

void displayItems(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("\nItems in the warehouse:\n");
    printf("------------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Item %d: %s | Quantity: %d | Price: %.2f\n",
               i + 1, warehouse->items[i].name,
               warehouse->items[i].quantity, warehouse->items[i].price);
    }
    printf("------------------------------------\n");
}

void searchItem(Warehouse *warehouse) {
    char searchName[50];
    printf("Enter item name to search: ");
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, searchName) == 0) {
            printf("Item found: %s | Quantity: %d | Price: %.2f\n",
                   warehouse->items[i].name,
                   warehouse->items[i].quantity, warehouse->items[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item '%s' not found in the warehouse.\n", searchName);
    }
}

void deleteItem(Warehouse *warehouse) {
    char deleteName[50];
    printf("Enter item name to delete: ");
    scanf("%s", deleteName);
    
    int index = -1;
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, deleteName) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Item '%s' not found for deletion.\n", deleteName);
        return;
    }
    
    for (int i = index; i < warehouse->count - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->count--;
    printf("Item '%s' deleted successfully!\n", deleteName);
}

void showMenu() {
    printf("\nWarehouse Management System Menu:\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Search Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Warehouse warehouse;
    initialize(&warehouse);
    
    int choice;
    do {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addItem(&warehouse); break;
            case 2: displayItems(&warehouse); break;
            case 3: searchItem(&warehouse); break;
            case 4: deleteItem(&warehouse); break;
            case 5: printf("Exiting the system. Goodbye!\n"); break;
            default: printf("Invalid choice! Please choose again.\n"); break;
        }
    } while (choice != 5);

    return 0;
}