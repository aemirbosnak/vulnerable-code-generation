//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 10, 5.0},
    {"Tea", 5, 4.0},
    {"Juice", 7, 3.5},
    {"Smoothie", 8, 6.0},
    {"Biscuits", 12, 2.0},
    {"Cookies", 9, 2.5},
    {"Brownies", 6, 3.0},
    {"Muffins", 3, 4.5},
    {"Scones", 4, 3.2},
    {"Pancakes", 2, 4.0}
};

int main() {
    int item_no;
    char item_name[20];
    int quantity;
    float total_price = 0.0;

    printf("Welcome to the C Cafe Billing System!\n");

    // Loop to get the item number
    printf("Enter the item number: ");
    scanf("%d", &item_no);

    // Validate the item number
    if (item_no < 0 || item_no >= MAX_ITEMS) {
        printf("Invalid item number.\n");
        return 1;
    }

    // Get the item name, quantity, and price
    strcpy(item_name, items[item_no].name);
    quantity = items[item_no].quantity;
    float price = items[item_no].price;

    // Calculate the total price
    total_price = quantity * price;

    // Print the item name, quantity, and total price
    printf("Item name: %s\n", item_name);
    printf("Quantity: %d\n", quantity);
    printf("Total price: %.2f\n", total_price);

    // Calculate the tax and total amount
    float tax = total_price * 0.1;
    float total_amount = total_price + tax;

    // Print the tax and total amount
    printf("Tax: %.2f\n", tax);
    printf("Total amount: %.2f\n", total_amount);

    return 0;
}