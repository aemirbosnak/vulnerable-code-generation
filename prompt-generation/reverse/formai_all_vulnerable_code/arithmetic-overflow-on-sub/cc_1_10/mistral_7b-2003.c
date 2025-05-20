//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 50

typedef struct {
    char description[50];
    float amount;
    int index;
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int num_transactions = 0;

void add_transaction(char* description, float amount) {
    if (num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Max number of transactions reached.\n");
        return;
    }

    strcpy(transactions[num_transactions].description, description);
    transactions[num_transactions].amount = amount;
    transactions[num_transactions].index = num_transactions;
    num_transactions++;
}

void delete_transaction(int index) {
    if (index < 0 || index >= num_transactions) {
        printf("Error: Invalid transaction index.\n");
        return;
    }

    for (int i = index; i < num_transactions - 1; i++) {
        transactions[i] = transactions[i + 1];
    }

    num_transactions--;
}

void view_transactions() {
    printf("\nCurrent Transactions:\n");
    printf("----------------------\n");

    for (int i = 0; i < num_transactions; i++) {
        printf("%d. %s: %.2f\n", i + 1, transactions[i].description, transactions[i].amount);
    }
}

void calculate_balance() {
    float total_income = 0;
    float total_expenses = 0;

    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].amount > 0) {
            total_income += transactions[i].amount;
        } else {
            total_expenses += transactions[i].amount;
        }
    }

    float balance = total_income - total_expenses;
    printf("\nCurrent Balance: %.2f", balance);
}

int main() {
    char command[10];
    int index;
    float amount;
    char description[50];

    while (1) {
        printf("\nPersonal Finance Planner\n"
               "------------------------\n"
               "1. Add Transaction\n"
               "2. Delete Transaction\n"
               "3. View Transactions\n"
               "4. Calculate Balance\n"
               "5. Exit\n"
               "\nEnter command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter transaction description: ");
                scanf("%s", description);
                printf("Enter transaction amount: ");
                scanf("%f", &amount);
                add_transaction(description, amount);
                break;
            case '2':
                printf("Enter transaction index to delete: ");
                scanf("%d", &index);
                delete_transaction(index - 1);
                break;
            case '3':
                view_transactions();
                break;
            case '4':
                calculate_balance();
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}