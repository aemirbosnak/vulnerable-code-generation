//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define FILE_NAME "bank_records.txt"

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void saveAccountsToFile() {
    FILE *file = fopen(FILE_NAME, "w");
    for (int i = 0; i < accountCount; i++) {
        fprintf(file, "%d,%s,%.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
    fclose(file);
}

void loadAccountsFromFile() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) return;

    while (fscanf(file, "%d,%49[^,],%lf\n", &accounts[accountCount].accountNumber, accounts[accountCount].name, &accounts[accountCount].balance) != EOF) {
        accountCount++;
    }
    fclose(file);
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &accounts[accountCount].accountNumber);
    printf("Enter name: ");
    getchar(); // Clear buffer
    fgets(accounts[accountCount].name, NAME_LENGTH, stdin);
    accounts[accountCount].name[strcspn(accounts[accountCount].name, "\n")] = 0; // Remove newline
    accounts[accountCount].balance = 0.0;
    accountCount++;

    saveAccountsToFile();
    printf("Account created successfully!\n");
}

void deposit() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            saveAccountsToFile();
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
                return;
            }
            accounts[i].balance -= amount;
            saveAccountsToFile();
            printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void viewAccountDetails() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void printMenu() {
    printf("\n=== Bank Record System ===\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account Details\n");
    printf("5. Exit\n");
    printf("==========================\n");
}

int main() {
    loadAccountsFromFile();
    int choice;

    while (1) {
        printMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                viewAccountDetails();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}