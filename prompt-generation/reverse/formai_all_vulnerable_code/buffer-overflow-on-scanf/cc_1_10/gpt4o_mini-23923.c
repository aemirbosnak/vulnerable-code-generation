//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Can't add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = itemCount + 1; // Simple incremental ID assignment

    printf("Enter the name of the item: ");
    scanf(" %[^\n]", newItem.name);
    
    printf("Enter the quantity of the item: ");
    scanf("%d", &newItem.quantity);
    
    printf("Enter the price of the item: ");
    scanf("%f", &newItem.price);

    warehouse[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully! ID: %d\n", newItem.id);
}

void updateItem() {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > itemCount) {
        printf("Item not found!\n");
        return;
    }

    Item* item = &warehouse[id - 1]; // Adjust for 0-based index
    printf("Updating Item ID: %d\n", item->id);
    printf("Current Name: %s\n", item->name);
    printf("Enter new name (or press enter to keep the same): ");
    char newName[NAME_LENGTH];
    scanf(" %[^\n]", newName);
    
    if (strlen(newName) > 0) {
        strcpy(item->name, newName);
    }

    printf("Current Quantity: %d\n", item->quantity);
    printf("Enter new quantity (or -1 to keep the same): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    
    if (newQuantity != -1) {
        item->quantity = newQuantity;
    }

    printf("Current Price: %.2f\n", item->price);
    printf("Enter new price (or -1 to keep the same): ");
    float newPrice;
    scanf("%f", &newPrice);
    
    if (newPrice != -1) {
        item->price = newPrice;
    }

    printf("Item updated successfully!\n");
}

void deleteItem() {
    int id;
    printf("Enter the ID of the item to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > itemCount) {
        printf("Item not found!\n");
        return;
    }

    for (int i = id - 1; i < itemCount - 1; i++) {
        warehouse[i] = warehouse[i + 1]; // Shift items left
    }
    
    itemCount--;
    printf("Item deleted successfully!\n");
}

void listItems() {
    if (itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nWarehouse Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
    printf("----------------------------------------------\n");
}

void displayMenu() {
    printf("\nWarehouse Management System:\n");
    printf("1. Add Item\n");
    printf("2. Update Item\n");
    printf("3. Delete Item\n");
    printf("4. List Items\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    while (1) {
        displayMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                deleteItem();
                break;
            case 4:
                listItems();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}