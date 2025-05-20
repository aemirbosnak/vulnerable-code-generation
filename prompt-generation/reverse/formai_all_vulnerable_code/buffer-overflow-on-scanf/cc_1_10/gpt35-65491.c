//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for the order
struct Order {
    int item_code;
    char item_name[50];
    float item_price;
    int quantity;
    float total_price;
};

// Global variables
int order_count = 0;
float total_amount = 0.0;
struct Order orders[100];

// Function to display the menu
void display_menu() {
    printf("----------------------------------------\n");
    printf("          C CAFE MENU\n");
    printf("----------------------------------------\n");
    printf(" ITEM CODE |         ITEM NAME       | PRICE\n");
    printf("----------------------------------------\n");
    printf("     1     |       Coffee            | 2.50\n");
    printf("     2     |       Tea               | 1.50\n");
    printf("     3     |       Sandwich          | 3.00\n");
    printf("     4     |       Cake              | 2.00\n");
    printf("----------------------------------------\n");
}

// Function to calculate total price of an order.
void calculate_total_price(struct Order *order) {
    float total_price = order->quantity * order->item_price;
    order->total_price = total_price;
}

// Function to add an order
void add_order() {
    struct Order order;
    printf("Enter item code: ");
    scanf("%d", &order.item_code);
    printf("Enter quantity: ");
    scanf("%d", &order.quantity);
    switch(order.item_code) {
        case 1:
            strcpy(order.item_name, "Coffee");
            order.item_price = 2.50;
            calculate_total_price(&order);
            break;
        case 2:
            strcpy(order.item_name, "Tea");
            order.item_price = 1.50;
            calculate_total_price(&order);
            break;
        case 3:
            strcpy(order.item_name, "Sandwich");
            order.item_price = 3.00;
            calculate_total_price(&order);
            break;
        case 4:
            strcpy(order.item_name, "Cake");
            order.item_price = 2.00;
            calculate_total_price(&order);
            break;
        default:
            printf("Invalid item code!\n");
            return;
    }
    printf("Item added successfully!\n");
    orders[order_count++] = order;
    total_amount += order.total_price;
}

// Function to display the orders
void display_orders() {
    if (order_count == 0) {
        printf("No orders added yet!\n");
        return;
    }
    printf("---------------------------------------------------------------------\n");
    printf(" ITEM CODE |         ITEM NAME       | PRICE  | QUANTITY | TOTAL PRICE\n");
    printf("---------------------------------------------------------------------\n");
    for (int i = 0; i < order_count; i++) {
        printf("     %d     |      %-18s| %.2f |    %d    |     %.2f    \n", orders[i].item_code, orders[i].item_name, orders[i].item_price, orders[i].quantity, orders[i].total_price);
    }
    printf("---------------------------------------------------------------------\n");
    printf("Total amount: %.2f\n", total_amount);
}

// Function to clear the orders
void clear_orders() {
    order_count = 0;
    total_amount = 0.0;
    printf("Orders cleared!\n");
}

// Main function
int main() {
    int choice;
    do {
        printf("\n\n----------------------------------------\n");
        printf("          C CAFE BILLING SYSTEM\n");
        printf("----------------------------------------\n");
        printf(" 1. Display menu\n");
        printf(" 2. Add an order\n");
        printf(" 3. Display orders\n");
        printf(" 4. Clear orders\n");
        printf(" 5. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_menu();
                break;
            case 2:
                add_order();
                break;
            case 3:
                display_orders();
                break;
            case 4:
                clear_orders();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);
    return 0;
}