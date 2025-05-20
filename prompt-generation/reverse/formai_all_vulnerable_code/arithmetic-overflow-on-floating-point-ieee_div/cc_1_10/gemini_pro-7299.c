//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the main function
int main() {
    // Variables for the user's details
    char name[100];
    int age;
    double income;

    // Get the user's name
    printf("What is your name? ");
    scanf("%s", name);

    // Get the user's age
    printf("How old are you? ");
    scanf("%d", &age);

    // Get the user's income
    printf("What is your annual income? ");
    scanf("%lf", &income);

    // Calculate the user's monthly expenses
    double monthlyExpenses = 0;
    printf("What are your monthly expenses?\n");
    printf("Housing: ");
    scanf("%lf", &monthlyExpenses);
    printf("Food: ");
    scanf("%lf", &monthlyExpenses);
    printf("Transportation: ");
    scanf("%lf", &monthlyExpenses);
    printf("Utilities: ");
    scanf("%lf", &monthlyExpenses);
    printf("Other: ");
    scanf("%lf", &monthlyExpenses);

    // Calculate the user's savings goal
    double savingsGoal;
    printf("What is your savings goal? ");
    scanf("%lf", &savingsGoal);

    // Calculate the number of years it will take to reach the savings goal
    int numYears = (int) (savingsGoal / (income * 12 - monthlyExpenses));

    // Print the results to the user
    printf("Hello, %s.\n", name);
    printf("You are %d years old.\n", age);
    printf("Your annual income is $%.2f.\n", income);
    printf("Your monthly expenses are $%.2f.\n", monthlyExpenses);
    printf("Your savings goal is $%.2f.\n", savingsGoal);
    printf("It will take you %d years to reach your savings goal.\n", numYears);

    return 0;
}