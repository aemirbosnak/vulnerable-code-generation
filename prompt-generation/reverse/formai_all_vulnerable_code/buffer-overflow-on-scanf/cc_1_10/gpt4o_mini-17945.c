//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse *warehouse, char *name, int quantity, float price) {
    if (warehouse->itemCount < MAX_ITEMS) {
        strcpy(warehouse->items[warehouse->itemCount].name, name);
        warehouse->items[warehouse->itemCount].quantity = quantity;
        warehouse->items[warehouse->itemCount].price = price;
        warehouse->itemCount++;
        printf("Item %s added successfully!\n", name);
    } else {
        printf("Warehouse is full! Cannot add more items.\n");
    }
}

void listItems(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nItems in the Warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", 
               warehouse->items[i].name, 
               warehouse->items[i].quantity, 
               warehouse->items[i].price);
    }
}

void updateItem(Warehouse *warehouse, char *name, int newQuantity) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity = newQuantity;
            printf("Updated %s quantity to %d.\n", name, newQuantity);
            return;
        }
    }
    printf("Item %s not found in the warehouse.\n", name);
}

void deleteItem(Warehouse *warehouse, char *name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            printf("Item %s deleted successfully!\n", name);
            return;
        }
    }
    printf("Item %s not found in the warehouse.\n", name);
}

void saveToFile(Warehouse *warehouse) {
    FILE *file = fopen("warehouse_data.txt", "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        fprintf(file, "%s,%d,%.2f\n", 
                warehouse->items[i].name, 
                warehouse->items[i].quantity, 
                warehouse->items[i].price);
    }
    fclose(file);
    printf("Warehouse data saved to file!\n");
}

void loadFromFile(Warehouse *warehouse) {
    FILE *file = fopen("warehouse_data.txt", "r");
    if (file == NULL) {
        printf("No saved file found or could not open the file for reading.\n");
        return;
    }
    
    warehouse->itemCount = 0;
    while (fscanf(file, "%[^,],%d,%f\n", 
                  warehouse->items[warehouse->itemCount].name, 
                  &warehouse->items[warehouse->itemCount].quantity, 
                  &warehouse->items[warehouse->itemCount].price) != EOF) {
        warehouse->itemCount++;
    }
    fclose(file);
    printf("Warehouse data loaded from file!\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    loadFromFile(&warehouse);

    int choice;
    char name[NAME_LENGTH];
    int quantity;
    float price;

    do {
        printf("\nWarehouse Management System Menu:\n");
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Save Data to File\n");
        printf("6. Load Data from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                printf("Enter item price: ");
                scanf("%f", &price);
                addItem(&warehouse, name, quantity, price);
                break;
            case 2:
                listItems(&warehouse);
                break;
            case 3:
                printf("Enter item name to update: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateItem(&warehouse, name, quantity);
                break;
            case 4:
                printf("Enter item name to delete: ");
                scanf("%s", name);
                deleteItem(&warehouse, name);
                break;
            case 5:
                saveToFile(&warehouse);
                break;
            case 6:
                loadFromFile(&warehouse);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 7);

    return 0;
}