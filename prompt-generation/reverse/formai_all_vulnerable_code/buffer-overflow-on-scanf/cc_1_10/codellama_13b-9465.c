//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
struct Customer {
    char name[50];
    char address[100];
    char contact[20];
    int order_count;
    double total_bill;
};

struct Order {
    char item_name[50];
    int quantity;
    double price;
};

// Functions
void print_menu();
void place_order(struct Order *order);
void process_order(struct Customer *customer, struct Order *order);
void print_bill(struct Customer *customer);

// Main function
int main() {
    struct Customer customer;
    struct Order order;
    int choice;

    // Print the menu
    print_menu();

    // Take customer's details
    printf("Enter customer name: ");
    scanf("%s", customer.name);
    printf("Enter customer address: ");
    scanf("%s", customer.address);
    printf("Enter customer contact: ");
    scanf("%s", customer.contact);

    // Take order details
    printf("Enter order details:\n");
    place_order(&order);

    // Process order
    process_order(&customer, &order);

    // Print bill
    print_bill(&customer);

    return 0;
}

// Function to print the menu
void print_menu() {
    printf("--- Menu ---\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Milkshake\n");
    printf("4. Cake\n");
    printf("5. Exit\n");
}

// Function to take order details
void place_order(struct Order *order) {
    printf("Enter item name: ");
    scanf("%s", order->item_name);
    printf("Enter quantity: ");
    scanf("%d", &order->quantity);
}

// Function to process the order
void process_order(struct Customer *customer, struct Order *order) {
    // Check if the order is valid
    if (strcmp(order->item_name, "Coffee") == 0 ||
        strcmp(order->item_name, "Tea") == 0 ||
        strcmp(order->item_name, "Milkshake") == 0 ||
        strcmp(order->item_name, "Cake") == 0) {
        // Calculate the total price
        order->price = order->quantity * (order->item_name[0] - 'A' + 1);

        // Update the customer details
        customer->order_count++;
        customer->total_bill += order->price;
    } else {
        printf("Invalid order.\n");
    }
}

// Function to print the bill
void print_bill(struct Customer *customer) {
    printf("--- Bill ---\n");
    printf("Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Contact: %s\n", customer->contact);
    printf("Order Count: %d\n", customer->order_count);
    printf("Total Bill: %.2f\n", customer->total_bill);
}