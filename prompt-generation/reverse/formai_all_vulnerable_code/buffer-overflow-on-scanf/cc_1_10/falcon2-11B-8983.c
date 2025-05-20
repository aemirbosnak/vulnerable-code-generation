//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

typedef struct {
    int id;
    char name[50];
    Product product;
} Order;

int main() {
    Order orders[5];
    int num_orders = 0;

    printf("Enter the number of orders: ");
    scanf("%d", &num_orders);

    for (int i = 0; i < num_orders; i++) {
        printf("Enter order details:\n");
        scanf("%d %s %f %d\n", &orders[i].id, orders[i].name, &orders[i].product.price, &orders[i].product.quantity);
    }

    // Sort the orders by price in descending order
    for (int i = 0; i < num_orders - 1; i++) {
        for (int j = i + 1; j < num_orders; j++) {
            if (orders[j].product.price > orders[i].product.price) {
                Product temp = orders[i].product;
                orders[i].product = orders[j].product;
                orders[j].product = temp;
            }
        }
    }

    // Print the sorted orders
    printf("Sorted orders:\n");
    for (int i = 0; i < num_orders; i++) {
        printf("Order %d:\n", orders[i].id);
        printf("Product: %s\n", orders[i].name);
        printf("Price: %.2f\n", orders[i].product.price);
        printf("Quantity: %d\n\n", orders[i].product.quantity);
    }

    return 0;
}