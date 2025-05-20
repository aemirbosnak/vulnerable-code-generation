//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int account_number;
    double balance;
} account;

account accounts[100];
int num_accounts = 0;

void create_account() {
    printf("Enter your name: ");
    scanf("%s", accounts[num_accounts].name);

    printf("Enter your account number: ");
    scanf("%d", &accounts[num_accounts].account_number);

    printf("Enter your initial deposit: ");
    scanf("%lf", &accounts[num_accounts].balance);

    num_accounts++;
}

void deposit() {
    int account_number;
    double amount;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter the amount you want to deposit: ");
            scanf("%lf", &amount);

            accounts[i].balance += amount;

            printf("Your new balance is €%.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account number not found!\n");
}

void withdraw() {
    int account_number;
    double amount;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter the amount you want to withdraw: ");
            scanf("%lf", &amount);

            if (amount > accounts[i].balance) {
                printf("You don't have enough money in your account!\n");
                return;
            }

            accounts[i].balance -= amount;

            printf("Your new balance is €%.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account number not found!\n");
}

void print_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        printf("Name: %s\n", accounts[i].name);
        printf("Account number: %d\n", accounts[i].account_number);
        printf("Balance: €%.2f\n\n", accounts[i].balance);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Print accounts\n");
        printf("5. Quit\n\n");

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
                print_accounts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}