//FormAI DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100

struct Transaction {
    char type[10];
    float amount;
};

int main() {
    struct Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;
    float balance = 0;

    // Display welcome message and available commands
    printf("********** Expense Tracker **********\n");
    printf("Commands:\n");
    printf("  add <type> <amount>\n");
    printf("  list\n");
    printf("  balance\n");
    printf("  exit\n");

    while (1) {
        char command[20];
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char type[10];
            float amount;
            scanf("%s %f", type, &amount);

            // Check if there is enough space for a new transaction
            if (num_transactions >= MAX_TRANSACTIONS) {
                printf("Maximum number of transactions reached\n");
                continue;
            }

            // Create a new transaction
            struct Transaction new_transaction;
            strcpy(new_transaction.type, type);
            new_transaction.amount = amount;

            transactions[num_transactions++] = new_transaction;
            balance += amount;
            printf("Transaction added successfully\n");
        } else if (strcmp(command, "list") == 0) {
            printf("Transactions:\n");
            printf("%-10s %-10s\n", "TYPE", "AMOUNT");
            for (int i = 0; i < num_transactions; i++) {
                printf("%-10s %-10.2f\n", transactions[i].type, transactions[i].amount);
            }
        } else if (strcmp(command, "balance") == 0) {
            printf("Balance: %.2f\n", balance);
        } else if (strcmp(command, "exit") == 0) {
            printf("Thank you for using Expense Tracker\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}