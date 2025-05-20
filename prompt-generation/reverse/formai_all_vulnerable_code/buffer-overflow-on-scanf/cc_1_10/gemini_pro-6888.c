//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the menu items
char menu_items[MAX_ITEMS][50] = {
    "Coffee",
    "Tea",
    "Latte",
    "Cappuccino",
    "Espresso",
    "Mocha",
    "Americano",
    "Macchiato",
    "Cortado",
    "Flat White"
};

// Define the menu prices
float menu_prices[MAX_ITEMS] = {
    1.50,
    1.75,
    2.00,
    2.25,
    2.50,
    2.75,
    3.00,
    3.25,
    3.50,
    3.75
};

// Define the order struct
typedef struct order {
    char item_name[50];
    int quantity;
    float price;
} order;

// Define the bill struct
typedef struct bill {
    order orders[MAX_ITEMS];
    int num_orders;
    float total_price;
} bill;

// Function to create a new order
order create_order(char *item_name, int quantity) {
    order new_order;
    strcpy(new_order.item_name, item_name);
    new_order.quantity = quantity;
    new_order.price = menu_prices[get_item_index(item_name)];
    return new_order;
}

// Function to get the index of an item in the menu
int get_item_index(char *item_name) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(item_name, menu_items[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add an order to a bill
void add_order_to_bill(bill *bill, order order) {
    bill->orders[bill->num_orders] = order;
    bill->num_orders++;
    bill->total_price += order.price * order.quantity;
}

// Function to print the bill
void print_bill(bill bill) {
    printf("Cafe Billing System\n");
    printf("---------------------\n");
    for (int i = 0; i < bill.num_orders; i++) {
        printf("%s x %d = $%.2f\n", bill.orders[i].item_name, bill.orders[i].quantity, bill.orders[i].price * bill.orders[i].quantity);
    }
    printf("---------------------\n");
    printf("Total: $%.2f\n", bill.total_price);
}

// Main function
int main() {
    // Initialize the bill
    bill bill;
    bill.num_orders = 0;
    bill.total_price = 0.0;

    // Get the number of items ordered
    int num_items;
    printf("Enter the number of items ordered: ");
    scanf("%d", &num_items);

    // Get the items ordered
    for (int i = 0; i < num_items; i++) {
        char item_name[50];
        int quantity;
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", item_name);
        printf("Enter the quantity of item %d: ", i + 1);
        scanf("%d", &quantity);

        // Create the order and add it to the bill
        order new_order = create_order(item_name, quantity);
        add_order_to_bill(&bill, new_order);
    }

    // Print the bill
    print_bill(bill);

    return 0;
}