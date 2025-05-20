//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float balance;
} Account;

int main() {
    Account accounts[100];
    int num_accounts = 0;
    int num_transactions = 0;

    printf("Welcome to the Post-Apocalyptic Banking Record System!\n");
    printf("Please enter the number of accounts you would like to create:\n");
    int num_accounts_input = scanf("%d", &num_accounts);
    if (num_accounts_input!= 1) {
        printf("Invalid input. Exiting program.\n");
        return 1;
    }

    for (int i = 0; i < num_accounts; i++) {
        printf("Enter account holder name:\n");
        char name[50];
        scanf("%s", name);

        printf("Enter initial balance:\n");
        float balance_input = scanf("%f", &accounts[i].balance);
        if (balance_input!= 1) {
            printf("Invalid input. Exiting program.\n");
            return 1;
        }

        accounts[i].name[strlen(name)] = '\0';
    }

    printf("Accounts created successfully!\n");
    printf("Please enter the number of transactions you would like to record:\n");
    int num_transactions_input = scanf("%d", &num_transactions);
    if (num_transactions_input!= 1) {
        printf("Invalid input. Exiting program.\n");
        return 1;
    }

    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction details:\n");
        char details[100];
        scanf("%s", details);

        printf("Enter transaction amount:\n");
        float amount_input = scanf("%f", &accounts[i].balance);
        if (amount_input!= 1) {
            printf("Invalid input. Exiting program.\n");
            return 1;
        }

        accounts[i].balance -= amount_input;
    }

    printf("Transactions recorded successfully!\n");
    printf("Printing account details:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("Account Holder: %s\n", accounts[i].name);
        printf("Balance: $%.2f\n", accounts[i].balance);
    }

    printf("Thank you for using the Post-Apocalyptic Banking Record System!\n");
    return 0;
}