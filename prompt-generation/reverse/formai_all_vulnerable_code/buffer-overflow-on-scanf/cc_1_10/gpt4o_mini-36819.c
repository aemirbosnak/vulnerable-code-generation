//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define ITEM_NAME_LENGTH 20

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

void addItem(Item *inventory, int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", inventory[*count].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[*count].price);
    (*count)++;
    printf("Item added successfully!\n");
}

void displayItems(Item *inventory, int count) {
    if (count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    
    printf("\nInventory Items:\n");
    for (int i = 0; i < count; i++) {
        printf("Item %d: %s, Quantity: %d, Price: %.2f\n", 
                i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void deleteItem(Item *inventory, int *count) {
    if (*count == 0) {
        printf("No items to delete.\n");
        return;
    }

    char name[ITEM_NAME_LENGTH];
    printf("Enter item name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Item '%s' deleted successfully!\n", name);
            return;
        }
    }
    
    printf("Item '%s' not found.\n", name);
}

void freeInventory(Item *inventory) {
    free(inventory);
}

int main() {
    Item *inventory = (Item *)malloc(MAX_ITEMS * sizeof(Item));
    if (!inventory) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    int count = 0;
    int choice;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Delete Item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &count);
                break;
            case 2:
                displayItems(inventory, count);
                break;
            case 3:
                deleteItem(inventory, &count);
                break;
            case 4:
                freeInventory(inventory);
                printf("Exiting program.\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    free(inventory);
    return 0;
}