//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 50

typedef struct {
    char description[50];
    float amount;
    int type; // 1 for income, -1 for expense
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int num_transactions = 0;

void display_menu() {
    printf("1. Add transaction\n");
    printf("2. Delete transaction\n");
    printf("3. Display transactions\n");
    printf("4. Quit\n");
}

void add_transaction() {
    if (num_transactions >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached.\n");
        return;
    }

    printf("Enter transaction description: ");
    scanf("%s", transactions[num_transactions].description);
    printf("Enter transaction amount: ");
    scanf("%f", &transactions[num_transactions].amount);
    printf("Enter transaction type (1 for income, -1 for expense): ");
    scanf("%d", &transactions[num_transactions].type);

    num_transactions++;
}

void delete_transaction() {
    int index;
    printf("Enter index of transaction to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_transactions) {
        printf("Invalid transaction index.\n");
        return;
    }

    memmove(&transactions[index], &transactions[index + 1],
            (num_transactions - index - 1) * sizeof(Transaction));

    num_transactions--;
}

void display_transactions() {
    float total_income = 0, total_expense = 0;

    printf("\n---------- Transactions ----------\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%d. %s %s\n", i + 1, transactions[i].type > 0 ? "Income" : "Expense",
               transactions[i].description);
        printf("    Amount: %.2f\n", transactions[i].amount);

        if (transactions[i].type > 0)
            total_income += transactions[i].amount;
        else
            total_expense += transactions[i].amount;
    }
    printf("\n---------- Total ----------\n");
    printf("Income: %.2f\n", total_income);
    printf("Expense: %.2f\n", total_expense);
    printf("Balance: %.2f\n", total_income - total_expense);
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction();
                break;
            case 2:
                delete_transaction();
                break;
            case 3:
                display_transactions();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}