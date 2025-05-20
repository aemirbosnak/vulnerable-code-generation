//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 100
#define FILE_NAME "bank_records.txt"

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void initializeAccounts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        while (fscanf(file, "%d %s %f", &accounts[accountCount].accountNumber, accounts[accountCount].name, &accounts[accountCount].balance) != EOF) {
            accountCount++;
        }
        fclose(file);
    }
}

void saveAccounts() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file) {
        for (int i = 0; i < accountCount; i++) {
            fprintf(file, "%d %s %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
        }
        fclose(file);
    } else {
        printf("Error saving accounts to file.\n");
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    printf("Enter your name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully. Account Number: %d\n", newAccount.accountNumber);
    saveAccounts();
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Deposit amount must be positive.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Deposited %.2f to account number %d. New balance: %.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
    saveAccounts();
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Withdrawal amount must be positive.\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient funds for withdrawal.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrew %.2f from account number %d. New balance: %.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
    saveAccounts();
}

void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Account Number: %d\nName: %s\nBalance: %.2f\n", 
           accountNumber, 
           accounts[accountNumber - 1].name, 
           accounts[accountNumber - 1].balance);
}

void displayMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("-----------------------------\n");
    printf("Select an option: ");
}

int main() {
    initializeAccounts();

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}