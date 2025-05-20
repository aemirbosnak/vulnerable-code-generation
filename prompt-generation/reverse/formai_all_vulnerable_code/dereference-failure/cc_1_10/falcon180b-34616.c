//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20

struct item {
    char name[50];
    float price;
};

struct order {
    int num_items;
    struct item items[MAX_ITEMS];
};

void add_item(struct order* order, char* name, float price) {
    if (order->num_items >= MAX_ITEMS) {
        printf("Sorry, you can only order up to %d items.\n", MAX_ITEMS);
        return;
    }

    strcpy(order->items[order->num_items].name, name);
    order->items[order->num_items].price = price;
    order->num_items++;
}

float calculate_total(struct order order) {
    float total = 0.0;

    for (int i = 0; i < order.num_items; i++) {
        total += order.items[i].price;
    }

    return total;
}

int main() {
    struct order order;
    char input[100];

    printf("Welcome to the C Cafe!\n");
    printf("Please enter your order (name price):\n");

    while (fgets(input, sizeof(input), stdin)) {
        char* name = strtok(input, " ");
        float price = atof(strtok(NULL, " "));

        if (name == NULL || price <= 0.0) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        add_item(&order, name, price);
    }

    printf("Your order:\n");

    for (int i = 0; i < order.num_items; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }

    printf("Total: $%.2f\n", calculate_total(order));

    return 0;
}