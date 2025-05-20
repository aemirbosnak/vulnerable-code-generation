//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEM_PRICE_LENGTH 10

struct Item {
    char name[MAX_ITEM_NAME_LENGTH];
    double price;
};

struct Order {
    struct Item items[MAX_ITEMS];
    int numItems;
    double totalPrice;
};

void printMenu() {
    printf("Welcome to the Cafe Billing System!\n\n");
    printf("Menu:\n");
    printf("1. Coffee - $2.00\n");
    printf("2. Tea - $1.50\n");
    printf("3. Cake - $3.00\n");
    printf("4. Sandwich - $4.00\n");
    printf("5. Salad - $5.00\n");
    printf("6. Exit\n\n");
}

void takeOrder(struct Order *order) {
    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(order->items[order->numItems].name, "Coffee");
                order->items[order->numItems].price = 2.00;
                order->numItems++;
                break;
            case 2:
                strcpy(order->items[order->numItems].name, "Tea");
                order->items[order->numItems].price = 1.50;
                order->numItems++;
                break;
            case 3:
                strcpy(order->items[order->numItems].name, "Cake");
                order->items[order->numItems].price = 3.00;
                order->numItems++;
                break;
            case 4:
                strcpy(order->items[order->numItems].name, "Sandwich");
                order->items[order->numItems].price = 4.00;
                order->numItems++;
                break;
            case 5:
                strcpy(order->items[order->numItems].name, "Salad");
                order->items[order->numItems].price = 5.00;
                order->numItems++;
                break;
            case 6:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

void calculateTotalPrice(struct Order *order) {
    order->totalPrice = 0.0;
    for (int i = 0; i < order->numItems; i++) {
        order->totalPrice += order->items[i].price;
    }
}

void printOrder(struct Order *order) {
    printf("\nYour order:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }
    printf("Total price: $%.2f\n", order->totalPrice);
}

int main() {
    struct Order order;
    order.numItems = 0;
    order.totalPrice = 0.0;

    takeOrder(&order);
    calculateTotalPrice(&order);
    printOrder(&order);

    return 0;
}