//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 10

typedef struct Order {
    char name[50];
    int quantity;
    float price;
} Order;

Order orders[MAX_ORDERS];

void displayMenu() {
    printf("------------------------\n");
    printf("Menu:\n");
    printf("1. Coffee\t\tPrice: $2.00\n");
    printf("2. Tea\t\tPrice: $1.50\n");
    printf("3. Juice\t\tPrice: $1.00\n");
    printf("4. Soda\t\tPrice: $1.25\n");
    printf("------------------------\n");
}

void addOrder() {
    Order newOrder;

    printf("Enter your name: ");
    scanf("%s", newOrder.name);

    printf("Enter the quantity: ");
    scanf("%d", &newOrder.quantity);

    printf("Enter the price: ");
    scanf("%f", &newOrder.price);

    orders[0] = newOrder;
}

void calculateTotal() {
    float total = 0;

    for (int i = 0; i < MAX_ORDERS; i++) {
        total += orders[i].quantity * orders[i].price;
    }

    printf("Total: $%.2f\n", total);
}

int main() {
    int choice;

    displayMenu();

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addOrder();
            break;
        case 2:
            addOrder();
            break;
        case 3:
            addOrder();
            break;
        case 4:
            addOrder();
            break;
        default:
            printf("Invalid choice.\n");
    }

    calculateTotal();

    return 0;
}