//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100

struct Transaction {
    char type;
    double amount;
};

int main() {
    struct Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions = 0;

    char choice;
    double balance = 0;

    printf("Welcome to Personal Finance Planner!\n");

    do {
        printf("\n[1] Add income\n");
        printf("[2] Add expense\n");
        printf("[3] View current balance\n");
        printf("[4] View transaction history\n");
        printf("[5] Exit\n");

        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                double amount;
                printf("\nEnter the income amount: ");
                scanf("%lf", &amount);

                transactions[numTransactions].type = '+';
                transactions[numTransactions].amount = amount;
                numTransactions++;

                balance += amount;

                printf("\nIncome added successfully!\n");

                break;
            }
            case '2': {
                double amount;
                printf("\nEnter the expense amount: ");
                scanf("%lf", &amount);

                transactions[numTransactions].type = '-';
                transactions[numTransactions].amount = amount;
                numTransactions++;

                balance -= amount;

                printf("\nExpense added successfully!\n");

                break;
            }
            case '3': {
                printf("\nCurrent balance: $%.2lf\n", balance);

                break;
            }
            case '4': {
                printf("\nTransaction history:\n");

                for (int i = 0; i < numTransactions; i++) {
                    if (transactions[i].type == '+') {
                        printf("Income: $%.2lf\n", transactions[i].amount);
                    } else if (transactions[i].type == '-') {
                        printf("Expense: $%.2lf\n", transactions[i].amount);
                    }
                }

                break;
            }
            case '5': {
                printf("\nThank you for using Personal Finance Planner!\n");

                break;
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");

                break;
            }
        }
    } while (choice != '5');

    return 0;
}