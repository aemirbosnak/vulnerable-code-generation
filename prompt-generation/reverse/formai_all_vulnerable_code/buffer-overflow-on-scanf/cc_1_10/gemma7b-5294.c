//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Define a structure to store customer information
    struct customer
    {
        char name[50];
        char address[100];
        char phone[20];
    };

    // Create a customer structure
    struct customer customer1;

    // Get customer information
    printf("Enter your name: ");
    scanf("%s", customer1.name);

    printf("Enter your address: ");
    scanf("%s", customer1.address);

    printf("Enter your phone number: ");
    scanf("%s", customer1.phone);

    // Print customer information
    printf("Name: %s\n", customer1.name);

    printf("Address: %s\n", customer1.address);

    printf("Phone number: %s\n", customer1.phone);

    // Define a structure to store item information
    struct item
    {
        char name[50];
        int quantity;
        float price;
    };

    // Create an array of items
    struct item items[] =
    {
        {"Coffee", 10, 5.0},
        {"Tea", 8, 4.0},
        {"Juice", 6, 3.0},
        {"Soda", 4, 2.0}
    };

    // Get the number of items
    int numItems = sizeof(items) / sizeof(struct item);

    // Print item information
    for (int i = 0; i < numItems; i++)
    {
        printf("Item name: %s\n", items[i].name);

        printf("Quantity: %d\n", items[i].quantity);

        printf("Price: %.2f\n", items[i].price);
    }

    // Calculate the total cost of items
    float totalCost = 0.0;
    for (int i = 0; i < numItems; i++)
    {
        totalCost += items[i].quantity * items[i].price;
    }

    // Print the total cost
    printf("Total cost: %.2f\n", totalCost);

    // Calculate the tax
    float tax = totalCost * 0.1;

    // Print the tax
    printf("Tax: %.2f\n", tax);

    // Calculate the total amount due
    float totalAmountDue = totalCost + tax;

    // Print the total amount due
    printf("Total amount due: %.2f\n", totalAmountDue);

    // Prompt the customer to pay
    printf("Please pay the total amount due: ");

    // Get the customer's payment
    float payment = 0.0;
    scanf("%f", &payment);

    // Check if the customer's payment is sufficient
    if (payment < totalAmountDue)
    {
        printf("Insufficient payment.\n");
    }
    else
    {
        printf("Thank you for your payment.\n");
    }
}