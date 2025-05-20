//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDER_SIZE 10

typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int qty;
    MenuItem item;
} OrderItem;

typedef struct {
    OrderItem orders[MAX_ORDER_SIZE];
    int num_orders;
} OrderList;

void add_item_to_order(OrderList *orders, MenuItem item, int qty) {
    if (orders->num_orders < MAX_ORDER_SIZE) {
        orders->orders[orders->num_orders].item = item;
        orders->orders[orders->num_orders].qty = qty;
        orders->num_orders++;
    } else {
        printf("Order list is full.\n");
    }
}

float calculate_total(OrderList orders) {
    float total = 0.0;
    for (int i = 0; i < orders.num_orders; i++) {
        total += orders.orders[i].item.price * orders.orders[i].qty;
    }
    return total;
}

void print_order(OrderItem order) {
    printf("%s: %d x %0.2f\n", order.item.name, order.qty, order.item.price);
}

void print_orders(OrderList orders) {
    printf("\nOrder List:\n");
    for (int i = 0; i < orders.num_orders; i++) {
        print_order(orders.orders[i]);
    }
}

int main() {
    MenuItem menu[] = {{"Cappuccino", 3.5}, {"Latte", 3.0}, {"Espresso", 2.5}, {"Mocha", 3.8}};
    OrderList orders;
    orders.num_orders = 0;

    while (1) {
        printf("\nCafe Menu:\n");
        for (int i = 0; i < sizeof(menu) / sizeof(MenuItem); i++) {
            printf("%d. %s: %0.2f\n", i+1, menu[i].name, menu[i].price);
        }

        int choice, qty;
        printf("\nEnter the number of the item you want to order: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > sizeof(menu) / sizeof(MenuItem)) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter the quantity: ");
        scanf("%d", &qty);

        MenuItem item = menu[choice-1];
        add_item_to_order(&orders, item, qty);

        printf("Order added successfully.\n");

        printf("Do you want to add another item? (y/n): ");
        char answer;
        scanf(" %c", &answer);

        if (answer != 'y') {
            break;
        }
    }

    printf("\nTotal: %0.2f\n", calculate_total(orders));
    print_orders(orders);

    return 0;
}