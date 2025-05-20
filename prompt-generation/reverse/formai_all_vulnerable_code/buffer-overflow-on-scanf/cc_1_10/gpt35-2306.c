//FormAI DATASET v1.0 Category: Banking Record System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing bank account details
struct BankAccount {
    int accountNumber;
    char accountHolder[50];
    float balance;
};

// Function prototypes
void addAccount();
void displayAccountDetails();
void depositOrWithdrawMoney(int option);
void transferMoney();
void deleteAccount();

// Global variables
struct BankAccount accounts[100];
int numOfAccounts = 0;

int main() {
    int choice;
    do {
        printf("\n-----Banking Record System-----\n");
        printf("1. Add Account\n");
        printf("2. Display Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Transfer Money\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                displayAccountDetails();
                break;
            case 3:
                depositOrWithdrawMoney(1);
                break;
            case 4:
                depositOrWithdrawMoney(2);
                break;
            case 5:
                transferMoney();
                break;
            case 6:
                deleteAccount();
                break;
            case 7:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);
    return 0;
}

// Function to add a new bank account
void addAccount() {
    struct BankAccount newAccount;
    printf("\nEnter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolder);
    printf("Enter account balance: ");
    scanf("%f", &newAccount.balance);
    accounts[numOfAccounts] = newAccount;
    numOfAccounts++;
}

// Function to display all bank account details
void displayAccountDetails() {
    printf("\n-----Bank Account Details-----\n");
    for (int i=0; i<numOfAccounts; i++) {
        struct BankAccount account = accounts[i];
        printf("Account Number: %d\n", account.accountNumber);
        printf("Account Holder Name: %s\n", account.accountHolder);
        printf("Account Balance: %.2f\n", account.balance);
        printf("\n");
    }
}

// Function to deposit or withdraw money
void depositOrWithdrawMoney(int option) {
    int accountNum;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &accountNum);
    int found = 0;
    for (int i=0; i<numOfAccounts; i++) {
        struct BankAccount account = accounts[i];
        if (account.accountNumber == accountNum) {
            found = 1;
            printf("Enter amount to %s: ", option == 1 ? "deposit" : "withdraw");
            scanf("%f", &amount);
            if (option == 1) {
                accounts[i].balance += amount;
                printf("%.2f deposited successfully in account number %d\n", amount, accountNum);
            } else {
                if (amount > account.balance) {
                    printf("Insufficient balance. Withdrawal unsuccessful.");
                } else {
                    accounts[i].balance -= amount;
                    printf("%.2f withdrawn successfully from account number %d\n", amount, accountNum);
                }
            }
            break;
        }
    }
    if (!found) {
        printf("Account with account number %d not found.\n", accountNum);
    }
}

// Function to transfer money between accounts
void transferMoney() {
    int fromAccount, toAccount;
    float amount;
    printf("\nEnter account number to transfer from: ");
    scanf("%d", &fromAccount);
    printf("\nEnter account number to transfer to: ");
    scanf("%d", &toAccount);
    int fromAccountIndex = -1, toAccountIndex = -1;
    for (int i=0; i<numOfAccounts; i++) {
        struct BankAccount account = accounts[i];
        if (account.accountNumber == fromAccount) {
            fromAccountIndex = i;
        }
         if (account.accountNumber == toAccount) {
            toAccountIndex = i;
        }
    }
    if (fromAccountIndex == -1) {
        printf("Source account with account number %d not found.\n", fromAccount);
        return;
    }
    if (toAccountIndex == -1) {
        printf("Destination account with account number %d not found.\n", toAccount);
        return;
    }
    printf("Enter amount to transfer: ");
    scanf("%f", &amount);
    if (amount > accounts[fromAccountIndex].balance) {
        printf("Insufficient balance. Transfer unsuccessful.\n");
        return;
    }
    accounts[fromAccountIndex].balance -= amount;
    accounts[toAccountIndex].balance += amount;
    printf("%.2f transferred successfully from account %d to account %d\n", amount, fromAccount, toAccount);
}

// Function to delete a bank account
void deleteAccount() {
    int accountNum;
    printf("\nEnter account number to delete: ");
    scanf("%d", &accountNum);
    int found = 0;
    for (int i=0; i<numOfAccounts; i++) {
        struct BankAccount account = accounts[i];
        if (account.accountNumber == accountNum) {
            found = 1;
            for (int j=i; j<numOfAccounts-1; j++) {
                accounts[j] = accounts[j+1];
            }
            numOfAccounts--;
            printf("Account with account number %d deleted successfully.\n", accountNum);
            break;
        }
    }
    if (!found) {
        printf("Account with account number %d not found.\n", accountNum);
    }
}