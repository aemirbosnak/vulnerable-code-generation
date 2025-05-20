//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char name[NAME_LENGTH];
    double balance;
    time_t creationDate;
} BankAccount;

void initializeAccounts(BankAccount accounts[], int *count) {
    *count = 0;
}

void createAccount(BankAccount accounts[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Bank account limit reached.\n");
        return;
    }
    BankAccount newAccount;
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    printf("Enter holder name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0.0;
    newAccount.creationDate = time(NULL);
    
    accounts[*count] = newAccount;
    (*count)++;

    printf("Account created successfully!\n");
}

void displayAccount(BankAccount account) {
    printf("Account Number: %s\n", account.accountNumber);
    printf("Account Holder: %s\n", account.name);
    printf("Balance: $%.2f\n", account.balance);
    printf("Creation Date: %s", ctime(&account.creationDate));
}

void viewAccounts(BankAccount accounts[], int count) {
    if (count == 0) {
        printf("No accounts available.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nAccount %d:\n", i + 1);
        displayAccount(accounts[i]);
    }
}

void deposit(BankAccount *account) {
    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }
    account->balance += amount;
    printf("Deposited $%.2f successfully.\n", amount);
}

void withdraw(BankAccount *account) {
    double amount;
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    
    if (amount <= 0 || amount > account->balance) {
        printf("Invalid amount or insufficient funds!\n");
        return;
    }
    account->balance -= amount;
    printf("Withdrew $%.2f successfully.\n", amount);
}

BankAccount* findAccount(BankAccount accounts[], int count, const char *accountNumber) {
    for (int i = 0; i < count; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            return &accounts[i];
        }
    }
    return NULL;
}

void performTransaction(BankAccount accounts[], int count) {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter account number for transaction: ");
    scanf("%s", accountNumber);
    
    BankAccount *account = findAccount(accounts, count, accountNumber);
    if (account == NULL) {
        printf("Account not found!\n");
        return;
    }
    
    int choice;
    printf("Select transaction type:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            deposit(account);
            break;
        case 2:
            withdraw(account);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    BankAccount accounts[MAX_RECORDS];
    int accountCount;
    
    initializeAccounts(accounts, &accountCount);
    
    int option;
    do {
        printf("\n--- Futuristic Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. View All Accounts\n");
        printf("3. Perform Transaction\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2:
                viewAccounts(accounts, accountCount);
                break;
            case 3:
                performTransaction(accounts, accountCount);
                break;
            case 4:
                printf("Thank you for using our futuristic banking system!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 4);
    
    return 0;
}