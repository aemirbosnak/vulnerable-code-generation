//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct customer {
    char name[50];
    int id;
} Customer;

typedef struct order {
    int id;
    char item[50];
    double price;
} Order;

int main() {
    int num_customers = 0;
    int num_orders = 0;
    int total_price = 0;

    printf("Welcome to the C Cafe Billing System!\n");
    printf("Enter the number of customers: ");
    scanf("%d", &num_customers);

    Customer customers[num_customers];
    for (int i = 0; i < num_customers; i++) {
        printf("Enter customer %d's name: ", i + 1);
        scanf("%s", customers[i].name);
        printf("Enter customer %d's ID: ", i + 1);
        scanf("%d", &customers[i].id);
    }

    printf("Enter the number of orders: ");
    scanf("%d", &num_orders);

    Order orders[num_orders];
    for (int i = 0; i < num_orders; i++) {
        printf("Enter order %d's item: ", i + 1);
        scanf("%s", orders[i].item);
        printf("Enter order %d's price: ", i + 1);
        scanf("%lf", &orders[i].price);
    }

    for (int i = 0; i < num_customers; i++) {
        for (int j = 0; j < num_orders; j++) {
            if (strcmp(customers[i].name, orders[j].item) == 0) {
                total_price += orders[j].price;
            }
        }
    }

    printf("Customer 1's total price: %.2lf\n", total_price);

    return 0;
}