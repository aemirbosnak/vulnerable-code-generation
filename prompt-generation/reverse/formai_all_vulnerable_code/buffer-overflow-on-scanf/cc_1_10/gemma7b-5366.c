//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice;
    float total = 0.0;
    char name[20];

    // Menu options
    printf("Welcome to the C Cafe!\n");
    printf("Please select an option:**\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Food\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Calculate the total cost based on the user's choice
    switch (choice)
    {
        case 1:
            total += 2.50;
            break;
        case 2:
            total += 3.00;
            break;
        case 3:
            total += 2.00;
            break;
        case 4:
            total += 4.00;
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }

    // Get the user's name
    printf("Please enter your name: ");
    scanf("%s", name);

    // Print the bill
    printf("**C Cafe Bill**\n");
    printf("Name: %s\n", name);
    printf("Total Cost: %.2f\n", total);
    printf("Thank you for your visit, %s!\n", name);

    return;
}