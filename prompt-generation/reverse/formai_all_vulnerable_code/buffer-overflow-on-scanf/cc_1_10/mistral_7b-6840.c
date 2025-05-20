//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 50

typedef struct Transaction {
    char description[50];
    float amount;
    struct Transaction *next;
} Transaction;

Transaction *transactions = NULL;
float balance = 0.0;

void addTransaction(char *desc, float amt) {
    Transaction *newTransaction = (Transaction *)malloc(sizeof(Transaction));
    strcpy(newTransaction->description, desc);
    newTransaction->amount = amt;
    newTransaction->next = transactions;
    transactions = newTransaction;

    balance += amt;
}

void printTransactions() {
    Transaction *current = transactions;

    printf("\nTransactions:\n");
    while (current != NULL) {
        printf("%s: %.2f\n", current->description, current->amount);
        current = current->next;
    }

    printf("\nCurrent Balance: %.2f\n", balance);
}

void printMonthlyStats() {
    Transaction *current = transactions;
    float income = 0.0, expenses = 0.0;

    printf("\nMonthly Stats:\n");

    while (current != NULL) {
        if (current->amount > 0) {
            income += current->amount;
        } else {
            expenses += current->amount;
        }
        current = current->next;
    }

    printf("Monthly Income: %.2f\n", income);
    printf("Monthly Expenses: %.2f\n", expenses);
    printf("Net Monthly Flow: %.2f\n", income - expenses);
}

int main() {
    char desc[50];
    int choice;
    float amt;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Monthly Stats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter transaction description: ");
                scanf("%s", desc);
                printf("Enter transaction amount: ");
                scanf("%f", &amt);
                addTransaction(desc, amt);
                break;
            case 2:
                printTransactions();
                break;
            case 3:
                printMonthlyStats();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}