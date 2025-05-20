//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ACCOUNTS 10
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    double balance;
} Account;

typedef struct {
    char name[50];
    int id;
} Category;

typedef struct {
    char description[100];
    double amount;
    int categoryId;
} Transaction;

int main() {
    srand(time(NULL));

    Account accounts[MAX_ACCOUNTS];
    Category categories[MAX_CATEGORIES];
    Transaction transactions[MAX_TRANSACTIONS];

    int numAccounts = 0;
    int numCategories = 0;
    int numTransactions = 0;

    Account* defaultAccount = &accounts[0];
    defaultAccount->name[0] = '\0';
    defaultAccount->balance = 0.0;

    while (numAccounts < MAX_ACCOUNTS) {
        printf("Enter account name (or leave blank to finish): ");
        scanf("%s", defaultAccount->name);

        if (defaultAccount->name[0] == '\0') {
            break;
        }

        numAccounts++;
        defaultAccount++;
    }

    while (numCategories < MAX_CATEGORIES) {
        printf("Enter category name: ");
        scanf("%s", categories[numCategories].name);
        categories[numCategories].id = numCategories + 1;

        numCategories++;
    }

    while (numTransactions < MAX_TRANSACTIONS) {
        printf("Enter transaction description: ");
        scanf("%s", transactions[numTransactions].description);

        printf("Select account: ");
        for (int i = 0; i < numAccounts; i++) {
            printf("%d. %s\n", i + 1, accounts[i].name);
        }

        int accountId;
        scanf("%d", &accountId);

        transactions[numTransactions].amount = rand() % 1000;
        transactions[numTransactions].categoryId = rand() % numCategories + 1;

        numTransactions++;
    }

    return 0;
}