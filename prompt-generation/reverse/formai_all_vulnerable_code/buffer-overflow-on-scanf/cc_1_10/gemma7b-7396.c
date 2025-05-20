//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

Item items[] = {
    {"Coffee", 5.0, 10},
    {"Tea", 4.0, 8},
    {"Juice", 3.0, 12},
    {"Smoothie", 6.0, 9}
};

int main() {
    int i, order_num = 1, total_price = 0;
    char customer_name[20];

    printf("Welcome to the C Cafe!\n");
    printf("Please enter your name: ");
    scanf("%s", customer_name);

    printf("What would you like to order?\n");

    for (i = 0; i < 4; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }

    int item_choice;

    printf("Please enter the number of your choice: ");
    scanf("%d", &item_choice);

    int item_quantity;

    printf("Please enter the quantity of your item: ");
    scanf("%d", &item_quantity);

    Item item = items[item_choice - 1];

    total_price += item.price * item_quantity;

    printf("Your order:\n");
    printf("%s - %d units - $%.2f\n", item.name, item_quantity, item.price * item_quantity);

    printf("Total price: $%.2f\n", total_price);

    printf("Thank you, %s! Enjoy your C Cafe experience!\n", customer_name);

    return 0;
}