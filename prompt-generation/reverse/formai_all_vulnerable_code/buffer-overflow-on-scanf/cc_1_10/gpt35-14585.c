//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct order {
    char name[50];
    float price;
    int qty;
    float subTotal;
} Order;

typedef struct bill {
    char customerName[50];
    Order orders[100];
    float totalAmount;
} Bill;

int main() {
    Bill bill;
    int count = 0;

    printf("Enter customer name: ");
    fgets(bill.customerName, 50, stdin);

    while (1) {
        Order order;

        printf("Enter item name (type 'exit' to finish): ");
        fgets(order.name, 50, stdin);
        if (strcmp(order.name, "exit\n") == 0) {
            break;
        }

        printf("Enter item price: ");
        scanf("%f", &order.price);

        printf("Enter quantity: ");
        scanf("%d", &order.qty);

        order.subTotal = order.price * order.qty;
        bill.orders[count++] = order;
    }

    printf("\n\n\n%-20s %-10s %-10s %-10s\n", "Item Name", "Price", "Quantity", "Total");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.2f %-10d %-10.2f\n", bill.orders[i].name, bill.orders[i].price, bill.orders[i].qty, bill.orders[i].subTotal);
        bill.totalAmount += bill.orders[i].subTotal;
    }

    printf("%-40s %-10.2f\n", "Total:", bill.totalAmount);

    return 0;
}