//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 50

typedef struct MenuItem {
    char name[25];
    int price;
    int quantity;
} MenuItem;

void printMenuItems(MenuItem items[], int numItems) {
    printf("MENU\n");
    printf("========================================\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%d\n", items[i].name, items[i].price);
    }
    printf("========================================\n");
}

int getMenuItemIndex(MenuItem items[], int numItems, char itemName[]) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void addItemToBill(MenuItem items[], int numItems, char itemName[], int quantity, MenuItem bill[], int* numBillItems) {
    int itemIndex = getMenuItemIndex(items, numItems, itemName);
    if (itemIndex == -1) {
        printf("Item not found in menu.\n");
        return;
    }

    int billIndex = getMenuItemIndex(bill, *numBillItems, itemName);
    if (billIndex == -1) {
        // Item not yet in the bill, add it
        bill[*numBillItems] = items[itemIndex];
        bill[*numBillItems].quantity = quantity;
        (*numBillItems)++;
    } else {
        // Item already in the bill, increase quantity
        bill[billIndex].quantity += quantity;
    }
}

void printBill(MenuItem bill[], int numBillItems) {
    printf("BILL\n");
    printf("========================================\n");
    int total = 0;
    for (int i = 0; i < numBillItems; i++) {
        printf("%d x %s - $%d\n", bill[i].quantity, bill[i].name, bill[i].price);
        total += bill[i].price * bill[i].quantity;
    }
    printf("----------------------------------------\n");
    printf("Total - $%d\n", total);
    printf("========================================\n");
}

void recursiveMenu(MenuItem items[], int numItems, MenuItem bill[], int* numBillItems) {
    int choice;
    char name[25];
    int quantity;

    printf("Enter 1 to view menu.\nEnter 2 to add item to bill.\nEnter 3 to view bill.\nEnter 4 to exit.\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printMenuItems(items, numItems);
            break;
        case 2:
            printf("Enter item name: ");
            scanf("%s", name);

            printf("Enter quantity: ");
            scanf("%d", &quantity);

            addItemToBill(items, numItems, name, quantity, bill, numBillItems);
            break;
        case 3:
            printBill(bill, *numBillItems);
            break;
        case 4:
            printf("Thank you for dining with us!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    recursiveMenu(items, numItems, bill, numBillItems);
}

int main() {
    MenuItem items[MAX_ITEMS] = {
        {"Coffee", 3, 0},
        {"Tea", 2, 0},
        {"Muffin", 2, 0},
        {"Croissant", 3, 0},
        {"Sandwich", 5, 0},
        {"Soup", 4, 0},
        {"Salad", 6, 0},
        {"Cake", 4, 0}
    };
    int numItems = 8;
    MenuItem bill[MAX_ITEMS];
    int numBillItems = 0;

    recursiveMenu(items, numItems, bill, &numBillItems);

    return 0;
}