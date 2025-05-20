//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 10

typedef struct Order {
    char name[50];
    char item[50];
    int quantity;
    float price;
} Order;

Order orders[MAX_ORDERS];

int main() {

    int i = 0;
    char ch;

    // Welcome the customer
    printf("Welcome to the C Cafe!\n");

    // Create a loop to get the customer's order
    while (1) {
        printf("Please enter your name: ");
        scanf("%s", orders[i].name);

        printf("Please enter the item you want: ");
        scanf("%s", orders[i].item);

        printf("Please enter the quantity you want: ");
        scanf("%d", &orders[i].quantity);

        printf("Please enter the price of the item: ");
        scanf("%f", &orders[i].price);

        i++;

        // Check if the customer wants to continue ordering
        printf("Do you want to continue ordering? (Y/N): ");
        scanf(" %c", &ch);

        if (ch == 'N') {
            break;
        }
    }

    // Calculate the total cost of the order
    float total_cost = 0;
    for (i = 0; i < MAX_ORDERS; i++) {
        total_cost += orders[i].quantity * orders[i].price;
    }

    // Print the order summary
    printf("Order Summary:\n");
    for (i = 0; i < MAX_ORDERS; i++) {
        printf("%s ordered %d %s for $%.2f\n", orders[i].name, orders[i].quantity, orders[i].item, orders[i].price);
    }

    // Print the total cost
    printf("Total Cost: $%.2f\n", total_cost);

    // Thank the customer
    printf("Thank you for your order!\n");

    return 0;
}