//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
    char type; // 'i' for income, 'e' for expense
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinanceTracker;

void displayMenu();
void addTransaction(FinanceTracker *tracker);
void viewTransactions(FinanceTracker *tracker);
void calculateNetWorth(FinanceTracker *tracker);
void clearScreen();

int main() {
    FinanceTracker tracker = { .count = 0 };
    int choice; 

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearScreen();

        switch (choice) {
            case 1:
                addTransaction(&tracker);
                break;
            case 2:
                viewTransactions(&tracker);
                break;
            case 3:
                calculateNetWorth(&tracker);
                break;
            case 0:
                printf("Exiting the personal finance planner. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}

void displayMenu() {
    printf("Personal Finance Planner\n");
    printf("=========================\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Calculate Net Worth\n");
    printf("0. Exit\n");
}

void clearScreen() {
    printf("\033[H\033[2J"); // ANSI escape code to clear the screen
}

void addTransaction(FinanceTracker *tracker) {
    if (tracker->count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached! Cannot add more transactions.\n");
        return;
    }

    Transaction newTrans;
    printf("Enter transaction description (max 50 characters): ");
    getchar(); // clear the newline from the previous input
    fgets(newTrans.description, MAX_DESC_LENGTH, stdin);
    newTrans.description[strcspn(newTrans.description, "\n")] = 0; // remove newline

    printf("Enter amount: ");
    scanf("%f", &newTrans.amount);

    printf("Enter type (i for income, e for expense): ");
    getchar(); // clear the newline before reading a char
    newTrans.type = getchar();

    tracker->transactions[tracker->count] = newTrans;
    tracker->count++;
    printf("Transaction added successfully!\n");
}

void viewTransactions(FinanceTracker *tracker) {
    if (tracker->count == 0) {
        printf("No transactions found.\n");
        return;
    }

    printf("Transactions:\n");
    printf("Description                           Amount       Type\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        Transaction trans = tracker->transactions[i];
        printf("%-36s %-12.2f %-10c\n", trans.description, trans.amount, trans.type);
    }
}

void calculateNetWorth(FinanceTracker *tracker) {
    float income = 0.0;
    float expenses = 0.0;

    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].type == 'i') {
            income += tracker->transactions[i].amount;
        } else if (tracker->transactions[i].type == 'e') {
            expenses += tracker->transactions[i].amount;
        }
    }

    printf("Total Income: %.2f\n", income);
    printf("Total Expenses: %.2f\n", expenses);
    printf("Net Worth: %.2f\n", income - expenses);
}