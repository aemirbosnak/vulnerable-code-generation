//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define the struct for the items that the customer can choose
typedef struct {
    char *name;
    double price;
} Item;

// Define the struct for the order that the customer makes
typedef struct {
    Item *item;
    int quantity;
} Order;

// Define the function to print the menu
void print_menu(Item *items, int num_items) {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }
}

// Define the function to get the customer's order
Order get_order(Item *items, int num_items) {
    Order order;
    printf("Enter the number of the item you want (1-%d): ", num_items);
    int item_number;
    scanf("%d", &item_number);
    order.item = &items[item_number - 1];
    printf("Enter the quantity: ");
    scanf("%d", &order.quantity);
    return order;
}

// Define the function to calculate the total price of the order
double calculate_total(Order *orders, int num_orders) {
    double total = 0;
    for (int i = 0; i < num_orders; i++) {
        total += orders[i].item->price * orders[i].quantity;
    }
    return total;
}

// Define the function to print the receipt
void print_receipt(Order *orders, int num_orders, double total) {
    printf("Receipt:\n");
    for (int i = 0; i < num_orders; i++) {
        printf("%s x %d - $%.2f\n", orders[i].item->name, orders[i].quantity, orders[i].item->price * orders[i].quantity);
    }
    printf("Total: $%.2f\n", total);
}

// Main function
int main() {
    // Define the items that the customer can choose
    Item items[] = {
        {"Coffee", 2.00},
        {"Tea", 1.50},
        {"Cake", 3.00},
        {"Muffin", 2.50}
    };
    int num_items = sizeof(items) / sizeof(Item);

    // Print the menu
    print_menu(items, num_items);

    // Get the customer's order
    Order orders[num_items];
    int num_orders = 0;
    char choice;
    do {
        Order order = get_order(items, num_items);
        orders[num_orders] = order;
        num_orders++;
        printf("Do you want to order anything else (y/n)? ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    // Calculate the total price of the order
    double total = calculate_total(orders, num_orders);

    // Print the receipt
    print_receipt(orders, num_orders, total);

    return 0;
}