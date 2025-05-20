//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int item_count = 0;

// Function prototypes
void addItem();
void viewItems();
void updateItem();
void removeItem();
void displayMenu();
void clearInputBuffer();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-%d): ", 5);
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the newline from buffer

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                printf("Exiting warehouse management system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Update Item\n");
    printf("4. Remove Item\n");
    printf("5. Exit\n");
}

void addItem() {
    if (item_count >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    clearInputBuffer();
    printf("Enter item name: ");
    fgets(newItem.name, NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Remove newline
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    inventory[item_count] = newItem;
    item_count++;
    printf("Item added successfully!\n");
}

void viewItems() {
    if (item_count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    printf("\n--- Inventory Items ---\n");
    for (int i = 0; i < item_count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
               inventory[i].id, inventory[i].name, 
               inventory[i].quantity, inventory[i].price);
    }
}

void updateItem() {
    int id, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating Item - ID: %d\n", id);
            printf("Enter new name: ");
            clearInputBuffer();
            fgets(inventory[i].name, NAME_LENGTH, stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = '\0'; // Remove newline
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Item updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void removeItem() {
    int id, found = 0;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < item_count - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift items left
            }
            item_count--;
            printf("Item removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void clearInputBuffer() {
    while(getchar() != '\n');
}