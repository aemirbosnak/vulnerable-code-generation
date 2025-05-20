//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing menu item information
typedef struct {
    char name[50];
    double price;
} MenuItem;

// Structure for storing order information
typedef struct {
    char item[50];
    double price;
    int quantity;
} Order;

// Function to display the menu
void display_menu(MenuItem *menu, int size) {
    printf("-----C Cafe Menu-----\n");
    for (int i = 0; i < size; i++) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
    printf("--------------------\n");
}

// Function to get an order from the user
Order get_order(MenuItem *menu, int size) {
    Order order;
    char item[50];
    double price;
    int quantity;

    // Get item name from user
    printf("Enter item name: ");
    scanf("%s", item);

    // Find item in the menu
    for (int i = 0; i < size; i++) {
        if (strcmp(menu[i].name, item) == 0) {
            // Item found, store its price
            price = menu[i].price;
            break;
        }
        if (i == size - 1) {
            // Item was not found, return an empty order
            Order empty_order = {"", 0, 0};
            return empty_order;
        }
    }

    // Get quantity from user
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Calculate total price of the order
    double total_price = price * quantity;

    // Store order information in an order struct
    order.price = total_price;
    order.quantity = quantity;
    strncpy(order.item, item, sizeof(order.item) - 1);

    return order;
}

// Function to calculate and display the total bill
void display_bill(Order *orders, int size) {
    double total = 0;
    printf("----C Cafe Bill----\n");
    for (int i = 0; i < size; i++) {
        printf("%d %s - $%.2f\n", orders[i].quantity, orders[i].item, orders[i].price);
        total += orders[i].price;
    }
    printf("-------------------\n");
    printf("Total bill: $%.2f\n", total);
}

int main() {
    // Define menu items
    MenuItem menu[] = {
        {"Cappuccino", 3.50},
        {"Latte", 4.00},
        {"Espresso", 2.50},
        {"Iced Coffee", 3.00},
        {"Mocha", 4.50}
    };
    int menu_size = sizeof(menu) / sizeof(MenuItem);

    // Get orders from the user
    Order orders[10];
    int num_orders = 0;
    char input[10];

    do {
        // Display menu
        display_menu(menu, menu_size);

        // Get order from user
        Order order = get_order(menu, menu_size);
        if (strcmp(order.item, "") == 0) {
            printf("Sorry, that item is not on the menu.\n");
        } else {
            orders[num_orders] = order;
            num_orders++;
        }

        // Prompt user for more orders
        printf("Do you want to order anything else? (y/n): ");
        scanf("%s", input);

    } while (strcmp(input, "y") == 0);

    // Display total bill
    display_bill(orders, num_orders);

    // Exit program
    return 0;
}