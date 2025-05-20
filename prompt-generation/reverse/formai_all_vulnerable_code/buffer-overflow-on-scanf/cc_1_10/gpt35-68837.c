//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int option;
    float income, expenses, savings;
    
    printf("\nWelcome to the Personal Finance Planner!\n");
    
    do
    {
        printf("\nPlease select an option:\n");
        printf("1. Calculate monthly income\n");
        printf("2. Calculate monthly expenses\n");
        printf("3. Calculate monthly savings\n");
        printf("4. Exit\n");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                printf("\nEnter your monthly income: ");
                scanf("%f", &income);
                printf("Your monthly income is: $%.2f\n", income);
                break;
                
            case 2:
                printf("\nEnter your monthly expenses: ");
                scanf("%f", &expenses);
                printf("Your monthly expenses are: $%.2f\n", expenses);
                break;
                
            case 3:
                savings = income - expenses;
                printf("\nYour monthly savings are: $%.2f\n", savings);
                
                if(savings < 0)
                {
                    printf("\nWARNING: You are spending more than you are earning!\n");
                }
                
                break;
                
            case 4:
                printf("\nThank you for using the Personal Finance Planner!\n");
                exit(0);
                
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
        
    }while(option != 4);
    
    return 0;
}