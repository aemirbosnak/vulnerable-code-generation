//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice;
    char name[20];
    float salary, expense, balance;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while(1)
    {
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Balance\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n");
                printf("Enter your salary: ");
                scanf("%f", &salary);
                printf("\n");
                printf("%s, you have added $%.2f to your income.\n", name, salary);
                break;

            case 2:
                printf("\n");
                printf("Enter your expense: ");
                scanf("%f", &expense);
                printf("\n");
                printf("%s, you have added $%.2f to your expense.\n", name, expense);
                break;

            case 3:
                printf("\n");
                printf("%s, your current balance is $%.2f.\n", name, balance);
                break;

            case 4:
                printf("\n");
                printf("Thank you for using the Personal Finance Planner, %s!\n", name);
                exit(0);

            default:
                printf("\n");
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}