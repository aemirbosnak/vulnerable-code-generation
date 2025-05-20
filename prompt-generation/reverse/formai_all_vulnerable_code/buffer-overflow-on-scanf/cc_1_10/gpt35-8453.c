//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: genious
#include<stdio.h>
#include<stdlib.h>

double monthly_income(double salary);
double monthly_expenses(double rent, double utilities, double groceries, double transportation);
double remaining_balance(double income, double expenses);
int check_savings(double balance);

int main() {
    double salary, rent, utilities, groceries, transportation, income, expenses, balance;
    int savings;

    printf("Welcome to the Personal Finance Planner\n");
    printf("---------------------------------------\n");

    printf("Please enter your monthly salary: ");
    scanf("%lf", &salary);

    printf("Please enter your monthly rent/mortgage payment: ");
    scanf("%lf", &rent);

    printf("Please enter your monthly utilities bill: ");
    scanf("%lf", &utilities);

    printf("Please enter your monthly groceries expense: ");
    scanf("%lf", &groceries);

    printf("Please enter your monthly transportation expense: ");
    scanf("%lf", &transportation);

    income = monthly_income(salary);
    expenses = monthly_expenses(rent, utilities, groceries, transportation);
    balance = remaining_balance(income, expenses);
    savings = check_savings(balance);

    printf("---------------------------------------\n");
    printf("Your monthly income: $%.2lf\n", income);
    printf("Your monthly expenses: $%.2lf\n", expenses);
    printf("Your remaining balance: $%.2lf\n", balance);
    if (savings) {
        printf("You have a positive savings this month!\n");
    } else {
        printf("You have no savings this month.\n");
    }
    printf("---------------------------------------\n");

    return 0;
}

double monthly_income(double salary) {
    return salary;
}

double monthly_expenses(double rent, double utilities, double groceries, double transportation) {
    return rent + utilities + groceries + transportation;
}

double remaining_balance(double income, double expenses) {
    return income - expenses;
}

int check_savings(double balance) {
    if (balance < 0) {
        return 0;
    } else {
        return 1;
    }
}