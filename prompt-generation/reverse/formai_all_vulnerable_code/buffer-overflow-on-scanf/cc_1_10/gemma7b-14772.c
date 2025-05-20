//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void main() {
    system("cls");
    int item_no, quantity;
    float total_cost = 0, item_price;

    // Display menu
    printf("Welcome to Cafe XYZ!\n");
    printf("------------------------\n");
    printf("Item No. | Item Name | Price\n");
    printf("------------------------\n");
    printf("1 | Coffee | $2.00\n");
    printf("2 | Tea | $1.50\n");
    printf("3 | Juice | $1.25\n");
    printf("4 | Smoothie | $1.75\n");
    printf("------------------------\n");

    // Get item number and quantity
    printf("Enter item number: ");
    scanf("%d", &item_no);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Calculate item price
    switch (item_no) {
        case 1:
            item_price = 2.00 * quantity;
            break;
        case 2:
            item_price = 1.50 * quantity;
            break;
        case 3:
            item_price = 1.25 * quantity;
            break;
        case 4:
            item_price = 1.75 * quantity;
            break;
        default:
            printf("Invalid item number.\n");
            return;
    }

    // Add item price to total cost
    total_cost += item_price;

    // Display total cost
    printf("Total cost: $%.2f\n", total_cost);

    // Calculate tax and total amount
    float tax = total_cost * 0.10;
    float total_amount = total_cost + tax;

    // Display tax and total amount
    printf("Tax: $%.2f\n", tax);
    printf("Total amount: $%.2f\n", total_amount);

    // Thank you message
    printf("Thank you for your order! Come again soon!\n");

    return;
}