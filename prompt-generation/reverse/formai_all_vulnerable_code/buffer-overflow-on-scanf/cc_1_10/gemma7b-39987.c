//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 5.0, 10},
    {"Tea", 3.0, 5},
    {"Juice", 4.0, 7},
    {"Smoothie", 6.0, 8},
    {"Soda", 2.0, 9}
};

int main() {
    int i, order_num = 0, total_amount = 0;
    char customer_name[50];
    printf("Welcome to the Crazy Coffee Cafe!\n");
    printf("Please enter your name: ");
    scanf("%s", customer_name);
    printf("Hello, %s, please select an item from the menu:\n", customer_name);

    for (i = 0; i < MAX_ITEM_NUM; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }

    printf("Enter the number of the item you want to order: ");
    scanf("%d", &order_num);

    if (order_num > MAX_ITEM_NUM || order_num <= 0) {
        printf("Invalid item number.\n");
    } else {
        int item_quantity;
        printf("Enter the quantity of the item you want to order: ");
        scanf("%d", &item_quantity);

        items[order_num - 1].quantity -= item_quantity;

        total_amount += items[order_num - 1].price * item_quantity;
        printf("Your order has been placed. Please wait for your item.\n");
    }

    printf("Total amount: $%.2f\n", total_amount);
    printf("Thank you for visiting the Crazy Coffee Cafe, %s!\n", customer_name);

    return 0;
}