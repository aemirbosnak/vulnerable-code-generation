//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    double amount;
    int transactionType; // 1 for income, -1 for expense
} Transaction;

void displayMenu();
void addTransaction(Transaction transactions[], int *numTransactions);
void calculateTotal(Transaction transactions[], int numTransactions);
void printTransactions(Transaction transactions[], int numTransactions);

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(transactions, &numTransactions);
                break;
            case 2:
                calculateTotal(transactions, numTransactions);
                break;
            case 3:
                printTransactions(transactions, numTransactions);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("--------------------------\n");
    printf("1. Add Transaction\n");
    printf("2. Calculate Total\n");
    printf("3. Print Transactions\n");
    printf("0. Exit\n");
}

void addTransaction(Transaction transactions[], int *numTransactions) {
    if (*numTransactions == MAX_TRANSACTIONS) {
        printf("Maximum number of transactions reached! Try again later.\n");
        return;
    }

    printf("Enter transaction description: ");
    scanf("%s", transactions[*numTransactions].description);

    printf("Enter transaction amount: ");
    scanf("%lf", &transactions[*numTransactions].amount);

    printf("Enter transaction type (1 for income, -1 for expense): ");
    scanf("%d", &transactions[*numTransactions].transactionType);

    (*numTransactions)++;
}

void calculateTotal(Transaction transactions[], int numTransactions) {
    double total = 0.0;

    for (int i = 0; i < numTransactions; i++) {
        total += transactions[i].amount * transactions[i].transactionType;
    }

    printf("Total: %.2lf\n", total);
}

void printTransactions(Transaction transactions[], int numTransactions) {
    printf("Transactions:\n");

    for (int i = 0; i < numTransactions; i++) {
        printf("%s: %.2lf\n", transactions[i].description, transactions[i].amount * transactions[i].transactionType);
    }
}