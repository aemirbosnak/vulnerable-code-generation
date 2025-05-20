//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct order {
    char name[50];
    char item[50];
    int quantity;
    float price;
    float total;
} Order;

int main() {
    Order orders[100];
    int numOrders = 0;
    float totalAmount = 0.0;

    printf("Welcome to the Cafe Billing System!\n");

    while (1) {
        printf("Enter the name of the customer: ");
        scanf("%s", orders[numOrders].name);

        printf("Enter the item ordered: ");
        scanf("%s", orders[numOrders].item);

        printf("Enter the quantity ordered: ");
        scanf("%d", &orders[numOrders].quantity);

        printf("Enter the price per item: ");
        scanf("%f", &orders[numOrders].price);

        orders[numOrders].total = orders[numOrders].quantity * orders[numOrders].price;

        totalAmount += orders[numOrders].total;

        numOrders++;

        if (numOrders == 100) {
            break;
        }

        printf("\n");
    }

    printf("Billing completed!\n");
    printf("Total amount: %.2f\n", totalAmount);

    return 0;
}