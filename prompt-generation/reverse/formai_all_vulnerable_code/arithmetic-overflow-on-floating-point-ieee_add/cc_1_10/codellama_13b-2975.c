//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>

// Define structure for a customer
struct customer {
    char name[256];
    int age;
    char address[256];
};

// Define structure for a menu item
struct menu_item {
    char name[256];
    double price;
};

// Define structure for a bill
struct bill {
    struct customer customer;
    struct menu_item menu_items[10];
    int num_items;
    double total_price;
};

// Function to calculate the total price of a bill
double calculate_total_price(struct bill *bill) {
    double total_price = 0.0;
    for (int i = 0; i < bill->num_items; i++) {
        total_price += bill->menu_items[i].price;
    }
    return total_price;
}

// Function to display a bill
void display_bill(struct bill *bill) {
    printf("Customer: %s\n", bill->customer.name);
    printf("Age: %d\n", bill->customer.age);
    printf("Address: %s\n", bill->customer.address);
    printf("Menu Items: \n");
    for (int i = 0; i < bill->num_items; i++) {
        printf("  %s - $%.2f\n", bill->menu_items[i].name, bill->menu_items[i].price);
    }
    printf("Total Price: $%.2f\n", bill->total_price);
}

int main() {
    // Create a bill for a customer
    struct bill bill = {
        .customer = {
            .name = "John Doe",
            .age = 30,
            .address = "123 Main St"
        },
        .menu_items = {
            { "Coffee", 2.50 },
            { "Croissant", 3.50 },
            { "Latte", 4.50 }
        },
        .num_items = 3,
        .total_price = calculate_total_price(&bill)
    };

    // Display the bill
    display_bill(&bill);

    return 0;
}