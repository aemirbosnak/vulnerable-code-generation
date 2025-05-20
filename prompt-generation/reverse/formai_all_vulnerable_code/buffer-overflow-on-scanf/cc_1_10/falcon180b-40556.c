//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000
#define MAX_ACCOUNT_NAME_LENGTH 50
#define MAX_ACCOUNT_NUMBER_LENGTH 20
#define MAX_TRANSACTION_DESCRIPTION_LENGTH 100
#define MAX_ACCOUNT_HOLDERS 10
#define MAX_ACCOUNT_HOLDER_NAME_LENGTH 50

#define NUM_ACCOUNTS 5
#define NUM_TRANSACTIONS 10

typedef struct {
    char name[MAX_ACCOUNT_NAME_LENGTH];
    char number[MAX_ACCOUNT_NUMBER_LENGTH];
    char currency[10];
    double balance;
    int num_holders;
    char holders[MAX_ACCOUNT_HOLDERS][MAX_ACCOUNT_HOLDER_NAME_LENGTH];
} Account;

typedef struct {
    char description[MAX_TRANSACTION_DESCRIPTION_LENGTH];
    double amount;
    int from_account;
    int to_account;
    char date[20];
} Transaction;

int main() {
    Account accounts[NUM_ACCOUNTS];
    Transaction transactions[NUM_TRANSACTIONS];

    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        printf("Enter account %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", accounts[i].name);
        printf("Number: ");
        scanf("%s", accounts[i].number);
        printf("Currency: ");
        scanf("%s", accounts[i].currency);
        printf("Balance: ");
        scanf("%lf", &accounts[i].balance);
        printf("Number of holders: ");
        scanf("%d", &accounts[i].num_holders);
        for (int j = 0; j < accounts[i].num_holders; j++) {
            printf("Holder %d name: ", j+1);
            scanf("%s", accounts[i].holders[j]);
        }
    }

    for (int i = 0; i < NUM_TRANSACTIONS; i++) {
        printf("Enter transaction %d details:\n", i+1);
        printf("Description: ");
        scanf("%s", transactions[i].description);
        printf("Amount: ");
        scanf("%lf", &transactions[i].amount);
        printf("From account: ");
        scanf("%d", &transactions[i].from_account);
        printf("To account: ");
        scanf("%d", &transactions[i].to_account);
        printf("Date: ");
        scanf("%s", transactions[i].date);
    }

    return 0;
}