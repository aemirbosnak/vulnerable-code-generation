//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_LENGTH 50

typedef struct {
    char description[MAX_LENGTH];
    float amount;
    char type; // 'I' for income, 'E' for expense
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinancePlanner;

void addTransaction(FinancePlanner* planner) {
    if (planner->count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot add more transactions.\n");
        return;
    }

    Transaction newTransaction;
    char typeInput;

    printf("Enter description: ");
    scanf(" %[^\n]", newTransaction.description);
    
    printf("Enter amount: ");
    scanf("%f", &newTransaction.amount);
    
    printf("Enter type (I for Income, E for Expense): ");
    scanf(" %c", &typeInput);
    
    if (typeInput == 'I' || typeInput == 'E') {
        newTransaction.type = typeInput;
        planner->transactions[planner->count] = newTransaction;
        planner->count++;
        printf("Transaction added successfully!\n");
    } else {
        printf("Invalid type entered. Transaction not added.\n");
    }
}

void viewTransactions(FinancePlanner* planner) {
    if (planner->count == 0) {
        printf("No transactions available.\n");
        return;
    }

    printf("Your Transactions:\n");
    for (int i = 0; i < planner->count; i++) {
        printf("%d. %s: %.2f (%c)\n", i + 1, planner->transactions[i].description,
               planner->transactions[i].amount, planner->transactions[i].type);
    }
}

void calculateBalance(FinancePlanner* planner) {
    float income = 0.0, expense = 0.0;

    for (int i = 0; i < planner->count; i++) {
        if (planner->transactions[i].type == 'I') {
            income += planner->transactions[i].amount;
        } else if (planner->transactions[i].type == 'E') {
            expense += planner->transactions[i].amount;
        }
    }

    printf("Total Income: %.2f\n", income);
    printf("Total Expenses: %.2f\n", expense);
    printf("Net Balance: %.2f\n", income - expense);
}

void displayMenu() {
    printf("Personal Finance Planner Menu\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Calculate Balance\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FinancePlanner planner = { .count = 0 };
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(&planner);
                break;
            case 2:
                viewTransactions(&planner);
                break;
            case 3:
                calculateBalance(&planner);
                break;
            case 4:
                printf("Exiting the Personal Finance Planner.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}