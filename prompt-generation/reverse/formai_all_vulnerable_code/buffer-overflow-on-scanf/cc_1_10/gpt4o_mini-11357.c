//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for warehouse items
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

// Function prototypes
void addItem(Item **inventory, int *count);
void viewInventory(Item *inventory, int count);
void updateItem(Item *inventory, int count);
void deleteItem(Item **inventory, int *count);
void freeInventory(Item *inventory);

// Main Function
int main() {
    Item *inventory = NULL;
    int count = 0;
    int choice;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. View Inventory\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&inventory, &count);
                break;
            case 2:
                viewInventory(inventory, count);
                break;
            case 3:
                updateItem(inventory, count);
                break;
            case 4:
                deleteItem(&inventory, &count);
                break;
            case 5:
                freeInventory(inventory);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to add an item to the inventory
void addItem(Item **inventory, int *count) {
    *inventory = realloc(*inventory, (*count + 1) * sizeof(Item));
    if (*inventory == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    Item *newItem = &(*inventory)[*count];
    printf("Enter item ID: ");
    scanf("%d", &newItem->id);
    printf("Enter item name: ");
    scanf(" %[^\n]", newItem->name); // Read string with spaces
    printf("Enter item quantity: ");
    scanf("%d", &newItem->quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem->price);
    
    (*count)++;
    printf("Item added successfully!\n");
}

// Function to view items in the inventory
void viewInventory(Item *inventory, int count) {
    if (count == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("\nInventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to update an item's details
void updateItem(Item *inventory, int count) {
    int id, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Enter new name: ");
            scanf(" %[^\n]", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Item updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found!\n", id);
    }
}

// Function to delete an item from the inventory
void deleteItem(Item **inventory, int *count) {
    int id, found = -1;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if ((*inventory)[i].id == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int i = found; i < *count - 1; i++) {
            (*inventory)[i] = (*inventory)[i + 1]; // Shift items left
        }
        *inventory = realloc(*inventory, (*count - 1) * sizeof(Item));
        (*count)--;
        printf("Item deleted successfully!\n");
    } else {
        printf("Item with ID %d not found!\n", id);
    }
}

// Function to free allocated memory for inventory
void freeInventory(Item *inventory) {
    free(inventory);
}