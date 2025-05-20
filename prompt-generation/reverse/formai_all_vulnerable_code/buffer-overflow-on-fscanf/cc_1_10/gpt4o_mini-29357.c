//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse* warehouse) {
    warehouse->itemCount = 0;
    printf("Warehouse initialized. Ready to manage your inventory.\n");
}

void addItem(Warehouse* warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    newItem.id = warehouse->itemCount + 1;

    printf("Enter item name: ");
    scanf("%s", newItem.name);
    
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    warehouse->items[warehouse->itemCount] = newItem;
    warehouse->itemCount++;
    printf("Item '%s' added successfully!\n", newItem.name);
}

void viewItems(const Warehouse* warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nCurrent Items in Warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        Item item = warehouse->items[i];
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
               item.id, item.name, item.quantity, item.price);
    }
}

void updateItem(Warehouse* warehouse) {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > warehouse->itemCount) {
        printf("Invalid item ID!\n");
        return;
    }

    Item* item = &warehouse->items[id - 1];
    printf("Updating item '%s'.\n", item->name);
    
    printf("Enter new quantity: ");
    scanf("%d", &item->quantity);
    
    printf("Enter new price: ");
    scanf("%f", &item->price);
    
    printf("Item '%s' updated successfully!\n", item->name);
}

void removeItem(Warehouse* warehouse) {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > warehouse->itemCount) {
        printf("Invalid item ID!\n");
        return;
    }

    for (int i = id - 1; i < warehouse->itemCount - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->itemCount--;
    printf("Item with ID %d removed successfully!\n", id);
}

void saveToFile(const Warehouse* warehouse) {
    FILE *file = fopen("warehouse_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        fprintf(file, "%d %s %d %.2f\n",
                warehouse->items[i].id,
                warehouse->items[i].name,
                warehouse->items[i].quantity,
                warehouse->items[i].price);
    }
    
    fclose(file);
    printf("Warehouse data saved to 'warehouse_data.txt'.\n");
}

void loadFromFile(Warehouse* warehouse) {
    FILE *file = fopen("warehouse_data.txt", "r");
    if (file == NULL) {
        printf("No previous data found.\n");
        return;
    }

    warehouse->itemCount = 0;
    while (fscanf(file, "%d %s %d %f",
                  &warehouse->items[warehouse->itemCount].id,
                  warehouse->items[warehouse->itemCount].name,
                  &warehouse->items[warehouse->itemCount].quantity,
                  &warehouse->items[warehouse->itemCount].price) != EOF) {
        warehouse->itemCount++;
    }
    
    fclose(file);
    printf("Warehouse data loaded successfully.\n");
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Update Item\n");
    printf("4. Remove Item\n");
    printf("5. Save Data to File\n");
    printf("6. Load Data from File\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    loadFromFile(&warehouse);

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                viewItems(&warehouse);
                break;
            case 3:
                updateItem(&warehouse);
                break;
            case 4:
                removeItem(&warehouse);
                break;
            case 5:
                saveToFile(&warehouse);
                break;
            case 6:
                loadFromFile(&warehouse);
                break;
            case 7:
                printf("Exiting the program. Have a great day!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}