//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct orders
{
    char item_name[20];
    float price;
    int quantity;
};

float total_price(int qty, float price)
{
    return qty * price;
}

int main()
{
    int num_of_items;
    printf("Welcome to The Artistic Cafe Billing System!");
    printf("\n\nHow many items did the customer order? ");
    scanf("%d", &num_of_items);

    struct orders order[num_of_items];

    for(int i=0; i<num_of_items; i++)
    {
        printf("\nItem %d\n", i+1);
        printf("Enter the item name: ");
        scanf("%s", order[i].item_name);
        printf("Enter the item price: ");
        scanf("%f", &order[i].price);
        printf("Enter the quantity: ");
        scanf("%d", &order[i].quantity);
    }

    float subtotal = 0;
    printf("\n\nItem\t\tQuantity\tPrice\t\tTotal\n");
    for(int i=0; i<num_of_items; i++)
    {
        printf("%s\t\t%d\t\t%.2f\t\t%.2f\n", order[i].item_name, order[i].quantity, order[i].price, total_price(order[i].quantity, order[i].price));
        subtotal += total_price(order[i].quantity, order[i].price);
    }

    float tax = subtotal * 0.1;
    float grand_total = subtotal + tax;
    printf("\n\nSubtotal: $%.2f", subtotal);
    printf("\nTax: $%.2f", tax);
    printf("\nGrand Total: $%.2f", grand_total);

    printf("\n\nThank you for using The Artistic Cafe Billing System!");

    return 0;
}