//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: safe
// Safe C Cafe Billing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing customer information
struct customer {
    char name[50];
    int table_number;
    float bill;
};

// Function to calculate the bill amount
float calculate_bill(int num_items, float item_price) {
    return num_items * item_price;
}

// Function to print the bill
void print_bill(struct customer *customer) {
    printf("Bill for %s: $%.2f\n", customer->name, customer->bill);
}

int main() {
    // Create an array of customers
    struct customer customers[50];

    // Prompt the user for input
    printf("Enter the number of customers: ");
    int num_customers;
    scanf("%d", &num_customers);

    // Iterate through each customer
    for (int i = 0; i < num_customers; i++) {
        // Prompt the user for input
        printf("Enter the customer's name: ");
        scanf("%s", customers[i].name);
        printf("Enter the table number: ");
        scanf("%d", &customers[i].table_number);
        printf("Enter the number of items: ");
        int num_items;
        scanf("%d", &num_items);
        printf("Enter the item price: ");
        float item_price;
        scanf("%f", &item_price);

        // Calculate the bill amount
        customers[i].bill = calculate_bill(num_items, item_price);

        // Print the bill
        print_bill(&customers[i]);
    }

    return 0;
}