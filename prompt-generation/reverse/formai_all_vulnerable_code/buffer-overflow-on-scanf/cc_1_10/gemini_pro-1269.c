//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
    int number;
    char *name;
    double balance;
} account;

account *accounts;
int num_accounts;

void create_account() {
    int number;
    char name[50];
    double balance;

    printf("Enter account number: ");
    scanf("%d", &number);

    printf("Enter account name: ");
    gets(name);

    printf("Enter account balance: ");
    scanf("%lf", &balance);

    account *new_account = (account *)malloc(sizeof(account));
    new_account->number = number;
    new_account->name = strdup(name);
    new_account->balance = balance;

    accounts = realloc(accounts, (num_accounts + 1) * sizeof(account));
    accounts[num_accounts] = *new_account;
    num_accounts++;
}

void deposit() {
    int number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &number);

    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].number == number) {
            accounts[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }

    printf("Account not found!\n");
}

void withdraw() {
    int number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &number);

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].number == number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful!\n");
                return;
            } else {
                printf("Insufficient funds!\n");
                return;
            }
        }
    }

    printf("Account not found!\n");
}

void display_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        printf("Account %d: %s, %lf\n", accounts[i].number, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Display accounts\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                display_accounts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}