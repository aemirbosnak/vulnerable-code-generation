//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int item_no, qty, total_items = 0, total_amount = 0;
    char item_name[20];
    float price;

    // Display menu
    printf("Welcome to the C Cafe Billing System!\n");
    printf("Please select an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Sandwich\n");
    printf("5. Pastry\n");

    // Get item number
    scanf("Enter item number:", &item_no);

    // Get item name
    switch (item_no)
    {
        case 1:
            strcpy(item_name, "Coffee");
            break;
        case 2:
            strcpy(item_name, "Tea");
            break;
        case 3:
            strcpy(item_name, "Juice");
            break;
        case 4:
            strcpy(item_name, "Sandwich");
            break;
        case 5:
            strcpy(item_name, "Pastry");
            break;
    }

    // Get item price
    printf("Enter item price:");
    scanf("%f", &price);

    // Get item quantity
    printf("Enter item quantity:");
    scanf("%d", &qty);

    // Calculate total items and amount
    total_items++;
    total_amount += qty * price;

    // Display bill
    printf("----------------------------------------\n");
    printf("Item No.: %d\n", item_no);
    printf("Item Name: %s\n", item_name);
    printf("Price: %.2f\n", price);
    printf("Quantity: %d\n", qty);
    printf("Total Amount: %.2f\n", qty * price);
    printf("----------------------------------------\n");

    // Display total items and amount
    printf("Total Items: %d\n", total_items);
    printf("Total Amount: %.2f\n", total_amount);

    // Calculate tax and total amount with tax
    float tax = 0.1 * total_amount;
    float total_amount_with_tax = total_amount + tax;

    // Display tax and total amount with tax
    printf("Tax: %.2f\n", tax);
    printf("Total Amount with Tax: %.2f\n", total_amount_with_tax);

    // Thank you message
    printf("Thank you for visiting the C Cafe!\n");

    // Exit
    exit(0);
}