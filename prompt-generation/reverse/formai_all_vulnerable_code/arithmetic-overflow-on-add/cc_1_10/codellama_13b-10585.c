//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: lively
// Cafe Billing System
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define structure for orders
struct Order {
    char name[50];
    int quantity;
    float price;
};

// Define structure for menu items
struct MenuItem {
    char name[50];
    float price;
};

// Define structure for bills
struct Bill {
    char name[50];
    float total;
    struct Order orders[10];
    int num_orders;
};

// Define menu items
struct MenuItem menu[] = {
    {"Coffee", 2.5},
    {"Tea", 3.5},
    {"Espresso", 5.0},
    {"Cappuccino", 7.0},
    {"Latte", 6.0},
    {"Mocha", 8.0}
};

// Define number of menu items
int num_menu_items = sizeof(menu) / sizeof(menu[0]);

// Function to print menu
void print_menu() {
    for (int i = 0; i < num_menu_items; i++) {
        printf("%d. %s (%f)\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to take order
void take_order(struct Order *order) {
    int choice;
    float total = 0.0;

    printf("Enter your name: ");
    scanf("%s", order->name);

    printf("Enter your order (e.g. 1,2,3): ");
    scanf("%d", &choice);

    for (int i = 0; i < num_menu_items; i++) {
        if (choice == i + 1) {
            order->quantity = 1;
            order->price = menu[i].price;
            total += order->price;
            break;
        }
    }

    printf("Your order is: %s (%f)\n", menu[choice - 1].name, total);
}

// Function to print bill
void print_bill(struct Bill *bill) {
    float total = 0.0;

    printf("Bill for %s\n", bill->name);

    for (int i = 0; i < bill->num_orders; i++) {
        printf("%s x %d = %f\n", bill->orders[i].name, bill->orders[i].quantity, bill->orders[i].price);
        total += bill->orders[i].price;
    }

    printf("Total: %f\n", total);
}

int main() {
    struct Bill bill;
    struct Order order;

    // Take orders until user enters 'quit'
    while (strcmp(order.name, "quit") != 0) {
        take_order(&order);

        // Add order to bill
        bill.orders[bill.num_orders] = order;
        bill.num_orders++;
    }

    // Print bill
    print_bill(&bill);

    return 0;
}