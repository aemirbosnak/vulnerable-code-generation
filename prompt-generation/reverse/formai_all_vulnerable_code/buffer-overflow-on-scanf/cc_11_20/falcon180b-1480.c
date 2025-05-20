//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUDGET_ITEMS 10
#define MAX_ACCOUNT_ITEMS 5
#define MAX_TRANSACTION_ITEMS 50

typedef struct {
    char name[50];
    float amount;
} BudgetItem;

typedef struct {
    char name[50];
    float balance;
} Account;

typedef struct {
    char description[100];
    float amount;
    int account_index;
} Transaction;

int main() {
    int choice;
    BudgetItem budget_items[MAX_BUDGET_ITEMS];
    Account accounts[MAX_ACCOUNT_ITEMS];
    Transaction transactions[MAX_TRANSACTION_ITEMS];

    int num_budget_items = 0, num_accounts = 0, num_transactions = 0;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add budget item\n");
        printf("2. Add account\n");
        printf("3. Add transaction\n");
        printf("4. View budget\n");
        printf("5. View account balances\n");
        printf("6. View transactions\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_budget_items >= MAX_BUDGET_ITEMS) {
                printf("Maximum number of budget items reached.\n");
            } else {
                printf("Enter budget item name: ");
                scanf("%s", budget_items[num_budget_items].name);
                printf("Enter budget item amount: ");
                scanf("%f", &budget_items[num_budget_items].amount);
                num_budget_items++;
            }
            break;

        case 2:
            if (num_accounts >= MAX_ACCOUNT_ITEMS) {
                printf("Maximum number of accounts reached.\n");
            } else {
                printf("Enter account name: ");
                scanf("%s", accounts[num_accounts].name);
                printf("Enter account balance: ");
                scanf("%f", &accounts[num_accounts].balance);
                num_accounts++;
            }
            break;

        case 3:
            if (num_transactions >= MAX_TRANSACTION_ITEMS) {
                printf("Maximum number of transactions reached.\n");
            } else {
                printf("Enter transaction description: ");
                scanf("%s", transactions[num_transactions].description);
                printf("Enter transaction amount: ");
                scanf("%f", &transactions[num_transactions].amount);
                printf("Enter account index: ");
                scanf("%d", &transactions[num_transactions].account_index);
                num_transactions++;
            }
            break;

        case 4:
            printf("Budget items:\n");
            for (int i = 0; i < num_budget_items; i++) {
                printf("%s: $%.2f\n", budget_items[i].name, budget_items[i].amount);
            }
            break;

        case 5:
            printf("Account balances:\n");
            for (int i = 0; i < num_accounts; i++) {
                printf("%s: $%.2f\n", accounts[i].name, accounts[i].balance);
            }
            break;

        case 6:
            printf("Transactions:\n");
            for (int i = 0; i < num_transactions; i++) {
                printf("%s: $%.2f (%s)\n", transactions[i].description, transactions[i].amount, accounts[transactions[i].account_index].name);
            }
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}