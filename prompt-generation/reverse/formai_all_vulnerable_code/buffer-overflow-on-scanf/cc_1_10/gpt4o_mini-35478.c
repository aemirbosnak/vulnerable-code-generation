//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int count;
} Menu;

void initializeMenu(Menu *menu) {
    menu->count = 5; // Total number of items
    menu->items[0] = (MenuItem){1, "Coffee", 2.5};
    menu->items[1] = (MenuItem){2, "Tea", 1.5};
    menu->items[2] = (MenuItem){3, "Sandwich", 5.0};
    menu->items[3] = (MenuItem){4, "Cake", 3.0};
    menu->items[4] = (MenuItem){5, "Juice", 2.0};
}

void displayMenu(Menu *menu) {
    printf("Welcome to the Cafe! Here is the menu:\n");
    for (int i = 0; i < menu->count; i++) {
        printf("ID: %d | Item: %s | Price: $%.2f\n", 
            menu->items[i].id, 
            menu->items[i].name, 
            menu->items[i].price);
    }
}

float calculateTotal(int *selections, int size, Menu *menu) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        if (selections[i] > 0 && selections[i] <= menu->count) {
            total += menu->items[selections[i] - 1].price; 
        }
    }
    return total;
}

void inputSelection(int *selections, int *size) {
    printf("Enter the IDs of the items you want to order (0 to finish):\n");
    int id;
    while (1) {
        scanf("%d", &id);
        if (id == 0) {
            break;
        }
        selections[(*size)++] = id;
    }
}

void printBill(float total) {
    printf("Thank you for your order!\n");
    printf("Your total bill is: $%.2f\n", total);
}

int main() {
    Menu cafeMenu;
    initializeMenu(&cafeMenu);

    int selections[MAX_ITEMS] = {0};
    int selectionCount = 0;

    displayMenu(&cafeMenu);
    inputSelection(selections, &selectionCount);

    float total = calculateTotal(selections, selectionCount, &cafeMenu);
    printBill(total);

    return 0;
}