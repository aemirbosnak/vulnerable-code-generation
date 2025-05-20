//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare constants for menu items
#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 30

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
    strcpy(menu->items[0].name, "Espresso");
    menu->items[0].price = 3.00;
    
    strcpy(menu->items[1].name, "Cappuccino");
    menu->items[1].price = 4.50;
    
    strcpy(menu->items[2].name, "Latte");
    menu->items[2].price = 4.00;
    
    strcpy(menu->items[3].name, "Tea");
    menu->items[3].price = 2.50;
    
    strcpy(menu->items[4].name, "Sandwich");
    menu->items[4].price = 5.00;

    menu->itemCount = 5;
}

void displayMenu(const CafeMenu *menu) {
    printf("Cafe Menu:\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < menu->itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
    printf("----------------------------------------------------------\n");
}

void takeOrder(const CafeMenu *menu, int *orderQuantity) {
    int itemNumber;
    printf("Enter the item number you would like to order (0 to finish): ");
    while (1) {
        scanf("%d", &itemNumber);
        
        if (itemNumber == 0) {
            break;
        } else if (itemNumber < 1 || itemNumber > menu->itemCount) {
            printf("Invalid item number. Please select again: ");
        } else {
            printf("Enter quantity for %s: ", menu->items[itemNumber - 1].name);
            scanf("%d", &orderQuantity[itemNumber - 1]);
        }
    }
}

float calculateTotal(const CafeMenu *menu, int *orderQuantity) {
    float total = 0.0;

    for (int i = 0; i < menu->itemCount; i++) {
        total += menu->items[i].price * orderQuantity[i];
    }

    return total;
}

void printBill(const CafeMenu *menu, int *orderQuantity) {
    printf("\nBill Summary:\n");
    printf("----------------------------------------------------------\n");
    
    for (int i = 0; i < menu->itemCount; i++) {
        if (orderQuantity[i] > 0) {
            printf("%s x%d - $%.2f\n", menu->items[i].name, orderQuantity[i], menu->items[i].price * orderQuantity[i]);
        }
    }
    
    float total = calculateTotal(menu, orderQuantity);
    printf("----------------------------------------------------------\n");
    printf("Total: $%.2f\n", total);
}

int main() {
    CafeMenu menu;
    initializeMenu(&menu);

    int orderQuantity[MAX_ITEMS] = { 0 };
    
    displayMenu(&menu);
    takeOrder(&menu, orderQuantity);
    printBill(&menu, orderQuantity);

    return 0;
}