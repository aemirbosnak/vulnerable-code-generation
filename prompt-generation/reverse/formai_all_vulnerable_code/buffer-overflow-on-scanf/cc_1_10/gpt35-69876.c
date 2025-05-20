//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the information of each item
typedef struct {
    int id;
    char name[100];
    int quantity;
    float price;
} item;

// Function to add an item to the inventory
void addItem(item inventory[], int *size) {
    int id, quantity;
    char name[100];
    float price;

    // Take input from user
    printf("Enter item ID: ");
    scanf("%d", &id);
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item quantity: ");
    scanf("%d", &quantity);
    printf("Enter item price: ");
    scanf("%f", &price);

    // Create a new item and add it to the inventory
    inventory[*size].id = id;
    strcpy(inventory[*size].name, name);
    inventory[*size].quantity = quantity;
    inventory[*size].price = price;

    printf("Item added successfully.\n");

    (*size)++;
}

// Function to search for an item in the inventory
void searchItem(item inventory[], int size) {
    int id;

    // Take input from user
    printf("Enter item ID to search for: ");
    scanf("%d", &id);

    // Search for the item
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == id) {
            printf("Item found!\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }

    printf("Item not found.\n");
}

// Function to update an item in the inventory
void updateItem(item inventory[], int size) {
    int id, quantity;
    char name[100];
    float price;

    // Take input from user
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    // Search for the item
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == id) {
            printf("Enter updated item name (press enter to skip): ");
            fflush(stdin);
            fgets(name, 100, stdin);
            if (strlen(name) > 0) {
                name[strlen(name) - 1] = '\0';
            }
            printf("Enter updated item quantity (press 0 to skip): ");
            scanf("%d", &quantity);
            printf("Enter updated item price (press 0 to skip): ");
            scanf("%f", &price);

            // Update the item
            if (strlen(name) > 0) {
                strcpy(inventory[i].name, name);
            }
            if (quantity > 0) {
                inventory[i].quantity = quantity;
            }
            if (price > 0) {
                inventory[i].price = price;
            }

            printf("Item updated successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

// Function to delete an item from the inventory
void deleteItem(item inventory[], int *size) {
    int id;

    // Take input from user
    printf("Enter item ID to delete: ");
    scanf("%d", &id);

    // Search for the item
    for (int i = 0; i < *size; i++) {
        if (inventory[i].id == id) {

            // Shift the elements to fill the gap
            for (int j = i; j < (*size - 1); j++) {
                inventory[j] = inventory[j + 1];
            }

            (*size)--;
            printf("Item deleted successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

// Function to display all the items in the inventory
void displayInventory(item inventory[], int size) {
    printf("Item ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    item inventory[100];
    int size = 0;
    int choice;

    do {
        printf("\nC Medical Store Management System\n");
        printf("----------------------------------\n");
        printf("1. Add Item\n");
        printf("2. Search Item\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Display Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &size);
                break;
            case 2:
                searchItem(inventory, size);
                break;
            case 3:
                updateItem(inventory, size);
                break;
            case 4:
                deleteItem(inventory, &size);
                break;
            case 5:
                displayInventory(inventory, size);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}