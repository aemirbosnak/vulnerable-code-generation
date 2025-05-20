//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[30];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void depositMoney();
void withdrawMoney();
void displayAccounts();
void transactionHistory();
void clearInputBuffer();

int main() {
    int choice;
    while (true) {
        printf("\n--- Bank Record System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Accounts\n");
        printf("5. Show Transaction History\n");
        printf("6. Exit\n");
        printf("Select an option (1-6): ");
        
        scanf("%d", &choice);
        clearInputBuffer();
        
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
                displayAccounts(); 
                break;
            case 5: 
                transactionHistory(); 
                break;
            case 6: 
                printf("Thank you for using the Bank Record System. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Max limit reached.\n");
        return;
    }
    Account newAccount;
    printf("Enter Account Number: ");
    scanf("%d", &newAccount.accountNumber);
    clearInputBuffer();
    printf("Enter Account Holder Name: ");
    fgets(newAccount.name, 30, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // Remove newline
    newAccount.balance = 0.0;
    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

void depositMoney() {
    int accNum;
    float amount;
    printf("Enter Account Number to deposit: ");
    scanf("%d", &accNum);
    clearInputBuffer();
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            accounts[i].balance += amount;
            printf("Successfully deposited %.2f to account number %d.\n", amount, accNum);
            return;
        }
    }
    printf("Account number not found.\n");
}

void withdrawMoney() {
    int accNum;
    float amount;
    printf("Enter Account Number to withdraw from: ");
    scanf("%d", &accNum);
    clearInputBuffer();
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Successfully withdrew %.2f from account number %d.\n", amount, accNum);
            } else {
                printf("Insufficient balance in account number %d.\n", accNum);
            }
            return;
        }
    }
    printf("Account number not found.\n");
}

void displayAccounts() {
    printf("\n--- List of Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

void transactionHistory() {
    // For now, we'll leave this function as a placeholder
    printf("Transaction history functionality is not yet implemented.\n");
}