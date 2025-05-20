//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    char account_number[20];
    int balance;
} Account;

typedef struct {
    char description[100];
    Account from_account;
    Account to_account;
    float amount;
    char date[20];
} Transaction;

int main() {
    int num_accounts = 0, num_transactions = 0;
    Account accounts[MAX_ACCOUNTS];
    Transaction transactions[MAX_TRANSACTIONS];

    FILE *fptr = fopen("accounts.txt", "r");
    if (fptr == NULL) {
        printf("Error: accounts.txt not found!\n");
        return 1;
    }

    while (fscanf(fptr, "%s %s %d\n", accounts[num_accounts].name, accounts[num_accounts].account_number, &accounts[num_accounts].balance)!= EOF) {
        num_accounts++;
    }

    fclose(fptr);

    printf("Enter the number of transactions you want to add:\n");
    scanf("%d", &num_transactions);

    fptr = fopen("transactions.txt", "a");
    if (fptr == NULL) {
        printf("Error: transactions.txt not found!\n");
        return 1;
    }

    for (int i = 0; i < num_transactions; i++) {
        printf("Enter the details for transaction #%d:\n", i + 1);
        printf("From account name: ");
        scanf("%s", transactions[i].from_account.name);
        printf("From account number: ");
        scanf("%s", transactions[i].from_account.account_number);
        printf("To account name: ");
        scanf("%s", transactions[i].to_account.name);
        printf("To account number: ");
        scanf("%s", transactions[i].to_account.account_number);
        printf("Transaction description: ");
        scanf("%s", transactions[i].description);
        printf("Transaction amount: ");
        scanf("%f", &transactions[i].amount);
        printf("Transaction date (YYYY-MM-DD): ");
        scanf("%s", transactions[i].date);

        fprintf(fptr, "%s %s %s %s %.2f %s\n", transactions[i].from_account.name, transactions[i].from_account.account_number, transactions[i].to_account.name, transactions[i].to_account.account_number, transactions[i].amount, transactions[i].date);
    }

    fclose(fptr);

    return 0;
}