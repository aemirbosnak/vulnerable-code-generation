//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    double balance;
} Account;

typedef struct {
    char description[100];
    double amount;
    int account_index;
} Transaction;

int main() {
    int num_accounts = 0, num_transactions = 0;
    Account accounts[MAX_ACCOUNTS];
    Transaction transactions[MAX_TRANSACTIONS];

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Create Account\n2. Deposit\n3. Withdraw\n4. View Transactions\n5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_accounts >= MAX_ACCOUNTS) {
                printf("Sorry, maximum number of accounts reached.\n");
            } else {
                printf("Enter account name: ");
                scanf("%s", accounts[num_accounts].name);
                accounts[num_accounts].balance = 0;
                num_accounts++;
            }
            break;

        case 2:
            printf("Enter account name: ");
            scanf("%s", accounts[0].name);
            printf("Enter deposit amount: ");
            scanf("%lf", &accounts[0].balance);
            break;

        case 3:
            printf("Enter account name: ");
            scanf("%s", accounts[0].name);
            printf("Enter withdrawal amount: ");
            scanf("%lf", &accounts[0].balance);
            break;

        case 4:
            printf("\nTransaction History:\n");
            for (int i = 0; i < num_transactions; i++) {
                printf("%s - $%.2f - %s\n", transactions[i].description, transactions[i].amount, accounts[transactions[i].account_index].name);
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}