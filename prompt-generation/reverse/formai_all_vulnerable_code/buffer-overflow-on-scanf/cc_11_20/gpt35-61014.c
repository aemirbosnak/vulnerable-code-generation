//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: brave
// Welcome to the Brave Cafe Billing System Program!
// This program takes orders from customers and generates bills for the same.

#include<stdio.h>
#include<stdlib.h>

void main()
{
    // Declare variables
    int choice, quantity, bill = 0;
    char cont;

    // Welcome message
    printf("Welcome to the Brave Cafe!\n");

    // Infinite loop for taking orders
    while(1)
    {
        // Display menu and take order
        printf("\nMENU\n1. Coffee - Rs. 100\n2. Tea - Rs. 50\n3. Sandwich - Rs. 150\n4. Pizza - Rs. 300\n5. Burger - Rs. 200\nEnter your choice: ");
        scanf("%d", &choice);

        // Validate user input
        if(choice<1 || choice>5)
        {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        // Take quantity and calculate bill
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        switch(choice)
        {
            case 1: bill += quantity*100; break;
            case 2: bill += quantity*50; break;
            case 3: bill += quantity*150; break;
            case 4: bill += quantity*300; break;
            case 5: bill += quantity*200; break;
        }

        // Ask if user wants to continue
        printf("\nDo you want to order something else? (y/n): ");
        scanf(" %c", &cont);

        // If user does not want to continue, display bill and exit
        if(cont=='n' || cont=='N')
        {
            printf("\nYour total bill is Rs. %d. Thanks for choosing Brave Cafe!\n", bill);
            exit(0);
        }
    }

    return;
}