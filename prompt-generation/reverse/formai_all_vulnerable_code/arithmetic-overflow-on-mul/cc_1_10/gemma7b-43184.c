//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a product
typedef struct product
{
    char name[20];
    int price;
    int quantity;
} product;

// Create a function to calculate the total cost of a product
int calculate_cost(product p)
{
    return p.price * p.quantity;
}

// Create a function to print the bill
void print_bill(product p)
{
    printf("---------------------------------------\n");
    printf("Product: %s\n", p.name);
    printf("Price: $%d\n", p.price);
    printf("Quantity: %d\n", p.quantity);
    printf("Total Cost: $%d\n", calculate_cost(p));
    printf("---------------------------------------\n");
}

int main()
{
    // Create a product structure
    product p;

    // Get the product name, price, and quantity
    printf("Enter the product name: ");
    scanf("%s", p.name);

    printf("Enter the product price: ");
    scanf("%d", &p.price);

    printf("Enter the product quantity: ");
    scanf("%d", &p.quantity);

    // Calculate the total cost of the product
    int total_cost = calculate_cost(p);

    // Print the bill
    print_bill(p);

    // Print the total cost
    printf("Total Cost: $%d\n", total_cost);

    return 0;
}