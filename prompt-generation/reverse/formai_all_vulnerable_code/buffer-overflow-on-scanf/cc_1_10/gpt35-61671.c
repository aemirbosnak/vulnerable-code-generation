//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>
#include <stdlib.h>

float calculateTax(float income);
float calculateSavings(int expense, float income);
void displayBudget(float income, int expense, float tax, float savings);

int main() {
    float income, tax, savings;
    int expense;
    
    printf("Welcome to Personal Finance Planner!\n");
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly expenses: ");
    scanf("%d", &expense);
    
    tax = calculateTax(income);
    savings = calculateSavings(expense, income);
    displayBudget(income, expense, tax, savings);
    
    return 0;
}

float calculateTax(float income) {
    float taxRate, tax = 0;
    
    if(income <= 5000) {
        taxRate = 0.05;
    } else if(income > 5000 && income <= 10000) {
        taxRate = 0.10;
    } else if(income > 10000 && income <= 20000) {
        taxRate = 0.15;
    } else if(income > 20000 && income <= 50000) {
        taxRate = 0.20;
    } else {
        taxRate = 0.25;
    }
    
    tax = income * taxRate;
    return tax;
}

float calculateSavings(int expense, float income) {
    float savings = 0;
    savings = income - expense - calculateTax(income);
    return savings;
}

void displayBudget(float income, int expense, float tax, float savings) {
    printf("\n-------Budget Summary-------\n");
    printf("Monthly Income: $%.2f\n", income);
    printf("Monthly Expenses: $%d\n", expense);
    printf("Monthly Tax: $%.2f\n", tax);
    printf("Monthly Savings: $%.2f\n", savings);
}