//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

int main() {
    int i, total_items = 0;
    float total_amount = 0.0f;

    // Initialize items
    for (i = 0; i < MAX_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].quantity = 0;
        items[i].price = 0.0f;
    }

    // Add items to the cart
    printf("Enter item name: ");
    scanf("%s", items[total_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[total_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[total_items].price);

    total_items++;

    // Calculate total amount
    for (i = 0; i < total_items; i++) {
        total_amount += items[i].quantity * items[i].price;
    }

    // Print invoice
    printf("------------------------\n");
    printf("Item Name:  \t\tQuantity:  \tPrice:  \tTotal Cost:\n");
    printf("------------------------\n");

    for (i = 0; i < total_items; i++) {
        printf("%s\t\t%d\t\t%.2f\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price, items[i].quantity * items[i].price);
    }

    printf("\nTotal Amount: $%.2f\n", total_amount);

    return 0;
}