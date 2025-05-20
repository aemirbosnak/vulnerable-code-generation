//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: lively
/*
 * C Cafe Billing System Example Program
 *
 * This program demonstrates a simple cafe billing system.
 * It allows customers to place orders, check the status of their order,
 * and pay for their order using a simple menu.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent a customer
typedef struct {
    char name[30];
    int table_number;
    int order_id;
    char menu_items[10][30];
    int menu_items_count;
    float total_price;
} Customer;

// Structure to represent a menu item
typedef struct {
    char name[30];
    float price;
} MenuItem;

// Array of menu items
MenuItem menu[] = {
    { "Coffee", 2.50 },
    { "Tea", 2.00 },
    { "Espresso", 3.50 },
    { "Cappuccino", 4.00 },
    { "Mocha", 4.50 },
    { "Latte", 4.00 },
    { "Macchiato", 4.50 },
    { "Chai", 3.50 },
    { "Frappuccino", 6.00 },
    { "Smoothie", 5.00 }
};

// Function to print the menu
void print_menu() {
    int i;
    printf("Menu\n");
    for (i = 0; i < sizeof(menu) / sizeof(MenuItem); i++) {
        printf("%d. %s (%.2f)\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to print the bill
void print_bill(Customer *customer) {
    int i;
    printf("Bill for %s\n", customer->name);
    for (i = 0; i < customer->menu_items_count; i++) {
        printf("%s (%.2f)\n", customer->menu_items[i], menu[i].price);
    }
    printf("Total: %.2f\n", customer->total_price);
}

// Function to add an item to the menu
void add_item(Customer *customer, int item_number) {
    if (customer->menu_items_count < 10) {
        strcpy(customer->menu_items[customer->menu_items_count], menu[item_number].name);
        customer->menu_items_count++;
        customer->total_price += menu[item_number].price;
    }
}

// Function to remove an item from the menu
void remove_item(Customer *customer, int item_number) {
    if (customer->menu_items_count > 0) {
        strcpy(customer->menu_items[item_number], customer->menu_items[item_number - 1]);
        customer->menu_items_count--;
        customer->total_price -= menu[item_number].price;
    }
}

// Function to clear the menu
void clear_menu(Customer *customer) {
    int i;
    for (i = 0; i < customer->menu_items_count; i++) {
        strcpy(customer->menu_items[i], "");
    }
    customer->menu_items_count = 0;
    customer->total_price = 0.0;
}

// Function to place an order
void place_order(Customer *customer) {
    int item_number;
    char input[3];
    printf("Enter the number of the item you would like to add (0 to cancel): ");
    scanf("%s", input);
    item_number = atoi(input);
    if (item_number > 0 && item_number <= sizeof(menu) / sizeof(MenuItem)) {
        add_item(customer, item_number - 1);
    } else if (item_number == 0) {
        clear_menu(customer);
    } else {
        printf("Invalid input\n");
    }
}

// Function to check the status of an order
void check_status(Customer *customer) {
    int i;
    printf("Order Status\n");
    for (i = 0; i < customer->menu_items_count; i++) {
        printf("%d. %s (%.2f)\n", i + 1, customer->menu_items[i], menu[i].price);
    }
    printf("Total: %.2f\n", customer->total_price);
}

// Function to pay for an order
void pay_order(Customer *customer) {
    printf("Payment Received\n");
    customer->total_price = 0.0;
    clear_menu(customer);
}

int main() {
    Customer customer;
    int input;
    printf("Welcome to our cafe!\n");
    printf("Please enter your name: ");
    scanf("%s", customer.name);
    printf("Please enter your table number: ");
    scanf("%d", &customer.table_number);
    printf("Please enter your order id: ");
    scanf("%d", &customer.order_id);

    while (1) {
        printf("1. Place Order\n");
        printf("2. Check Status\n");
        printf("3. Pay\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                place_order(&customer);
                break;
            case 2:
                check_status(&customer);
                break;
            case 3:
                pay_order(&customer);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}