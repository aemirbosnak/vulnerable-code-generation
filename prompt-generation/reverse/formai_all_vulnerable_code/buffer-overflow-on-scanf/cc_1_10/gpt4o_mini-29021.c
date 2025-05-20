//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
    char category[NAME_LENGTH];
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
    float totalIncome;
    float totalExpenses;
} FinancePlanner;

void addTransaction(FinancePlanner *planner);
void displayTransactions(const FinancePlanner *planner);
float calculateBalance(const FinancePlanner *planner);

int main() {
    FinancePlanner planner;
    planner.count = 0;
    planner.totalIncome = 0.0;
    planner.totalExpenses = 0.0;

    int choice;

    printf("Welcome to the Personal Finance Planner!\n");

    do {
        printf("\nMain Menu:\n");
        printf("1. Add Transaction\n");
        printf("2. Display Transactions\n");
        printf("3. Calculate Balance\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                addTransaction(&planner);
                break;
            case 2: 
                displayTransactions(&planner);
                break;
            case 3:
                printf("Current Balance: $%.2f\n", calculateBalance(&planner));
                break;
            case 4:
                printf("Exiting the Finance Planner. Happy budgeting!\n");
                break;
            default:
                printf("Invalid option. Please choose again!\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void addTransaction(FinancePlanner *planner) {
    if (planner->count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached! Cannot add more transactions.\n");
        return;
    }

    Transaction newTransaction;
    printf("Enter transaction name: ");
    scanf("%s", newTransaction.name);
    
    printf("Enter amount (negative for expenses): ");
    scanf("%f", &newTransaction.amount);
    
    printf("Enter category: ");
    scanf("%s", newTransaction.category);

    planner->transactions[planner->count++] = newTransaction;

    if (newTransaction.amount > 0) {
        planner->totalIncome += newTransaction.amount;
    } else {
        planner->totalExpenses += (-newTransaction.amount);
    }

    printf("Transaction added successfully!\n");
}

void displayTransactions(const FinancePlanner *planner) {
    if (planner->count == 0) {
        printf("No transactions to display.\n");
        return;
    }

    printf("\nList of Transactions:\n");
    printf("---------------------------------------------------\n");
    printf("%-30s %-10s %-15s\n", "Transaction Name", "Amount", "Category");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < planner->count; i++) {
        printf("%-30s $%-9.2f %-15s\n", planner->transactions[i].name, 
               planner->transactions[i].amount, planner->transactions[i].category);
    }
    printf("---------------------------------------------------\n");
}

float calculateBalance(const FinancePlanner *planner) {
    return planner->totalIncome - planner->totalExpenses;
}