//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
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
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    warehouse[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void viewItems() {
    if (itemCount == 0) {
        printf("No items in warehouse.\n");
        return;
    }

    printf("\nWarehouse Items:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

void updateItem() {
    int id, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            found = 1;
            printf("Updating item ID %d:\n", id);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &warehouse[i].price);
            printf("Item updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void deleteItem() {
    int id, found = 0;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            found = 1;
            for (int j = i; j < itemCount - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void saveToFile() {
    FILE *file = fopen("warehouse.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d %s %d %.2f\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
    fclose(file);
    printf("Data saved to warehouse.txt successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("warehouse.txt", "r");
    if (file == NULL) {
        printf("No saved data found!\n");
        return;
    }
    itemCount = 0;
    while (fscanf(file, "%d %s %d %f", &warehouse[itemCount].id, warehouse[itemCount].name, &warehouse[itemCount].quantity, &warehouse[itemCount].price) != EOF) {
        itemCount++;
    }
    fclose(file);
    printf("Data loaded successfully! %d items restored.\n", itemCount);
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Save to File\n");
    printf("6. Load from File\n");
    printf("7. Exit\n");
}

int main() {
    int choice;

    loadFromFile();

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addItem(); break;
            case 2: viewItems(); break;
            case 3: updateItem(); break;
            case 4: deleteItem(); break;
            case 5: saveToFile(); break;
            case 6: loadFromFile(); break;
            case 7: 
                printf("Exiting warehouse management system...\n");
                exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}