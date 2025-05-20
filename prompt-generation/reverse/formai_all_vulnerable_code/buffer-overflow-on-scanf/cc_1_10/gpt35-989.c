//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
#include <stdio.h>

// Define the struct for an account
struct Account {
    int accountNumber;
    char accountType[20];
    double balance;
};

int main() {
    // Initialize an account and prompt user for account information
    struct Account account1;
    printf("Please enter your account number: ");
    scanf("%d", &account1.accountNumber);
    printf("Please enter your account type (checking, savings, or credit card): ");
    scanf("%s", account1.accountType);
    printf("Please enter your current account balance: ");
    scanf("%lf", &account1.balance);

    // Prompt user for monthly income and expenses
    double monthlyIncome, housingExpense, transportationExpense, foodExpense, otherExpense;
    printf("\nPlease enter your monthly income: ");
    scanf("%lf", &monthlyIncome);
    printf("Please enter your housing expense: ");
    scanf("%lf", &housingExpense);
    printf("Please enter your transportation expense: ");
    scanf("%lf", &transportationExpense);
    printf("Please enter your food expense: ");
    scanf("%lf", &foodExpense);
    printf("Please enter your other expenses: ");
    scanf("%lf", &otherExpense);

    // Calculate monthly net income and expenses
    double netIncome = monthlyIncome - (housingExpense + transportationExpense + foodExpense + otherExpense);
    double netExpense = housingExpense + transportationExpense + foodExpense + otherExpense;

    // Display account information and financial overview
    printf("\nAccount Information:\n");
    printf("Account Number: %d\n", account1.accountNumber);
    printf("Account Type: %s\n", account1.accountType);
    printf("Current Balance: $%.2lf\n\n", account1.balance);

    printf("Financial Overview:\n");
    printf("Monthly Net Income: $%.2lf\n", netIncome);
    printf("Monthly Net Expenses: $%.2lf\n", netExpense);
    printf("Projected Account Balance with Current Month's Income and Expenses: $%.2lf\n", account1.balance + netIncome);
    printf("Projected Account Balance with Current Month's Expenses: $%.2lf\n", account1.balance - netExpense);

    return 0;
}