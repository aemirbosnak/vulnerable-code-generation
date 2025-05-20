//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of a menu item
typedef struct menu_item {
    char *name;
    float price;
} menu_item;

// Define the structure of an order item
typedef struct order_item {
    int quantity;
    menu_item *item;
} order_item;

// Define the structure of an order
typedef struct order {
    int num_items;
    order_item *items;
} order;

// Define the menu
menu_item menu[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Cake", 3.00},
    {"Cookie", 1.50},
    {"Muffin", 2.00}
};

// Function to print the menu
void print_menu() {
    printf("Menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to get the user's order
order get_order() {
    order order;
    order.num_items = 0;
    order.items = malloc(sizeof(order_item) * MAX_ITEMS);

    int item_num;
    int quantity;
    while (1) {
        printf("Enter the item number (0 to finish): ");
        scanf("%d", &item_num);

        if (item_num == 0) {
            break;
        }

        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        order.items[order.num_items].quantity = quantity;
        order.items[order.num_items].item = &menu[item_num - 1];
        order.num_items++;
    }

    return order;
}

// Function to calculate the total price of an order
float calculate_total(order order) {
    float total = 0.0;
    for (int i = 0; i < order.num_items; i++) {
        total += order.items[i].quantity * order.items[i].item->price;
    }

    return total;
}

// Function to print an order
void print_order(order order) {
    printf("Order:\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("%d x %s - $%.2f\n", order.items[i].quantity, order.items[i].item->name, order.items[i].quantity * order.items[i].item->price);
    }
}

// Function to get the user's payment
float get_payment(float total) {
    float payment;
    printf("Total: $%.2f\n", total);
    printf("Enter your payment: ");
    scanf("%f", &payment);

    return payment;
}

// Function to process an order
void process_order(order order) {
    float total = calculate_total(order);
    print_order(order);
    float payment = get_payment(total);
    float change = payment - total;

    printf("Change: $%.2f\n", change);
}

// Main function
int main() {
    print_menu();
    order order = get_order();
    process_order(order);

    return 0;
}