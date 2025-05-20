//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int item_count;
} Warehouse;

// Function declarations
void initializeWarehouse(Warehouse *warehouse);
void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void displayItems(const Warehouse *warehouse);
void saveToFile(const Warehouse *warehouse, const char *filename);
void loadFromFile(Warehouse *warehouse, const char *filename);
double calculateTotalValue(const Warehouse *warehouse);
void sortItems(Warehouse *warehouse);

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    loadFromFile(&warehouse, "warehouse.txt");

    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Calculate Total Value\n");
        printf("5. Sort Items by Name\n");
        printf("6. Save to File\n");
        printf("7. Load from File\n");
        printf("0. Exit\n");
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
                printf("Total Warehouse Value: $%.2f\n", calculateTotalValue(&warehouse));
                break;
            case 5:
                sortItems(&warehouse);
                printf("Items sorted by name.\n");
                break;
            case 6:
                saveToFile(&warehouse, "warehouse.txt");
                break;
            case 7:
                loadFromFile(&warehouse, "warehouse.txt");
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->item_count = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->item_count >= MAX_ITEMS) {
        printf("Cannot add more items. Warehouse is full.\n");
        return;
    }
    Item *item = &warehouse->items[warehouse->item_count];
    
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter item price: ");
    scanf("%lf", &item->price);
    warehouse->item_count++;
    printf("Item added successfully.\n");
}

void removeItem(Warehouse *warehouse) {
    char name[MAX_NAME_LENGTH];
    printf("Enter item name to remove: ");
    scanf("%s", name);
    
    for (int i = 0; i < warehouse->item_count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->item_count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->item_count--;
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->item_count == 0) {
        printf("No items in warehouse.\n");
        return;
    }
    printf("\nItems in Warehouse:\n");
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < warehouse->item_count; i++) {
        printf("%s\t%d\t\t$%.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

double calculateTotalValue(const Warehouse *warehouse) {
    double total_value = 0.0;
    for (int i = 0; i < warehouse->item_count; i++) {
        total_value += warehouse->items[i].quantity * warehouse->items[i].price;
    }
    return total_value;
}

void saveToFile(const Warehouse *warehouse, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < warehouse->item_count; i++) {
        fprintf(file, "%s %d %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
    fclose(file);
    printf("Warehouse saved to file successfully.\n");
}

void loadFromFile(Warehouse *warehouse, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading. Starting with an empty warehouse.\n");
        return;
    }
    
    warehouse->item_count = 0;
    while (fscanf(file, "%s %d %lf", warehouse->items[warehouse->item_count].name,
                  &warehouse->items[warehouse->item_count].quantity, 
                  &warehouse->items[warehouse->item_count].price) == 3) {
        warehouse->item_count++;
    }
    fclose(file);
    printf("Warehouse loaded from file successfully.\n");
}

void sortItems(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->item_count - 1; i++) {
        for (int j = i + 1; j < warehouse->item_count; j++) {
            if (strcmp(warehouse->items[i].name, warehouse->items[j].name) > 0) {
                Item temp = warehouse->items[i];
                warehouse->items[i] = warehouse->items[j];
                warehouse->items[j] = temp;
            }
        }
    }
}