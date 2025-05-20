//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

struct item {
    char name[50];
    float price;
};

struct order {
    int num_items;
    struct item items[MAX_ITEMS];
};

void display_menu(struct item items[], int num_items) {
    printf("Cafe Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

int main() {
    struct item menu_items[MAX_ITEMS];
    int num_menu_items = 0;

    // Populate menu items
    strcpy(menu_items[num_menu_items].name, "Coffee");
    menu_items[num_menu_items].price = 2.50;
    num_menu_items++;

    strcpy(menu_items[num_menu_items].name, "Tea");
    menu_items[num_menu_items].price = 1.50;
    num_menu_items++;

    strcpy(menu_items[num_menu_items].name, "Pastry");
    menu_items[num_menu_items].price = 3.00;
    num_menu_items++;

    struct order customer_order;
    customer_order.num_items = 0;

    while (1) {
        display_menu(menu_items, num_menu_items);
        printf("Enter the number of the item you want to order or 0 to checkout:\n");
        scanf("%d", &customer_order.items[customer_order.num_items].name);
        if (customer_order.items[customer_order.num_items].name == 0) {
            break;
        }
        customer_order.num_items++;
    }

    float total_price = 0.0;
    printf("Your order:\n");
    for (int i = 0; i < customer_order.num_items; i++) {
        printf("%s - $%.2f\n", customer_order.items[i].name, customer_order.items[i].price);
        total_price += customer_order.items[i].price;
    }
    printf("Total price: $%.2f\n", total_price);

    return 0;
}