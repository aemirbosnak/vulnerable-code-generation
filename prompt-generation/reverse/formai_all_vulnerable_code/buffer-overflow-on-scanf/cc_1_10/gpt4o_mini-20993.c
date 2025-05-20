//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_ENTRIES];
    int count;
} Budget;

void addTransaction(Budget *budget) {
    if (budget->count >= MAX_ENTRIES) {
        printf("Budget is full! Cannot add more transactions.\n");
        return;
    }
    Transaction newTransaction;
    printf("Enter transaction name: ");
    scanf("%s", newTransaction.name);
    printf("Enter transaction amount (negative for expenses): ");
    scanf("%f", &newTransaction.amount);
    
    budget->transactions[budget->count++] = newTransaction;
    printf("Transaction added: %s - $%.2f\n", newTransaction.name, newTransaction.amount);
}

void viewTransactions(const Budget *budget) {
    if (budget->count == 0) {
        printf("No transactions to display.\n");
        return;
    }
    
    printf("\nTransaction List:\n");
    for (int i = 0; i < budget->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, budget->transactions[i].name, budget->transactions[i].amount);
    }
}

void calculateBalance(const Budget *budget) {
    float balance = 0.0;
    for (int i = 0; i < budget->count; i++) {
        balance += budget->transactions[i].amount;
    }
    printf("Your current balance is: $%.2f\n", balance);
}

void summary(const Budget *budget) {
    float totalIncome = 0.0;
    float totalExpenses = 0.0;

    for (int i = 0; i < budget->count; i++) {
        if (budget->transactions[i].amount > 0) {
            totalIncome += budget->transactions[i].amount;
        } else {
            totalExpenses += budget->transactions[i].amount;
        }
    }

    printf("\n--- Summary ---\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Savings: $%.2f\n", totalIncome + totalExpenses);
}

void menu() {
    printf("\n--- Personal Finance Planner Menu ---\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Calculate Balance\n");
    printf("4. Summary\n");
    printf("5. Exit\n");
}

int main() {
    Budget budget;
    budget.count = 0;
    int choice;

    do {
        menu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(&budget);
                break;
            case 2:
                viewTransactions(&budget);
                break;
            case 3:
                calculateBalance(&budget);
                break;
            case 4:
                summary(&budget);
                break;
            case 5:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}