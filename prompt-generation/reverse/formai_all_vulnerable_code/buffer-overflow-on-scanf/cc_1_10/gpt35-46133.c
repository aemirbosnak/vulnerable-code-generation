//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to calculate the total bill amount
float calculateBill(int quantity, float pricePerUnit)
{
    return quantity * pricePerUnit;
}

int main()
{
    int choice, quantity;
    float billAmount;
    float pricePerUnit;

    // menu for customers
    printf("Welcome to the Cafe Billing System\n");
    printf("Select your order from the menu:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Sandwich\n");

    // read user's order choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // set the price per unit according to the user's choice
    switch(choice)
    {
        case 1:
            pricePerUnit = 1.5;
            break;
        case 2:
            pricePerUnit = 1.0;
            break;
        case 3:
            pricePerUnit = 2.5;
            break;
        default:
            printf("Invalid choice!");
            exit(0);
    }

    // read the quantity of the order placed by the customer
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // calculate the total bill amount
    billAmount = calculateBill(quantity, pricePerUnit);

    // print the bill amount
    printf("Your total bill amount is: $%.2f\n", billAmount);

    printf("Thank you for visiting the Cafe! Have a nice day!");

    return 0;
}