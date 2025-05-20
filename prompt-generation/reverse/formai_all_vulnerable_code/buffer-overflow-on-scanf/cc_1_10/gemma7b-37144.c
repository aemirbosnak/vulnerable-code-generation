//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 10, 3.5},
    {"Tea", 8, 2.5},
    {"Juice", 6, 2.0},
    {"Smoothie", 4, 4.0},
    {"Biscuits", 12, 1.5},
    {"Cookies", 8, 1.2},
    {"Cake", 6, 2.2},
    {"Pie", 4, 2.8},
    {"Ice Cream", 2, 3.2},
    {"Smoothie Juice", 1, 4.5}
};

int main() {

    int item_no = 0;
    char customer_name[20];
    int total_items = 0;
    float total_amount = 0.0;

    printf("Welcome to Cafe XYZ!\n");

    // Get customer name
    printf("Please enter your name: ");
    scanf("%s", customer_name);

    // Display menu
    printf("Menu:\n");
    for (item_no = 0; item_no < MAX_ITEMS; item_no++) {
        printf("%d. %s - %d pieces - $%.2f\n", item_no + 1, items[item_no].name, items[item_no].quantity, items[item_no].price);
    }

    // Order items
    int order_item_no;
    printf("Enter the number of the item you want to order: ");
    scanf("%d", &order_item_no);

    // Validate order item number
    if (order_item_no < 1 || order_item_no > MAX_ITEMS) {
        printf("Invalid item number.\n");
        return 1;
    }

    // Add item to order
    items[order_item_no - 1].quantity--;
    total_items++;
    total_amount += items[order_item_no - 1].price;

    // Continue ordering or exit
    char continue_order;
    printf("Do you want to continue ordering (Y/N)? ");
    scanf(" %c", &continue_order);

    // Repeat ordering until customer decides to exit
    while (continue_order == 'Y') {
        order_item_no = 0;
        printf("Enter the number of the item you want to order: ");
        scanf("%d", &order_item_no);

        // Validate order item number
        if (order_item_no < 1 || order_item_no > MAX_ITEMS) {
            printf("Invalid item number.\n");
            return 1;
        }

        // Add item to order
        items[order_item_no - 1].quantity--;
        total_items++;
        total_amount += items[order_item_no - 1].price;

        // Continue ordering or exit
        printf("Do you want to continue ordering (Y/N)? ");
        scanf(" %c", &continue_order);
    }

    // Calculate total amount due
    float tax = 0.08;
    float total_due = total_amount * (1 + tax);

    // Print receipt
    printf("\nThank you for your order, %s!\n", customer_name);
    printf("Your total order: %d items\n", total_items);
    printf("Total amount: $%.2f\n", total_amount);
    printf("Tax: 8% - $%.2f\n", tax * total_amount);
    printf("Total due: $%.2f\n", total_due);

    return 0;
}