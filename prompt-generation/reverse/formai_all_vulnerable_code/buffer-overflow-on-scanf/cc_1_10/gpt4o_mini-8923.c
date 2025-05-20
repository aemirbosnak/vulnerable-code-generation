//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_NUMBER_LENGTH 20
#define NAME_LENGTH 100

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void clearScreen() {
    printf("\033[H\033[J");
}

void pause() {
    printf("Press Enter to continue...");
    while(getchar() != '\n');
}

void displayMenu() {
    clearScreen();
    printf("--------- Banking Record System ---------\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Display Account Details\n");
    printf("5. Exit\n");
    printf("-----------------------------------------\n");
    printf("Select an option: ");
}

int validateAccountNumber(const char* accountNumber) {
    for(int i = 0; i < accountCount; i++) {
        if(strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            return 1; // Account found
        }
    }
    return 0; // Account not found
}

void createAccount() {
    if(accountCount >= MAX_ACCOUNTS) {
        printf("Error: Maximum account limit reached!\n");
        pause();
        return;
    }

    Account newAccount;
    printf("Creating a new account...\n");
    
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    
    while(validateAccountNumber(newAccount.accountNumber)) {
        printf("Account number already exists. Please try again: ");
        scanf("%s", newAccount.accountNumber);
    }

    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0.0;
    
    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
    pause();
}

void depositMoney() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for deposit: ");
    scanf("%s", accountNumber);
    
    if(!validateAccountNumber(accountNumber)) {
        printf("Error: Account not found!\n");
        pause();
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for(int i = 0; i < accountCount; i++) {
        if(strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            accounts[i].balance += amount;
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            break;
        }
    }
    pause();
}

void withdrawMoney() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for withdrawal: ");
    scanf("%s", accountNumber);
    
    if(!validateAccountNumber(accountNumber)) {
        printf("Error: Account not found!\n");
        pause();
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for(int i = 0; i < accountCount; i++) {
        if(strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            if(amount > accounts[i].balance) {
                printf("Error: Insufficient balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            }
            break;
        }
    }
    pause();
}

void displayAccountDetails() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];

    printf("Enter account number to display details: ");
    scanf("%s", accountNumber);
    
    if(!validateAccountNumber(accountNumber)) {
        printf("Error: Account not found!\n");
        pause();
        return;
    }

    for(int i = 0; i < accountCount; i++) {
        if(strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Account Number: %s\n", accounts[i].accountNumber);
            printf("Account Holder's Name: %s\n", accounts[i].name);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            break;
        }
    }
    pause();
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
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
                displayAccountDetails();
                break;
            case 5:
                printf("Exiting the system securely...\n");
                break;
            default:
                printf("Error: Invalid choice, please try again.\n");
                pause();
                break;
        }
    } while(choice != 5);

    printf("Thank you for using our banking system!\n");
    return 0;
}