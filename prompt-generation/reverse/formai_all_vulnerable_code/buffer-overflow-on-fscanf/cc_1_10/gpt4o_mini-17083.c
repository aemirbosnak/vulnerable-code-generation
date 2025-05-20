//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50
#define FILENAME "accounts.txt"

typedef struct {
    int accountNumber;
    char name[NAME_LEN];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function prototypes
void loadAccounts();
void saveAccounts();
void createAccount();
void deposit(int accountNumber);
void withdraw(int accountNumber);
void checkBalance(int accountNumber);
void listAccounts();
int findAccount(int accountNumber);

int main() {
    int choice, accountNumber;

    loadAccounts();

    do {
        printf("\n--- Banking System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. List Accounts\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter account number to deposit into: ");
                scanf("%d", &accountNumber);
                deposit(accountNumber);
                break;
            case 3:
                printf("Enter account number to withdraw from: ");
                scanf("%d", &accountNumber);
                withdraw(accountNumber);
                break;
            case 4:
                printf("Enter account number to check balance: ");
                scanf("%d", &accountNumber);
                checkBalance(accountNumber);
                break;
            case 5:
                listAccounts();
                break;
            case 6:
                saveAccounts();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void loadAccounts() {
    FILE *file = fopen(FILENAME, "r");
    if (file) {
        while (fscanf(file, "%d %s %f", &accounts[accountCount].accountNumber, accounts[accountCount].name, &accounts[accountCount].balance) == 3) {
            accountCount++;
        }
        fclose(file);
    }
}

void saveAccounts() {
    FILE *file = fopen(FILENAME, "w");
    if (file) {
        for (int i = 0; i < accountCount; i++) {
            fprintf(file, "%d %s %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
        }
        fclose(file);
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create more accounts.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number assignment
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully! Your account number is %d.\n", newAccount.accountNumber);
}

void deposit(int accountNumber) {
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        accounts[index].balance += amount;
        printf("Successfully deposited %.2f. New balance is %.2f.\n", amount, accounts[index].balance);
    } else {
        printf("Invalid amount. Deposit failed.\n");
    }
}

void withdraw(int accountNumber) {
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= accounts[index].balance) {
        accounts[index].balance -= amount;
        printf("Successfully withdrew %.2f. New balance is %.2f.\n", amount, accounts[index].balance);
    } else {
        printf("Invalid amount or insufficient balance. Withdrawal failed.\n");
    }
}

void checkBalance(int accountNumber) {
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }
    printf("Current balance for account %d is %.2f.\n", accountNumber, accounts[index].balance);
}

void listAccounts() {
    printf("\n--- List of Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int findAccount(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1; // Account not found
}