//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50
#define LOCATION_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    char location[LOCATION_LENGTH];
} Item;

void addItem(Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }
    
    Item newItem;
    newItem.id = *count + 1; // ID starts from 1
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item location: ");
    scanf("%s", newItem.location);
    
    items[*count] = newItem;
    (*count)++;
    
    printf("Item added successfully! ID: %d\n", newItem.id);
}

void viewItems(Item items[], int count) {
    if (count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nList of Items in Warehouse:\n");
    printf("ID\tName\tQuantity\tLocation\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%s\n", items[i].id, items[i].name, items[i].quantity, items[i].location);
    }
}

void updateItem(Item items[], int count) {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > count) {
        printf("Item with ID %d does not exist.\n", id);
        return;
    }

    printf("Updating item ID: %d\n", id);
    printf("Enter new item name: ");
    scanf("%s", items[id - 1].name);
    printf("Enter new item quantity: ");
    scanf("%d", &items[id - 1].quantity);
    printf("Enter new item location: ");
    scanf("%s", items[id - 1].location);
    
    printf("Item updated successfully!\n");
}

void deleteItem(Item items[], int *count) {
    int id;
    printf("Enter the ID of the item to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > *count) {
        printf("Item with ID %d does not exist.\n", id);
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        items[i] = items[i + 1];
    }
    
    (*count)--;
    printf("Item deleted successfully!\n");
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Item items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &itemCount);
                break;
            case 2:
                viewItems(items, itemCount);
                break;
            case 3:
                updateItem(items, itemCount);
                break;
            case 4:
                deleteItem(items, &itemCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}