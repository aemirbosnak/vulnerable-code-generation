//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item in the inventory
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Function prototypes
void addItem(Item *inventory, int *count);
void displayInventory(Item *inventory, int count);
void findItem(Item *inventory, int count);
void removeItem(Item *inventory, int *count);
void saveInventory(Item *inventory, int count);
void loadInventory(Item *inventory, int *count);

int main() {
    Item inventory[100]; // Setting max items to 100
    int count = 0; // Count of items in the inventory
    int choice;
    
    // Load existing inventory from the file
    loadInventory(inventory, &count);
    
    do {
        printf("\n=== The Grand Inventory of Items ===\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Find Item\n");
        printf("4. Remove Item\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
        printf("Choose thy fate: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                findItem(inventory, count);
                break;
            case 4:
                removeItem(inventory, &count);
                break;
            case 5:
                saveInventory(inventory, count);
                printf("Inventory hath been saved to the scrolls of time.\n");
                break;
            case 6:
                printf("Farewell, brave merchant! Till we meet again.\n");
                break;
            default:
                printf("Alas! That is not a valid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

void addItem(Item *inventory, int *count) {
    if (*count < 100) {
        printf("Enter the name of the item: ");
        scanf("%s", inventory[*count].name);
        printf("Enter the quantity of the item: ");
        scanf("%d", &inventory[*count].quantity);
        printf("Enter the price of the item: ");
        scanf("%f", &inventory[*count].price);
        (*count)++;
        printf("Item successfully added to the inventory.\n");
    } else {
        printf("The inventory is full, cannot add more items!\n");
    }
}

void displayInventory(Item *inventory, int count) {
    if (count == 0) {
        printf("The inventory is empty, nothing to display.\n");
    } else {
        printf("\nThe Splendid Inventory:\n");
        for (int i = 0; i < count; i++) {
            printf("Item %d: %s - Quantity: %d, Price: %.2f gold\n", 
                   i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

void findItem(Item *inventory, int count) {
    char name[50];
    printf("Enter the name of the item to search for: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Item found: %s - Quantity: %d, Price: %.2f gold\n", 
                   inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Alas! The item is not in the inventory.\n");
}

void removeItem(Item *inventory, int *count) {
    char name[50];
    printf("Enter the name of the item to remove: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Shift items to the left
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("The item hath been removed from the inventory.\n");
            return;
        }
    }
    printf("Alas! The item is not in the inventory. Hence, it cannot be removed.\n");
}

void saveInventory(Item *inventory, int count) {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Could not open file to save inventory!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
}

void loadInventory(Item *inventory, int *count) {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("No prior inventory found.\n");
        return;
    }
    while (fscanf(file, "%s %d %f", inventory[*count].name, &inventory[*count].quantity, &inventory[*count].price) != EOF) {
        (*count)++;
    }
    fclose(file);
}