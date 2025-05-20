//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 0, 5.0},
    {"Tea", 0, 4.0},
    {"Juice", 0, 3.0},
    {"Smoothie", 0, 6.0},
    {"Biscuits", 0, 2.0},
    {"Cookies", 0, 1.5},
    {"Brownies", 0, 3.5},
    {"Cake", 0, 4.5},
    {"Ice Cream", 0, 2.2},
    {"Coffee Cake", 0, 6.0}
};

int main() {
    char order[200];
    int i, item_count = 0, total_cost = 0;

    printf("Welcome to the C Cafe!\n");
    printf("Please enter your order: ");

    scanf("%s", order);

    for (i = 0; items[i].name[0] != '\0'; i++) {
        if (strstr(order, items[i].name) != NULL) {
            items[i].quantity++;
            item_count++;
            total_cost += items[i].price * items[i].quantity;
        }
    }

    if (item_count == 0) {
        printf("Error: Invalid item.\n");
    } else {
        printf("Your order:\n");
        for (i = 0; items[i].name[0] != '\0'; i++) {
            if (items[i].quantity > 0) {
                printf("%s: %d, $%.2f\n", items[i].name, items[i].quantity, items[i].price);
            }
        }

        printf("Total cost: $%.2f\n", total_cost);
        printf("Thank you for your order. Enjoy your C Cafe experience!\n");
    }

    return 0;
}