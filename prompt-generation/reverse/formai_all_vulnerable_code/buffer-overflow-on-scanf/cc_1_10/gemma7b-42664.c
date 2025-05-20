//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store customer information
typedef struct customer
{
    char name[50];
    char address[100];
    int phone_number;
} customer;

// Define a structure to store item information
typedef struct item
{
    char name[50];
    int quantity;
    double price;
} item;

// Create a customer list
customer customers[100];

// Create an item list
item items[100];

// Function to calculate the total cost of an order
double calculate_total_cost(item items[], int num_items)
{
    double total_cost = 0;
    for (int i = 0; i < num_items; i++)
    {
        total_cost += items[i].quantity * items[i].price;
    }
    return total_cost;
}

// Function to print an invoice
void print_invoice(customer customer, item items[], int num_items, double total_cost)
{
    printf("----------------------------------------------------------------\n");
    printf("Customer Information:\n");
    printf("Name: %s\n", customer.name);
    printf("Address: %s\n", customer.address);
    printf("Phone Number: %d\n", customer.phone_number);
    printf("\n");
    printf("Order Items:\n");
    for (int i = 0; i < num_items; i++)
    {
        printf("Item Name: %s\n", items[i].name);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: %.2lf\n", items[i].price);
        printf("\n");
    }
    printf("\n");
    printf("Total Cost: %.2lf\n", total_cost);
    printf("----------------------------------------------------------------\n");
}

int main()
{
    // Create a new customer
    customer new_customer;
    printf("Enter your name: ");
    scanf("%s", new_customer.name);
    printf("Enter your address: ");
    scanf("%s", new_customer.address);
    printf("Enter your phone number: ");
    scanf("%d", &new_customer.phone_number);

    // Create a new item
    item new_item;
    printf("Enter the name of the item: ");
    scanf("%s", new_item.name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &new_item.quantity);
    printf("Enter the price of the item: ");
    scanf("%lf", &new_item.price);

    // Add the new customer and item to their respective lists
    customers[0] = new_customer;
    items[0] = new_item;

    // Calculate the total cost of the order
    double total_cost = calculate_total_cost(items, 1);

    // Print the invoice
    print_invoice(customers[0], items, 1, total_cost);

    return 0;
}