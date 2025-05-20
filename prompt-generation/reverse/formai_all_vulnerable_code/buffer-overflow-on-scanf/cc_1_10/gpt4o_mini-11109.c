//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    float balance;
    int isActive;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function to create a new account
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("No more accounts can be created. All life has gone to waste!\n");
        return;
    }
    
    Account newAccount;
    printf("Enter survivor's name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0f;
    newAccount.isActive = 1;
    
    accounts[accountCount++] = newAccount;
    printf("Account for %s created. Balance: %.2f\n", newAccount.name, newAccount.balance);
}

// Function to deposit to an account
void depositToAccount() {
    char name[NAME_LEN];
    float amount;
    printf("Enter survivor's name for deposit: ");
    scanf("%s", name);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].name, name) == 0 && accounts[i].isActive) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount < 0) {
                printf("Post-apocalyptic economy doesn't allow negative deposits!\n");
            } else {
                accounts[i].balance += amount;
                printf("Deposited %.2f to %s's account. New balance: %.2f\n", amount, name, accounts[i].balance);
            }
            return;
        }
    }
    printf("Survivor %s not found or inactive.\n", name);
}

// Function to withdraw from an account
void withdrawFromAccount() {
    char name[NAME_LEN];
    float amount;
    printf("Enter survivor's name for withdrawal: ");
    scanf("%s", name);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].name, name) == 0 && accounts[i].isActive) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount < 0) {
                printf("You can't withdraw negative amounts in this wasteland!\n");
            } else if (amount > accounts[i].balance) {
                printf("Insufficient balance! You can't withdraw more than %.2f\n", accounts[i].balance);
            } else {
                accounts[i].balance -= amount;
                printf("Withdrew %.2f from %s's account. New balance: %.2f\n", amount, name, accounts[i].balance);
            }
            return;
        }
    }
    printf("Survivor %s not found or inactive.\n", name);
}

// Function to display account information
void displayAccountInfo() {
    char name[NAME_LEN];
    printf("Enter survivor's name to display account info: ");
    scanf("%s", name);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("Account for %s: Balance: %.2f, Status: %s\n", 
                   accounts[i].name, 
                   accounts[i].balance, 
                   accounts[i].isActive ? "Active" : "Inactive");
            return;
        }
    }
    printf("Survivor %s not found.\n", name);
}

// Main menu
void menu() {
    int choice;
    do {
        printf("\nPost-Apocalyptic Banking System:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account Info\n");
        printf("5. Exit\n");
        printf("Choose an action: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositToAccount();
                break;
            case 3:
                withdrawFromAccount();
                break;
            case 4:
                displayAccountInfo();
                break;
            case 5:
                printf("Wasteland awaits, take care!\n");
                break;
            default:
                printf("Invalid choice. Make the choice wisely!\n");
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Post-Apocalyptic Banking Record System!\n");
    menu();
    return 0;
}