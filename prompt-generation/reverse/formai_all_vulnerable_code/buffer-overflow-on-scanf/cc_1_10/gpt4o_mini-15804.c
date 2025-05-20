//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_NUMBER_LENGTH 15
#define NAME_LENGTH 50
#define TRANSACTION_HISTORY_LENGTH 100

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char accountHolderName[NAME_LENGTH];
    double balance;
    char transactionHistory[TRANSACTION_HISTORY_LENGTH][100];
    int transactionCount;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayMenu();
void createAccount();
void deposit();
void withdraw();
void displayAccountDetails();
void listAccounts();
void saveAccounts();
void loadAccounts();

int main() {
    loadAccounts();

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: displayAccountDetails(); break;
            case 5: listAccounts(); break;
            case 6: saveAccounts(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid option! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Display Account Details\n");
    printf("5. List All Accounts\n");
    printf("6. Save Accounts\n");
    printf("0. Exit\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }

    BankAccount account;
    printf("Enter Account Number: ");
    scanf("%s", account.accountNumber);
    
    printf("Enter Account Holder Name: ");
    getchar(); // to consume newline left by scanf
    fgets(account.accountHolderName, NAME_LENGTH, stdin);
    account.accountHolderName[strcspn(account.accountHolderName, "\n")] = 0; // remove newline

    account.balance = 0.0;
    account.transactionCount = 0;
    accounts[accountCount++] = account;

    printf("Account created successfully!\n");
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    double amount;

    printf("Enter Account Number: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            sprintf(accounts[i].transactionHistory[accounts[i].transactionCount++], 
                    "Deposited: %.2f", amount);
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found!\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    double amount;

    printf("Enter Account Number: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient funds!\n");
            } else {
                accounts[i].balance -= amount;
                sprintf(accounts[i].transactionHistory[accounts[i].transactionCount++], 
                        "Withdrew: %.2f", amount);
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }

    printf("Account not found!\n");
}

void displayAccountDetails() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter Account Number: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Account Holder: %s\n", accounts[i].accountHolderName);
            printf("Balance: %.2f\n", accounts[i].balance);
            printf("Transaction History:\n");
            for (int j = 0; j < accounts[i].transactionCount; j++) {
                printf("  %s\n", accounts[i].transactionHistory[j]);
            }
            return;
        }
    }

    printf("Account not found!\n");
}

void listAccounts() {
    printf("\n--- List of Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %s, Account Holder: %s, Balance: %.2f\n",
               accounts[i].accountNumber, accounts[i].accountHolderName, accounts[i].balance);
    }
}

void saveAccounts() {
    FILE *file = fopen("accounts.dat", "wb");
    if (file == NULL) {
        printf("Unable to save accounts!\n");
        return;
    }
    
    fwrite(accounts, sizeof(BankAccount), accountCount, file);
    fclose(file);
    printf("Accounts saved successfully!\n");
}

void loadAccounts() {
    FILE *file = fopen("accounts.dat", "rb");
    if (file == NULL) {
        printf("No existing accounts to load.\n");
        return;
    }
    
    accountCount = fread(accounts, sizeof(BankAccount), MAX_ACCOUNTS, file);
    fclose(file);
    printf("Accounts loaded successfully!\n");
}