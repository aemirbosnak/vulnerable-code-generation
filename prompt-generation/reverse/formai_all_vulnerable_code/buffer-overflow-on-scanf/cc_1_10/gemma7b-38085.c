//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 10, 50.0},
    {"Tea", 8, 40.0},
    {"Juice", 6, 30.0},
    {"Smoothie", 4, 20.0},
    {"Biscuits", 12, 10.0},
    {"Cookies", 8, 15.0},
    {"Scones", 6, 25.0},
    {"Muffins", 4, 35.0},
    {"Pancakes", 2, 45.0},
    {"Waffles", 3, 55.0}
};

int main() {

    int item_num = 0;
    char item_name[20];
    int item_quantity;
    float item_price;

    printf("Welcome to the C Cafe Billing System!\n");

    // Display menu items
    printf("Items:\n");
    for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++) {
        printf("%d. %s - %d - %.2f\n", item_num + 1, items[item_num].name, items[item_num].quantity, items[item_num].price);
    }

    // Get item name, quantity, and price
    printf("Enter item name: ");
    scanf("%s", item_name);

    for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++) {
        if (strcmp(items[item_num].name, item_name) == 0) {
            item_quantity = items[item_num].quantity;
            item_price = items[item_num].price;
            break;
        }
    }

    // Calculate total cost
    int total_cost = item_quantity * item_price;

    // Display total cost
    printf("Total cost: %.2f\n", total_cost);

    // Calculate tax (10%)
    float tax = total_cost * 0.1;

    // Display tax
    printf("Tax: %.2f\n", tax);

    // Calculate total amount
    float total_amount = total_cost + tax;

    // Display total amount
    printf("Total amount: %.2f\n", total_amount);

    return 0;
}