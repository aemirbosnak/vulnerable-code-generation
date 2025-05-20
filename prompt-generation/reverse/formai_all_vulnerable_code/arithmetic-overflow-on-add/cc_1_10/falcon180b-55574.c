//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10
#define MAX_QUANTITY_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
} item_t;

typedef struct {
    int num_items;
    item_t items[MAX_ITEMS];
} order_t;

void add_item(order_t* order) {
    printf("Enter item name: ");
    scanf("%s", order->items[order->num_items].name);
    printf("Enter item price: ");
    scanf("%s", order->items[order->num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &order->items[order->num_items].quantity);
    order->num_items++;
}

void display_order(order_t* order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s - %s - %d\n", order->items[i].name, order->items[i].price, order->items[i].quantity);
    }
}

void calculate_total(order_t* order) {
    int total = 0;
    for (int i = 0; i < order->num_items; i++) {
        total += order->items[i].quantity * atoi(order->items[i].price);
    }
    printf("Total: %d\n", total);
}

int main() {
    order_t order;
    order.num_items = 0;

    int choice;
    do {
        printf("Cafe Billing System\n");
        printf("1. Add item\n");
        printf("2. Display order\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&order);
                break;
            case 2:
                display_order(&order);
                break;
            case 3:
                calculate_total(&order);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}