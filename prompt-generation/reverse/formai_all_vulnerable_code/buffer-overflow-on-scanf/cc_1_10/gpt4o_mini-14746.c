//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void displayAccounts();
void depositMoney();
void withdrawMoney();
void displayMenu();
int findAccountIndex(const char *accountNumber);
void saveToFile();
void loadFromFile();

int main() {
    loadFromFile();
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                saveToFile();
                break;
            case 0:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. Display All Accounts\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Save Accounts to File\n");
    printf("0. Exit\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }

    Account newAccount;
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    printf("Enter account holder name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

void displayAccounts() {
    if (accountCount == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("\n--- List of Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %s, Name: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

void depositMoney() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float depositAmount;

    printf("Enter account number for deposit: ");
    scanf("%s", accountNumber);
    
    int index = findAccountIndex(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &depositAmount);
    if (depositAmount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }

    accounts[index].balance += depositAmount;
    printf("Amount deposited successfully. New balance: %.2f\n", accounts[index].balance);
}

void withdrawMoney() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float withdrawalAmount;

    printf("Enter account number for withdrawal: ");
    scanf("%s", accountNumber);

    int index = findAccountIndex(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &withdrawalAmount);
    if (withdrawalAmount <= 0 || withdrawalAmount > accounts[index].balance) {
        printf("Invalid withdrawal amount!\n");
        return;
    }

    accounts[index].balance -= withdrawalAmount;
    printf("Amount withdrawn successfully. New balance: %.2f\n", accounts[index].balance);
}

int findAccountIndex(const char *accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            return i;
        }
    }
    return -1;
}

void saveToFile() {
    FILE *file = fopen("accounts.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    for (int i = 0; i < accountCount; i++) {
        fprintf(file, "%s,%s,%.2f\n", accounts[i].accountNumber, 
                accounts[i].name, accounts[i].balance);
    }
    fclose(file);
    printf("Accounts saved to file successfully.\n");
}

void loadFromFile() {
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        return; // If the file doesn't exist, just return
    }

    while (fscanf(file, "%[^,],%[^,],%f\n", accounts[accountCount].accountNumber,
                  accounts[accountCount].name, &accounts[accountCount].balance) == 3) {
        accountCount++;
        if (accountCount >= MAX_ACCOUNTS) {
            break;
        }
    }
    fclose(file);
    printf("Accounts loaded from file successfully.\n");
}