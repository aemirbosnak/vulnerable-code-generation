//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int account_number;
    char name[100];
    int balance;
};

void print_account(struct account *account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: $%.2f\n", account->balance);
}

void deposit(struct account *account, double amount) {
    account->balance += amount;
    printf("Deposited $%.2f\n", amount);
}

void withdraw(struct account *account, double amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrew $%.2f\n", amount);
    } else {
        printf("Insufficient funds\n");
    }
}

void main() {
    struct account accounts[100];

    int choice, account_num;
    char name[100];
    double amount;

    printf("Welcome to the C Banking Record System!\n");
    printf("Enter 1 to create a new account\n");
    printf("Enter 2 to deposit money into an existing account\n");
    printf("Enter 3 to withdraw money from an existing account\n");
    printf("Enter 4 to print account information\n");
    printf("Enter 5 to exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (account_num >= 100 || account_num < 0) {
                    printf("Invalid account number\n");
                } else {
                    printf("Enter account holder's name: ");
                    fgets(name, sizeof(name), stdin);

                    accounts[account_num].account_number = account_num;
                    strncpy(accounts[account_num].name, name, sizeof(name));
                    accounts[account_num].balance = 0.00;

                    printf("Account created successfully!\n");
                }
                break;

            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (account_num >= 100 || account_num < 0) {
                    printf("Invalid account number\n");
                } else {
                    printf("Enter deposit amount: ");
                    scanf("%lf", &amount);

                    deposit(&accounts[account_num], amount);
                }
                break;

            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_num);

                if (account_num >= 100 || account_num < 0) {
                    printf("Invalid account number\n");
                } else {
                    printf("Enter withdrawal amount: ");
                    scanf("%lf", &amount);

                    withdraw(&accounts[account_num], amount);
                }
                break;

            case 4:
                printf("Account information:\n");
                for (int i = 0; i < 100; i++) {
                    print_account(&accounts[i]);
                }
                break;

            case 5:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
}