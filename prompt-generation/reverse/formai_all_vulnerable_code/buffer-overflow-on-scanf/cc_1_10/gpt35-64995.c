//FormAI DATASET v1.0 Category: Product Inventory System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 1000

// Item structure for product inventory
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Item;

// Global array of items
Item items[MAX_ITEMS];
int itemCount = 0;

// Add item to inventory
void addItem(Item item) {
    items[itemCount++] = item;
    printf("Item added successfully.\n");
}

// Update item in inventory
void updateItem(int id, Item item) {
    for (int i = 0; i < itemCount; i++) {
        if (items[i].id == id) {
            items[i] = item;
            printf("Item with ID '%d' updated successfully.\n", id);
            return;
        }
    }
    printf("Item with ID '%d' not found.\n", id);
}

// Remove item from inventory
void removeItem(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (items[i].id == id) {
            for (int j = i; j < itemCount - 1; j++) {
                items[j] = items[j+1];
            }
            itemCount--;
            printf("Item with ID '%d' removed successfully.\n", id);
            return;
        }
    }
    printf("Item with ID '%d' not found.\n", id);
}

// Get item from inventory by ID
Item getItem(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (items[i].id == id) {
            return items[i];
        }
    }
    Item emptyItem;
    emptyItem.id = -1;
    return emptyItem;
}

// Display all items in inventory
void displayItems() {
    printf("Inventory List\n");
    printf("--------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d   Name: %s   Price: %.2f   Quantity: %d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
    }
    printf("--------------\n");
}

int main() {
    int choice = 0;
    Item item;
    int id;
    
    printf("Product Inventory System\n");
    printf("------------------------\n");
    
    do {
        printf("\n1. Add item\n");
        printf("2. Update item\n");
        printf("3. Remove item\n");
        printf("4. Get item by ID\n");
        printf("5. Display all items\n");
        printf("6. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter item ID: ");
                scanf("%d", &item.id);
                printf("Enter item name: ");
                scanf("%s", item.name);
                printf("Enter item price: ");
                scanf("%f", &item.price);
                printf("Enter item quantity: ");
                scanf("%d", &item.quantity);
                addItem(item);
                break;
            case 2:
                printf("\nEnter item ID to update: ");
                scanf("%d", &id);
                item = getItem(id);
                if (item.id != -1) {
                    printf("Enter new item name (leave blank to keep existing): ");
                    scanf("%s", item.name);
                    printf("Enter new item price (leave blank to keep existing): ");
                    scanf("%f", &item.price);
                    printf("Enter new item quantity (leave blank to keep existing): ");
                    scanf("%d", &item.quantity);
                    updateItem(id, item);
                } else {
                    printf("Item with ID '%d' not found.\n", id);
                }
                break;
            case 3:
                printf("\nEnter item ID to remove: ");
                scanf("%d", &id);
                removeItem(id);
                break;
            case 4:
                printf("\nEnter item ID to get: ");
                scanf("%d", &id);
                item = getItem(id);
                if (item.id != -1) {
                    printf("ID: %d   Name: %s   Price: %.2f   Quantity: %d\n", item.id, item.name, item.price, item.quantity);
                } else {
                    printf("Item with ID '%d' not found.\n", id);
                }
                break;
            case 5:
                displayItems();
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}