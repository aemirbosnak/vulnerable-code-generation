//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Donald Knuth
/* Personal Finance Planner */

#include <stdio.h>

#define MONTHS_PER_YEAR 12

int main(void)
{
    double salary, rent, groceries, bills, loan_payments, entertainment, savings;
    int num_months;
    
    printf("Welcome to the Personal Finance Planner. Let's get started.\n\n");
    
    printf("Please enter your monthly salary: ");
    scanf("%lf", &salary);
    
    printf("Please enter your monthly rent/mortgage payment: ");
    scanf("%lf", &rent);
    
    printf("Please enter your monthly grocery expense: ");
    scanf("%lf", &groceries);
    
    printf("Please enter your monthly bills (utilities, phone, etc.) expense: ");
    scanf("%lf", &bills);
    
    printf("Please enter your monthly loan payments: ");
    scanf("%lf", &loan_payments);
    
    printf("Please enter your monthly entertainment expense: ");
    scanf("%lf", &entertainment);
    
    printf("Please enter the number of months you want to plan for: ");
    scanf("%d", &num_months);
    
    printf("\nThank you. Here is your financial plan.\n\n");
    printf("|  Month  |  Salary  |  Rent/Mortgage  |  Groceries  |  Bills  |  Loan Payments  |  Entertainment  |  Savings  |\n");
    
    /* Calculate and print financial plan for each month */
    for (int i = 1; i <= num_months; i++)
    {
        double monthly_savings = salary - rent - groceries - bills - loan_payments - entertainment;
        savings += monthly_savings;
        
        printf("|    %2d   | $%7.2lf |     $%7.2lf    |  $%7.2lf | $%6.2lf |    $%9.2lf    |    $%9.2lf    |  $%7.2lf |\n", 
        i, salary, rent, groceries, bills, loan_payments, entertainment, monthly_savings);
    }
    
    printf("\nYour total savings over %d months is $%.2lf\n", num_months, savings);
    
    return 0;
}