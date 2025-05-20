//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    double balance;
} BankAccount;

int main() {
    srand(time(0));

    BankAccount accounts[100];
    int account_count = 0;

    printf("Welcome to the Banking Record System!\n");
    printf("Please enter the number of accounts you would like to create:\n");
    int num_accounts;
    scanf("%d", &num_accounts);

    while (account_count < num_accounts) {
        printf("Enter the name of the account holder:\n");
        scanf("%s", accounts[account_count].name);

        accounts[account_count].balance = rand() % 1000 + 1;

        printf("Account created with balance of %f\n", accounts[account_count].balance);
        account_count++;
    }

    printf("Accounts created successfully!\n");
    printf("Enter 1 to create a new account\n");
    printf("Enter 2 to display account details\n");
    printf("Enter 3 to deposit money\n");
    printf("Enter 4 to withdraw money\n");
    printf("Enter 5 to exit\n");

    int choice;
    scanf("%d", &choice);

    while (choice!= 5) {
        switch (choice) {
            case 1:
                printf("Enter the name of the account holder:\n");
                scanf("%s", accounts[account_count].name);

                accounts[account_count].balance = rand() % 1000 + 1;

                printf("Account created with balance of %f\n", accounts[account_count].balance);
                account_count++;
                break;

            case 2:
                for (int i = 0; i < account_count; i++) {
                    printf("Account Name: %s\n", accounts[i].name);
                    printf("Balance: %f\n", accounts[i].balance);
                }
                break;

            case 3:
                printf("Enter the account name:\n");
                scanf("%s", accounts[account_count].name);

                printf("Enter the amount to deposit:\n");
                double deposit_amount;
                scanf("%lf", &deposit_amount);

                accounts[account_count].balance += deposit_amount;
                printf("Deposit successful! New balance is %f\n", accounts[account_count].balance);
                account_count++;
                break;

            case 4:
                printf("Enter the account name:\n");
                scanf("%s", accounts[account_count].name);

                printf("Enter the amount to withdraw:\n");
                double withdrawal_amount;
                scanf("%lf", &withdrawal_amount);

                if (withdrawal_amount <= accounts[account_count].balance) {
                    accounts[account_count].balance -= withdrawal_amount;
                    printf("Withdrawal successful! New balance is %f\n", accounts[account_count].balance);
                } else {
                    printf("Insufficient funds! New balance is %f\n", accounts[account_count].balance);
                }
                account_count++;
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

        printf("Enter 1 to create a new account\n");
        printf("Enter 2 to display account details\n");
        printf("Enter 3 to deposit money\n");
        printf("Enter 4 to withdraw money\n");
        printf("Enter 5 to exit\n");

        scanf("%d", &choice);
    }

    printf("Bye!\n");

    return 0;
}