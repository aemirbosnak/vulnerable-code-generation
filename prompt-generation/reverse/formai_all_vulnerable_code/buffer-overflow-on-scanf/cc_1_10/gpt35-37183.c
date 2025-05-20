//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ITEMS 50
#define MAX_ITEM_NAME_LENGTH 25

struct Item {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
};

struct Warehouse {
    struct Item inventory[MAX_ITEMS];
    int itemCount;
};

void addItems(struct Warehouse *warehouse);

void removeItems(struct Warehouse *warehouse);

void displayInventory(struct Warehouse *warehouse);

void printMenu();

int main() {
    struct Warehouse warehouse;
    int option;

    warehouse.itemCount = 0;

    do {
        printMenu();

        scanf("%d", &option);

        switch (option) {
            case 1:
                addItems(&warehouse);
                break;
            case 2:
                removeItems(&warehouse);
                break;
            case 3:
                displayInventory(&warehouse);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option entered. Try again.\n");
                break;
        }
        
        printf("\n");
    } while (option != 4);

    return 0;
}

void addItems(struct Warehouse *warehouse) {
    char itemName[MAX_ITEM_NAME_LENGTH];
    int quantity;

    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("\nCannot add more items. Warehouse full.\n");
        return;
    }

    printf("\nEnter item name: ");
    scanf("%s", itemName);

    for (int i = 0; i < strlen(itemName); i++) {
        itemName[i] = toupper(itemName[i]);
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    strcpy(warehouse->inventory[warehouse->itemCount].name, itemName);
    warehouse->inventory[warehouse->itemCount].quantity = quantity;

    printf("\nAdded %d %s(s) to warehouse inventory.\n", quantity, itemName);

    warehouse->itemCount++;
}

void removeItems(struct Warehouse *warehouse) {
    char itemName[MAX_ITEM_NAME_LENGTH];
    int quantity;

    if (warehouse->itemCount <= 0) {
        printf("\nNo items to remove. Warehouse empty.\n");
        return;
    }

    printf("\nEnter item name: ");
    scanf("%s", itemName);

    for (int i = 0; i < strlen(itemName); i++) {
        itemName[i] = toupper(itemName[i]);
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->inventory[i].name, itemName) == 0) {
            if (warehouse->inventory[i].quantity < quantity) {
                printf("\nCannot remove more items than available in warehouse.\n");
                return;
            }

            warehouse->inventory[i].quantity -= quantity;

            if (warehouse->inventory[i].quantity == 0) {
                for (int j = i; j < warehouse->itemCount - 1; j++) {
                    warehouse->inventory[j] = warehouse->inventory[j + 1];
                }

                warehouse->itemCount--;

                printf("\nRemoved all %s(s) from warehouse inventory.\n", itemName);
            } else {
                printf("\nRemoved %d %s(s) from warehouse inventory.\n", quantity, itemName);
            }

            return;
        }
    }

    printf("\nItem not found in warehouse inventory.\n");
}

void displayInventory(struct Warehouse *warehouse) {
    if (warehouse->itemCount <= 0) {
        printf("\nWarehouse inventory empty.\n");
        return;
    }

    printf("\nWarehouse inventory:\n");

    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%d %s(s)\n", warehouse->inventory[i].quantity, warehouse->inventory[i].name);
    }
}

void printMenu() {
    printf("Warehouse Management System\n");
    printf("1. Add item(s)\n");
    printf("2. Remove item(s)\n");
    printf("3. Display inventory\n");
    printf("4. Exit\n");
    printf("Enter option number: ");
}