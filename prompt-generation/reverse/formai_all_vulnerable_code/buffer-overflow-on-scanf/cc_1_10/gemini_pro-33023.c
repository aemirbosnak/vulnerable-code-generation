//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int account_number;
    char name[50];
    double balance;
} bank_account;

bank_account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void greeting() {
    printf("Welcome to our most esteemed banking institution!\n");
    printf("Where your money is safe, secure, and oh so very gratefully accepted.\n");
}

void create_account() {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Sorry, too many accounts. Please try again later.\n");
        return;
    }

    bank_account account;

    printf("Thank you for choosing our bank!\n");
    printf("Please provide your name: ");
    scanf(" %s", account.name);

    printf("And your initial deposit: ");
    scanf(" %lf", &account.balance);

    account.account_number = num_accounts + 1;
    accounts[num_accounts] = account;
    num_accounts++;

    printf("Your account has been created. Your account number is %d.\n", account.account_number);
}

void deposit() {
    int account_number;
    double amount;

    printf("Please enter your account number: ");
    scanf(" %d", &account_number);

    int account_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            account_index = i;
            break;
        }
    }

    if (account_index == -1) {
        printf("Invalid account number.\n");
        return;
    }

    printf("How much would you like to deposit: ");
    scanf(" %lf", &amount);

    accounts[account_index].balance += amount;

    printf("Your deposit has been processed. Your new balance is: %.2lf\n", accounts[account_index].balance);
}

void withdraw() {
    int account_number;
    double amount;

    printf("Please enter your account number: ");
    scanf(" %d", &account_number);

    int account_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            account_index = i;
            break;
        }
    }

    if (account_index == -1) {
        printf("Invalid account number.\n");
        return;
    }

    printf("How much would you like to withdraw: ");
    scanf(" %lf", &amount);

    if (amount > accounts[account_index].balance) {
        printf("Insufficient funds.\n");
        return;
    }

    accounts[account_index].balance -= amount;

    printf("Your withdrawal has been processed. Your new balance is: %.2lf\n", accounts[account_index].balance);
}

void check_balance() {
    int account_number;

    printf("Please enter your account number: ");
    scanf(" %d", &account_number);

    int account_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            account_index = i;
            break;
        }
    }

    if (account_index == -1) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Your account balance is: %.2lf\n", accounts[account_index].balance);
}

void print_all_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        printf("Account %d:\n", accounts[i].account_number);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2lf\n", accounts[i].balance);
        printf("\n");
    }
}

int main() {
    greeting();

    int choice;
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Print all accounts\n");
        printf("6. Exit\n");
        scanf(" %d", &choice);

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
                check_balance();
                break;
            case 5:
                print_all_accounts();
                break;
            case 6:
                printf("Thank you for your business. Have a grateful day!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}