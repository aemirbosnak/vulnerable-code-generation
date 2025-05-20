//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char name[30];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int count;
} Menu;

void initializeMenu(Menu *menu) {
    menu->count = 0;
    
    // Sample menu items
    snprintf(menu->items[menu->count].name, sizeof(menu->items[menu->count].name), "Espresso");
    menu->items[menu->count].price = 2.50;
    menu->count++;

    snprintf(menu->items[menu->count].name, sizeof(menu->items[menu->count].name), "Cappuccino");
    menu->items[menu->count].price = 3.00;
    menu->count++;

    snprintf(menu->items[menu->count].name, sizeof(menu->items[menu->count].name), "Latte");
    menu->items[menu->count].price = 2.80;
    menu->count++;

    snprintf(menu->items[menu->count].name, sizeof(menu->items[menu->count].name), "Americano");
    menu->items[menu->count].price = 2.00;
    menu->count++;

    snprintf(menu->items[menu->count].name, sizeof(menu->items[menu->count].name), "Mocha");
    menu->items[menu->count].price = 3.50;
    menu->count++;

    snprintf(menu->items[menu->count].name, sizeof(menu->items[menu->count].name), "Croissant");
    menu->items[menu->count].price = 1.50;
    menu->count++;
}

void displayMenu(const Menu *menu) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < menu->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
    printf("-------------------\n");
}

float calculateTotal(int quantities[], const Menu *menu, int itemCount) {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += quantities[i] * menu->items[i].price;
    }
    return total;
}

int main() {
    Menu cafeMenu;
    int quantities[MAX_ITEMS] = {0};
    int choice, itemCount = 0;
    float total;

    initializeMenu(&cafeMenu);
    
    while (1) {
        displayMenu(&cafeMenu);
        printf("Enter the item number to order (0 to finish): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= cafeMenu.count) {
            itemCount++;
            printf("Enter quantity for %s: ", cafeMenu.items[choice - 1].name);
            scanf("%d", &quantities[choice - 1]);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    total = calculateTotal(quantities, &cafeMenu, cafeMenu.count);

    printf("\n--- Your Bill ---\n");
    for (int i = 0; i < cafeMenu.count; i++) {
        if (quantities[i] > 0) {
            printf("%d x %s - $%.2f\n", quantities[i], cafeMenu.items[i].name, quantities[i] * cafeMenu.items[i].price);
        }
    }
    printf("-------------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("-------------------\n");

    return 0;
}