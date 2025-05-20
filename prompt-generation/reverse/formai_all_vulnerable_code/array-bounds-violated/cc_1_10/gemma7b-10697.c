//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include <stdio.h>
#include <string.h>

// Define a structure to store customer information
typedef struct customer
{
    char name[50];
    char address[100];
    char phone[20];
} customer;

// Define a structure to store item information
typedef struct item
{
    char name[50];
    int quantity;
    double price;
} item;

// Create a list of customers
customer customers[] = {
    {"John Doe", "123 Main St", "555-123-4567"},
    {"Jane Doe", "456 Oak Ave", "555-432-5678"},
    {"Peter Pan", "12 Neverland Rd", "555-984-1235"}
};

// Create a list of items
item items[] = {
    {"Coffee", 10, 2.50},
    {"Tea", 5, 3.00},
    {"Juice", 7, 2.00},
    {"Soda", 8, 1.50}
};

// Function to calculate the total cost of an order
double calculateTotalCost(item items[], int numItems)
{
    double totalCost = 0.0;
    for (int i = 0; i < numItems; i++)
    {
        totalCost += items[i].quantity * items[i].price;
    }
    return totalCost;
}

// Function to generate a receipt
void generateReceipt(customer customer, item items[], int numItems)
{
    printf("------------------------------------------------\n");
    printf("Customer: %s\n", customer.name);
    printf("Address: %s\n", customer.address);
    printf("Phone: %s\n", customer.phone);
    printf("------------------------------------------------\n");
    printf("Items:\n");
    for (int i = 0; i < numItems; i++)
    {
        printf("%s: %d @ $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("------------------------------------------------\n");
    printf("Total Cost: $%.2f\n", calculateTotalCost(items, numItems));
    printf("------------------------------------------------\n");
}

// Main function
int main()
{
    // Create a customer order
    customer customer = customers[0];
    item items[] = {items[0], items[2], items[3]};
    int numItems = 3;

    // Generate the receipt
    generateReceipt(customer, items, numItems);

    return 0;
}