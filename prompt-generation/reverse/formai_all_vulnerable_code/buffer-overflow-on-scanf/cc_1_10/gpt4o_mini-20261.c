//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    float price;
    int quantity;
} Item;

void displayMenu() {
    printf("\n--- Inventory Management System ---\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Save Inventory to File\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void addItem(Item *items, int *itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = *itemCount + 1;
    
    printf("Enter the name of the item: ");
    scanf(" %[^\n]", newItem.name);
    
    printf("Enter the description of the item: ");
    scanf(" %[^\n]", newItem.description);
    
    printf("Enter the price of the item: ");
    scanf("%f", &newItem.price);
    
    printf("Enter the quantity of the item: ");
    scanf("%d", &newItem.quantity);
    
    items[*itemCount] = newItem;
    (*itemCount)++;
    printf("Item added successfully!\n");
}

void displayItems(Item *items, int itemCount) {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }
    
    printf("\n--- Inventory Items ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d\n", items[i].id);
        printf("Name: %s\n", items[i].name);
        printf("Description: %s\n", items[i].description);
        printf("Price: $%.2f\n", items[i].price);
        printf("Quantity: %d\n", items[i].quantity);
        printf("-----------------------\n");
    }
}

void saveToFile(Item *items, int itemCount, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d,%s,%s,%.2f,%d\n", items[i].id,
                items[i].name, items[i].description, items[i].price,
                items[i].quantity);
    }
    
    fclose(file);
    printf("Inventory saved to %s\n", filename);
}

int main() {
    Item *inventory = (Item *)malloc(MAX_ITEMS * sizeof(Item));
    int itemCount = 0;
    int choice;

    if (inventory == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &itemCount);
                break;
            case 2:
                displayItems(inventory, itemCount);
                break;
            case 3:
                saveToFile(inventory, itemCount, "inventory.txt");
                break;
            case 4:
                free(inventory);
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free(inventory);
    return 0;
}