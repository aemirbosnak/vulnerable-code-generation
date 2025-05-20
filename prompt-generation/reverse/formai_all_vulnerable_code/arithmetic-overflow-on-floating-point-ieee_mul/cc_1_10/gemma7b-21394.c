//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a product
typedef struct product
{
    char name[50];
    int quantity;
    double price;
} product;

// Define a function to calculate the total cost of a product
double calculate_total_cost(product p)
{
    return p.quantity * p.price;
}

// Define a function to display the billing details
void display_billing_details(product p)
{
    printf("Product Name: %s\n", p.name);
    printf("Quantity: %d\n", p.quantity);
    printf("Price: %.2lf\n", p.price);
    printf("Total Cost: %.2lf\n", calculate_total_cost(p));
}

int main()
{
    // Create a product structure
    product p;

    // Get the product name, quantity, and price
    printf("Enter product name: ");
    scanf("%s", p.name);

    printf("Enter quantity: ");
    scanf("%d", &p.quantity);

    printf("Enter price: ");
    scanf("%lf", &p.price);

    // Calculate the total cost of the product
    double total_cost = calculate_total_cost(p);

    // Display the billing details
    display_billing_details(p);

    // Print the total cost
    printf("Total Cost: %.2lf\n", total_cost);

    return 0;
}