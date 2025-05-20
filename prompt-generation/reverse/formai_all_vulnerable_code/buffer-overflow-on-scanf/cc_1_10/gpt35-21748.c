//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int quantity;
    float price;
} MenuItem;

typedef struct {
    MenuItem menu[MAX_ITEMS];
    int count;
} Menu;

float calculateTotal(Menu);

int main() {
    Menu menu;
    menu.count = 0;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        printf("Enter item name: ");
        scanf("%s", menu.menu[menu.count].name);
        printf("Enter item price: ");
        scanf("%f", &menu.menu[menu.count].price);
        printf("Enter quantity: ");
        scanf("%d", &menu.menu[menu.count].quantity);

        printf("Do you want to add another item? (y/n) ");
        scanf(" %c", &choice);

        menu.count++;
    }

    float total = calculateTotal(menu);

    printf("\n\nBILL\n");
    printf("======================================\n");
    printf("%-20s %-12s %-12s\n", "Item", "Quantity", "Price");
    printf("--------------------------------------\n");
    for (int i = 0; i < menu.count; i++) {
        printf("%-20s %-12d %-12.2f\n", menu.menu[i].name, menu.menu[i].quantity, menu.menu[i].price);
    }
    printf("--------------------------------------\n");
    printf("%-20s %-12s %-12.2f\n\n", "Total", "", total);

    return 0;
}

float calculateTotal(Menu menu) {
    float total = 0;
    for (int i = 0; i < menu.count; i++) {
        total += menu.menu[i].price * menu.menu[i].quantity;
    }
    return total;
}