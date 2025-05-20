//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Ale", 5, 3.5},
    {"Bread", 2, 2.0},
    {"Fish", 1, 4.0},
    {"Honey", 4, 1.5},
    {"Meat", 3, 5.0},
    {"Noodle", 1, 3.0},
    {"Pie", 2, 2.5},
    {"Soup", 3, 2.0},
    {"Tea", 4, 1.0},
    {"Water", 2, 1.2}
};

int main() {
    int i, order_num = 1, item_num = 0;
    float total_price = 0.0;

    printf("Welcome to The Golden Dragon Inn!\n");
    printf("Please select an item from the menu:**\n");

    for (i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - %d units - %.2f each\n", i + 1, items[i].name, items[i].quantity, items[i].price);
    }

    printf("Enter the number of the item you want to order: ");
    scanf("%d", &item_num);

    if (item_num > MAX_ITEMS || item_num < 1) {
        printf("Invalid item number.\n");
    } else {
        int quantity;

        printf("Enter the quantity you want to order: ");
        scanf("%d", &quantity);

        if (quantity > items[item_num - 1].quantity) {
            printf("Sorry, there is not enough of that item.\n");
        } else {
            items[item_num - 1].quantity -= quantity;
            total_price += quantity * items[item_num - 1].price;
            order_num++;
        }
    }

    printf("Thank you for your order. Your order number is: %d\n", order_num);
    printf("Total price: %.2f\n", total_price);

    return 0;
}