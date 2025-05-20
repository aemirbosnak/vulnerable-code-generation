//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

//Function to calculate total expenses
float calcExpenses(int *rent, int *food, int *utilities, int *transport, int *miscellaneous)
{
    return (*rent + *food + *utilities + *transport + *miscellaneous);
}

//Function to calculate total income
float calcIncome(float *salary, float *bonus, float *otherIncome)
{
    return (*salary + *bonus + *otherIncome);
}

//Function to calculate savings
float calcSavings(float *income, float *expenses)
{
    return (*income - *expenses);
}

//Main function
int main()
{
    int rent, food, utilities, transport, miscellaneous;
    float salary, bonus, otherIncome;
    
    //Taking input from user
    printf("Enter monthly rent: ");
    scanf("%d", &rent);
    printf("Enter monthly food expenses: ");
    scanf("%d", &food);
    printf("Enter monthly utilities bill: ");
    scanf("%d", &utilities);
    printf("Enter monthly transport expenses: ");
    scanf("%d", &transport);
    printf("Enter monthly miscellaneous expenses: ");
    scanf("%d", &miscellaneous);
    printf("Enter monthly salary: ");
    scanf("%f", &salary);
    printf("Enter monthly bonus: ");
    scanf("%f", &bonus);
    printf("Enter other monthly income: ");
    scanf("%f", &otherIncome);
    
    //Calculating expenses, income and savings
    float expenses = calcExpenses(&rent, &food, &utilities, &transport, &miscellaneous);
    float income = calcIncome(&salary, &bonus, &otherIncome);
    float savings = calcSavings(&income, &expenses);
    
    //Displaying the output
    printf("\n\n\t\tPERSONAL FINANCE PLANNER\n");
    printf("\n\nMonthly Expenses:\n\n");
    printf("Rent: %d\nFood: %d\nUtilities: %d\nTransport: %d\nMiscellaneous: %d\nTotal Expenses: %.2f\n\n", 
           rent, food, utilities, transport, miscellaneous, expenses);
    printf("Monthly Income:\n\n");
    printf("Salary: %.2f\nBonus: %.2f\nOther Income: %.2f\nTotal Income: %.2f\n\n", 
           salary, bonus, otherIncome, income);
    printf("Monthly Savings: %.2f\n\n", savings);
    
    return 0;
}