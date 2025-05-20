//FormAI DATASET v1.0 Category: Expense Tracker ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expense
{
    char category[20];
    float amount;
    char date[15];
};

int main()
{
    int choice, count=0;
    float totalAmount=0;
    char input[10];
    
    struct expense expenses[100];    //creating an array of expense structure to store multiple expenses
    
    printf("\nWelcome to Expense Tracker\n\n");
    
    do{
        printf("What would you like to do?\n");
        printf("1. Add an Expense\n");
        printf("2. View All Expenses\n");
        printf("3. View Expenses by Category\n");
        printf("4. View Total Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("\nEnter the expense category: ");
                scanf("%s", expenses[count].category);
                printf("Enter the amount spent: ");
                scanf("%f", &expenses[count].amount);
                printf("Enter the date (dd/mm/yyyy): ");
                scanf("%s", expenses[count].date);
                totalAmount += expenses[count].amount;
                count++;
                printf("\nExpense added successfully!\n\n");
                break;
                
            case 2:
                if(count == 0)
                {
                    printf("\nYou haven't added any expenses yet!\n\n");
                    break;
                }
                printf("\nDate\t\tCategory\tAmount\n");
                printf("---------------------------------------\n");
                for(int i=0; i<count; i++)
                {
                    printf("%s\t%s\t\t$%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
                }
                printf("---------------------------------------\n");
                printf("Total Expenses: $%.2f\n\n", totalAmount);
                break;
                
            case 3:
                if(count == 0)
                {
                    printf("\nYou haven't added any expenses yet!\n\n");
                    break;
                }
                printf("\nEnter the category you wish to view: ");
                scanf("%s", input);
                printf("\nDate\t\tCategory\tAmount\n");
                printf("---------------------------------------\n");
                for(int i=0; i<count; i++)
                {
                    if(strcmp(expenses[i].category, input) == 0)
                    {
                        printf("%s\t%s\t\t$%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
                    }
                }
                printf("---------------------------------------\n");
                printf("Total Expenses in '%s': $%.2f\n\n", input, totalAmount);
                break;
                
            case 4:
                printf("\nTotal Expenses: $%.2f\n\n", totalAmount);
                break;
            
            case 5:
                printf("\nExiting Expense Tracker...\n\n");
                break;
                
            default:
                printf("\nInvalid Choice!\n\n");
                break;
        }
    }while(choice != 5);
    
    return 0;
}