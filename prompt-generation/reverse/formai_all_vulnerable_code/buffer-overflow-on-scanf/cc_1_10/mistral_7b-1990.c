//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 50

typedef struct {
    char description[50];
    float amount;
    struct Transaction *next;
} Transaction;

Transaction *head = NULL;

void addTransaction(char *description, float amount) {
    Transaction *newTransaction = (Transaction *)malloc(sizeof(Transaction));

    strcpy(newTransaction->description, description);
    newTransaction->amount = amount;
    newTransaction->next = head;
    head = newTransaction;
}

void viewTransactions() {
    Transaction *current = head;

    printf("\nCurrent Transactions:\n");
    printf("----------------------\n");

    while (current != NULL) {
        printf("%s: %.2f\n", current->description, current->amount);
        current = current->next;
    }
}

void calculateBalance() {
    Transaction *current = head;
    float balance = 0.0;

    while (current != NULL) {
        balance += current->amount;
        current = current->next;
    }

    printf("\nCurrent Balance: %.2f\n", balance);
}

int main() {
    char description[50];
    float amount;
    int choice;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Calculate Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter transaction description: ");
                scanf("%s", description);
                printf("Enter transaction amount: ");
                scanf("%f", &amount);
                addTransaction(description, amount);
                break;
            case 2:
                viewTransactions();
                break;
            case 3:
                calculateBalance();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}