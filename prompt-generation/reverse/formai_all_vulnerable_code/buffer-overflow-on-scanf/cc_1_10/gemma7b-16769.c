//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 10, 5.0},
    {"Tea", 8, 4.0},
    {"Juice", 6, 3.0},
    {"Water", 4, 2.0},
    {"Smoothie", 2, 7.0},
    {"Ice Cream", 3, 6.0},
    {"Pizza", 1, 9.0},
    {"Pasta", 0, 8.0},
    {"Salad", 5, 4.0},
    {"Sandwich", 6, 3.0}
};

void display_menu() {
    int i;
    for (i = 0; i < MAX_ITEM_NUM; i++) {
        printf("%d. %s - %d - $%.2lf\n", i + 1, items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    int item_num;
    char item_name[20];
    int quantity;
    double total_price = 0.0;

    display_menu();

    printf("Enter item number: ");
    scanf("%d", &item_num);

    if (item_num > 0 && item_num <= MAX_ITEM_NUM) {
        strcpy(item_name, items[item_num - 1].name);
        quantity = items[item_num - 1].quantity;
        total_price += items[item_num - 1].price * quantity;
    } else {
        printf("Invalid item number.\n");
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if (quantity > 0) {
        items[item_num - 1].quantity -= quantity;
        total_price += items[item_num - 1].price * quantity;
    } else {
        printf("Invalid quantity.\n");
    }

    printf("Total price: $%.2lf\n", total_price);

    return 0;
}