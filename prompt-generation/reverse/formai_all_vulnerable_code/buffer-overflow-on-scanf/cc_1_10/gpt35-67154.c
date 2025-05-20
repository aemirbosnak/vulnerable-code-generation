//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 20
#define MAX_MENU_ITEM_NAME_LENGTH 50
#define MAX_MENU_ITEM_PRICE_LENGTH 10

struct MenuItem {
    char name[MAX_MENU_ITEM_NAME_LENGTH];
    float price;
    int quantity;
};

void printMenu(struct MenuItem menu[], int numItems) {
    printf("---------------MENU---------------\n");
    printf("%-20s%-10s\n", "Item", "Price");
    for (int i = 0; i < numItems; i++) {
        printf("%-20s$%-10.2f\n", menu[i].name, menu[i].price);
    }
    printf("----------------------------------\n");
}

int findMenuItemIndex(struct MenuItem menu[], int numItems, char item[]) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(menu[i].name, item) == 0) {
            return i;
        }
    }
    return -1;
}

void printBill(struct MenuItem menu[], int numItems, int quantity[], int numOrders) {
    printf("-----------------BILL-----------------\n");
    float total = 0;
    for (int i = 0; i < numOrders; i++) {
        int index = findMenuItemIndex(menu, numItems, menu[i].name);
        printf("%-20s%-10d$%-10.2f\n", menu[i].name, quantity[i], (float)quantity[i]*menu[index].price);
        total += (float)quantity[i]*menu[index].price;
    }
    printf("---------------------------------------\n");
    printf("Total: $%.2f\n", total);
}

int main() {
    // Initialize Menu Items
    struct MenuItem menu[MAX_MENU_ITEMS];
    int numItems = 3;

    strcpy(menu[0].name, "Coffee");
    menu[0].price = 1.50;
    menu[0].quantity = 10;

    strcpy(menu[1].name, "Tea");
    menu[1].price = 1.00;
    menu[1].quantity = 10;

    strcpy(menu[2].name, "Juice");
    menu[2].price = 2.00;
    menu[2].quantity = 10;

    // Print Menu
    printMenu(menu, numItems);

    // Take order
    int quantity[MAX_MENU_ITEMS] = {0};
    int numOrders = 0;

    char item[MAX_MENU_ITEM_NAME_LENGTH];
    while (1) {
        printf("Enter item name, q to quit: ");
        scanf("%s", item);
        if (strcmp(item, "q") == 0) {
            break;
        }
        int index = findMenuItemIndex(menu, numItems, item);
        if (index == -1) {
            printf("Invalid item name!\n");
            continue;
        }
        int numLeft = menu[index].quantity - quantity[index];
        if (numLeft <= 0) {
            printf("Sorry, we ran out of %s.\n", item);
            continue;
        } else {
            printf("Enter quantity (currently %d  left): ", numLeft);
            int q;
            scanf("%d", &q);
            if (q <= 0) {
                printf("Invalid quantity!\n");
                continue;
            }
            quantity[numOrders] = q;
            numOrders++;
            menu[index].quantity -= q;
        }
    }

    // Print Bill
    printBill(menu, numItems, quantity, numOrders);

    return 0;
}