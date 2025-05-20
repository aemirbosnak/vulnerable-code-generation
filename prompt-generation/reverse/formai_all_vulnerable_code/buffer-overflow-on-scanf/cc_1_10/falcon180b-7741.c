//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 20
#define MAX_MENU_ITEM_LEN 50

typedef struct {
    char name[MAX_MENU_ITEM_LEN];
    float price;
} MenuItem;

typedef struct {
    int numItems;
    MenuItem items[MAX_MENU_ITEMS];
} Menu;

void addMenuItem(Menu *menu, char *name, float price) {
    if (menu->numItems >= MAX_MENU_ITEMS) {
        printf("Error: Menu is full.\n");
        return;
    }

    strncpy(menu->items[menu->numItems].name, name, MAX_MENU_ITEM_LEN);
    menu->items[menu->numItems].price = price;
    menu->numItems++;
}

void displayMenu(Menu *menu) {
    printf("Menu:\n");
    for (int i = 0; i < menu->numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu->items[i].name, menu->items[i].price);
    }
}

int main() {
    // Initialize menu
    Menu menu = {0};

    // Add menu items
    addMenuItem(&menu, "Coffee", 2.50);
    addMenuItem(&menu, "Tea", 1.75);
    addMenuItem(&menu, "Soda", 1.50);
    addMenuItem(&menu, "Pastry", 3.00);

    // Display menu
    displayMenu(&menu);

    // Get customer's order
    char order[MAX_MENU_ITEM_LEN];
    printf("Enter your order: ");
    scanf("%s", order);

    // Calculate total price
    float totalPrice = 0;
    for (int i = 0; i < menu.numItems; i++) {
        if (strcmp(menu.items[i].name, order) == 0) {
            totalPrice += menu.items[i].price;
            break;
        }
    }

    // Display total price
    printf("Total price: $%.2f\n", totalPrice);

    return 0;
}