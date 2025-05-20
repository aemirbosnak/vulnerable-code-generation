//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNTS 100
#define NAME_SIZE 50
#define INITIAL_BALANCE 1000.0

typedef struct {
    char name[NAME_SIZE];
    int accountNumber;
    float balance;
    time_t creationTime;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void dreamOfNewAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("The bank of dreams is too full, no more accounts can be created!\n");
        return;
    }
    
    Account newAccount;
    printf("Enter your name, ethereal wanderer: ");
    scanf("%s", newAccount.name);
    newAccount.accountNumber = accountCount + 1;
    newAccount.balance = INITIAL_BALANCE;
    newAccount.creationTime = time(NULL);
    
    accounts[accountCount] = newAccount;
    accountCount++;
    
    printf("Congratulations! An account named '%s' has emerged into existence with number %d, balance %.2f!\n",
           newAccount.name, newAccount.accountNumber, newAccount.balance);
}

void danceOfBalanceCheck() {
    int accountNumber;
    printf("Enter your account number to check the balance, brave voyager: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Alas! The number you seek is lost in translation.\n");
        return;
    }
    
    Account acc = accounts[accountNumber - 1];
    printf("Account name: %s\nAccount number: %d\nBalance: %.2f\n",
           acc.name, acc.accountNumber, acc.balance);
}

void whisperOfDeposit() {
    int accountNumber;
    float amount;
    printf("Enter your account number to deposit into, enlightened spirit: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("In this foggy realm, your account number dissolves.\n");
        return;
    }
    
    printf("How much do you wish to deposit into the cosmic account? ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("An offering of zero or less? Reality itself shudders!\n");
        return;
    }
    
    accounts[accountNumber - 1].balance += amount;
    printf("A deposit of %.2f has fluttered into your balance. New balance: %.2f\n",
           amount, accounts[accountNumber - 1].balance);
}

void echoTheMenu() {
    printf("Welcome to the surreal banking system.\n");
    printf("1. Create a New Account\n");
    printf("2. Check Balance\n");
    printf("3. Deposit Money\n");
    printf("4. Exit\n");
}

void surrealBankingExperience() {
    int choice;
    while (1) {
        echoTheMenu();
        printf("What do you desire, lost traveler? ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                dreamOfNewAccount();
                break;
            case 2:
                danceOfBalanceCheck();
                break;
            case 3:
                whisperOfDeposit();
                break;
            case 4:
                printf("Thank you for floating through our surreal banking realm. Until we meet again!\n");
                exit(0);
            default:
                printf("The choice you made is a riddle wrapped in an enigma.\n");
                break;
        }
    }
}

int main() {
    surrealBankingExperience();
    return 0;
}