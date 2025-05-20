//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int id;
    int quantity;
    double price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem(char *name, int id, int quantity, double price) {
    if (itemCount < MAX_ITEMS) {
        strcpy(inventory[itemCount].name, name);
        inventory[itemCount].id = id;
        inventory[itemCount].quantity = quantity;
        inventory[itemCount].price = price;
        itemCount++;
        printf("Item added to inventory: %s\n", name);
    } else {
        printf("Inventory is full, unable to add more items.\n");
    }
}

void displayInventory() {
    if (itemCount == 0) {
        printf("The inventory is currently empty, my dear Watson.\n");
        return;
    }
    printf("\nCurrent Inventory:\n");
    printf("------------------------------------------------\n");
    printf("ID\tItem Name\tQuantity\tPrice\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%-20s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("------------------------------------------------\n");
}

void findItem(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("Item found: %s | Quantity: %d | Price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Alas, the item with ID %d could not be found in our inventory.\n", id);
}

void updateItem(int id, int newQuantity) {
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            inventory[i].quantity = newQuantity;
            printf("Updated the quantity of %s to %d.\n", inventory[i].name, newQuantity);
            return;
        }
    }
    printf("I'm afraid that item ID %d does not exist in the records, Watson.\n", id);
}

void saveInventory(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file for saving inventory.\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
    printf("Inventory has been saved to %s, Watson.\n", filename);
}

void loadInventory(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file for loading inventory.\n");
        return;
    }
    while (fscanf(file, "%d,%49[^,],%d,%lf", &inventory[itemCount].id, inventory[itemCount].name, &inventory[itemCount].quantity, &inventory[itemCount].price) == 4) {
        itemCount++;
    }
    fclose(file);
    printf("Inventory has been loaded from %s.\n", filename);
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    int id, quantity;
    double price;

    do {
        printf("\n---- Sherlock Holmes Inventory System ----\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Find Item\n");
        printf("4. Update Item\n");
        printf("5. Save Inventory\n");
        printf("6. Load Inventory\n");
        printf("0. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add Item
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                printf("Enter item price: ");
                scanf("%lf", &price);
                addItem(name, id, quantity, price);
                break;
            case 2: // Display Inventory
                displayInventory();
                break;
            case 3: // Find Item
                printf("Enter item ID to find: ");
                scanf("%d", &id);
                findItem(id);
                break;
            case 4: // Update Item
                printf("Enter item ID to update: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateItem(id, quantity);
                break;
            case 5: // Save Inventory
                saveInventory("inventory.txt");
                break;
            case 6: // Load Inventory
                loadInventory("inventory.txt");
                break;
            case 0: // Exit
                printf("Thank you for using the Sherlock Holmes Inventory System. Farewell, Watson!\n");
                break;
            default:
                printf("That is not a valid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}