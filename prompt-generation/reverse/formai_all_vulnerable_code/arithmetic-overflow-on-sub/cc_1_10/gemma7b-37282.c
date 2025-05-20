//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 0, 5.0},
    {"Tea", 1, 3.5},
    {"Juice", 2, 4.0},
    {"Smoothie", 0, 6.0},
    {"Biscuits", 3, 2.0},
    {"Cookies", 2, 2.5},
    {"Brownies", 1, 3.0},
    {"Muffins", 0, 3.2},
    {"Scones", 0, 4.2},
    {"Pancakes", 0, 4.5}
};

int main() {
    int i, order_count = 0, total_price = 0;
    char item_name[20];
    int item_quantity;

    printf("Welcome to the C Cafe!\n");
    printf("Please select an item from the menu:\n");

    for (i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - %d - $%.2f\n", i + 1, items[i].name, items[i].quantity, items[i].price);
    }

    printf("\nEnter the item name and quantity:");
    scanf("%s %d", item_name, &item_quantity);

    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(item_name, items[i].name) == 0) {
            if (items[i].quantity >= item_quantity) {
                items[i].quantity -= item_quantity;
                order_count++;
                total_price += items[i].price * item_quantity;
            } else {
                printf("Sorry, insufficient quantity.\n");
            }
        }
    }

    if (order_count > 0) {
        printf("Your order has been placed!\n");
        printf("Total price: $%.2f\n", total_price);
        printf("Thank you for your visit!\n");
    } else {
        printf("Invalid item selection.\n");
    }

    return 0;
}