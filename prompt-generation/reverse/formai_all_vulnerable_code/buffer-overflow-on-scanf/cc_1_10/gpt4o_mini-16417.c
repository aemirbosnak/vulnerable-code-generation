//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }
    
    Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0; // Start with a zero balance
    
    accounts[numAccounts] = newAccount;
    numAccounts++;
    printf("Account created successfully!\n");
}

void deposit() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("New balance for account %d is %.2f\n", accountNumber, accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found.\n");
}

void withdraw() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient funds.\n");
            } else {
                accounts[i].balance -= amount;
                printf("New balance for account %d is %.2f\n", accountNumber, accounts[i].balance);
            }
            return;
        }
    }
    
    printf("Account not found.\n");
}

void viewAccounts() {
    if (numAccounts == 0) {
        printf("No accounts available.\n");
        return;
    }
    
    printf("\n--- Account List ---\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

void deleteAccount() {
    int accountNumber;
    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            for (int j = i; j < numAccounts - 1; j++) {
                accounts[j] = accounts[j + 1]; // Shift accounts left
            }
            numAccounts--;
            printf("Account %d deleted successfully.\n", accountNumber);
            return;
        }
    }
    
    printf("Account not found.\n");
}

void menu() {
    while (1) {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Accounts\n");
        printf("5. Delete Account\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        
        int choice;
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
                viewAccounts();
                break;
            case 5:
                deleteAccount();
                break;
            case 6:
                printf("Thank you for using the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}