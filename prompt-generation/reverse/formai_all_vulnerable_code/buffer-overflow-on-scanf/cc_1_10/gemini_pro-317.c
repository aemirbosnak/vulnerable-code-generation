//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct account {
    int accountNumber;
    char accountHolderName[50];
    double balance;
} account;

void createAccount(account *accounts, int *numAccounts) {
    printf("Enter account number: ");
    scanf("%d", &accounts[*numAccounts].accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", accounts[*numAccounts].accountHolderName);
    printf("Enter initial balance: ");
    scanf("%lf", &accounts[*numAccounts].balance);
    (*numAccounts)++;
}

void deposit(account *accounts, int numAccounts) {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    int index = findAccountIndex(accounts, numAccounts, accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
    } else {
        printf("Enter amount to deposit: ");
        scanf("%lf", &amount);
        accounts[index].balance += amount;
        printf("New balance: %lf\n", accounts[index].balance);
    }
}

void withdraw(account *accounts, int numAccounts) {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    int index = findAccountIndex(accounts, numAccounts, accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
    } else {
        printf("Enter amount to withdraw: ");
        scanf("%lf", &amount);
        if (amount > accounts[index].balance) {
            printf("Insufficient funds.\n");
        } else {
            accounts[index].balance -= amount;
            printf("New balance: %lf\n", accounts[index].balance);
        }
    }
}

void transfer(account *accounts, int numAccounts) {
    int fromAccountNumber, toAccountNumber;
    double amount;
    printf("Enter from account number: ");
    scanf("%d", &fromAccountNumber);
    int fromIndex = findAccountIndex(accounts, numAccounts, fromAccountNumber);
    if (fromIndex == -1) {
        printf("From account not found.\n");
        return;
    }
    printf("Enter to account number: ");
    scanf("%d", &toAccountNumber);
    int toIndex = findAccountIndex(accounts, numAccounts, toAccountNumber);
    if (toIndex == -1) {
        printf("To account not found.\n");
        return;
    }
    printf("Enter amount to transfer: ");
    scanf("%lf", &amount);
    if (amount > accounts[fromIndex].balance) {
        printf("Insufficient funds.\n");
        return;
    }
    accounts[fromIndex].balance -= amount;
    accounts[toIndex].balance += amount;
    printf("Transfer successful.\n");
}

void printAccounts(account *accounts, int numAccounts) {
    for (int i = 0; i < numAccounts; i++) {
        printf("Account number: %d\n", accounts[i].accountNumber);
        printf("Account holder name: %s\n", accounts[i].accountHolderName);
        printf("Balance: %lf\n\n", accounts[i].balance);
    }
}

int findAccountIndex(account *accounts, int numAccounts, int accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

int main() {
    account accounts[100];
    int numAccounts = 0;
    int choice;

    while (1) {
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Print accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                withdraw(accounts, numAccounts);
                break;
            case 4:
                transfer(accounts, numAccounts);
                break;
            case 5:
                printAccounts(accounts, numAccounts);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}