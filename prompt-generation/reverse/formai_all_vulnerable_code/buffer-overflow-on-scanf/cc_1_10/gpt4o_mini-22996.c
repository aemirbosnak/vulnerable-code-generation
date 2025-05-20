//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    newItem.id = itemCount + 1;

    printf("Enter item name: ");
    scanf("%s", newItem.name);
    
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    warehouse[itemCount] = newItem;
    itemCount++;
    
    printf("Item added successfully: %s, Quantity: %d\n", newItem.name, newItem.quantity);
}

void viewInventory() {
    if (itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nWarehouse Inventory:\n");
    printf("ID\tName\t\tQuantity\n");
    printf("-----------------------------------\n");
    
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
    printf("-----------------------------------\n");
}

void removeItem() {
    int itemId;
    printf("Enter item ID to remove: ");
    scanf("%d", &itemId);
    
    if (itemId < 1 || itemId > itemCount) {
        printf("Invalid item ID.\n");
        return;
    }

    for (int i = itemId - 1; i < itemCount - 1; i++) {
        warehouse[i] = warehouse[i + 1];
    }
    itemCount--;
    
    printf("Item removed successfully.\n");
}

void generateReport() {
    FILE *file = fopen("warehouse_report.txt", "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    fprintf(file, "Warehouse Inventory Report\n");
    fprintf(file, "ID\tName\t\tQuantity\n");
    fprintf(file, "-----------------------------------\n");
    
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d\t%s\t\t%d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }

    fclose(file);
    printf("Report generated successfully: warehouse_report.txt\n");
}

void displayMenu() {
    printf("\nWarehouse Management System Menu\n");
    printf("1. Add Item\n");
    printf("2. View Inventory\n");
    printf("3. Remove Item\n");
    printf("4. Generate Report\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
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
                viewInventory();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                generateReport();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}