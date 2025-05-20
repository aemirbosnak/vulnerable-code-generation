//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <string.h>

// Define a structure to store customer information
typedef struct customer {
    char name[20];
    char address[50];
    int phone;
} customer;

// Create a function to calculate the total cost of a beverage
int calculate_cost(char beverage) {
    switch (beverage) {
        case 'C':
            return 50;
        case 'A':
            return 75;
        case 'S':
            return 100;
        default:
            return 0;
    }
}

// Create a function to print the receipt
void print_receipt(customer customer, int total_cost) {
    printf("----------------------------------------\n");
    printf("Customer Name: %s\n", customer.name);
    printf("Customer Address: %s\n", customer.address);
    printf("Customer Phone: %d\n", customer.phone);
    printf("Total Cost: $%d\n", total_cost);
    printf("----------------------------------------\n");
}

int main() {
    // Create a customer structure
    customer customer;

    // Get the customer's name, address, and phone number
    printf("Enter your name: ");
    scanf("%s", customer.name);

    printf("Enter your address: ");
    scanf("%s", customer.address);

    printf("Enter your phone number: ");
    scanf("%d", &customer.phone);

    // Get the customer's beverage order
    char beverage;
    printf("Enter the letter of your beverage (C, A, S): ");
    scanf(" %c", &beverage);

    // Calculate the total cost of the beverage
    int total_cost = calculate_cost(beverage);

    // Print the receipt
    print_receipt(customer, total_cost);

    return 0;
}