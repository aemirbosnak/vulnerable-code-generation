//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int count;
} Menu;

typedef struct {
    char name[MAX_NAME_LEN];
    int quantities[MAX_ITEMS];
    float total;
} Order;

void initializeMenu(Menu *menu) {
    menu->count = 3;
    strcpy(menu->items[0].name, "Espresso");
    menu->items[0].price = 2.5;
    strcpy(menu->items[1].name, "Cappuccino");
    menu->items[1].price = 3.0;
    strcpy(menu->items[2].name, "Latte");
    menu->items[2].price = 3.5;
}

void printMenu(Menu *menu) {
    printf("Welcome to the Cafe!\n");
    printf("Menu:\n");
    for (int i = 0; i < menu->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
    printf("\n");
}

void takeOrder(Menu *menu, Order *order) {
    printf("Enter your name: ");
    scanf("%s", order->name);

    // Initialize quantities to 0
    for (int i = 0; i < menu->count; i++) {
        order->quantities[i] = 0;
    }

    int itemNumber;
    while (1) {
        printf("Enter the item number to order (0 to finish): ");
        scanf("%d", &itemNumber);
        if (itemNumber == 0) {
            break;
        }
        if (itemNumber < 1 || itemNumber > menu->count) {
            printf("Invalid item number, please try again.\n");
            continue;
        }
        printf("How many %s(s) would you like? ", menu->items[itemNumber - 1].name);
        int quantity;
        scanf("%d", &quantity);
        order->quantities[itemNumber - 1] += quantity;
    }
}

float calculateTotal(Order *order, Menu *menu) {
    float total = 0.0;
    for (int i = 0; i < menu->count; i++) {
        total += order->quantities[i] * menu->items[i].price;
    }
    order->total = total;
    return total;
}

void printReceipt(Order *order, Menu *menu) {
    printf("\n--- Receipt ---\n");
    printf("Customer: %s\n", order->name);
    printf("Items Ordered:\n");
    for (int i = 0; i < menu->count; i++) {
        if (order->quantities[i] > 0) {
            printf("%s x%d - $%.2f\n", menu->items[i].name, order->quantities[i], 
                   order->quantities[i] * menu->items[i].price);
        }
    }
    printf("Total Amount: $%.2f\n", order->total);
    printf("Thank you for visiting the Cafe!\n");
}

int main() {
    Menu menu;
    Order order;
    float taxRate = 0.1; // 10% tax

    initializeMenu(&menu);
    printMenu(&menu);
    takeOrder(&menu, &order);
    calculateTotal(&order, &menu);
    order.total += order.total * taxRate; // Add tax
    printReceipt(&order, &menu);

    return 0;
}