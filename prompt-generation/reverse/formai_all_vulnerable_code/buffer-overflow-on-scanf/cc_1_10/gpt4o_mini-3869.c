//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: detailed
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

void displayMenu() {
    printf("\n===== Warehouse Management System =====\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Update Item\n");
    printf("4. View All Items\n");
    printf("5. Exit\n");
    printf("========================================\n");
    printf("Select an option (1-5): ");
}

void addItem(Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = *count + 1; // Simple sequential ID
    printf("Enter item name: ");
    scanf(" %[^\n]", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    items[*count] = newItem;
    (*count)++;
    printf("Item added successfully!\n");
}

void removeItem(Item items[], int *count) {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *count; i++) {
        if (items[i].id == id) {
            items[i] = items[*count - 1]; // Replace with the last item
            (*count)--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void updateItem(Item items[], int count) {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("Updating item: %s\n", items[i].name);
            printf("Enter new item name: ");
            scanf(" %[^\n]", items[i].name);
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new item price: ");
            scanf("%f", &items[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void viewAllItems(Item items[], int count) {
    printf("\n=== Items in Warehouse ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n", 
                items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
    printf("===========================\n");
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &count);
                break;
            case 2:
                removeItem(items, &count);
                break;
            case 3:
                updateItem(items, count);
                break;
            case 4:
                viewAllItems(items, count);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}