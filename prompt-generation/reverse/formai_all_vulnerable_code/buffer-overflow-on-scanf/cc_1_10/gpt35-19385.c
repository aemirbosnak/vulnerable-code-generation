//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    double balance;
    double income;
    double expenses;
} Account;

typedef struct {
    char date[MAX_NAME_LENGTH];
    char description[MAX_NAME_LENGTH];
    double amount;
} Transaction;

int main() {
    int num_accounts, num_transactions;
    printf("Enter the number of accounts: ");
    scanf("%d", &num_accounts);
    Account accounts[num_accounts];

    for (int i = 0; i < num_accounts; i++) {
        printf("\nEnter the name of account %d: ", i+1);
        scanf("%s", accounts[i].name);
        accounts[i].balance = accounts[i].income = accounts[i].expenses = 0;
    }

    printf("\nEnter the number of transactions: ");
    scanf("%d", &num_transactions);
    Transaction transactions[num_transactions];

    for (int i = 0; i < num_transactions; i++) {
        printf("\nEnter the date of transaction %d (mm/dd/yy format): ", i+1);
        scanf("%s", transactions[i].date);

        printf("Enter a description of the transaction: ");
        scanf("%s", transactions[i].description);

        printf("Enter the amount of the transaction: ");
        scanf("%lf", &transactions[i].amount);

        int account_index = -1;
        while (account_index == -1) {
            printf("Enter the name of the account this transaction applies to: ");
            char account_name[MAX_NAME_LENGTH];
            scanf("%s", account_name);

            for (int j = 0; j < num_accounts; j++) {
                if (strcmp(accounts[j].name, account_name) == 0) {
                    account_index = j;
                    break;
                }
            }

            if (account_index == -1) {
                printf("Account not found. Please try again.\n");
            }
        }

        if (transactions[i].amount > 0) {
            accounts[account_index].income += transactions[i].amount;
        } else {
            accounts[account_index].expenses -= transactions[i].amount;
        }

        accounts[account_index].balance += transactions[i].amount;
    }

    printf("\n\nAccount summaries:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("\nName: %s\n", accounts[i].name);
        printf("Balance: $%.2lf\n", accounts[i].balance);
        printf("Total income: $%.2lf\n", accounts[i].income);
        printf("Total expenses: $%.2lf\n", accounts[i].expenses);
    }

    return 0;
}