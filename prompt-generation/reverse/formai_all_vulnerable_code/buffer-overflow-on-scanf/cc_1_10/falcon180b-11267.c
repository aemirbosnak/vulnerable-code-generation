//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 10
#define MAX_QUANTITY_LEN 10

// Menu items
struct menu_item {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    char quantity[MAX_QUANTITY_LEN];
};

int main() {
    int num_items;
    struct menu_item items[MAX_ITEMS];

    // Read in menu items
    printf("Enter number of items on menu (up to %d): ", MAX_ITEMS);
    scanf("%d", &num_items);
    for (int i = 0; i < num_items; i++) {
        printf("Enter name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter price of item %d: ", i+1);
        scanf("%s", items[i].price);
        printf("Enter quantity of item %d: ", i+1);
        scanf("%s", items[i].quantity);
    }

    // Print menu
    printf("\nMenu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%s - %s\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }

    // Accept customer orders
    int num_orders;
    printf("\nEnter number of orders: ");
    scanf("%d", &num_orders);
    for (int i = 0; i < num_orders; i++) {
        int item_num;
        printf("Enter item number for order %d: ", i+1);
        scanf("%d", &item_num);
        if (item_num < 1 || item_num > num_items) {
            printf("Invalid item number.\n");
            continue;
        }
        items[item_num-1].quantity[0] = '\0';
        printf("Order %d: %s - $%s - %s\n", i+1, items[item_num-1].name, items[item_num-1].price, items[item_num-1].quantity);
    }

    return 0;
}