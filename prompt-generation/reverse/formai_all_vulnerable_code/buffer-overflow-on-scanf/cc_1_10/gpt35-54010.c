//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_INCOME 1000000.00
#define MIN_INCOME 1.00
#define MAX_DEBT   1000000.00
#define MIN_DEBT   0.00
#define MAX_SPEND  1000000.00
#define MIN_SPEND  0.00
#define MAX_SAVING 1000000.00
#define MIN_SAVING 0.00

// Function declarations
double get_income();
double get_debt();
double get_spending();
double get_savings(double income, double debt, double spending);
void print_report(double income, double debt, double spending, double savings);

int main()
{
    double income, debt, spending, savings;

    income = get_income();
    debt = get_debt();
    spending = get_spending();
    savings = get_savings(income, debt, spending);

    // Print the report
    print_report(income, debt, spending, savings);

    return 0;
}

// Functions:

double get_income()
{
    double income;

    // Ask user for their income
    printf("Enter your monthly income (between $%0.2f and $%0.2f): ", MIN_INCOME, MAX_INCOME);
    scanf("%lf", &income);

    // Check for valid input
    while (income < MIN_INCOME || income > MAX_INCOME) {
        printf("Invalid input. Please enter an income between $%0.2f and $%0.2f: ", MIN_INCOME, MAX_INCOME);
        scanf("%lf", &income);
    }

    return income;
}

double get_debt()
{
    double debt;

    // Ask user for their debt
    printf("Enter your total debt (between $%0.2f and $%0.2f): ", MIN_DEBT, MAX_DEBT);
    scanf("%lf", &debt);

    // Check for valid input
    while (debt < MIN_DEBT || debt > MAX_DEBT) {
        printf("Invalid input. Please enter a debt between $%0.2f and $%0.2f: ", MIN_DEBT, MAX_DEBT);
        scanf("%lf", &debt);
    }

    return debt;
}

double get_spending()
{
    double spending;

    // Ask user for their monthly spending
    printf("Enter your monthly spending (between $%0.2f and $%0.2f): ", MIN_SPEND, MAX_SPEND);
    scanf("%lf", &spending);

    // Check for valid input
    while (spending < MIN_SPEND || spending > MAX_SPEND) {
        printf("Invalid input. Please enter a monthly spending between $%0.2f and $%0.2f: ", MIN_SPEND, MAX_SPEND);
        scanf("%lf", &spending);
    }

    return spending;
}

double get_savings(double income, double debt, double spending)
{
    double max_savings = income - spending - debt;

    // Check if user has negative savings
    if (max_savings <= 0) {
        printf("Warning: Your spending and debt are too high. You have negative savings. \n");
        return 0;
    }

    double savings;

    // Ask user for their monthly savings
    printf("Enter your monthly savings (between $%0.2f and $%0.2f): ", MIN_SAVING, max_savings);
    scanf("%lf", &savings);

    // Check for valid input
    while (savings < MIN_SAVING || savings > max_savings) {
        printf("Invalid input. Please enter a savings between $%0.2f and $%0.2f: ", MIN_SAVING, max_savings);
        scanf("%lf", &savings);
    }

    return savings;
}

void print_report(double income, double debt, double spending, double savings)
{
    printf("\n\nPersonal Finance Planner Report:\n");
    printf("------------------------------------\n");
    printf("Monthly Income: $%0.2f\n", income);
    printf("Total Debt: $%0.2f\n", debt);
    printf("Monthly Spending: $%0.2f\n", spending);
    printf("Monthly Savings: $%0.2f\n", savings);
    printf("------------------------------------\n");
    printf("End of Report.\n\n");
}