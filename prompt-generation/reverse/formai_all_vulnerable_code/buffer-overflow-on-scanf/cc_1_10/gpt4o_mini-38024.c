//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: all-encompassing
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

void addItem(Item **inventory, int *currentItemCount);
void removeItem(Item *inventory, int *currentItemCount);
void displayInventory(Item *inventory, int currentItemCount);
void saveInventoryToFile(Item *inventory, int currentItemCount);
void loadInventoryFromFile(Item **inventory, int *currentItemCount);

int main() {
    Item *inventory = malloc(MAX_ITEMS * sizeof(Item));
    int currentItemCount = 0;
    int choice;

    loadInventoryFromFile(&inventory, &currentItemCount);

    while(1) {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Save Inventory to File\n");
        printf("5. Load Inventory from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 6.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch(choice) {
            case 1:
                addItem(&inventory, &currentItemCount);
                break;
            case 2:
                removeItem(inventory, &currentItemCount);
                break;
            case 3:
                displayInventory(inventory, currentItemCount);
                break;
            case 4:
                saveInventoryToFile(inventory, currentItemCount);
                break;
            case 5:
                loadInventoryFromFile(&inventory, &currentItemCount);
                break;
            case 6:
                free(inventory);
                printf("Exiting program... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
}

void addItem(Item **inventory, int *currentItemCount) {
    if (*currentItemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    (*inventory)[*currentItemCount] = newItem;
    (*currentItemCount)++;
    printf("Item '%s' added successfully!\n", newItem.name);
}

void removeItem(Item *inventory, int *currentItemCount) {
    if (*currentItemCount == 0) {
        printf("No items in inventory to remove.\n");
        return;
    }

    char itemName[NAME_LENGTH];
    printf("Enter item name to remove: ");
    scanf("%s", itemName);

    for (int i = 0; i < *currentItemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            for (int j = i; j < *currentItemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*currentItemCount)--;
            printf("Item '%s' removed successfully!\n", itemName);
            return;
        }
    }
    printf("Item '%s' not found in inventory.\n", itemName);
}

void displayInventory(Item *inventory, int currentItemCount) {
    if (currentItemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\n---- Inventory ----\n");
    for (int i = 0; i < currentItemCount; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
}

void saveInventoryToFile(Item *inventory, int currentItemCount) {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < currentItemCount; i++) {
        fprintf(file, "%s %d %.2f\n", 
                inventory[i].name, 
                inventory[i].quantity, 
                inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved to 'inventory.txt'.\n");
}

void loadInventoryFromFile(Item **inventory, int *currentItemCount) {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("Could not open file for reading. Starting with an empty inventory.\n");
        return;
    }

    while (fscanf(file, "%s %d %f", 
                  (*inventory)[*currentItemCount].name, 
                  &(*inventory)[*currentItemCount].quantity, 
                  &(*inventory)[*currentItemCount].price) == 3) {
        (*currentItemCount)++;
    }
    fclose(file);
    printf("Inventory loaded from 'inventory.txt'.\n");
}