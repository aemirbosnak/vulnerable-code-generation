//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the Personal Finance Planner struct
typedef struct PersonalFinancePlanner {
    char name[20];
    int age;
    double income;
    double expenses;
    double savings;
} PersonalFinancePlanner;

// Function to calculate the total net worth of a person
double calculateNetWorth(PersonalFinancePlanner *planner) {
    return planner->savings + planner->income - planner->expenses;
}

// Function to calculate the monthly savings of a person
double calculateMonthlySavings(PersonalFinancePlanner *planner) {
    return (planner->income - planner->expenses) * planner->savings / 100;
}

int main() {
    // Create a Personal Finance Planner struct
    PersonalFinancePlanner planner;

    // Get the person's name, age, income, and expenses
    printf("Enter your name: ");
    scanf("%s", planner.name);

    printf("Enter your age: ");
    scanf("%d", &planner.age);

    printf("Enter your income: ");
    scanf("%lf", &planner.income);

    printf("Enter your expenses: ");
    scanf("%lf", &planner.expenses);

    // Calculate the person's total net worth
    double netWorth = calculateNetWorth(&planner);

    // Calculate the person's monthly savings
    double monthlySavings = calculateMonthlySavings(&planner);

    // Print the results
    printf("Your total net worth is $%.2lf.", netWorth);

    printf("\nYour monthly savings are $%.2lf.", monthlySavings);

    return 0;
}