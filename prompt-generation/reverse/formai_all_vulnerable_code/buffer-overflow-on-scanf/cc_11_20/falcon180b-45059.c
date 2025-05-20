//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 5
#define MAX_TRANSACTIONS 10
#define MAX_CATEGORIES 5
#define MAX_CATEGORY_NAME_LENGTH 20
#define MAX_ACCOUNT_NAME_LENGTH 20
#define MAX_TRANSACTION_NAME_LENGTH 40
#define MAX_TRANSACTION_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_ACCOUNT_NAME_LENGTH];
    double balance;
} Account;

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int accountIndex;
} Category;

typedef struct {
    char name[MAX_TRANSACTION_NAME_LENGTH];
    double amount;
    int accountIndex;
    int categoryIndex;
} Transaction;

int main() {
    int numAccounts = 0, numTransactions = 0, numCategories = 0;
    Account accounts[MAX_ACCOUNTS];
    Category categories[MAX_CATEGORIES];
    Transaction transactions[MAX_TRANSACTIONS];

    char input[MAX_ACCOUNT_NAME_LENGTH];
    while (numAccounts < MAX_ACCOUNTS) {
        printf("Enter account name (or enter 'done' to finish): ");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        strcpy(accounts[numAccounts].name, input);
        accounts[numAccounts].balance = 0.0;
        numAccounts++;
    }

    char categoryInput[MAX_CATEGORY_NAME_LENGTH];
    while (numCategories < MAX_CATEGORIES) {
        printf("Enter category name (or enter 'done' to finish): ");
        scanf("%s", categoryInput);
        if (strcmp(categoryInput, "done") == 0) {
            break;
        }
        strcpy(categories[numCategories].name, categoryInput);
        numCategories++;
    }

    while (numTransactions < MAX_TRANSACTIONS) {
        printf("Enter transaction name: ");
        scanf("%s", input);

        int accountFound = 0;
        int categoryFound = 0;

        for (int i = 0; i < numAccounts; i++) {
            if (strcmp(accounts[i].name, input) == 0) {
                strcpy(transactions[numTransactions].name, input);
                transactions[numTransactions].accountIndex = i;
                accountFound = 1;
                break;
            }
        }

        if (!accountFound) {
            printf("Invalid account name\n");
            continue;
        }

        for (int i = 0; i < numCategories; i++) {
            if (strcmp(categories[i].name, input) == 0) {
                strcpy(transactions[numTransactions].name, input);
                transactions[numTransactions].categoryIndex = i;
                categoryFound = 1;
                break;
            }
        }

        if (!categoryFound) {
            printf("Invalid category name\n");
            continue;
        }

        printf("Enter transaction amount: ");
        scanf("%s", input);
        transactions[numTransactions].amount = atof(input);

        numTransactions++;
    }

    return 0;
}