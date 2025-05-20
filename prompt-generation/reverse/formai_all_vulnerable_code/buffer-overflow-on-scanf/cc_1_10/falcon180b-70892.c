//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    float balance;
} Account;

typedef struct {
    char name[50];
    int category;
    float amount;
} Transaction;

int main() {
    Account account;
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;
    int i, j;

    printf("Welcome to the Personal Finance Planner!\n");

    printf("Enter your account name: ");
    scanf("%s", account.name);

    printf("Enter your account balance: $");
    scanf("%f", &account.balance);

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a transaction\n");
        printf("2. View transactions\n");
        printf("3. Change account balance\n");
        printf("4. Quit\n");

        scanf("%d", &i);

        switch (i) {
        case 1:
            if (num_transactions == MAX_TRANSACTIONS) {
                printf("Maximum number of transactions reached.\n");
            } else {
                printf("Enter transaction name: ");
                scanf("%s", transactions[num_transactions].name);

                printf("Enter transaction amount: $");
                scanf("%f", &transactions[num_transactions].amount);

                printf("Enter transaction category (1-10): ");
                scanf("%d", &transactions[num_transactions].category);

                num_transactions++;
            }
            break;

        case 2:
            printf("\nTransactions:\n");
            for (j = 0; j < num_transactions; j++) {
                printf("%s - $%.2f - %d\n", transactions[j].name, transactions[j].amount, transactions[j].category);
            }
            break;

        case 3:
            printf("\nEnter new account balance: $");
            scanf("%f", &account.balance);
            break;

        case 4:
            printf("Thank you for using the Personal Finance Planner!\n");
            return 0;

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}