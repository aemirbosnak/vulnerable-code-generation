//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
/* C Cafe Billing System Example Program */
/* Author: Linus Torvalds style */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME_LENGTH 25
#define MAX_ITEMS 100
#define VAT_RATE 0.12

struct MenuItem {
    char name[MAX_ITEM_NAME_LENGTH];
    double price;
};

int main() {
    struct MenuItem menu[MAX_ITEMS];
    int itemCount = 0, numOrderedItems = 0;
    double subtotal = 0.0, vat = 0.0, total = 0.0;

    printf("\nWelcome to C Cafe Billing System!\n");
    printf("---------------------------------\n\n");

    while (itemCount < MAX_ITEMS) { // Menu Creation
        char itemName[MAX_ITEM_NAME_LENGTH];
        double itemPrice;

        printf("Enter menu item name (end with 'done'): ");
        scanf("%s", itemName);

        if (strcmp(itemName, "done") == 0) break;

        printf("Enter menu item price: ");
        scanf("%lf", &itemPrice);

        struct MenuItem item = { .price = itemPrice };
        strcpy(item.name, itemName);
        menu[itemCount++] = item;
        printf("\n");
    }

    printf("Menu created successfully! Below is the menu:\n");

    for (int i = 0; i < itemCount; i++) { // Menu Display
        printf("%s - %lf\n", menu[i].name, menu[i].price);
    }

    printf("---------------------------\n\n");
    struct MenuItem order[MAX_ITEMS];

    while (1) { // Order Entry
        char itemName[MAX_ITEM_NAME_LENGTH];
        printf("Enter menu item name to order (end with 'done'): ");
        scanf("%s", itemName);

        if (strcmp(itemName, "done") == 0) break;

        struct MenuItem* item = NULL;

        for (int i = 0; i < itemCount; i++) {
            if (strcmp(menu[i].name, itemName) == 0) {
                item = &menu[i];
                break;
            }
        }

        if (item == NULL) {
            printf("Error: Invalid menu item entered.\n");
            continue;
        }

        printf("Enter quantity to order: ");
        int quantity;
        scanf("%d", &quantity);

        order[numOrderedItems++] = (struct MenuItem) { .price = item->price, .name = item->name }; // Store the order

        subtotal += item->price * quantity; // Compute Subtotal
    }

    vat = subtotal * VAT_RATE; // Compute VAT

    total = subtotal + vat; // Compute Total

    printf("\n\nC Cafe Billing System\n");
    printf("---------------------------\n");
    printf("Ordered Items:\n");

    for (int i = 0; i < numOrderedItems; i++) { // Display the orders made
        printf("%s - %lf\n", order[i].name, order[i].price);
    }

    printf("\nSubtotal: %lf\nVAT: %lf\nTotal: %lf\n", subtotal, vat, total);
    printf("---------------------------\n");

    return 0;
}