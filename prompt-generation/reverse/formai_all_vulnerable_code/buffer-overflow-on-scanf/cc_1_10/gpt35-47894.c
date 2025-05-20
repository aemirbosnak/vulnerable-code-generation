//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for menu items
#define ITEM_1 "Coffee"
#define ITEM_2 "Tea"
#define ITEM_3 "Scone"
#define ITEM_4 "Brownie"

// Define prices for each menu item
#define PRICE_1 2.50
#define PRICE_2 2.00
#define PRICE_3 1.00
#define PRICE_4 1.50

// Define struct to hold order information
struct Order {
    char item[10];
    int quantity;
    float price;
};

// Function to get user input for order
void getOrder(struct Order* order) {
    printf("Enter item name: ");
    scanf("%s", order->item);

    printf("Enter item quantity: ");
    scanf("%d", &order->quantity);

    // Set price based on item
    if (strcmp(order->item, ITEM_1) == 0) {
        order->price = PRICE_1;
    } else if (strcmp(order->item, ITEM_2) == 0) {
        order->price = PRICE_2;
    } else if (strcmp(order->item, ITEM_3) == 0) {
        order->price = PRICE_3;
    } else if (strcmp(order->item, ITEM_4) == 0) {
        order->price = PRICE_4;
    } else {
        printf("Invalid item name. Please try again.\n");
        getOrder(order);
    }
}

// Function to print receipt
void printReceipt(struct Order* orders, int numOrders) {
    float total = 0;

    printf("----- C CAFE BILLING SYSTEM -----\n\n");

    // Print time and date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Date: %02d/%02d/%4d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("Time: %02d:%02d:%02d\n\n", tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Print orders
    for (int i = 0; i < numOrders; i++) {
        struct Order order = orders[i];
        float subtotal = order.price * order.quantity;
        total += subtotal;

        printf("%-10s x %2d %6.2f\n", order.item, order.quantity, subtotal);
    }

    // Print total
    printf("\nTotal: %6.2f\n", total);
}

int main() {
    int numOrders = 0;
    struct Order orders[100];

    // Print menu and get user input until they choose to exit
    while (1) {
        printf("\n----- C CAFE MENU -----\n");
        printf("1. %s - $%.2f\n", ITEM_1, PRICE_1);
        printf("2. %s - $%.2f\n", ITEM_2, PRICE_2);
        printf("3. %s - $%.2f\n", ITEM_3, PRICE_3);
        printf("4. %s - $%.2f\n", ITEM_4, PRICE_4);
        printf("5. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        } else if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please try again.\n");
        } else {
            struct Order order;
            getOrder(&order);
            orders[numOrders++] = order;
        }
    }

    printReceipt(orders, numOrders);

    return 0;
}