//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store data
typedef struct MedicalStore {
    char name[50];
    char address[100];
    char phoneNumber[20];
    char email[50];
    int inventory[100];
    int quantity[100];
    int totalItems;
} MedicalStore;

// Create a function to add an item to the inventory
void addItem(MedicalStore *store) {
    // Allocate memory for the new item
    store->inventory[store->totalItems] = (char *)malloc(50);
    store->quantity[store->totalItems] = 0;

    // Get the item name, address, and quantity
    printf("Enter item name: ");
    scanf("%s", store->inventory[store->totalItems]);

    printf("Enter item address: ");
    scanf("%s", store->address);

    printf("Enter item quantity: ");
    scanf("%d", &store->quantity[store->totalItems]);

    // Increment the total items
    store->totalItems++;
}

// Create a function to remove an item from the inventory
void removeItem(MedicalStore *store) {
    // Get the item name
    char itemName[50];
    printf("Enter item name: ");
    scanf("%s", itemName);

    // Find the item to remove
    int i = 0;
    for (i = 0; i < store->totalItems; i++) {
        if (strcmp(store->inventory[i], itemName) == 0) {
            // Free the item memory
            free(store->inventory[i]);

            // Decrement the total items
            store->totalItems--;

            // Move items down to fill the gap
            for (int j = i; j < store->totalItems; j++) {
                store->inventory[j] = store->inventory[j + 1];
                store->quantity[j] = store->quantity[j + 1];
            }

            printf("Item removed successfully.\n");
            break;
        }
    }

    if (i == store->totalItems) {
        printf("Item not found.\n");
    }
}

// Create a function to display the inventory
void displayInventory(MedicalStore *store) {
    // Print the inventory items
    printf("Inventory:\n");
    for (int i = 0; i < store->totalItems; i++) {
        printf("%s - %d\n", store->inventory[i], store->quantity[i]);
    }
}

// Main function
int main() {
    // Create a medical store
    MedicalStore store;
    store.totalItems = 0;

    // Loop until the user chooses to exit
    int choice;
    printf("Welcome to the Medical Store Management System!\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Inventory\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addItem(&store);
            break;
        case 2:
            removeItem(&store);
            break;
        case 3:
            displayInventory(&store);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}