//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int numItems = 0;

void addItem();
void removeItem();
void printInventory();

int main() {
    int choice = 0;

    while (choice != 4) {
        printf("~~~~~~ Warehouse Management System ~~~~~~\n");
        printf("1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. Print inventory\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                printInventory();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addItem() {
    if (numItems == MAX_ITEMS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    Item newItem;

    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);

    newItem.id = numItems + 1;

    inventory[numItems] = newItem;
    numItems++;

    printf("Item added to inventory.\n");
}

void removeItem() {
    if (numItems == 0) {
        printf("Error: Inventory is empty.\n");
        return;
    }

    int id, i, found = 0;

    printf("Enter item ID: ");
    scanf("%d", &id);

    for (i = 0; i < numItems; i++) {
        if (inventory[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < numItems - 1; j++) {
            inventory[j] = inventory[j + 1];
        }

        numItems--;

        printf("Item removed from inventory.\n");
    } else {
        printf("Item not found in inventory.\n");
    }
}

void printInventory() {
    if (numItems == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    float totalValue = 0;

    printf("ID\tName\tQuantity\tPrice\tValue\n");
    for (int i = 0; i < numItems; i++) {
        Item item = inventory[i];
        float value = item.quantity * item.price;

        printf("%d\t%s\t%d\t\t%.2f\t%.2f\n", item.id, item.name, item.quantity, item.price, value);

        totalValue += value;
    }

    printf("Total inventory value: $%.2f\n", totalValue);
}