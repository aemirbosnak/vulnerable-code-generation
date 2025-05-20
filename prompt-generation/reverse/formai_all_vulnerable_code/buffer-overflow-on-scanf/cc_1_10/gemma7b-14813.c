//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

int main() {
    int i, order_num = 1, total_price = 0;
    char ch;

    // Initialize items
    for (i = 0; i < MAX_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].quantity = 0;
        items[i].price = 0.0f;
    }

    // Menu loop
    do {
        printf("Enter item name: ");
        scanf("%s", items[order_num - 1].name);

        printf("Enter item quantity: ");
        scanf("%d", &items[order_num - 1].quantity);

        printf("Enter item price: ");
        scanf("%f", &items[order_num - 1].price);

        order_num++;
        printf("Do you want to continue ordering (Y/N)? ");
        scanf(" %c", &ch);
    } while (ch == 'Y');

    // Calculate total price
    for (i = 0; i < order_num - 1; i++) {
        total_price += items[i].quantity * items[i].price;
    }

    // Print receipt
    printf("Order Receipt\n");
    printf("Order Number: %d\n", order_num - 1);
    printf("Items:\n");
    for (i = 0; i < order_num - 1; i++) {
        printf("%s - %d @ %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("Total Price: $%.2f\n", total_price);
    printf("Thank you for your order!\n");

    return 0;
}