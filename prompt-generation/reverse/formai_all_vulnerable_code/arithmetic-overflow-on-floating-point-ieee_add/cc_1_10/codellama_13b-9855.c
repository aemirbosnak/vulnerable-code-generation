//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a customer
struct Customer {
    char name[50];
    char address[100];
    int phone_number;
    float bill;
};

// Define the structure for a bill
struct Bill {
    float total;
    float tax;
    float tip;
};

// Function to calculate the tax
float calculate_tax(float total) {
    return total * 0.06;
}

// Function to calculate the tip
float calculate_tip(float total, float tax) {
    return total * 0.15;
}

// Function to calculate the total bill
float calculate_bill(float total, float tax, float tip) {
    return total + tax + tip;
}

// Function to print the bill
void print_bill(struct Bill bill) {
    printf("Total: $%.2f\n", bill.total);
    printf("Tax: $%.2f\n", bill.tax);
    printf("Tip: $%.2f\n", bill.tip);
    printf("Bill: $%.2f\n", bill.total + bill.tax + bill.tip);
}

// Main function
int main() {
    // Declare variables
    struct Customer customer;
    struct Bill bill;

    // Get customer information
    printf("Enter customer name: ");
    scanf("%s", customer.name);
    printf("Enter customer address: ");
    scanf("%s", customer.address);
    printf("Enter customer phone number: ");
    scanf("%d", &customer.phone_number);

    // Get bill information
    printf("Enter total: ");
    scanf("%f", &bill.total);

    // Calculate tax and tip
    bill.tax = calculate_tax(bill.total);
    bill.tip = calculate_tip(bill.total, bill.tax);

    // Calculate total bill
    bill.total = calculate_bill(bill.total, bill.tax, bill.tip);

    // Print bill
    print_bill(bill);

    return 0;
}