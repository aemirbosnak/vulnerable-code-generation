//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50
#define FILE_NAME "bank_records.txt"

typedef struct {
    int accountNumber;
    char name[NAME_LEN];
    float balance;
} Account;

void createAccount(int accountNumber);
void viewAccount(int accountNumber);
void deposit(int accountNumber, float amount);
void withdraw(int accountNumber, float amount);
void listAccounts();
float getBalance(int accountNumber);
void saveAccount(Account acc);
Account loadAccount(int accountNumber);

int main() {
    int choice, accountNumber;
    char name[NAME_LEN];

    while (1) {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter Name: ");
                scanf("%s", name);
                createAccount(accountNumber);
                printf("Account Created Successfully!\n");
                break;
            case 2:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                viewAccount(accountNumber);
                break;
            case 3:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter Deposit Amount: ");
                float depositAmount;
                scanf("%f", &depositAmount);
                deposit(accountNumber, depositAmount);
                break;
            case 4:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter Withdrawal Amount: ");
                float withdrawAmount;
                scanf("%f", &withdrawAmount);
                withdraw(accountNumber, withdrawAmount);
                break;
            case 5:
                listAccounts();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void createAccount(int accountNumber) {
    Account newAccount;
    newAccount.accountNumber = accountNumber;
    strcpy(newAccount.name, "Unnamed");
    newAccount.balance = 0.0;
    saveAccount(newAccount);
}

void viewAccount(int accountNumber) {
    Account acc = loadAccount(accountNumber);
    if (acc.accountNumber != 0) {
        printf("Account Number: %d\n", acc.accountNumber);
        printf("Name: %s\n", acc.name);
        printf("Balance: %.2f\n", acc.balance);
    } else {
        printf("Account not found!\n");
    }
}

void deposit(int accountNumber, float amount) {
    Account acc = loadAccount(accountNumber);
    if (acc.accountNumber != 0) {
        acc.balance += amount;
        saveAccount(acc);
        printf("Deposited %.2f to Account Number: %d\n", amount, accountNumber);
    } else {
        printf("Account not found!\n");
    }
}

void withdraw(int accountNumber, float amount) {
    Account acc = loadAccount(accountNumber);
    if (acc.accountNumber != 0) {
        if (acc.balance >= amount) {
            acc.balance -= amount;
            saveAccount(acc);
            printf("Withdrew %.2f from Account Number: %d\n", amount, accountNumber);
        } else {
            printf("Insufficient funds!\n");
        }
    } else {
        printf("Account not found!\n");
    }
}

void listAccounts() {
    FILE *file = fopen(FILE_NAME, "r");
    Account acc;
    printf("\n--- List of Accounts ---\n");
    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.accountNumber != 0) {
            printf("Account Number: %d, Name: %s, Balance: %.2f\n",
                   acc.accountNumber, acc.name, acc.balance);
        }
    }
    fclose(file);
}

void saveAccount(Account acc) {
    FILE *file = fopen(FILE_NAME, "r+b");
    if (!file) {
        file = fopen(FILE_NAME, "wb");
    }
    fseek(file, (acc.accountNumber - 1) * sizeof(Account), SEEK_SET);
    fwrite(&acc, sizeof(Account), 1, file);
    fclose(file);
}

Account loadAccount(int accountNumber) {
    Account acc = {0};
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        return acc;
    }
    fseek(file, (accountNumber - 1) * sizeof(Account), SEEK_SET);
    fread(&acc, sizeof(Account), 1, file);
    fclose(file);
    return acc;
}