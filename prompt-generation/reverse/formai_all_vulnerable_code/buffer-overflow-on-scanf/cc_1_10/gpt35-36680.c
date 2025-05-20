//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold medicine information
struct medicine {
    int id;
    char name[50];
    float price;
};

// Function to add new medicine to the inventory
void addMedicine(struct medicine *inventory, int *inventorySize) {
    // Allocate memory for new medicine record
    struct medicine newMedicine;
    printf("\nEnter medicine id: ");
    scanf("%d", &newMedicine.id);
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter medicine price: ");
    scanf("%f", &newMedicine.price);
    // Add new medicine to inventory
    inventory[*inventorySize] = newMedicine;
    *inventorySize += 1;
    printf("\nMedicine added successfully!\n");
}

// Function to display inventory
void displayInventory(struct medicine *inventory, int inventorySize) {
    printf("\nMedicine Inventory:\n");
    printf("ID\tName\tPrice\n");
    for (int i = 0; i < inventorySize; i++) {
        printf("%d\t%s\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].price);
    }
}

// Function to remove medicine from inventory
void removeMedicine(struct medicine *inventory, int *inventorySize, int id) {
    for (int i = 0; i < *inventorySize; i++) {
        if (inventory[i].id == id) {
            // Shift remaining elements of array
            for (int j = i + 1; j < *inventorySize; j++) {
                inventory[j - 1] = inventory[j];
            }
            *inventorySize -= 1;
            printf("\nMedicine removed successfully!\n");
            return;
        }
    }
    printf("\nMedicine with ID %d not found!\n", id);
}

int main() {
    // Initialize inventory
    struct medicine inventory[50];
    int inventorySize = 0;
    int choice, id;
    while (1) {
        printf("\nMenu:\n1. Add medicine to inventory\n2. Display inventory\n3. Remove medicine from inventory\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(inventory, &inventorySize);
                break;
            case 2:
                displayInventory(inventory, inventorySize);
                break;
            case 3:
                printf("\nEnter medicine id: ");
                scanf("%d", &id);
                removeMedicine(inventory, &inventorySize, id);
                break;
            case 4:
                printf("\nThank you for using the Medical Store Management System!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}