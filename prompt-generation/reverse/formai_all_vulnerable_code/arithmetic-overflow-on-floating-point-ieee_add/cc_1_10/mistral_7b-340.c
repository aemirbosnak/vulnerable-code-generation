//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 10
#define MAX_NAME_LEN 20
#define MAX_ORDER_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} Item;

typedef struct {
    int id;
    Item items[MAX_ITEMS];
    int num_items;
    float total;
} Order;

Item menu[] = {
    {"Burger", 5.99},
    {"Sandwich", 4.99},
    {"Pizza", 8.99},
    {"Salad", 3.99},
    {"Soda", 1.99}
};

void print_menu() {
    printf("\n---- MENU ----\n");
    for (int i = 0; i < sizeof(menu) / sizeof(Item); i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

void add_item_to_order(Order *order, Item item) {
    if (order->num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    order->items[order->num_items] = item;
    order->num_items++;
    order->total += item.price;
}

void print_order(Order order) {
    printf("\nOrder #%d\n", order.id);
    printf("-------------------------\n");

    for (int i = 0; i < order.num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, order.items[i].name, order.items[i].price);
    }

    printf("-------------------------\n");
    printf("Total: $%.2f\n", order.total);
}

int main() {
    Order current_order = {.id = 0, .num_items = 0};

    print_menu();

    char input[MAX_ORDER_LEN];
    while (1) {
        printf("\nEnter your order (Q to quit): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "Q") == 0) {
            break;
        }

        char *token = strtok(input, " ");
        int item_id;
        sscanf(token, "%d", &item_id);

        Item chosen_item = menu[item_id-1];
        add_item_to_order(&current_order, chosen_item);
    }

    print_order(current_order);

    printf("\nTotal sales: $%.2f\n", current_order.total);

    return 0;
}