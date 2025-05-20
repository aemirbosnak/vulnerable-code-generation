//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item warehouse[MAX_ITEMS];
int item_count = 0;

void addItem() {
    if (item_count >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    Item new_item;
    printf("Enter item ID: ");
    scanf("%d", &new_item.id);
    printf("Enter item name: ");
    getchar(); // consume newline
    fgets(new_item.name, MAX_NAME_LENGTH, stdin);
    new_item.name[strcspn(new_item.name, "\n")] = 0; // remove newline
    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);
    printf("Enter item price: ");
    scanf("%f", &new_item.price);
    
    warehouse[item_count] = new_item;
    item_count++;
    printf("Item added successfully!\n");
}

void displayItems() {
    if (item_count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    
    printf("\nWarehouse Items:\n");
    printf("%-10s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < item_count; i++) {
        printf("%-10d %-30s %-10d $%-9.2f\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

void removeItem() {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    
    for (int i = 0; i < item_count; i++) {
        if (warehouse[i].id == id) {
            for (int j = i; j < item_count - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            item_count--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void updateItem() {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < item_count; i++) {
        if (warehouse[i].id == id) {
            printf("Updating item %s (ID: %d)\n", warehouse[i].name, id);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &warehouse[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void searchItem() {
    char name[MAX_NAME_LENGTH];
    printf("Enter item name to search: ");
    getchar(); // consume newline
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline
    
    printf("\nSearch Results:\n");
    printf("%-10s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    int found = 0;
    for (int i = 0; i < item_count; i++) {
        if (strstr(warehouse[i].name, name) != NULL) {
            printf("%-10d %-30s %-10d $%-9.2f\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No items found with name containing '%s'.\n", name);
    }
}

void displayMenu() {
    printf("\n======= Warehouse Management System =======\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Remove Item\n");
    printf("4. Update Item\n");
    printf("5. Search Item\n");
    printf("6. Exit\n");
    printf("===========================================\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                searchItem();
                break;
            case 6:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}