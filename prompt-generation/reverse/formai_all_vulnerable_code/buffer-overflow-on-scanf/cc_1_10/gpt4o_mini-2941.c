//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
    int type; // 1 for income, 0 for expense
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinancePlanner;

void addTransaction(FinancePlanner *planner, const char *description, float amount, int type) {
    if (planner->count < MAX_TRANSACTIONS) {
        strncpy(planner->transactions[planner->count].description, description, MAX_DESC_LENGTH);
        planner->transactions[planner->count].amount = amount;
        planner->transactions[planner->count].type = type;
        planner->count++;
        printf("Transaction added successfully.\n");
    } else {
        printf("Transaction limit reached! Cannot add more transactions.\n");
    }
}

void viewTransactions(const FinancePlanner *planner) {
    printf("\nTransactions:\n");
    for (int i = 0; i < planner->count; i++) {
        printf("%d. %s: %.2f (%s)\n", i + 1, planner->transactions[i].description, 
                planner->transactions[i].amount, 
                planner->transactions[i].type == 1 ? "Income" : "Expense");
    }
}

void calculateTotals(const FinancePlanner *planner, float *totalIncome, float *totalExpenses, float *totalSavings) {
    *totalIncome = 0.0;
    *totalExpenses = 0.0;
    for (int i = 0; i < planner->count; i++) {
        if (planner->transactions[i].type == 1) {
            *totalIncome += planner->transactions[i].amount;
        } else {
            *totalExpenses += planner->transactions[i].amount;
        }
    }
    *totalSavings = *totalIncome - *totalExpenses;
}

void viewReport(const FinancePlanner *planner) {
    float totalIncome, totalExpenses, totalSavings;
    calculateTotals(planner, &totalIncome, &totalExpenses, &totalSavings);
    printf("\nFinancial Report:\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Total Savings: %.2f\n", totalSavings);
}

void displayMenu() {
    printf("\nPersonal Finance Planner Menu:\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Transactions\n");
    printf("4. View Financial Report\n");
    printf("5. Exit\n");
}

int main() {
    FinancePlanner planner = {0};
    int choice;
    char description[MAX_DESC_LENGTH];
    float amount;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter income description: ");
                scanf("%s", description);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                addTransaction(&planner, description, amount, 1);
                break;
            case 2:
                printf("Enter expense description: ");
                scanf("%s", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addTransaction(&planner, description, amount, 0);
                break;
            case 3:
                viewTransactions(&planner);
                break;
            case 4:
                viewReport(&planner);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}