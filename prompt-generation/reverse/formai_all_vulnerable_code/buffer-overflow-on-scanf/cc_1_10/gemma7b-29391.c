//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
    char name[20];
    char address[50];
    int item_no;
    char item_name[20];
    int quantity;
    float price;
    float total_amount = 0.0f;

    printf("Welcome to the Sherlock Holmes C Cafe Billing System!\n");

    // Get customer information
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your address: ");
    scanf("%s", address);

    // Get item information
    printf("Please enter the item number: ");
    scanf("%d", &item_no);

    printf("Please enter the item name: ");
    scanf("%s", item_name);

    printf("Please enter the quantity: ");
    scanf("%d", &quantity);

    // Get item price
    printf("Please enter the item price: ");
    scanf("%f", &price);

    // Calculate total amount
    total_amount = quantity * price;

    // Print receipt
    printf("\n**Sherlock Holmes C Cafe Receipt**\n");
    printf("Name: %s\n", name);
    printf("Address: %s\n", address);

    printf("Item No.: %d\n", item_no);
    printf("Item Name: %s\n", item_name);
    printf("Quantity: %d\n", quantity);
    printf("Price: %.2f\n", price);
    printf("Total Amount: %.2f\n", total_amount);

    // Thank you message
    printf("Thank you for visiting the Sherlock Holmes C Cafe. Please come again!\n");

    return 0;
}