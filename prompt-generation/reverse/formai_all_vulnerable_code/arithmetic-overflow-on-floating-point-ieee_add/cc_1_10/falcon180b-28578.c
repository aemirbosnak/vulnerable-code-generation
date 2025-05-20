//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure for personal finance planner
struct financePlanner
{
    char name[50];
    char accountNumber[20];
    float balance;
    float interestRate;
    float monthlyDeposit;
    float monthlyWithdrawal;
    float totalExpenses;
};

//Function to calculate the total expenses
float calculateTotalExpenses(struct financePlanner *fp)
{
    float totalExpenses = 0;
    if(fp->monthlyWithdrawal > 0)
    {
        totalExpenses += fp->monthlyWithdrawal;
    }
    if(fp->monthlyDeposit > 0)
    {
        totalExpenses += fp->monthlyDeposit;
    }
    return totalExpenses;
}

//Function to calculate the monthly interest earned
float calculateMonthlyInterest(struct financePlanner *fp)
{
    float monthlyInterest = fp->balance * (fp->interestRate / 1200);
    return monthlyInterest;
}

//Function to update the finance planner
void updateFinancePlanner(struct financePlanner *fp)
{
    printf("\nEnter your name (Max 50 characters): ");
    scanf("%s", fp->name);

    printf("\nEnter your account number (Max 20 characters): ");
    scanf("%s", fp->accountNumber);

    printf("\nEnter your current balance: ");
    scanf("%f", &fp->balance);

    printf("\nEnter your interest rate (in percentage): ");
    scanf("%f", &fp->interestRate);

    printf("\nEnter your monthly deposit: ");
    scanf("%f", &fp->monthlyDeposit);

    printf("\nEnter your monthly withdrawal: ");
    scanf("%f", &fp->monthlyWithdrawal);

    printf("\nTotal Expenses: $%.2f\n", calculateTotalExpenses(fp));
    printf("Monthly Interest Earned: $%.2f\n", calculateMonthlyInterest(fp));
}

//Main function to execute the program
int main()
{
    struct financePlanner fp;
    int choice;

    do
    {
        printf("\nWelcome to the Personal Finance Planner\n");
        printf("\n1. Create a new account\n");
        printf("2. Update an existing account\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                updateFinancePlanner(&fp);
                break;

            case 2:
                printf("\nEnter your account number: ");
                scanf("%s", fp.accountNumber);

                if(fp.accountNumber[0] == '\0')
                {
                    printf("\nAccount not found.\n");
                }
                else
                {
                    updateFinancePlanner(&fp);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }while(1);

    return 0;
}