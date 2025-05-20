//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QTY 100
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LEN];
    int qty;
    float price;
} Item;

int main() {
    int numItems, i;
    char input[100];
    char name[MAX_NAME_LEN];
    int qty;
    float price;
    Item items[MAX_ITEMS];
    float total = 0;

    printf("Welcome to the Cafe Billing System!\n");
    printf("Enter the number of items you would like to order: ");
    scanf("%d", &numItems);

    for (i = 0; i < numItems; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", name);
        printf("Enter the quantity of %s: ", name);
        scanf("%d", &qty);
        printf("Enter the price of %s: $", name);
        scanf("%f", &price);

        strcpy(items[i].name, name);
        items[i].qty = qty;
        items[i].price = price;

        total += qty * price;
    }

    printf("\nYour order:\n");
    for (i = 0; i < numItems; i++) {
        printf("%s - %d x $%.2f = $%.2f\n", items[i].name, items[i].qty, items[i].price, items[i].price * items[i].qty);
    }

    printf("\nTotal: $%.2f\n", total);

    return 0;
}