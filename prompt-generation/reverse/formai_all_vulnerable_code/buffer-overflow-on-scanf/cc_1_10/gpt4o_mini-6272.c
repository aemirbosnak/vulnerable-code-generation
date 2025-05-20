//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Oops! We can't create any more accounts right now. Try again later!\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = numAccounts + 1; 

    printf("Enter the name for the new account: ");
    scanf("%s", newAccount.name);

    newAccount.balance = 0; // Initial balance
    accounts[numAccounts] = newAccount;
    numAccounts++;

    printf("Surprise! Account created successfully!\n");
    printf("Account Number: %d, Account Holder: %s\n", newAccount.accountNumber, newAccount.name);
}

void displayBalance(int accountNumber) {
    if (accountNumber < 1 || accountNumber > numAccounts) {
        printf("Hmm... Account not found. Please check the account number!\n");
        return;
    }
    
    printf("Balance inquiry! The balance for account number %d is: $%.2f\n", 
           accounts[accountNumber - 1].accountNumber, accounts[accountNumber - 1].balance);
}

void depositMoney(int accountNumber, double amount) {
    if (accountNumber < 1 || accountNumber > numAccounts) {
        printf("Surprise! Account not found. Please check again...\n");
        return;
    }

    if (amount <= 0) {
        printf("Oh dear! The deposit amount must be positive!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Hooray! You have deposited $%.2f into account number %d.\n", 
           amount, accounts[accountNumber - 1].accountNumber);
}

void withdrawMoney(int accountNumber, double amount) {
    if (accountNumber < 1 || accountNumber > numAccounts) {
        printf("Uh-oh! Account not found. Please check your details!\n");
        return;
    }

    if (amount <= 0) {
        printf("Oops! Withdrawal amount must be positive!\n");
        return;
    }

    if (amount > accounts[accountNumber - 1].balance) {
        printf("Oops! Insufficient funds! You cannot withdraw this amount...\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Success! You have withdrawn $%.2f from account number %d.\n", 
           amount, accounts[accountNumber - 1].accountNumber);
}

void listAccounts() {
    printf("Let's take a look at all the accounts we have:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("Account Number: %d, Account Holder: %s, Balance: $%.2f\n", 
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice, accountNumber;
    double amount;

    while (1) {
        printf("\n*** Welcome to the Super Surprise Banking System! ***\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. List Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                depositMoney(accountNumber, amount);
                break;
            case 3:
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdrawMoney(accountNumber, amount);
                break;
            case 4:
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                displayBalance(accountNumber);
                break;
            case 5:
                listAccounts();
                break;
            case 6:
                printf("Thank you for using our Super Surprise Banking System! Goodbye!\n");
                exit(0);
            default:
                printf("Uh-oh! Invalid choice, please choose again!\n");
        }
    }
    return 0;
}