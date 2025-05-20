//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 5
#define NAME_LENGTH 30

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LENGTH];
    float balance;
} BankAccount;

void createAccount(BankAccount *accounts, int *count);
void depositMoney(BankAccount *accounts, int count);
void withdrawMoney(BankAccount *accounts, int count);
void checkBalance(BankAccount *accounts, int count);
void printMenu();

int main() {
    BankAccount accounts[MAX_ACCOUNTS];
    int count = 0;
    int choice;

    printf("Welcome to the Wacky World of Banking!\n");

    while (1) {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &count);
                break;
            case 2:
                depositMoney(accounts, count);
                break;
            case 3:
                withdrawMoney(accounts, count);
                break;
            case 4:
                checkBalance(accounts, count);
                break;
            case 5:
                printf("Have a nice day! Remember, money doesn't grow on trees unless you water them.\n");
                exit(0);
            default:
                printf("Oops! That's not on the menu. Try again without any wizardry!\n");
        }
    }
    return 0;
}

void printMenu() {
    printf("\n*** Wacky Banking Menu ***\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
}

void createAccount(BankAccount *accounts, int *count) {
    if (*count >= MAX_ACCOUNTS) {
        printf("We're full! Go open a bank in a parallel universe!\n");
        return;
    }
    printf("Enter account holder name (max %d characters): ", NAME_LENGTH - 1);
    scanf(" %[^\n]", accounts[*count].accountHolder);
    accounts[*count].accountNumber = *count + 1;
    accounts[*count].balance = 0.0;
    (*count)++;
    printf("Account created for %s with account number %d!\n", accounts[*count - 1].accountHolder, accounts[*count - 1].accountNumber);
}

void depositMoney(BankAccount *accounts, int count) {
    int accountNumber;
    float amount;

    if (count == 0) {
        printf("No accounts to deposit into! Go create one before we run out of giggles!\n");
        return;
    }

    printf("Enter account number to deposit into: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > count) {
        printf("Whoops! That account doesn't exist! Are you trying to pull a fast one?\n");
        return;
    }

    printf("How much would you like to deposit, oh generous one? ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("A deposit of $%f? Are you kidding? Go find some coins!\n", amount);
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Woohoo! You have deposited $%.2f into %s's account.\n", amount, accounts[accountNumber - 1].accountHolder);
}

void withdrawMoney(BankAccount *accounts, int count) {
    int accountNumber;
    float amount;

    if (count == 0) {
        printf("No accounts to withdraw from! Are we bankrupt yet?!\n");
        return;
    }

    printf("Enter account number to withdraw from: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > count) {
        printf("Hoo boy! That account number doesn't exist!\n");
        return;
    }

    printf("How much money would you like to take? ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Ha! Withdrawing negative money? You've cracked the code!\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Uh oh! You can't withdraw more than you have! This isn't a magic show.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("You've successfully withdrawn $%.2f from %s's account!\n", amount, accounts[accountNumber - 1].accountHolder);
}

void checkBalance(BankAccount *accounts, int count) {
    int accountNumber;

    if (count == 0) {
        printf("No accounts? No balance! Are you financially challenged?\n");
        return;
    }

    printf("Enter account number to check balance: ");
    scanf("%d", &accountNumber);
    if (accountNumber < 1 || accountNumber > count) {
        printf("This is like looking for a unicorn—there's no such account!\n");
        return;
    }

    printf("%s's current balance is: $%.2f (feel free to faint)\n", accounts[accountNumber - 1].accountHolder, accounts[accountNumber - 1].balance);
}