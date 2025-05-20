//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// default income values
#define DEFAULT_NET_INCOME 2000
#define DEFAULT_TAX 0.2
#define DEFAULT_RENT 500
#define DEFAULT_UTILITIES 200
#define DEFAULT_GROCERIES 300
#define DEFAULT_CLOTHING 150
#define DEFAULT_TRANSPORTATION 100
#define DEFAULT_OTHER_EXPENSES 200

// function declarations
void printWelcomeMessage();
void printExpenses(double netIncome, double tax, double rent, double utilities, double groceries, double clothing, double transportation, double otherExpenses);
double calculateTotalExpenses(double rent, double utilities, double groceries, double clothing, double transportation, double otherExpenses);
double calculateSavings(double netIncome, double totalExpenses);
double calculatePercentOfIncome(double netIncome, double amount);

int main()
{
    double netIncome = DEFAULT_NET_INCOME, tax = DEFAULT_TAX, rent = DEFAULT_RENT, utilities = DEFAULT_UTILITIES, groceries = DEFAULT_GROCERIES, clothing = DEFAULT_CLOTHING, transportation = DEFAULT_TRANSPORTATION, otherExpenses = DEFAULT_OTHER_EXPENSES;

    char choice;

    printWelcomeMessage();

    do
    {
        printExpenses(netIncome, tax, rent, utilities, groceries, clothing, transportation, otherExpenses);

        printf("\nDo you want to modify (y/n)? ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            printf("\nEnter new values:\n");
            printf("Net Income: ");
            scanf("%lf", &netIncome);

            printf("Tax Rate: ");
            scanf("%lf", &tax);

            printf("Rent: ");
            scanf("%lf", &rent);

            printf("Utilities: ");
            scanf("%lf", &utilities);

            printf("Groceries: ");
            scanf("%lf", &groceries);

            printf("Clothing: ");
            scanf("%lf", &clothing);

            printf("Transportation: ");
            scanf("%lf", &transportation);

            printf("Other Expenses: ");
            scanf("%lf", &otherExpenses);
        }
    } while (choice == 'y' || choice == 'Y');

    double totalExpenses = calculateTotalExpenses(rent, utilities, groceries, clothing, transportation, otherExpenses);
    double savings = calculateSavings(netIncome, totalExpenses);
    double percentOfIncome = calculatePercentOfIncome(netIncome, savings);

    printf("\nYour total expenses are: $%.2lf\n\n", totalExpenses);
    printf("Your monthly savings are: $%.2lf\n\n", savings);
    printf("You are saving %.2lf%% of your monthly income.\n\n", percentOfIncome);

    return 0;
}

/**
 * Prints the welcome message to the console.
 */
void printWelcomeMessage()
{
    printf("\n-----------------------------------------------\n");
    printf("Welcome to the Personal Finance Planner!\n");
    printf("-----------------------------------------------\n\n");
}

/**
 * Prints the user's current expenses to the console.
 * 
 * @param netIncome The user's net monthly income.
 * @param tax The user's monthly tax rate.
 * @param rent The monthly rent expense.
 * @param utilities The monthly utilities expense.
 * @param groceries The monthly groceries expense.
 * @param clothing The monthly clothing expense.
 * @param transportation The monthly transportation expense.
 * @param otherExpenses The other monthly expenses.
 */
void printExpenses(double netIncome, double tax, double rent, double utilities, double groceries, double clothing, double transportation, double otherExpenses)
{
    printf("Your current expenses are:\n");
    printf("-----------------------------------------------\n");
    printf("Net Income: $%.2lf\n", netIncome);
    printf("Tax: $%.2lf\n", netIncome * tax);
    printf("Rent: $%.2lf\n", rent);
    printf("Utilities: $%.2lf\n", utilities);
    printf("Groceries: $%.2lf\n", groceries);
    printf("Clothing: $%.2lf\n", clothing);
    printf("Transportation: $%.2lf\n", transportation);
    printf("Other Expenses: $%.2lf\n", otherExpenses);
    printf("-----------------------------------------------\n\n");
}

/**
 * Calculates the total monthly expenses.
 * 
 * @param rent The monthly rent expense.
 * @param utilities The monthly utilities expense.
 * @param groceries The monthly groceries expense.
 * @param clothing The monthly clothing expense.
 * @param transportation The monthly transportation expense.
 * @param otherExpenses The other monthly expenses.
 * 
 * @return The total monthly expenses.
 */
double calculateTotalExpenses(double rent, double utilities, double groceries, double clothing, double transportation, double otherExpenses)
{
    return rent + utilities + groceries + clothing + transportation + otherExpenses;
}

/**
 * Calculates the monthly savings amount.
 * 
 * @param netIncome The user's net monthly income.
 * @param totalExpenses The total monthly expenses.
 * 
 * @return The monthly savings amount.
 */
double calculateSavings(double netIncome, double totalExpenses)
{
    return netIncome - totalExpenses;
}

/**
 * Calculates the percent of the user's income saved each month.
 * 
 * @param netIncome The user's net monthly income.
 * @param amount The amount saved per month.
 * 
 * @return The percent of income saved each month.
 */
double calculatePercentOfIncome(double netIncome, double amount)
{
    return (amount / netIncome) * 100;
}