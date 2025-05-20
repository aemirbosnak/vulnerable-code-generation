//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
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

void printMenu() {
    printf("\n*** Shape-Shifting Product Inventory System ***\n");
    printf("1. Add Item\n");
    printf("2. Update Item\n");
    printf("3. Delete Item\n");
    printf("4. List Items\n");
    printf("5. Search Item\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

void addItem(Item items[], int *itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", items[*itemCount].name);
    printf("Enter quantity: ");
    scanf("%d", &items[*itemCount].quantity);
    printf("Enter price: ");
    scanf("%f", &items[*itemCount].price);
    (*itemCount)++;
    printf("Item added successfully!\n");
}

void updateItem(Item items[], int itemCount) {
    char name[NAME_LENGTH];
    printf("Enter item name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Updating item: %s\n", items[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &items[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void deleteItem(Item items[], int *itemCount) {
    char name[NAME_LENGTH];
    printf("Enter item name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < *itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i] = items[--(*itemCount)]; // Remove item by shifting
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void listItems(Item items[], int itemCount) {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void searchItem(Item items[], int itemCount) {
    char name[NAME_LENGTH];
    printf("Enter item name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Item found: %s, Quantity: %d, Price: %.2f\n", items[i].name, items[i].quantity, items[i].price);
            return;
        }
    }
    printf("Item not found!\n");
}

int main() {
    Item items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(items, &itemCount);
                break;
            case 2:
                updateItem(items, itemCount);
                break;
            case 3:
                deleteItem(items, &itemCount);
                break;
            case 4:
                listItems(items, itemCount);
                break;
            case 5:
                searchItem(items, itemCount);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}