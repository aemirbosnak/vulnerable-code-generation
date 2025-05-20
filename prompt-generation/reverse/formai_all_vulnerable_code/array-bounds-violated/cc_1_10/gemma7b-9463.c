//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: standalone
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
    {"Tea", 8, 4.0},
    {"Juice", 6, 3.5},
    {"Smoothie", 7, 4.5},
    {"Water", 9, 2.0},
    {"Soda", 5, 3.0},
    {"Energy Drink", 4, 3.2},
    {"Coffee Cake", 3, 6.0},
    {"Apple Pie", 2, 5.5},
    {"Chocolate Cake", 1, 7.0}
};

int main() {
    int i, totalItems = 0, itemChoice, quantity;
    float totalAmount = 0.0;

    printf("Welcome to the C Cafe Billing System!\n");

    for (i = 0; i < MAX_ITEMS; i++) {
        items[i].quantity = items[i].quantity - 1;
        totalItems++;
    }

    printf("Total number of items: %d\n", totalItems);

    printf("Please select an item: ");
    scanf("%d", &itemChoice);

    printf("Please enter the quantity of the item: ");
    scanf("%d", &quantity);

    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == items[itemChoice].name[0]) {
            items[i].quantity++;
            totalAmount += items[i].price * quantity;
        }
    }

    printf("Total amount: $%.2f\n", totalAmount);

    printf("Thank you for your visit to the C Cafe!\n");

    return 0;
}