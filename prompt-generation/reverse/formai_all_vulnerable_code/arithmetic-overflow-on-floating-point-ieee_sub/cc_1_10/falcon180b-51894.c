//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define structure for personal finance information
struct personal_finance {
    char name[50];
    float income;
    float expenses;
    float savings;
};

// Function to print personal finance information
void print_personal_finance(struct personal_finance pf) {
    printf("Name: %s\n", pf.name);
    printf("Income: $%.2f\n", pf.income);
    printf("Expenses: $%.2f\n", pf.expenses);
    printf("Savings: $%.2f\n\n", pf.savings);
}

// Function to calculate savings percentage
float calculate_savings_percentage(float income, float expenses) {
    float savings = income - expenses;
    float percentage = (savings / income) * 100;
    return percentage;
}

// Main function
int main() {
    struct personal_finance pf;

    // Get user input for personal finance information
    printf("Enter your name: ");
    scanf("%s", pf.name);

    printf("Enter your income: $");
    scanf("%f", &pf.income);

    printf("Enter your expenses: $");
    scanf("%f", &pf.expenses);

    // Calculate savings and savings percentage
    pf.savings = pf.income - pf.expenses;
    float savings_percentage = calculate_savings_percentage(pf.income, pf.expenses);

    // Print personal finance information
    printf("\nPersonal Finance Information:\n");
    print_personal_finance(pf);

    // Print savings percentage
    printf("\nSavings Percentage: %.2f%%\n", savings_percentage);

    return 0;
}