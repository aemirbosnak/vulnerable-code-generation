//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MENU_ITEMS 10
#define MAX_ITEM_NAME_LENGTH 30
#define MAX_ITEM_PRICE 10000

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int price;
} MenuItem;

void displayMenu(MenuItem menuItems[], int numItems) {
    printf("Cafe Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%d\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

int getMenuItemIndex(MenuItem menuItems[], int numItems, char* itemName) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(menuItems[i].name, itemName) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    MenuItem menuItems[MAX_MENU_ITEMS];
    int numItems = 0;

    // Add menu items
    strcpy(menuItems[numItems].name, "Coffee");
    menuItems[numItems].price = 3;
    numItems++;

    strcpy(menuItems[numItems].name, "Tea");
    menuItems[numItems].price = 2;
    numItems++;

    strcpy(menuItems[numItems].name, "Cake");
    menuItems[numItems].price = 5;
    numItems++;

    int choice;
    char itemName[MAX_ITEM_NAME_LENGTH];

    // Display menu and take customer order
    printf("Welcome to the Cafe!\n");
    while (1) {
        displayMenu(menuItems, numItems);
        printf("Enter your choice (item name): ");
        scanf("%s", itemName);

        int itemIndex = getMenuItemIndex(menuItems, numItems, itemName);
        if (itemIndex == -1) {
            printf("Invalid item name.\n");
            continue;
        }

        choice = itemIndex;
        break;
    }

    // Calculate total cost
    int totalCost = menuItems[choice-1].price;

    // Display receipt
    printf("Receipt:\n");
    printf("Item: %s\n", menuItems[choice-1].name);
    printf("Price: $%d\n", menuItems[choice-1].price);
    printf("Total Cost: $%d\n", totalCost);

    return 0;
}