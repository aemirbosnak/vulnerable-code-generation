//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure for item
struct Item {
    int id;
    char name[50];
    int quantity;
};

// Array to store items
struct Item items[MAX_ITEMS];

// Function to add a new item
void addItem() {
    int id, quantity;
    char name[50];
    printf("Enter id of item: ");
    scanf("%d", &id);
    printf("Enter name of item: ");
    scanf("%s", name);
    printf("Enter quantity of item: ");
    scanf("%d", &quantity);

    // Check if item already exists
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].id == id) {
            items[i].quantity += quantity;
            printf("Item already exists, updated quantity to %d\n", items[i].quantity);
            return;
        }
    }

    // Add new item
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].id == 0) {
            items[i].id = id;
            strcpy(items[i].name, name);
            items[i].quantity = quantity;
            printf("Item added\n");
            return;
        }
    }
    printf("Max capacity reached\n");
}

// Function to remove an item
void removeItem() {
    int id;
    printf("Enter id of item: ");
    scanf("%d", &id);

    // Check if item exists
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].id == id) {
            items[i].id = 0;
            items[i].quantity = 0;
            printf("Item removed\n");
            return;
        }
    }
    printf("Item not found\n");
}

// Function to display all items
void displayItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].id != 0) {
            printf("Item %d:\n", i + 1);
            printf("  Id: %d\n", items[i].id);
            printf("  Name: %s\n", items[i].name);
            printf("  Quantity: %d\n", items[i].quantity);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nWarehouse Management System:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display All Items\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem();
                break;

            case 2:
                removeItem();
                break;

            case 3:
                displayItems();
                break;

            case 0:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}