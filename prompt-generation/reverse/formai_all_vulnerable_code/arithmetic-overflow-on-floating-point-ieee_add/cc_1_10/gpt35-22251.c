//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

float getIncome(void);
float calculateExpenses(void);
void calculateSavings(float income, float expenses);
void displayResults(float income, float expenses, float savings);

int main(void) {
    float income, expenses, savings;
    
    printf("****PERSONAL FINANCE PLANNER****\n\n");
    
    //get user's income
    income = getIncome();
    
    //calculate monthly expenses
    expenses = calculateExpenses();
    
    //calculate monthly savings
    calculateSavings(income, expenses);
    
    //display results
    displayResults(income, expenses, savings);
    
    return 0;
}

float getIncome(void) {
    float income;
    
    printf("Enter your monthly income: $");
    scanf("%f", &income);
    
    return income;
}

float calculateExpenses(void) {
    float housing, transportation, food, utilities, entertainment, other, totalExpenses;
    
    printf("Enter monthly expenses:\n");
    
    printf("\tHousing: $");
    scanf("%f", &housing);
    
    printf("\tTransportation: $");
    scanf("%f", &transportation);
    
    printf("\tFood: $");
    scanf("%f", &food);
    
    printf("\tUtilities: $");
    scanf("%f", &utilities);
    
    printf("\tEntertainment: $");
    scanf("%f", &entertainment);
    
    printf("\tOther: $");
    scanf("%f", &other);
    
    totalExpenses = housing + transportation + food + utilities + entertainment + other;
    
    return totalExpenses;
}

void calculateSavings(float income, float expenses) {
    float savings;
    
    savings = income - expenses;
    
    printf("\n\nCalculating savings...\n\n");
    system("sleep 2");
    
    printf("Monthly Savings: $%.2f\n", savings);
}

void displayResults(float income, float expenses, float savings) {
    printf("\n\n****RESULTS****\n\n");
    
    printf("Monthly Income: $%.2f\n", income);
    
    printf("Monthly Expenses: $%.2f\n", expenses);
    
    printf("Monthly Savings: $%.2f\n", savings);
}