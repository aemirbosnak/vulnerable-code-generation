//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount < MAX_ITEMS) {
        Item newItem;
        newItem.id = warehouse->itemCount + 1;

        printf("Enter item name: ");
        scanf("%s", newItem.name);
        printf("Enter item quantity: ");
        scanf("%d", &newItem.quantity);

        warehouse->items[warehouse->itemCount++] = newItem;
        printf("Item added successfully!\n");
    } else {
        printf("Warehouse is full, cannot add more items!\n");
    }
}

void removeItem(Warehouse *warehouse) {
    int id, found = 0;

    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            printf("Item removed successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found!\n", id);
    }
}

void displayItems(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("Warehouse is empty!\n");
        return;
    }
    
    printf("ID\tName\t\tQuantity\n");
    printf("----------------------------\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%d\t%s\t\t%d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void updateItem(Warehouse *warehouse) {
    int id, found = 0;

    printf("Enter item ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;
            printf("Current Quantity: %d\n", warehouse->items[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse->items[i].quantity);
            printf("Item updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found!\n", id);
    }
}

void saveToFile(Warehouse *warehouse) {
    FILE *file = fopen("warehouse_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "ID,Name,Quantity\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        fprintf(file, "%d,%s,%d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
    fclose(file);
    printf("Data saved to warehouse_data.txt successfully!\n");
}

void loadFromFile(Warehouse *warehouse) {
    FILE *file = fopen("warehouse_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char buffer[100];
    fscanf(file, "%s", buffer); // Skip header
    while (fscanf(file, "%d,%49[^,],%d", &warehouse->items[warehouse->itemCount].id, 
            warehouse->items[warehouse->itemCount].name, &warehouse->items[warehouse->itemCount].quantity) == 3) {
        warehouse->itemCount++;
    }
    fclose(file);
    printf("Data loaded successfully from warehouse_data.txt!\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Update Item\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Exit\n");
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
                displayItems(&warehouse);
                break;
            case 4:
                updateItem(&warehouse);
                break;
            case 5:
                saveToFile(&warehouse);
                break;
            case 6:
                loadFromFile(&warehouse);
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}