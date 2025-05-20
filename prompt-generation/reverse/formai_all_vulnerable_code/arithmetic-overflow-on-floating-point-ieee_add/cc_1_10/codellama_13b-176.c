//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
/*
 * Personal Finance Planner
 *
 * This program allows the user to plan their personal finances by
 * inputting their income, expenses, and savings goals.
 *
 * It will then calculate the user's net worth, debt-to-income ratio,
 * and savings progress.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the income and expense struct
struct Income {
    char name[256];
    float amount;
};

struct Expense {
    char name[256];
    float amount;
};

// Define the savings goal struct
struct Goal {
    char name[256];
    float amount;
};

// Define the net worth struct
struct NetWorth {
    float income;
    float expenses;
    float savings;
    float debt;
};

// Function to calculate the net worth
float calculate_net_worth(struct NetWorth *nw) {
    return nw->income - nw->expenses + nw->savings - nw->debt;
}

// Function to calculate the debt-to-income ratio
float calculate_debt_to_income_ratio(struct NetWorth *nw) {
    return nw->debt / nw->income;
}

// Function to calculate the savings progress
float calculate_savings_progress(struct NetWorth *nw, struct Goal *g) {
    return nw->savings / g->amount;
}

// Function to print the net worth, debt-to-income ratio, and savings progress
void print_financial_status(struct NetWorth *nw, struct Goal *g) {
    printf("Net Worth: $%.2f\n", calculate_net_worth(nw));
    printf("Debt-to-Income Ratio: %.2f\n", calculate_debt_to_income_ratio(nw));
    printf("Savings Progress: %.2f%%\n", calculate_savings_progress(nw, g));
}

// Function to prompt the user for their income and expenses
void prompt_income_expenses(struct Income *i, struct Expense *e) {
    printf("Enter your income: ");
    scanf("%f", &i->amount);
    printf("Enter your expenses: ");
    scanf("%f", &e->amount);
}

// Function to prompt the user for their savings goal
void prompt_savings_goal(struct Goal *g) {
    printf("Enter your savings goal: ");
    scanf("%f", &g->amount);
}

// Function to prompt the user for their debt
void prompt_debt(struct NetWorth *nw) {
    printf("Enter your debt: ");
    scanf("%f", &nw->debt);
}

int main() {
    // Initialize the income and expense structs
    struct Income i;
    struct Expense e;

    // Initialize the savings goal struct
    struct Goal g;

    // Initialize the net worth struct
    struct NetWorth nw;

    // Prompt the user for their income and expenses
    prompt_income_expenses(&i, &e);

    // Prompt the user for their savings goal
    prompt_savings_goal(&g);

    // Prompt the user for their debt
    prompt_debt(&nw);

    // Calculate the net worth
    nw.income = i.amount;
    nw.expenses = e.amount;

    // Calculate the debt-to-income ratio
    float debt_to_income_ratio = calculate_debt_to_income_ratio(&nw);

    // Calculate the savings progress
    float savings_progress = calculate_savings_progress(&nw, &g);

    // Print the financial status
    print_financial_status(&nw, &g);

    return 0;
}