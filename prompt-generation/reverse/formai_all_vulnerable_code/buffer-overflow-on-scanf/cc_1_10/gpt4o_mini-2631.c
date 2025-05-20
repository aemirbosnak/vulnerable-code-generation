//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int itemCount;
} CafeMenu;

void initializeMenu(CafeMenu *menu) {
    strcpy(menu->items[0].name, "Coffee");
    menu->items[0].price = 3.50;
    menu->items[1] = (MenuItem){"Tea", 2.50, 0};
    menu->items[2] = (MenuItem){"Sandwich", 5.00, 0};
    menu->items[3] = (MenuItem){"Cake", 4.00, 0};
    menu->items[4] = (MenuItem){"Juice", 3.00, 0};
    menu->itemCount = 5;
}

void displayMenu(CafeMenu *menu) {
    printf("Welcome to the Cafe! Here is our menu:\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < menu->itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
    printf("-----------------------------------------------------\n");
}

void takeOrder(CafeMenu *menu, int orderQuantities[]) {
    printf("Please enter the quantities for the items you wish to order (0 to skip):\n");
    for (int i = 0; i < menu->itemCount; i++) {
        printf("Quantity for %s: ", menu->items[i].name);
        scanf("%d", &orderQuantities[i]);
    }
}

float calculateTotal(CafeMenu *menu, int orderQuantities[]) {
    float total = 0.0f;
    for (int i = 0; i < menu->itemCount; i++) {
        total += menu->items[i].price * orderQuantities[i];
    }
    return total;
}

void generateBill(CafeMenu *menu, int orderQuantities[]) {
    printf("\nYour Bill:\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < menu->itemCount; i++) {
        if (orderQuantities[i] > 0) {
            printf("%s (x%d) - $%.2f\n", menu->items[i].name, orderQuantities[i], 
                   menu->items[i].price * orderQuantities[i]);
        }
    }
    float total = calculateTotal(menu, orderQuantities);
    printf("-----------------------------------------------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("Thank you for visiting our cafe!\n");
}

int main() {
    CafeMenu menu;
    initializeMenu(&menu);
    
    int orderQuantities[MAX_ITEMS] = {0};

    displayMenu(&menu);
    takeOrder(&menu, orderQuantities);
    generateBill(&menu, orderQuantities);

    return 0;
}