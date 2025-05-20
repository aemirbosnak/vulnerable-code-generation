//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a product
typedef struct product
{
    char name[20];
    float price;
    int quantity;
} product;

// Define a function to calculate the total cost of a product
float calculate_total_cost(product p)
{
    return p.price * p.quantity;
}

// Define a function to display the bill
void display_bill(product p)
{
    printf("--------------------------------------------------------\n");
    printf("Product Name: %s\n", p.name);
    printf("Price: $%.2f\n", p.price);
    printf("Quantity: %d\n", p.quantity);
    printf("Total Cost: $%.2f\n", calculate_total_cost(p));
    printf("--------------------------------------------------------\n");
}

// Define a function to manage the inventory
void manage_inventory(product p)
{
    printf("Enter the quantity of the product you want to add: ");
    scanf("%d", &p.quantity);
    printf("The quantity of the product has been updated to: %d\n", p.quantity);
}

// Main function
int main()
{
    // Create a product structure
    product p;

    // Initialize the product structure
    p.name[0] = '\0';
    p.price = 0.0f;
    p.quantity = 0;

    // Manage the inventory
    manage_inventory(p);

    // Display the bill
    display_bill(p);

    return 0;
}