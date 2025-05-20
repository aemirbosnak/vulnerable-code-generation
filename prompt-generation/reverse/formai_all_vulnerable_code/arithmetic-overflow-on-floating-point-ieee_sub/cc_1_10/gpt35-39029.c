//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include<stdio.h>

typedef struct {
    //user input variables
    float salary;
    float expenses;
    float investments;

    //computed variables
    float totalIncome;
    float netIncome;
    float savings;
    float savingsPercent;
} PersonalFinance;

PersonalFinance p;

void calculateNetIncome() {
    p.totalIncome = p.salary + p.investments;
    p.netIncome = p.totalIncome - p.expenses;
}

void calculateSavings() {
    p.savings = p.netIncome - p.expenses;
    p.savingsPercent = (p.savings / p.totalIncome) * 100;
}

void printResults() {
    printf("Total Income: $%.2f\n", p.totalIncome);
    printf("Net Income: $%.2f\n", p.netIncome);
    printf("Expenses: $%.2f\n", p.expenses);
    printf("Savings: $%.2f\n", p.savings);
    printf("Savings Percent: %.2f%c", p.savingsPercent, '%');
}

int main() {
    //user inputs
    printf("Enter Salary: $");
    scanf("%f", &p.salary);

    printf("Enter Monthly Expenses: $");
    scanf("%f", &p.expenses);

    printf("Enter Monthly Investments: $");
    scanf("%f", &p.investments);

    //calculate results
    calculateNetIncome();
    calculateSavings();

    //display results
    printResults();

    return 0;
}