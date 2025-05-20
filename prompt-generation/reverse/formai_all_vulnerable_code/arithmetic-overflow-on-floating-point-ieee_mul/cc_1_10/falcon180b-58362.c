//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: accurate
//C Cafe Billing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE 10000

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float total_price;
} Order;

void add_item(Item items[], int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);
    (*num_items)++;
}

void display_items(Item items[], int num_items) {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void add_to_order(Order order, Item items[], int num_items) {
    int found = 0;
    printf("Enter item number: ");
    scanf("%d", &order.quantity);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, order.name) == 0) {
            found = 1;
            order.total_price += items[i].price * order.quantity;
            break;
        }
    }
    if (!found) {
        printf("Item not found.\n");
    }
}

void display_order(Order order) {
    printf("Order:\n");
    printf("Name: %s\n", order.name);
    printf("Quantity: %d\n", order.quantity);
    printf("Total price: $%.2f\n", order.total_price);
}

void main() {
    Item items[MAX_ITEMS];
    int num_items = 0;
    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    Order order;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float total_price;

    while (1) {
        printf("Enter customer name: ");
        scanf("%s", name);
        printf("Enter quantity of %s: ", name);
        scanf("%d", &quantity);
        add_to_order(order, items, num_items);
        display_order(order);
        printf("Total price: $%.2f\n\n", order.total_price);
    }
}