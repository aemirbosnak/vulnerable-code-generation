//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10
#define MAX_QUANTITY_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char price[MAX_PRICE_LENGTH + 1];
    char quantity[MAX_QUANTITY_LENGTH + 1];
    float cost;
} item_t;

int main() {
    int num_items = 0;
    item_t items[MAX_ITEMS];
    char input[MAX_ITEMS][MAX_NAME_LENGTH + MAX_PRICE_LENGTH + MAX_QUANTITY_LENGTH + 2];
    int i, j, k, l;
    float total_cost = 0.0;

    printf("Welcome to the Cafe Billing System!\n");
    printf("Please enter the number of items you would like to order:\n");
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("Please enter the name of item %d:\n", i + 1);
        scanf("%s", input[i]);
        strcpy(items[i].name, input[i]);

        printf("Please enter the price of item %d:\n", i + 1);
        scanf("%s", input[i]);
        strcpy(items[i].price, input[i]);

        printf("Please enter the quantity of item %d:\n", i + 1);
        scanf("%s", input[i]);
        strcpy(items[i].quantity, input[i]);

        items[i].cost = atof(items[i].price) * atoi(items[i].quantity);
        total_cost += items[i].cost;
    }

    printf("\nYour order:\n");
    for (i = 0; i < num_items; i++) {
        printf("Item %d: %s\n", i + 1, items[i].name);
        printf("Price: $%s\n", items[i].price);
        printf("Quantity: %s\n", items[i].quantity);
        printf("Cost: $%.2f\n\n", items[i].cost);
    }

    printf("Total cost: $%.2f\n", total_cost);

    return 0;
}