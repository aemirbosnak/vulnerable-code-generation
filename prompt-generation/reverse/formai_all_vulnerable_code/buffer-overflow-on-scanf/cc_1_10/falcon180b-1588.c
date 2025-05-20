//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

void addItem(Item* inventory, int numItems) {
    printf("Enter item name: ");
    scanf("%s", inventory[numItems].name);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[numItems].quantity);
    printf("Enter item price: ");
    scanf("%f", &inventory[numItems].price);
    printf("\n");
}

void displayInventory(Item* inventory, int numItems) {
    printf("\nInventory:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%d\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem(Item* inventory, int numItems) {
    printf("\nEnter item name to search: ");
    char searchName[MAX_NAME_LENGTH];
    scanf("%s", searchName);
    for (int i = 0; i < numItems; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("\nItem found:\n");
            printf("%s\t%d\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

void updateItemQuantity(Item* inventory, int numItems) {
    printf("\nEnter item name to update quantity: ");
    char searchName[MAX_NAME_LENGTH];
    scanf("%s", searchName);
    for (int i = 0; i < numItems; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("\nEnter new item quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("\n");
            break;
        }
    }
}

void updateItemPrice(Item* inventory, int numItems) {
    printf("\nEnter item name to update price: ");
    char searchName[MAX_NAME_LENGTH];
    scanf("%s", searchName);
    for (int i = 0; i < numItems; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("\nEnter new item price: ");
            scanf("%f", &inventory[i].price);
            printf("\n");
            break;
        }
    }
}

int main() {
    Item inventory[MAX_ITEMS];
    int numItems = 0;

    printf("\nWelcome to the Product Inventory System!\n");
    while (numItems < MAX_ITEMS) {
        printf("\nEnter 1 to add item, 2 to display inventory, 3 to search item, 4 to update quantity, 5 to update price, or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addItem(inventory, numItems);
            numItems++;
            break;
        case 2:
            displayInventory(inventory, numItems);
            break;
        case 3:
            searchItem(inventory, numItems);
            break;
        case 4:
            updateItemQuantity(inventory, numItems);
            break;
        case 5:
            updateItemPrice(inventory, numItems);
            break;
        case 0:
            printf("\nExiting program...\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}