//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, i, total_cost = 0;
    char name[20];

    // Welcome, dear reader, to the expense tracker of Sherlock Holmes...
    printf("Welcome, dear reader, to the expense tracker of Sherlock Holmes. Prepare to delve into the mysteries of your finances.\n");

    // Create an array to store expenses...
    int expenses[10] = {0};

    // Loop until the user chooses to quit...
    do
    {
        // Display the available options...
        printf("Please select an option:\n");
        printf("1. Record Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Cost\n");
        printf("4. Quit\n");

        // Get the user's choice...
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Get the expense name and cost...
                printf("Enter the name of the expense: ");
                scanf("%s", name);

                printf("Enter the cost of the expense: ");
                scanf("%d", &expenses[i]);

                // Increment the index...
                i++;
                break;

            case 2:
                // Display the expenses...
                printf("Your expenses:\n");
                for (i = 0; i < i; i++)
                {
                    printf("%s - %d\n", expenses[i], name[i]);
                }
                break;

            case 3:
                // Calculate the total cost...
                total_cost = 0;
                for (i = 0; i < i; i++)
                {
                    total_cost += expenses[i];
                }

                // Display the total cost...
                printf("Your total cost is: %d\n", total_cost);
                break;

            case 4:
                // Quit...
                printf("Thank you for using the expense tracker, dear reader. Until next time...\n");
                break;

            default:
                // Invalid choice...
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}