//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
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
    int totalItems;
} Warehouse;

// Function prototypes
void addItem(Warehouse *warehouse);
void displayItems(Warehouse *warehouse);
void updateItem(Warehouse *warehouse);
void deleteItem(Warehouse *warehouse);
void saveToFile(Warehouse *warehouse);
void loadFromFile(Warehouse *warehouse);
void menu();

int main() {
    Warehouse warehouse;
    warehouse.totalItems = 0;

    loadFromFile(&warehouse);

    int choice;
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                displayItems(&warehouse);
                break;
            case 3:
                updateItem(&warehouse);
                break;
            case 4:
                deleteItem(&warehouse);
                break;
            case 5:
                saveToFile(&warehouse);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 6);

    return 0;
}

void menu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Save to File\n");
    printf("6. Exit\n");
}

void addItem(Warehouse *warehouse) {
    if (warehouse->totalItems >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);

    printf("Enter item name: ");
    scanf(" %[^\n]s", newItem.name); // Read string with spaces

    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    warehouse->items[warehouse->totalItems++] = newItem;
    printf("Item added successfully!\n");
}

void displayItems(Warehouse *warehouse) {
    if (warehouse->totalItems == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nItems in Warehouse:\n");
    printf("%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < warehouse->totalItems; i++) {
        printf("%-10d %-25s %-10d %-10.2f\n", 
               warehouse->items[i].id, 
               warehouse->items[i].name, 
               warehouse->items[i].quantity, 
               warehouse->items[i].price);
    }
}

void updateItem(Warehouse *warehouse) {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->totalItems; i++) {
        if (warehouse->items[i].id == id) {
            printf("Updating item %s (Current quantity: %d, price: %.2f)\n", 
                   warehouse->items[i].name, 
                   warehouse->items[i].quantity, 
                   warehouse->items[i].price);
            
            printf("Enter new quantity: ");
            scanf("%d", &warehouse->items[i].quantity);

            printf("Enter new price: ");
            scanf("%f", &warehouse->items[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found!\n", id);
}

void deleteItem(Warehouse *warehouse) {
    int id;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->totalItems; i++) {
        if (warehouse->items[i].id == id) {
            // Move the last item into the deleted item's space
            warehouse->items[i] = warehouse->items[warehouse->totalItems - 1];
            warehouse->totalItems--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found!\n", id);
}

void saveToFile(Warehouse *warehouse) {
    FILE *file = fopen("warehouse_data.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < warehouse->totalItems; i++) {
        fprintf(file, "%d;%s;%d;%.2f\n", 
                warehouse->items[i].id, 
                warehouse->items[i].name, 
                warehouse->items[i].quantity, 
                warehouse->items[i].price);
    }
    fclose(file);
    printf("Data saved to file successfully!\n");
}

void loadFromFile(Warehouse *warehouse) {
    FILE *file = fopen("warehouse_data.txt", "r");
    if (!file) {
        printf("No existing data found, starting fresh.\n");
        return;
    }

    while (!feof(file) && warehouse->totalItems < MAX_ITEMS) {
        Item item;
        fscanf(file, "%d;%49[^;];%d;%f\n", &item.id, item.name, &item.quantity, &item.price);
        warehouse->items[warehouse->totalItems++] = item;
    }
    fclose(file);
    printf("Data loaded from file successfully!\n");
}