//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[50];
    int account_number;
    double balance;
};

struct transaction {
    int account_number;
    char type[20];
    double amount;
};

void create_account(struct account *accounts, int *num_accounts) {
    char name[50];
    int account_number;
    double balance;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    printf("Enter your balance: ");
    scanf("%lf", &balance);

    accounts[*num_accounts].account_number = account_number;
    strcpy(accounts[*num_accounts].name, name);
    accounts[*num_accounts].balance = balance;

    (*num_accounts)++;
}

void deposit(struct account *accounts, int num_accounts) {
    int account_number;
    double amount;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    printf("Enter the amount you want to deposit: ");
    scanf("%lf", &amount);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            break;
        }
    }
}

void withdraw(struct account *accounts, int num_accounts) {
    int account_number;
    double amount;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    printf("Enter the amount you want to withdraw: ");
    scanf("%lf", &amount);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
            } else {
                printf("Insufficient funds\n");
            }
            break;
        }
    }
}

void transfer(struct account *accounts, int num_accounts) {
    int from_account_number;
    int to_account_number;
    double amount;

    printf("Enter the account number you want to transfer from: ");
    scanf("%d", &from_account_number);

    printf("Enter the account number you want to transfer to: ");
    scanf("%d", &to_account_number);

    printf("Enter the amount you want to transfer: ");
    scanf("%lf", &amount);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == from_account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                for (int j = 0; j < num_accounts; j++) {
                    if (accounts[j].account_number == to_account_number) {
                        accounts[j].balance += amount;
                        break;
                    }
                }
            } else {
                printf("Insufficient funds\n");
            }
            break;
        }
    }
}

void print_accounts(struct account *accounts, int num_accounts) {
    for (int i = 0; i < num_accounts; i++) {
        printf("Account Number: %d\n", accounts[i].account_number);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2lf\n\n", accounts[i].balance);
    }
}

int main() {
    struct account accounts[100];
    int num_accounts = 0;
    int choice;

    while (1) {
        printf("1. Create an account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Transfer money\n");
        printf("5. Print accounts\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(accounts, &num_accounts);
                break;
            case 2:
                deposit(accounts, num_accounts);
                break;
            case 3:
                withdraw(accounts, num_accounts);
                break;
            case 4:
                transfer(accounts, num_accounts);
                break;
            case 5:
                print_accounts(accounts, num_accounts);
                break;
            case 6:
                exit(0);
        }
    }

    return 0;
}