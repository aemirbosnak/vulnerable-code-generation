//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_ACCOUNT_ITEMS 10

typedef struct {
    char name[50];
    float amount;
} budget_item_t;

typedef struct {
    char name[50];
    float balance;
} account_t;

int main() {
    int num_budget_items, num_account_items;
    budget_item_t budget[MAX_BUDGET_ITEMS];
    account_t accounts[MAX_ACCOUNT_ITEMS];

    printf("Welcome to the Personal Finance Planner!\n\n");

    // Get number of budget items
    printf("How many budget items do you have? ");
    scanf("%d", &num_budget_items);

    // Get budget items
    for (int i = 0; i < num_budget_items; i++) {
        printf("Enter budget item #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", budget[i].name);
        printf("Amount: ");
        scanf("%f", &budget[i].amount);
    }

    // Get number of accounts
    printf("\nHow many accounts do you have? ");
    scanf("%d", &num_account_items);

    // Get accounts
    for (int i = 0; i < num_account_items; i++) {
        printf("\nEnter account #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", accounts[i].name);
        printf("Balance: ");
        scanf("%f", &accounts[i].balance);
    }

    // Calculate total income and expenses
    float total_income = 0.0;
    float total_expenses = 0.0;

    for (int i = 0; i < num_budget_items; i++) {
        if (budget[i].amount > 0) {
            total_income += budget[i].amount;
        } else {
            total_expenses += abs(budget[i].amount);
        }
    }

    // Calculate total account balances
    float total_account_balance = 0.0;

    for (int i = 0; i < num_account_items; i++) {
        total_account_balance += accounts[i].balance;
    }

    // Print results
    printf("\nResults:\n");
    printf("Total Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Total Account Balances: $%.2f\n", total_account_balance);

    return 0;
}