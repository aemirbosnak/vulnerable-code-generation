//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LEN 50

typedef struct {
    int id;
    char name[ITEM_NAME_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Inventory;

void initializeInventory(Inventory* inventory) {
    inventory->count = 0;
}

void addItem(Inventory* inventory, int id, const char* name, int quantity, float price) {
    if (inventory->count < MAX_ITEMS) {
        inventory->items[inventory->count].id = id;
        strncpy(inventory->items[inventory->count].name, name, ITEM_NAME_LEN);
        inventory->items[inventory->count].quantity = quantity;
        inventory->items[inventory->count].price = price;
        inventory->count++;
        printf("Item \"%s\" added successfully.\n", name);
    } else {
        printf("Inventory is full, cannot add more items.\n");
    }
}

void displayInventory(const Inventory* inventory) {
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("%d\t%-15s\t%d\t\t%.2f\n",
                inventory->items[i].id,
                inventory->items[i].name,
                inventory->items[i].quantity,
                inventory->items[i].price);
    }
}

void updateItemQuantity(Inventory* inventory, int id, int quantity) {
    for (int i = 0; i < inventory->count; i++) {
        if (inventory->items[i].id == id) {
            inventory->items[i].quantity += quantity;
            printf("Updated quantity for item \"%s\". New quantity: %d\n", 
                    inventory->items[i].name, 
                    inventory->items[i].quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void removeItem(Inventory* inventory, int id) {
    for (int i = 0; i < inventory->count; i++) {
        if (inventory->items[i].id == id) {
            printf("Removing item \"%s\" from inventory.\n", inventory->items[i].name);
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->count--;
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void saveInventoryToFile(const Inventory* inventory, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < inventory->count; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n",
                inventory->items[i].id,
                inventory->items[i].name,
                inventory->items[i].quantity,
                inventory->items[i].price);
    }
    fclose(file);
    printf("Inventory saved to %s.\n", filename);
}

void loadInventoryFromFile(Inventory* inventory, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    while (fscanf(file, "%d,%49[^,],%d,%f\n", 
                  &inventory->items[inventory->count].id,
                  inventory->items[inventory->count].name,
                  &inventory->items[inventory->count].quantity,
                  &inventory->items[inventory->count].price) == 4) {
        inventory->count++;
        if (inventory->count >= MAX_ITEMS) {
            break;
        }
    }
    fclose(file);
    printf("Inventory loaded from %s. Total items: %d\n", filename, inventory->count);
}

int main() {
    Inventory inventory;
    initializeInventory(&inventory);

    int choice, id, quantity;
    char name[ITEM_NAME_LEN];
    float price;
    const char* filename = "inventory.txt";

    loadInventoryFromFile(&inventory, filename);

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. View Inventory\n");
        printf("3. Update Item Quantity\n");
        printf("4. Remove Item\n");
        printf("5. Save to File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                printf("Enter item price: ");
                scanf("%f", &price);
                addItem(&inventory, id, name, quantity, price);
                break;
            case 2:
                displayInventory(&inventory);
                break;
            case 3:
                printf("Enter item ID to update quantity: ");
                scanf("%d", &id);
                printf("Enter quantity to add/subtract: ");
                scanf("%d", &quantity);
                updateItemQuantity(&inventory, id, quantity);
                break;
            case 4:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                removeItem(&inventory, id);
                break;
            case 5:
                saveInventoryToFile(&inventory, filename);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}