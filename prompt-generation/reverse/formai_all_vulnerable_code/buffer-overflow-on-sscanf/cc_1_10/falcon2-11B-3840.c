//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_PRICE 100.0

int main() {
    int items[MAX_ITEMS];
    double total = 0.0;
    int num_items = 0;
    char name[50];
    char order[100];

    printf("Welcome to the Cafe Billing System!\n");
    printf("Please enter your name:\n");
    scanf("%s", name);

    printf("What would you like to order? (type 'done' when finished)\n");
    while (1) {
        printf("> ");
        scanf("%s", order);

        if (strcmp(order, "done") == 0) {
            break;
        }

        char item[50];
        double price = 0.0;

        sscanf(order, "%s %lf", item, &price);

        if (num_items >= MAX_ITEMS) {
            printf("Sorry, you can't order that many items!\n");
            continue;
        }

        if (price > MAX_PRICE) {
            printf("Sorry, that item is too expensive!\n");
            continue;
        }

        items[num_items++] = strdup(item);
        total += price;
    }

    printf("Thank you for your order!\n");
    printf("Your total bill is $%.2f\n", total);
    printf("Your order was:\n");
    for (int i = 0; i < num_items; i++) {
        printf("- %s\n", items[i]);
    }

    free(items[0]);
    for (int i = 1; i < num_items; i++) {
        free(items[i]);
    }
    free(items);

    return 0;
}