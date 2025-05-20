//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
    float income;
    float expenses;
    float savings;
} Finance;

void initializeFinance(Finance *finance) {
    finance->count = 0;
    finance->income = 0;
    finance->expenses = 0;
    finance->savings = 0;
}

void addIncome(Finance *finance) {
    char name[MAX_LENGTH];
    float amount;
    printf("Enter income source: ");
    scanf("%s", name);
    printf("Enter amount: ");
    scanf("%f", &amount);
    finance->transactions[finance->count++] = (Transaction){.name = name, .amount = amount};
    finance->income += amount;
    printf("Added income: %s of %.2f\n", name, amount);
}

void addExpense(Finance *finance) {
    char name[MAX_LENGTH];
    float amount;
    printf("Enter expense description: ");
    scanf("%s", name);
    printf("Enter amount: ");
    scanf("%f", &amount);
    finance->transactions[finance->count++] = (Transaction){.name = name, .amount = -amount};
    finance->expenses += amount;
    printf("Added expense: %s of %.2f\n", name, amount);
}

void calculateSavings(Finance *finance) {
    finance->savings = finance->income - finance->expenses;
}

void displaySummary(Finance *finance) {
    printf("\n--- Financial Summary ---\n");
    printf("Total Income: %.2f\n", finance->income);
    printf("Total Expenses: %.2f\n", finance->expenses);
    printf("Total Savings: %.2f\n", finance->savings);
    
    if (finance->savings < 0) {
        printf("Warning: You are in deficit! Consider reviewing your expenses.\n");
    } else if (finance->savings < finance->income * 0.20) {
        printf("Tip: Aim to save at least 20%% of your income for better financial health!\n");
    }
}

void displayTransactions(Finance *finance) {
    printf("\n--- Transaction List ---\n");
    for (int i = 0; i < finance->count; i++) {
        printf("%s: %.2f\n", finance->transactions[i].name, finance->transactions[i].amount);
    }
}

void clearFinance(Finance *finance) {
    initializeFinance(finance);
    printf("All financial data cleared.\n");
}

int main() {
    Finance finance;
    initializeFinance(&finance);
    int choice;

    do {
        printf("\n----- Personal Finance Planner -----\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. View Transactions\n");
        printf("5. Clear Data\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&finance);
                break;
            case 2:
                addExpense(&finance);
                break;
            case 3:
                calculateSavings(&finance);
                displaySummary(&finance);
                break;
            case 4:
                displayTransactions(&finance);
                break;
            case 5:
                clearFinance(&finance);
                break;
            case 6:
                printf("Exiting the Personal Finance Planner. Happy budgeting!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}