//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char type; // 'i' for income, 'e' for expense
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinancePlanner;

void initializePlanner(FinancePlanner *planner) {
    planner->count = 0;
}

void addTransaction(FinancePlanner *planner, const char *name, float amount, char type) {
    if (planner->count >= MAX_TRANSACTIONS) {
        printf("Thou hast reached the limit of transactions! A bard may sing of this woe.\n");
        return;
    }
    
    strncpy(planner->transactions[planner->count].name, name, MAX_NAME_LENGTH);
    planner->transactions[planner->count].amount = amount;
    planner->transactions[planner->count].type = type;
    planner->count++;
    printf("A transaction hath been recorded: %s of %.2f pieces of gold (Type: %c)\n", name, amount, type);
}

void viewTransactions(const FinancePlanner *planner) {
    if (planner->count == 0) {
        printf("Alas! No transactions have been recorded.\n");
        return;
    }
    
    printf("Herein lies thy ledger of transactions:\n");
    for (int i = 0; i < planner->count; i++) {
        printf("%d. %s: %.2f pieces of gold (%c)\n",
               i + 1,
               planner->transactions[i].name,
               planner->transactions[i].amount,
               planner->transactions[i].type);
    }
}

float calculateBalance(const FinancePlanner *planner) {
    float balance = 0.0;
    for (int i = 0; i < planner->count; i++) {
        if (planner->transactions[i].type == 'i') {
            balance += planner->transactions[i].amount;
        } else if (planner->transactions[i].type == 'e') {
            balance -= planner->transactions[i].amount;
        }
    }
    return balance;
}

void showBalance(const FinancePlanner *planner) {
    float balance = calculateBalance(planner);
    printf("Thy current balance stands at: %.2f pieces of gold\n", balance);
}

void displayMenu() {
    printf("=== Medieval Personal Finance Planner ===\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Show Balance\n");
    printf("4. Exit\n");
}

int main() {
    FinancePlanner planner;
    initializePlanner(&planner);
    
    int choice;
    char name[MAX_NAME_LENGTH];
    float amount;
    char type;

    do {
        displayMenu();
        printf("Choose thy quest (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the name of the transaction (e.g., 'golden coin'): ");
                scanf("%s", name);
                printf("Enter the amount in pieces of gold: ");
                scanf("%f", &amount);
                printf("Enter the type of transaction (i for income, e for expense): ");
                scanf(" %c", &type);
                addTransaction(&planner, name, amount, type);
                break;
            case 2:
                viewTransactions(&planner);
                break;
            case 3:
                showBalance(&planner);
                break;
            case 4:
                printf("Farewell! May fortune favor thee in thy endeavors!\n");
                break;
            default:
                printf("Thou hast chosen poorly! Select a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}