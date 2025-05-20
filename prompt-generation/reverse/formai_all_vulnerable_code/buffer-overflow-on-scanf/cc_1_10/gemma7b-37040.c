//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct Coffee {
    char name[20];
    float price;
    int quantity;
} Coffee;

Coffee coffee_menu[] = {
    {"Cappuccino", 5.0, 0},
    {"Latte", 4.0, 0},
    {"Americano", 3.0, 0},
    {"Mocha", 4.5, 0},
    {"Macchiato", 4.0, 0}
};

int main() {
    int i, order_num = 1, total_price = 0;
    char customer_name[20];

    printf("Welcome to the Coffee Beanery, %s!\n", customer_name);
    printf("Please select your order:\n");

    for (i = 0; i < 5; i++) {
        printf("%d. %s - %.2f\n", i + 1, coffee_menu[i].name, coffee_menu[i].price);
    }

    printf("Enter your order number: ");
    scanf("%d", &order_num);

    for (i = 0; i < 5; i++) {
        if (coffee_menu[i].name[0] == order_num) {
            coffee_menu[i].quantity++;
            total_price += coffee_menu[i].price * coffee_menu[i].quantity;
        }
    }

    printf("Here is your order:\n");

    for (i = 0; i < 5; i++) {
        if (coffee_menu[i].quantity > 0) {
            printf("%s - %d cups\n", coffee_menu[i].name, coffee_menu[i].quantity);
        }
    }

    printf("Total price: $%.2f\n", total_price);
    printf("Thank you for your order, %s! Please enjoy your coffee!\n", customer_name);

    return 0;
}