//FormAI DATASET v1.0 Category: Product Inventory System ; Style: happy
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[20];
    float price;
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int totalItems = 0;

void addItem() {
    Item newItem;

    printf("\nEnter the name of the item: ");
    scanf("%s", &newItem.name);

    printf("\nEnter the price of the item: ");
    scanf("%f", &newItem.price);

    printf("\nEnter the quantity of the item: ");
    scanf("%d", &newItem.quantity);

    inventory[totalItems++] = newItem;

    printf("\nItem added successfully!\n");
}

void removeItem() {
    char itemName[20];
    int i, j;
    int itemFound = 0;

    printf("\nEnter the name of the item you want to remove: ");
    scanf("%s", itemName);

    for (i = 0; i < totalItems; ++i) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            itemFound = 1;
            totalItems--;

            for (j = i; j < totalItems; ++j) {
                inventory[j] = inventory[j+1];
            }

            printf("\nItem removed successfully!\n");
            break;
        }
    }

    if (!itemFound) {
        printf("\nItem not found!\n");
    }
}

void viewInventory() {
    int i;

    printf("\nCurrent Inventory:\n");
    printf("------------------\n");

    for (i = 0; i < totalItems; ++i) {
        printf("Item %d:\n", i+1);
        printf("Name: %s\n", inventory[i].name);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Quantity: %d\n\n", inventory[i].quantity);
    }
}

int main() {
    int choice;

    printf("Welcome to Happy Product Inventory System\n\n");

    while (1) {
        printf("Please choose from the following options:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Inventory\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;

            case 2:
                removeItem();
                break;

            case 3:
                viewInventory();
                break;

            case 4:
                printf("\nThank you for using Happy Product Inventory System!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}