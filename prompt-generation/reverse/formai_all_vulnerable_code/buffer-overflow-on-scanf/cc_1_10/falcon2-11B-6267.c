//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

typedef struct {
    char name[50];
    double price;
} item;

typedef struct {
    char name[50];
    int quantity;
    double total_price;
} order;

int main() {
    item items[10];
    int n = 0;
    printf("Welcome to the Cafe Billing System!\n");
    printf("Enter the number of items: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter item name: ");
        scanf("%s", items[i].name);
        printf("Enter item price: ");
        scanf("%lf", &items[i].price);
    }
    order orders[10];
    int m = 0;
    printf("Enter the number of orders: ");
    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
        printf("Enter order name: ");
        scanf("%s", orders[j].name);
        printf("Enter order quantity: ");
        scanf("%d", &orders[j].quantity);
    }
    double total_price = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strcmp(orders[j].name, items[i].name) == 0) {
                orders[j].total_price = orders[j].quantity * items[i].price;
                total_price += orders[j].total_price;
            }
        }
    }
    printf("Total price: %.2f\n", total_price);
    return 0;
}