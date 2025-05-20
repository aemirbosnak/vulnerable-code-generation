//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct Transaction {
    char description[50];
    float amount;
    int type; // 1 for income, -1 for expense, 0 for savings
} Transaction;

void print_menu();
void add_transaction(Transaction transactions[], int *num_transactions);
void display_balance(Transaction transactions[], int num_transactions);
void display_history(Transaction transactions[], int num_transactions);

int main() {
    int num_transactions = 0;
    Transaction transactions[MAX_TRANSACTIONS];

    while (1) {
        print_menu();
        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction(transactions, &num_transactions);
                break;
            case 2:
                display_balance(transactions, num_transactions);
                break;
            case 3:
                display_history(transactions, num_transactions);
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

void print_menu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Transaction\n");
    printf("2. Display Balance\n");
    printf("3. Display Transaction History\n");
    printf("4. Exit\n");
}

void add_transaction(Transaction transactions[], int *num_transactions) {
    if (*num_transactions >= MAX_TRANSACTIONS) {
        printf("Maximum number of transactions reached!\n");
        return;
    }

    printf("Enter description: ");
    scanf("%s", transactions[*num_transactions].description);

    printf("Enter amount: ");
    float amount;
    scanf("%f", &amount);

    printf("Enter transaction type (1 for income, -1 for expense, 0 for savings): ");
    int type;
    scanf("%d", &type);

    transactions[*num_transactions].amount = amount;
    transactions[*num_transactions].type = type;

    (*num_transactions)++;

    printf("Transaction added successfully!\n");
}

void display_balance(Transaction transactions[], int num_transactions) {
    float balance = 0;

    for (int i = 0; i < num_transactions; i++) {
        balance += transactions[i].amount * transactions[i].type;
    }

    printf("Current balance: $%.2f\n", balance);
}

void display_history(Transaction transactions[], int num_transactions) {
    printf("\nTransaction History\n");
    printf("--------------------\n");

    for (int i = 0; i < num_transactions; i++) {
        printf("| %-45s | $%.2f | %s |\n", transactions[i].description, transactions[i].amount,
               transactions[i].type > 0 ? "Income" : "Expense");
    }
}