//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_TRANSACTION_CATEGORIES 10

typedef struct {
    char name[50];
    double amount;
    int frequency; // 1 = monthly, 2 = weekly, 3 = daily
} BudgetCategory;

typedef struct {
    char name[50];
    double amount;
    int category; // 1 = income, 2 = expense
} Transaction;

int numBudgetCategories = 0;
BudgetCategory budgetCategories[MAX_BUDGET_CATEGORIES];

int numTransactions = 0;
Transaction transactions[MAX_TRANSACTIONS];

void addBudgetCategory() {
    printf("Enter the name of the budget category: ");
    scanf("%s", budgetCategories[numBudgetCategories].name);
    printf("Enter the amount: ");
    scanf("%lf", &budgetCategories[numBudgetCategories].amount);
    printf("Enter the frequency (1 = monthly, 2 = weekly, 3 = daily): ");
    scanf("%d", &budgetCategories[numBudgetCategories].frequency);
    numBudgetCategories++;
}

void addTransaction() {
    printf("Enter the name of the transaction: ");
    scanf("%s", transactions[numTransactions].name);
    printf("Enter the amount: ");
    scanf("%lf", &transactions[numTransactions].amount);
    printf("Enter the category (1 = income, 2 = expense): ");
    scanf("%d", &transactions[numTransactions].category);
    numTransactions++;
}

void displayBudgetCategories() {
    printf("Budget Categories:\n");
    for (int i = 0; i < numBudgetCategories; i++) {
        printf("%s - $%.2lf - %d\n", budgetCategories[i].name, budgetCategories[i].amount, budgetCategories[i].frequency);
    }
}

void displayTransactions() {
    printf("Transactions:\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("%s - $%.2lf - %d\n", transactions[i].name, transactions[i].amount, transactions[i].category);
    }
}

int main() {
    int choice;
    char repeat = 'y';

    do {
        printf("Personal Finance Planner\n");
        printf("1. Add budget category\n");
        printf("2. Add transaction\n");
        printf("3. Display budget categories\n");
        printf("4. Display transactions\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBudgetCategory();
                break;
            case 2:
                addTransaction();
                break;
            case 3:
                displayBudgetCategories();
                break;
            case 4:
                displayTransactions();
                break;
            case 5:
                repeat = 'n';
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (repeat == 'y');

    return 0;
}