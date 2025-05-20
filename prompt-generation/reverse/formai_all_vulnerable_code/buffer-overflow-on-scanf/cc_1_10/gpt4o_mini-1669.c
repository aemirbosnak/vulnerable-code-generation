//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char itemName[NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.itemName);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    warehouse->items[warehouse->itemCount] = newItem;
    warehouse->itemCount++;
    printf("Item added successfully!\n");
}

void removeItem(Warehouse *warehouse) {
    char itemName[NAME_LENGTH];
    printf("Enter item name to remove: ");
    scanf("%s", itemName);
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].itemName, itemName) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->itemCount - 1]; // Replace with last item
            warehouse->itemCount--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void viewItems(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse!\n");
        return;
    }
    printf("Items in the warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Name: %s, Quantity: %d, Price: $%.2f\n", 
               warehouse->items[i].itemName, 
               warehouse->items[i].quantity, 
               warehouse->items[i].price);
    }
}

void updateQuantity(Warehouse *warehouse) {
    char itemName[NAME_LENGTH];
    printf("Enter item name to update quantity: ");
    scanf("%s", itemName);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].itemName, itemName) == 0) {
            int newQuantity;
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            warehouse->items[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void shiftShapeMenu() {
    printf("\nChoose a shape to represent your items in the warehouse:\n");
    printf("1. Square\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("You have chosen a Square to represent your items.\n");
            break;
        case 2:
            printf("You have chosen a Circle to represent your items.\n");
            break;
        case 3:
            printf("You have chosen a Triangle to represent your items.\n");
            break;
        default:
            printf("Invalid choice! Defaulting to Square.\n");
            break;
    }
}

int main() {
    Warehouse warehouse = {.itemCount = 0};
    int option;
    
    while (1) {
        printf("\n--- Warehouse Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Items\n");
        printf("4. Update Item Quantity\n");
        printf("5. Shape Menu\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                removeItem(&warehouse);
                break;
            case 3:
                viewItems(&warehouse);
                break;
            case 4:
                updateQuantity(&warehouse);
                break;
            case 5:
                shiftShapeMenu();
                break;
            case 6:
                printf("Exiting the Warehouse Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    }
    
    return 0;
}