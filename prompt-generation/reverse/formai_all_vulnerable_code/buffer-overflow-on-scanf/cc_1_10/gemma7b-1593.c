//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 5.0, 10},
    {"Tea", 3.0, 5},
    {"Juice", 4.0, 7},
    {"Water", 2.0, 8},
    {"Soda", 3.5, 6},
    {"Smoothie", 4.5, 3},
    {"Ice Cream", 2.5, 4},
    {"Cookies", 1.5, 2},
    {"Brownies", 2.0, 1},
    {"Muffins", 2.2, 3}
};

int main() {

    int i, total_items = 0, total_amount = 0;
    char item_name[20];
    float item_price;
    int item_quantity;

    printf("Welcome to the C Cafe Billing System!\n");

    // Calculate total number of items
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity > 0) {
            total_items++;
        }
    }

    // Display total number of items
    printf("Total number of items: %d\n", total_items);

    // Get item name, price, and quantity
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Find item and calculate total amount
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(item_name, items[i].name) == 0) {
            item_price = items[i].price;
            item_quantity = items[i].quantity;
            total_amount += item_price * item_quantity;
        }
    }

    // Display total amount
    printf("Total amount: $%.2f\n", total_amount);

    // Calculate tax and total cost
    float tax = 0.08 * total_amount;
    int total_cost = (int)(total_amount + tax);

    // Display tax and total cost
    printf("Tax: $%.2f\n", tax);
    printf("Total cost: $%d\n", total_cost);

    return 0;
}