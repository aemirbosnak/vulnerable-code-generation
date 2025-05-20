//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 5.0, 10},
    {"Tea", 4.0, 8},
    {"Juice", 3.0, 6},
    {"Smoothie", 6.0, 4},
    {"Ice Cream", 7.0, 3}
};

int main() {
    int i, order_num = 0, total_price = 0;
    char customer_name[20];

    printf("Welcome to the C Cafe! Please enter your name: ");
    scanf("%s", customer_name);

    printf("Hello, %s! Please select an item from the menu:\n", customer_name);

    for (i = 0; i < MAX_ITEM_NUM; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }

    printf("Enter the number of the item you want to order: ");
    scanf("%d", &order_num);

    if (order_num > MAX_ITEM_NUM || order_num < 1) {
        printf("Invalid item number. Please try again.\n");
    } else {
        int item_quantity;

        printf("Enter the quantity of the item you want to order: ");
        scanf("%d", &item_quantity);

        items[order_num - 1].quantity -= item_quantity;

        total_price += items[order_num - 1].price * item_quantity;
    }

    printf("Thank you for your order, %s! Your total price is $%.2f. Please come again next time!\n", customer_name, total_price);

    return 0;
}