//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold financial data
typedef struct {
    char name[50];
    double income;
    double expenses;
    double savings;
} PersonalFinance;

// Function to create a new financial plan
PersonalFinance* createFinancialPlan(char* name) {
    PersonalFinance* plan = (PersonalFinance*) malloc(sizeof(PersonalFinance));
    strcpy(plan->name, name);
    plan->income = 0;
    plan->expenses = 0;
    plan->savings = 0;
    return plan;
}

// Function to add income to a financial plan
void addIncome(PersonalFinance* plan, double amount) {
    plan->income += amount;
}

// Function to add expenses to a financial plan
void addExpenses(PersonalFinance* plan, double amount) {
    plan->expenses += amount;
}

// Function to add savings to a financial plan
void addSavings(PersonalFinance* plan, double amount) {
    plan->savings += amount;
}

// Function to display a financial plan
void displayFinancialPlan(PersonalFinance* plan) {
    printf("Name: %s\n", plan->name);
    printf("Income: $%.2f\n", plan->income);
    printf("Expenses: $%.2f\n", plan->expenses);
    printf("Savings: $%.2f\n", plan->savings);
}

// Function to calculate the net worth of a financial plan
double calculateNetWorth(PersonalFinance* plan) {
    return plan->income - plan->expenses;
}

// Function to calculate the savings rate of a financial plan
double calculateSavingsRate(PersonalFinance* plan) {
    return plan->savings / plan->income;
}

// Main function to test the financial planner
int main() {
    PersonalFinance* plan = createFinancialPlan("John Doe");
    addIncome(plan, 5000);
    addExpenses(plan, 3000);
    addSavings(plan, 1000);
    displayFinancialPlan(plan);
    printf("Net Worth: $%.2f\n", calculateNetWorth(plan));
    printf("Savings Rate: %.2f%%\n", calculateSavingsRate(plan) * 100);
    return 0;
}