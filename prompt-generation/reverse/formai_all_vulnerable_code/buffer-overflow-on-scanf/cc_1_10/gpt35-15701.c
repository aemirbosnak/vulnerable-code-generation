//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdlib.h>
#include <stdio.h>
#define MAX_CAPACITY 100

int warehouseInventory[MAX_CAPACITY];
int numberOfItems = 0;

int recursiveAddItem(int itemNumber, int quantityToAdd) {
    if (itemNumber < 0 || itemNumber > MAX_CAPACITY) {
        return -1; // Out of bounds item number
    }

    if (numberOfItems == MAX_CAPACITY) {
        return -2; // Warehouse is full
    }

    if (warehouseInventory[itemNumber] + quantityToAdd < 0) {
        return -3; // Not enough quantity to remove
    }

    warehouseInventory[itemNumber] += quantityToAdd;
    numberOfItems++;

    return 0;
}

int recursiveRemoveItem(int itemNumber, int quantityToRemove) {
    if (itemNumber < 0 || itemNumber > MAX_CAPACITY) {
        return -1; // Out of bounds item number
    }

    if (warehouseInventory[itemNumber] - quantityToRemove < 0) {
        return -3; // Not enough quantity to remove
    }

    warehouseInventory[itemNumber] -= quantityToRemove;
    numberOfItems--;

    return 0;
}

void displayInventory() {
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < MAX_CAPACITY; i++) {
        if (warehouseInventory[i] > 0) {
            printf("Item %d: %d\n", i, warehouseInventory[i]);
        }
    }
}

int main() {
    printf("Welcome to the warehouse management system!\n");

    int itemNumber, quantity;

    char userChoice;
    do {
        printf("Enter (A)dd item, (R)emove item, or (D)isplay inventory: ");
        scanf(" %c", &userChoice);

        switch (userChoice) {
            case 'A':
                printf("Enter item number and quantity to add: ");
                scanf("%d %d", &itemNumber, &quantity);
                if (recursiveAddItem(itemNumber, quantity) == 0) {
                    printf("Item added successfully\n");
                } else {
                    printf("Error adding item\n");
                }
                break;
            case 'R':
                printf("Enter item number and quantity to remove: ");
                scanf("%d %d", &itemNumber, &quantity);
                if (recursiveRemoveItem(itemNumber, quantity) == 0) {
                    printf("Item removed successfully\n");
                } else {
                    printf("Error removing item\n");
                }
                break;
            case 'D':
                displayInventory();
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (userChoice != 'Q');

    return 0;
}