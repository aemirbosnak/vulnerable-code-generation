//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_ORDERS 1000
#define MAX_MENU_ITEMS 50

typedef struct Order {
    int tableNumber;
    float totalPrice;
} Order;

typedef struct MenuItem {
    char name[50];
    float price;
} MenuItem;

void print_menu(MenuItem menu[], int num_items) {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

int main() {
    MenuItem menu[MAX_MENU_ITEMS] = {
        {"Coffee", 1.99},
        {"Tea", 1.50},
        {"Burger", 4.99},
        {"Fries", 1.99},
        {"Salad", 2.99}
    };
    int num_menu_items = 5;

    Order orders[MAX_ORDERS];
    int num_orders = 0;

    printf("Welcome to Knuth's Cafe!\n");

    while (1) {
        printf("Enter table number or 0 to exit: ");
        int table_number;
        scanf("%d", &table_number);
        if (table_number == 0) break;

        float total_price = 0.0;
        int order_count = 0;

        while (1) {
            print_menu(menu, num_menu_items);
            printf("Enter item number or 0 to finish order: ");
            int item_number;
            scanf("%d", &item_number);
            if (item_number == 0) break;

            MenuItem item = menu[item_number - 1];
            total_price += item.price;

            order_count++;
        }

        Order order = {table_number, total_price};
        orders[num_orders] = order;
        num_orders++;

        printf("Order for table %d:\n", table_number);
        printf("%d items - $%.2f\n", order_count, total_price);
        printf("Press enter to continue");
        getchar(); // wait for user to press enter
        getchar(); // consume enter character
    }

    printf("Summary of orders:\n");
    for (int i = 0; i < num_orders; i++) {
        Order order = orders[i];
        printf("Table %d - $%.2f\n", order.tableNumber, order.totalPrice);
    }

    return 0;
}