//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void welcomeMessage();
void getUserInfo(int*, float*, float*);
void calculateExpenses(int, float, float, float*, float*, float*);
void displayResult(float, float, float);


int main()
{
    // variables to hold user input
    int numMonths;
    float monthlyIncome, monthlyExpense;

    // variables to hold calculated data
    float yearlyIncome = 0, yearlyExpense = 0, netSavings = 0;

    // welcome message function call
    welcomeMessage();

    // get user input function call
    getUserInfo(&numMonths, &monthlyIncome, &monthlyExpense);

    // calculate expenses function call
    calculateExpenses(numMonths, monthlyIncome, monthlyExpense, &yearlyIncome, &yearlyExpense, &netSavings);

    // display result function call
    displayResult(yearlyIncome, yearlyExpense, netSavings);

    return 0;
}


// function to display welcome message
void welcomeMessage() 
{
    printf("*****************************************************\n");
    printf("    Welcome to the Happy Personal Finance Planner!    \n");
    printf("*****************************************************\n\n");
    printf("This tool will help you plan your finances for the year based on your monthly income and expenses.\n\n");
}

// function to get user information
void getUserInfo(int* numMonths, float* monthlyIncome, float* monthlyExpense)
{
    printf("Please enter the number of months you want to plan for: ");
    scanf("%d", numMonths);

    printf("\nPlease enter your monthly income: ");
    scanf("%f", monthlyIncome);

    printf("\nPlease enter your monthly expenses: ");
    scanf("%f", monthlyExpense);

    printf("\nThank you for the input! Press enter to move on to the next step.");
    getchar(); // to clear the newline character from the input buffer
}

// function to calculate expenses
void calculateExpenses(int numMonths, float monthlyIncome, float monthlyExpense, float* yearlyIncome, float* yearlyExpense, float* netSavings)
{
    // calculate yearly income and expenses
    *yearlyIncome = monthlyIncome * numMonths;
    *yearlyExpense = monthlyExpense * numMonths;

    // calculate net savings
    *netSavings = *yearlyIncome - *yearlyExpense;
}

// function to display the result
void displayResult(float yearlyIncome, float yearlyExpense, float netSavings)
{
    system("clear"); // clear the console

    printf("*****************************************************\n");
    printf("                 Your Finance Plan                     \n");
    printf("*****************************************************\n\n");
    printf("Your yearly income: $%.2f\n", yearlyIncome);
    printf("Your yearly expenses: $%.2f\n", yearlyExpense);
    printf("Your net yearly savings: $%.2f\n\n", netSavings);

    if (netSavings > 0) {
        printf("Great job! You have a positive net savings for the year. You can now enjoy your financial freedom with peace of mind.\n");
    } else if (netSavings < 0) {
        printf("Oops! You have a negative net savings for the year. You may need to look at your expenses and find ways to cut down on unnecessary expenditure.\n");
    } else {
        printf("Hmm... it looks like your income and expenses are equal. You need to find ways to increase your income or reduce your expenses to have a savings for the year.\n");
    }

    printf("\n\nThank you for using the Happy Personal Finance Planner! Stay happy and financially sound!\n");
}