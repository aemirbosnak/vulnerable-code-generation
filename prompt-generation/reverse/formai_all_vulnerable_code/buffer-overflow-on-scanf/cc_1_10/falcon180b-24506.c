//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
} item_t;

int main() {
    int num_items, i, j;
    char input[100];
    item_t items[MAX_ITEMS];
    double total_price = 0.0;

    printf("Welcome to the Cafe Billing System!\n");
    printf("Please enter the number of items you want to order: ");
    scanf("%d", &num_items);

    // Read in the items
    for (i = 0; i < num_items; i++) {
        printf("Please enter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Please enter the price of item %d: ", i+1);
        scanf("%s", items[i].price);
        items[i].quantity = 1;
    }

    // Calculate the total price
    for (i = 0; i < num_items; i++) {
        total_price += atof(items[i].price) * items[i].quantity;
    }

    // Print out the order
    printf("\nYour order:\n");
    for (i = 0; i < num_items; i++) {
        printf("%s - $%.2f (x %d) = $%.2f\n", items[i].name, atof(items[i].price), items[i].quantity, atof(items[i].price) * items[i].quantity);
    }

    // Print out the total price
    printf("\nTotal price: $%.2f\n", total_price);

    return 0;
}