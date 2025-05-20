//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100 // Limit for number of transactions
#define NAME_SIZE 50 // Max size for name of transaction

typedef struct {
    char name[NAME_SIZE];
    float amount;
} Transaction;

typedef struct {
    float totalIncome;
    float totalExpense;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
} FinancePlanner;

// Function to initialize Finance Planner
void initFinancePlanner(FinancePlanner *planner) {
    planner->totalIncome = 0.0;
    planner->totalExpense = 0.0;
    planner->transactionCount = 0;
}

// Function to add income
void addIncome(FinancePlanner *planner, float amount, const char *name) {
    if (planner->transactionCount < MAX_TRANSACTIONS) {
        Transaction t;
        snprintf(t.name, NAME_SIZE, "Income: %s", name);
        t.amount = amount;
        planner->transactions[planner->transactionCount++] = t;
        planner->totalIncome += amount;
    } else {
        printf("Maximum transaction limit reached.\n");
    }
}

// Function to add expense
void addExpense(FinancePlanner *planner, float amount, const char *name) {
    if (planner->transactionCount < MAX_TRANSACTIONS) {
        Transaction t;
        snprintf(t.name, NAME_SIZE, "Expense: %s", name);
        t.amount = amount;
        planner->transactions[planner->transactionCount++] = t;
        planner->totalExpense += amount;
    } else {
        printf("Maximum transaction limit reached.\n");
    }
}

// Function to display all transactions
void displayTransactions(const FinancePlanner *planner) {
    printf("\n--- Transactions ---\n");
    for (int i = 0; i < planner->transactionCount; i++) {
        printf("%s - $%.2f\n", planner->transactions[i].name, planner->transactions[i].amount);
    }
    printf("--------------------\n");
}

// Function to display the summary
void displaySummary(const FinancePlanner *planner) {
    float netIncome = planner->totalIncome - planner->totalExpense;
    printf("\n--- Financial Summary ---\n");
    printf("Total Income: $%.2f\n", planner->totalIncome);
    printf("Total Expense: $%.2f\n", planner->totalExpense);
    printf("Net Income: $%.2f\n", netIncome);
    printf("--------------------------\n");
}

// Main function
int main() {
    FinancePlanner planner;
    initFinancePlanner(&planner);
    int choice;
    
    while (1) {
        printf("\n=== Personal Finance Planner ===\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Show Transactions\n");
        printf("4. Show Summary\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        if (choice == 5) {
            break; // Exit
        }
        
        if (choice == 1) {
            float income;
            char name[NAME_SIZE];
            printf("Enter income amount: ");
            scanf("%f", &income);
            printf("Enter source of income: ");
            scanf("%s", name);
            addIncome(&planner, income, name);
        } else if (choice == 2) {
            float expense;
            char name[NAME_SIZE];
            printf("Enter expense amount: ");
            scanf("%f", &expense);
            printf("Enter purpose of expense: ");
            scanf("%s", name);
            addExpense(&planner, expense, name);
        } else if (choice == 3) {
            displayTransactions(&planner);
        } else if (choice == 4) {
            displaySummary(&planner);
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
    
    printf("Thank you for using the Personal Finance Planner!\n");
    return 0;
}