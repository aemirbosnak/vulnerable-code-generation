//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 100

typedef struct {
    int id;
    float price;
    int qty;
} coffee_order;

coffee_order orders[MAX_ORDERS];
int current_order = 0;

void add_order(int id, float price, int qty) {
    if (current_order >= MAX_ORDERS) {
        printf("Error: Maximum number of orders reached.\n");
        return;
    }

    orders[current_order].id = id;
    orders[current_order].price = price;
    orders[current_order].qty = qty;

    current_order++;
}

float calculate_total() {
    float total = 0.0;

    for (int i = 0; i < current_order; i++) {
        total += orders[i].price * orders[i].qty;
    }

    return total;
}

void display_orders() {
    printf("\nOrders and their total prices:\n");

    for (int i = 0; i < current_order; i++) {
        printf("Order %d: Coffee %d (%.2f)\tTotal: %.2f\n", orders[i].id, orders[i].price, orders[i].qty, orders[i].price * orders[i].qty);
    }
}

int main() {
    char input[50];
    int id;
    float price;
    int qty;

    while (1) {
        printf("\nC Cafe Billing System\n");
        printf("Enter 'add' to add an order, 'display' to display all orders, 'total' to calculate total bill, or 'exit' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter coffee ID: ");
            scanf("%d", &id);
            printf("Enter coffee price: ");
            scanf("%f", &price);
            printf("Enter coffee quantity: ");
            scanf("%d", &qty);

            add_order(id, price, qty);
        } else if (strcmp(input, "display") == 0) {
            display_orders();
        } else if (strcmp(input, "total") == 0) {
            float total = calculate_total();
            printf("Total bill: %.2f\n", total);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}