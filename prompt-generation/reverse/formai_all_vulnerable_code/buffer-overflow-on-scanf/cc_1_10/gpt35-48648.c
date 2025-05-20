//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>

// Struct for expenses
struct Expense {
    char name[50];
    float amount;
};

// Function for calculating total expenses
float calculateTotalExpense(struct Expense expenses[], int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    // Welcome message
    printf("Welcome to your Personal Finance Planner!\n");

    // Ask user for number of expenses
    int n;
    printf("How many expenses do you have? ");
    scanf("%d", &n);

    // Create array of expenses
    struct Expense expenses[n];

    // Ask user for expense details
    for (int i = 0; i < n; i++) {
        printf("\nExpense #%d-\n", i+1);
        printf("Name: ");
        scanf("%s", expenses[i].name);
        printf("Amount: ");
        scanf("%f", &expenses[i].amount);
    }

    // Display expense details
    printf("\nHere are your expenses:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s: %.2f\n", i+1, expenses[i].name, expenses[i].amount);
    }

    // Calculate total expenses
    float totalExpense = calculateTotalExpense(expenses, n);

    // Display total expenses
    printf("\nYour total expenses are: %.2f\n", totalExpense);

    // Ask user for income
    float income;
    printf("\nWhat is your monthly income? ");
    scanf("%f", &income);

    // Calculate remaining income after expenses
    float remainingIncome = income - totalExpense;

    // Display remaining income
    printf("Your remaining income after expenses is: %.2f\n", remainingIncome);

    // Determine if you are saving or overspending
    if (remainingIncome > 0) {
        printf("You are saving money this month!\n");
    } else if (remainingIncome < 0) {
        printf("You are overspending this month!\n");
    } else {
        printf("You are breaking even this month!\n");
    }

    return 0;
}