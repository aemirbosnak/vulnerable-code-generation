//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[51];
    int quantity;
    float price;
} Item;

typedef struct {
    int num_items;
    Item items[100];
} Order;

void print_menu() {
    printf("Welcome to the Cafe Billing System!\n");
    printf("==============================\n");
    printf("Items:\n");
    printf("------\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $1.50\n");
    printf("3. Cake - $3.00\n");
    printf("4. Pie - $4.00\n");
}

Order* create_order() {
    Order* order = malloc(sizeof(Order));
    order->num_items = 0;
    return order;
}

void add_item_to_order(Order* order, Item item) {
    order->items[order->num_items++] = item;
}

float calculate_total(Order* order) {
    float total = 0;
    for (int i = 0; i < order->num_items; i++) {
        total += order->items[i].price * order->items[i].quantity;
    }
    return total;
}

void print_order(Order* order) {
    printf("Order Summary:\n");
    printf("=============\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%d. %s (%dx) - $%.2f\n", i + 1, order->items[i].name, order->items[i].quantity, order->items[i].price * order->items[i].quantity);
    }
    printf("Total: $%.2f\n", calculate_total(order));
}

int main() {
    print_menu();

    Order* order = create_order();

    int choice;
    while (1) {
        printf("Enter your choice (1-4, or 0 to quit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        Item item;

        switch (choice) {
            case 1:
                strcpy(item.name, "Coffee");
                item.price = 2.50;
                break;
            case 2:
                strcpy(item.name, "Tea");
                item.price = 1.50;
                break;
            case 3:
                strcpy(item.name, "Cake");
                item.price = 3.00;
                break;
            case 4:
                strcpy(item.name, "Pie");
                item.price = 4.00;
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &item.quantity);

        add_item_to_order(order, item);
    }

    print_order(order);

    return 0;
}