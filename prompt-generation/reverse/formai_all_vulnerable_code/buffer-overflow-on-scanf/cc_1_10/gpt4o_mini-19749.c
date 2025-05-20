//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char itemName[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int totalItems;
} Warehouse;

// Function prototypes
void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void viewItems(const Warehouse *warehouse);
void clearInputBuffer();

int main() {
    Warehouse warehouse;
    warehouse.totalItems = 0;

    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Items\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear newline from the buffer

        switch (choice) {
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
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->totalItems >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    fgets(newItem.itemName, sizeof(newItem.itemName), stdin);
    strtok(newItem.itemName, "\n"); // Remove newline character

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    clearInputBuffer(); // Clear newline from the buffer

    warehouse->items[warehouse->totalItems] = newItem;
    warehouse->totalItems++;
    printf("Item added successfully.\n");
}

void removeItem(Warehouse *warehouse) {
    char itemName[50];
    int found = 0;
    printf("Enter the name of the item to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    strtok(itemName, "\n"); // Remove newline character

    for (int i = 0; i < warehouse->totalItems; i++) {
        if (strcmp(warehouse->items[i].itemName, itemName) == 0) {
            found = 1;
            for (int j = i; j < warehouse->totalItems - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->totalItems--;
            printf("Item removed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Item not found.\n");
    }
}

void viewItems(const Warehouse *warehouse) {
    if (warehouse->totalItems == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nItems in the warehouse:\n");
    printf("-----------------------------------------------------------------\n");
    printf("| %-20s | %-8s | %-8s |\n", "Item Name", "Quantity", "Price");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < warehouse->totalItems; i++) {
        printf("| %-20s | %-8d | $%-7.2f |\n", warehouse->items[i].itemName, warehouse->items[i].quantity, warehouse->items[i].price);
    }
    printf("-----------------------------------------------------------------\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}