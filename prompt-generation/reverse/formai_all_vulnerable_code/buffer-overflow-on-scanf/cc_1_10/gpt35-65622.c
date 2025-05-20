//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct order_item {
    char name[50];    // item name
    int quantity;     // item quantity ordered
    float price;      // item price per unit
    float total;      // item total price
};

struct order {
    int order_number;         // unique order number
    char customer_name[50];   // customer name
    struct order_item items[10];
    int num_items;            // number of items ordered
    float total_price;        // total price for the entire order
} orders[50];

int num_orders = 0;           // number of orders placed
int order_counter = 1001;     // order number counter

float calculate_total(struct order_item item) {
    // calculates the total price of an item based on quantity and price per unit
    return item.quantity * item.price;
}

void add_item_to_order(int order_index) {
    // adds an item to an existing order
    struct order_item item;
    printf("\nEnter item name: ");
    scanf("%s", item.name);
    printf("Enter quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter price per unit: ");
    scanf("%f", &item.price);
    item.total = calculate_total(item);
    orders[order_index].items[orders[order_index].num_items++] = item;
    orders[order_index].total_price += item.total;
    printf("\nItem added to order successfully!\n");
}

void add_new_order() {
    // adds a new order
    struct order order;
    order.order_number = order_counter++;
    printf("\nEnter customer name: ");
    scanf("%s", order.customer_name);
    order.num_items = 0;
    order.total_price = 0;
    add_item_to_order(num_orders);
    orders[num_orders++] = order;
    printf("\nOrder added successfully!\n");
}

void view_order(int index) {
    // displays details of an order
    struct order order = orders[index];
    printf("\nOrder Number: %d\nCustomer Name: %s\n\n", order.order_number, order.customer_name);
    printf("Item\t\tQuantity\tPrice per unit\tTotal\n\n");
    for (int i = 0; i < order.num_items; i++) {
        struct order_item item = order.items[i];
        printf("%s\t\t%d\t\t%.2f\t\t%.2f\n", item.name, item.quantity, item.price, item.total);
    }
    printf("\nTotal Price: %.2f\n", order.total_price);
}

void view_all_orders() {
    // displays details of all orders
    if (num_orders == 0) {
        printf("\nNo orders found!\n");
        return;
    }
    printf("\nOrder Number\tCustomer Name\tTotal Price\n\n");
    for (int i = 0; i < num_orders; i++) {
        struct order order = orders[i];
        printf("%d\t\t%s\t\t%.2f\n", order.order_number, order.customer_name, order.total_price);
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nWelcome to the Cafe Billing System!\n");
        printf("\n1. Add a new order\n2. Add an item to an existing order\n3. View an order\n4. View all orders\n5. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_new_order();
                break;
            case 2:
                if (num_orders == 0) {
                    printf("\nNo orders found. Please add a new order first.\n");
                } else {
                    printf("\nEnter order number: ");
                    int order_number;
                    scanf("%d", &order_number);
                    int order_index = -1;
                    for (int i = 0; i < num_orders; i++) {
                        if (orders[i].order_number == order_number) {
                            order_index = i;
                            break;
                        }
                    }
                    if (order_index == -1) {
                        printf("\nInvalid order number!\n");
                    } else {
                        add_item_to_order(order_index);
                    }
                }
                break;
            case 3:
                if (num_orders == 0) {
                    printf("\nNo orders found!\n");
                } else {
                    printf("\nEnter order number: ");
                    int order_number;
                    scanf("%d", &order_number);
                    int order_index = -1;
                    for (int i = 0; i < num_orders; i++) {
                        if (orders[i].order_number == order_number) {
                            order_index = i;
                            break;
                        }
                    }
                    if (order_index == -1) {
                        printf("\nInvalid order number!\n");
                    } else {
                        view_order(order_index);
                    }
                }
                break;
            case 4:
                view_all_orders();
                break;
            case 5:
                printf("\nThank you for using Cafe Billing System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}