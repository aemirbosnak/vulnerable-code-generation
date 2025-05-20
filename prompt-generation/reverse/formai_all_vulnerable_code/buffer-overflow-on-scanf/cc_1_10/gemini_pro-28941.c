//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Structure to store the details of a menu item
typedef struct Menuitem {
    char name[50];
    float price;
} Menuitem;

// Structure to store the details of an order item
typedef struct Orderitem {
    char name[50];
    float price;
    int quantity;
} Orderitem;

// Structure to store the details of a customer
typedef struct Customer {
    char name[50];
    char address[100];
    char phone[20];
} Customer;

// Structure to store the details of an order
typedef struct Order {
    int order_id;
    Customer customer;
    Orderitem items[100];
    int num_items;
    float total_price;
} Order;

// Function to print the menu
void print_menu(Menuitem menu[], int num_items) {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to get the customer details
void get_customer_details(Customer *customer) {
    printf("Enter the customer name: ");
    scanf("%s", customer->name);
    printf("Enter the customer address: ");
    scanf("%s", customer->address);
    printf("Enter the customer phone number: ");
    scanf("%s", customer->phone);
}

// Function to get the order details
void get_order_details(Order *order) {
    printf("Enter the order ID: ");
    scanf("%d", &order->order_id);
    get_customer_details(&order->customer);
    int num_items;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    order->num_items = num_items;
    for (int i = 0; i < num_items; i++) {
        printf("Enter the item name: ");
        scanf("%s", order->items[i].name);
        printf("Enter the item price: ");
        scanf("%f", &order->items[i].price);
        printf("Enter the item quantity: ");
        scanf("%d", &order->items[i].quantity);
    }
}

// Function to calculate the total price of an order
float calculate_total_price(Order *order) {
    float total_price = 0;
    for (int i = 0; i < order->num_items; i++) {
        total_price += order->items[i].price * order->items[i].quantity;
    }
    return total_price;
}

// Function to print the order details
void print_order_details(Order *order) {
    printf("Order ID: %d\n", order->order_id);
    printf("Customer Name: %s\n", order->customer.name);
    printf("Customer Address: %s\n", order->customer.address);
    printf("Customer Phone: %s\n", order->customer.phone);
    printf("Items:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%d. %s - %.2f - %d\n", i + 1, order->items[i].name, order->items[i].price, order->items[i].quantity);
    }
    printf("Total Price: %.2f\n", order->total_price);
}

// Main function
int main() {
    // Create the menu
    Menuitem menu[] = {
        {"Coffee", 2.50},
        {"Tea", 1.50},
        {"Sandwich", 5.00},
        {"Cake", 3.00},
        {"Cookie", 1.00}
    };
    int num_menu_items = sizeof(menu) / sizeof(menu[0]);

    // Print the menu
    print_menu(menu, num_menu_items);

    // Get the order details
    Order order;
    get_order_details(&order);

    // Calculate the total price of the order
    order.total_price = calculate_total_price(&order);

    // Print the order details
    print_order_details(&order);

    return 0;
}