//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ACCOUNTS 10
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    double balance;
    int account_type; // 1 for checking, 2 for savings
} Account;

typedef struct {
    char name[50];
    double budget;
} Category;

int main() {
    int num_accounts, num_categories;
    Account accounts[MAX_ACCOUNTS];
    Category categories[MAX_CATEGORIES];

    printf("Enter the number of accounts: ");
    scanf("%d", &num_accounts);

    for (int i = 0; i < num_accounts; i++) {
        printf("Enter account %d name: ", i + 1);
        scanf("%s", accounts[i].name);
        printf("Enter account %d balance: ", i + 1);
        scanf("%lf", &accounts[i].balance);
        printf("Enter account %d type (1 for checking, 2 for savings): ", i + 1);
        scanf("%d", &accounts[i].account_type);
    }

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter category %d name: ", i + 1);
        scanf("%s", categories[i].name);
        printf("Enter category %d budget: ", i + 1);
        scanf("%lf", &categories[i].budget);
    }

    // Example transactions
    double transaction_amounts[10] = {100.0, 50.0, 25.0, 200.0, 75.0, 150.0, 300.0, 125.0, 175.0, 400.0};
    char transaction_accounts[10][50];
    char transaction_categories[10][50];

    for (int i = 0; i < 10; i++) {
        printf("Enter transaction %d account name: ", i + 1);
        scanf("%s", transaction_accounts[i]);
        printf("Enter transaction %d category name: ", i + 1);
        scanf("%s", transaction_categories[i]);
    }

    // Example budget calculations
    int budget_met_count = 0;
    for (int i = 0; i < num_categories; i++) {
        double total_spent = 0.0;
        for (int j = 0; j < 10; j++) {
            if (strcmp(transaction_categories[j], categories[i].name) == 0) {
                total_spent += transaction_amounts[j];
            }
        }
        if (total_spent <= categories[i].budget) {
            budget_met_count++;
        }
    }

    printf("Budget met for %d out of %d categories.\n", budget_met_count, num_categories);

    return 0;
}