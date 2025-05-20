//FormAI DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense 
{
    char name[50];
    float amount;
};

int main() 
{
    int option = 0, i = 0;
    float total = 0;
    struct Expense expenses[10];

    while (option != 4) 
    {
        printf("\n\n---Expense Tracker---\n");
        printf("1. Add Expense\n2. View Expenses\n3. Calculate Total\n4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) 
        {
            case 1:
                if (i == 10) // Check if maximum expenses already reached
                {
                    printf("\nMaximum expenses reached!\n");
                    break;
                }

                printf("\nEnter expense name: ");
                scanf("%s", expenses[i].name);
                printf("Enter expense amount: ");
                scanf("%f", &expenses[i].amount);

                total += expenses[i].amount; // Add expense amount to total
                i++; // Increment expense counter

                printf("\nExpense added successfully!\n");
                break;

            case 2:
                if (i == 0) // Check if there are no expenses to display
                {
                    printf("\nNo expenses to display!\n");
                    break;
                }

                printf("\n---Expense List---\n");
                for (int j = 0; j < i; j++)
                {
                    printf("%d. %s - %.2f\n", j+1, expenses[j].name, expenses[j].amount);
                }
                break;

            case 3:
                printf("\nTotal Expenses: %.2f\n", total);
                break;

            case 4:
                printf("\nExiting the program...\n");
                break;

            default:
                printf("\nInvalid option!\n");
                break;
        }
    }
    return 0;
}