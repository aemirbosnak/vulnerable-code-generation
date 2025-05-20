//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDER 10
#define MAX_ITEM_NAME 20
#define MAX_ITEM_PRICE 10

struct item {
    char name[MAX_ITEM_NAME];
    double price;
};

struct order {
    struct item items[MAX_ORDER];
    int num_items;
};

int main() {
    struct order orders[MAX_ORDER];
    int num_orders = 0;

    struct item menu[] = {
        {"Ale", 3.50},
        {"Bread", 2.00},
        {"Stew", 5.00},
        {"Roast Chicken", 7.00},
        {"Flagon of Wine", 10.00},
        {"Whiskey", 6.00},
        {"Cheese", 4.00},
        {"Honey Cake", 3.00},
        {"Mead", 4.50},
        {"Fruit Tart", 4.00}
    };

    int num_items = sizeof(menu) / sizeof(struct item);

    printf("Welcome to Ye Olde Cafe!\n");

    while (1) {
        printf("\nWhat would you like?\n");

        for (int i = 0; i < num_items; i++) {
            printf("%d. %s - %.2f coins\n", i+1, menu[i].name, menu[i].price);
        }

        printf("Enter \"0\" to finish order.\n");

        int selection;
        scanf("%d", &selection);

        if (selection == 0) {
            break;
        }

        if (num_orders >= MAX_ORDER) {
            printf("Sorry, we cannot take any more orders.\n");
            break;
        }

        if (selection < 1 || selection > num_items) {
            printf("Invalid selection. Please select a number between 1 and %d.\n", num_items);
            continue;
        }

        struct item chosen = menu[selection - 1];
        orders[num_orders].items[0] = chosen;
        orders[num_orders].num_items = 1;

        printf("You have chosen: %s\n", chosen.name);

        printf("Enter quantity:\n");

        int quantity;
        scanf("%d", &quantity);

        if (quantity <= 0) {
            printf("Quantity must be a positive integer.\n");
            continue;
        }

        orders[num_orders].items[0].price = chosen.price * quantity;

        printf("Your order of %d %s will cost %.2f coins. Proceed to payment?\n", quantity, chosen.name, orders[num_orders].items[0].price);

        printf("Enter \"y\" for yes, or any other key for no:\n");

        char response[10];
        scanf("%s", response);

        if (strcmp(response, "y") == 0) {
            printf("Payment accepted.\n");
            num_orders++;
        } else {
            printf("Payment declined. Order cancelled.\n");
        }
    }

    printf("\nThank you for visiting Ye Olde Cafe!\n");

    return 0;
}