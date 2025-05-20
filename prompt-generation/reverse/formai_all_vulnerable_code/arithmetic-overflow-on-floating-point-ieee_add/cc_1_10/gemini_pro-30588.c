//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct Order {
    int order_id;
    char customer_name[50];
    Item items[10];
    int num_items;
    float total_amount;
} Order;

// Function prototypes
void print_menu();
void take_order(Order *order);
void calculate_total(Order *order);
void print_receipt(Order *order);

// Global variables
Item menu[] = {
    {"Coffee", 1, 1.50},
    {"Tea", 1, 1.25},
    {"Cake", 1, 2.00},
    {"Muffin", 1, 1.75},
    {"Sandwich", 1, 3.00}
};
int num_menu_items = sizeof(menu) / sizeof(Item);

int main() {
    // Create a new order
    Order order;

    // Print the menu
    print_menu();

    // Take the order
    take_order(&order);

    // Calculate the total amount
    calculate_total(&order);

    // Print the receipt
    print_receipt(&order);

    return 0;
}

void print_menu() {
    printf("Cafe Menu\n");
    printf("----------\n");
    for (int i = 0; i < num_menu_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

void take_order(Order *order) {
    // Get the customer's name
    printf("Customer name: ");
    scanf("%s", order->customer_name);

    // Get the number of items ordered
    printf("Number of items ordered: ");
    scanf("%d", &order->num_items);

    // Get the items ordered
    for (int i = 0; i < order->num_items; i++) {
        int item_number;
        printf("Item %d: ", i + 1);
        scanf("%d", &item_number);

        order->items[i] = menu[item_number - 1];
    }
}

void calculate_total(Order *order) {
    order->total_amount = 0.0;
    for (int i = 0; i < order->num_items; i++) {
        order->total_amount += order->items[i].price * order->items[i].quantity;
    }
}

void print_receipt(Order *order) {
    printf("\nCafe Receipt\n");
    printf("----------\n");
    printf("Customer name: %s\n", order->customer_name);
    printf("Order ID: %d\n", order->order_id);
    printf("\nItems ordered:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, order->items[i].name, order->items[i].price * order->items[i].quantity);
    }
    printf("\nTotal amount: $%.2f\n", order->total_amount);
    printf("Thank you for your patronage!\n");
}